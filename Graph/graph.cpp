#include <cstdlib>
#include <iostream>

#include "consgraph.cpp"
using namespace std;

void graph()
{
    graph_main();
    int i,j,k;
    for(i=1;i<=n;i++){
    for(j=i+1;j<=n;j++){
    ed[i][j]=-(j-i)*(j-i);
    for(k=1;k<=terms;k++)
    ed[i][j]+=ts[k][i]*ts[k][j];
                        }
    ed[j][i]=ed[i][j];
    par+=ed[i][j];
                      }
    par=par/(float)n;
    consgraph();
    return;
}
