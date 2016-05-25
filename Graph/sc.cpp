#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include "graph_allocate.cpp"

using namespace std;
void connect(int);
int ind[100000],st[100000],low[100000],in;


stack<int> s;

void sc()
{
    
    int i;
    in=0;
    cn=0;
    for(i=1;i<=n;i++){
    ind[i]=-1;
    st[i]=-1;
                      }
    
    for(i=1;i<=n;i++)
    {
      if(ind[i]!=-1)
        connect(i);
     }
    
    graph_allocate();
    return;
}
void connect(int j)
{
int w,i,k;
in++;
ind[j]=in;
low[j]=in;
s.push(j);
st[j]=1;
for(i=0;i<g[j].size();i++)
{
k=g[j][i];
if(ind[k]==-1){
connect(k);
low[j]=min(low[j],low[k]);
                }
else if(st[k]==1){
low[j]=min(low[j],ind[k]);
                   } 
}


if(low[j]==ind[j]){
cn++;
do{
if(!s.empty()){
  w=s.top();
  s.pop();
              }
  scc[cn].push_back(w);
   }while(w!=j);
                   }
}
