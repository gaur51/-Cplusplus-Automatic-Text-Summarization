#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cctype>
#include <ctype.h>
#include <map>
#include "tsm_sen_matrix.h"

using namespace std;

typedef map<int,int> MyClassSet;
typedef map<string, MyClassSet> MyClassSetMap;

int** tsm_gen(int *m, int *n){
    int i=0,sen=0,term=0;
    MyClassSetMap tsm;
    ifstream inf("Sim_file.txt");
    vector<string> sw (
        (istream_iterator<string>(inf)),
         istream_iterator<string>());

    vector<string>::iterator str = sw.begin();

    while(str!=sw.end())   //the most important part of the term sentence matrix generation
    {
        if(*str==".")sen++;
        else if(tsm.find(*str)==tsm.end()){
            tsm[*str][sen]=1;
            ++term;
        }
        else{
            (((tsm.find(*str))->second)[sen])++;
        }
        str++;
    }

        int **a=new int*[term];

        for(int x=0;x<term;x++)
        {
            a[x]=new int[sen];
        }

    ofstream ts("term_sen.txt");

    for(MyClassSetMap::iterator it=tsm.begin();it!=tsm.end();it++)
    {
        ts<<it->first;
        for(int y=0;y<20-strlen((it->first).c_str());y++){
        ts<<" ";
        }
        for(int x=0;x<sen;x++){
        ts<<(it->second)[x]<<" ";
        a[i][x]=(it->second)[x];
        }
        ts<<endl;   i++;
    }

    *m=term;    *n=sen;
    return a;
}
