#include <cstdlib>
#include <iostream>
#include <vector>
 
using namespace std;
int n,terms,cn;
float par,ed[1001][1001],ts[1001][1001],svd_points[1001],neural_points[1001],fr;
vector< vector<int> > g;
vector < vector <int> > scc;
void graph_main()
{
     int i,j;
    freopen("values.txt","r",stdin);
    cin >> n;
    cin >> terms;
    for(i=1;i<=terms;i++){
    for(j=1;j<=n;j++){
    cin >> ts[i][j];
                          }
                          }
    cin >> fr;
    for(i=1;i<=n;i++)
    cin >> neural_points[i];
    for(i=1;i<=n;i++)
    cin >> svd_points[i];
   
    return;
}
