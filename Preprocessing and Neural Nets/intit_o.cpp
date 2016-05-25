#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cctype>
//#define sigma(f) ((f*(f+1))/2)

using namespace std;
int sigma(int x)
{
    int ans;
    ans=x*(x+1);
    ans=ans/2;
    return ans;
}
void init_o(float o[29],float w[29][29])
{
    int l,i,j,sig_i,sig_j;
    cout<<"Sdfaf"<<w[3][5];
    for(l=5;l>=0;l--)
    {
        sig_i=sigma(l);
        for(i=sig_i+1; i<= sigma(l+1);i++)
        {
            //cout<<"i  "<<i<<"\n";
            sig_j=sigma(l+1);
            for(j=sig_j;j<=sigma(l+2);j++)
            {
                o[i]+=w[i][j]*o[j];

            }
//            if(line<5)
//            cout<<"o["<<i<<"] "<<o[i]<<" ";
        }
    }

    return;
}
