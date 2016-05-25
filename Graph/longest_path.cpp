#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
struct node{
int num;
int da;
       };
struct edge{
int o;
int se;
int len;
       };

class compare{
public:
bool operator()(struct node &v1,struct node &v2){
if((v2.da!=-1&&v1.da==-1)||(v1.da!=-1&&v1.da!=-1&&v2.da<v1.da))
return true;
return false;
                                    }
              };
using namespace std;

int main(int argc, char *argv[])
{
    int n,m,s,i,v1,v2,j,l,b,d,v,count,u,q,p,dt,k;
    priority_queue <node,vector<node>,compare> pq;
    cin >> n >> m >> s;
    struct edge ed[m+10];
    int vis[n+10],di[n+10];
    vector< vector<int> > g,dis;
    g.resize(n+10);
    dis.resize(n+10); 
    for(i=0;i<m;i++){
    cin >> v1 >> v2 >> dt;
    g[v1].push_back(v2);
    dis[v1].push_back(dt);
    g[v2].push_back(v1);
    dis[v2].push_back(dt);
    ed[i+1].o=v1;
    ed[i+1].se=v2;
    ed[i+1].len=dt;
                     }
    cin>> l;
    for(j=1;j<=n;j++){
    vis[j]=0;
    di[j]=-1;
                      }
    struct node a,x,c;
 di[s]=0;
 a.num=s;
 a.da=0;
 pq.push(a);
 while(!pq.empty()){
 x=pq.top();
 b=x.num;
 vis[b]=1;
 for(i=0;i<g[b].size();i++){
 v=g[b][i];
 d=dis[b][i];
 if(di[b]==-1)
 k=-1;
 else
 k=di[b]+d;
 if(vis[v]!=1&&((k!=-1&&di[v]!=-1&&k<di[v])||(k!=-1&&di[v]==-1)))
 {
 di[v]=k;
 c.num=v;
 c.da=k;
 pq.push(c);
                                   }
                            }
 pq.pop();
                    }
 count=0;
 
 for(i=1;i<=n;i++){
 
 if(di[i]==l)
 count++;
                   }
for(i=1;i<=m;i++){
u=ed[i].o;
v=ed[i].se;
if(l>di[u]&&(l<di[u]+ed[i].len)&&l<=(di[v]+ed[i].len-l+di[u]))
count++;
if(l>di[v]&&(l<di[v]+ed[i].len)&&l<=(di[u]+ed[i].len-l+di[v]))
count++;
q=l-di[u];
p=l-di[v];
if(q+p==ed[i].len&&l>di[u]&&l<(di[u]+ed[i].len)&&l>di[v]&&l<(di[v]+ed[i].len))
count--;
                  }
cout<< count <<"\n";
g.clear();
dis.clear();
    //system("PAUSE");
    return 0;
}
