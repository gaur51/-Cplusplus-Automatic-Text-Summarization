#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include "graph_main.cpp"
struct node{
int num;
float poin;
            }; 
class compare{
public:
bool operator()(node &nd1,node &nd2){
if(nd2.poin>nd1.poin)
return true;
return false;
                                     }
              };
using namespace std;

void graph_allocate()
{
      float graph_points[1001],sum,avg,sz,r,mini;
      int t,i,j;
     
      
    
    node nd;
    priority_queue<node,vector<node>,compare> pq[1000];
    
   freopen("Points_graph.txt","w",stdout);

    for(i=1;i<=n;i++){
    graph_points[i]=rand() % 10 + 10;
                      }
    for(i=1;i<=cn;i++){
    sum+=scc[i].size();
    for(j=0;j<scc[i].size();j++){
    nd.num=scc[i][j];
    nd.poin=svd_points[nd.num]+neural_points[nd.num];
    pq[i].push(nd);
                                 }
                       }
    avg=sum/n;
    for(i=1;i<=cn;i++)
    {
    r=(float) pq[i].size()*(fr);
    t=(int) r;
    
    mini=max(2,t);
    sz=pq[i].size();
   for(j=0;j<mini && !pq[i].empty() && sz>=avg;j++){
   nd=pq[i].top();
   pq[i].pop();
   graph_points[nd.num]+=nd.poin;
    
                                     }
    
     }
     for(i=1;i<=n;i++)
     cout << graph_points[i];
    
    return;
}
