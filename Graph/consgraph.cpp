#include <cstdlib>
#include <iostream>
#include <vector>

#include "sc.cpp"
using namespace std;

 
void consgraph()
{
    vector< vector<int> > gc; 
     g.resize(1001);
     gc.resize(1001);
    int i,j,k;
    float len;
    for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
    if(i!=j)
    gc[i].push_back(j);
                      }
                      }
    for(i=1;i<=n;i++)
    {
     for(j=0;j<gc[i].size();j++)
     {
     k=gc[i][j];
     len=ed[i][j];
     if(len>=par)
     g[i].push_back(k);
     
     }
    }
    sc();
    return ;
}
