#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cctype>
#include <ctype.h>
#include <map>
#include <conio.h>
#include "tsm_sen_matrix.h"
#include "term_sen_matrix.cpp"
#include "SVD.h"
#include "svdcmp.c"
#include "stemmer.cpp"

using namespace std;

typedef map<int,int> MyClassSet;
typedef map<string, MyClassSet> MyClassSetMap;

void main_kartik()
{
    main_stemmer();
    int m,n;
    double** a;
    int **b;
    double** v;
    double* w;

    b = tsm_gen(&m,&n);
    ofstream fo("B.txt");
    ofstream fm("Values.txt");

    fm<<m<<endl<<n<<endl;


    a=new double* [m];

    for(int i=0;i<m;i++){
    a[i]=new double [n];
    }

    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
    a[i][j]=(double)b[i][j];
    fo<<"\t"<<a[i][j];
    fm<<a[i][j];
    }
    fo<<endl;
    fm<<endl;
    }

    w = new double [n];
    v= new double* [n];

    for(int i=0;i<n;i++){
    w[i]=0;
    v[i]=new double [n];
    for(int j=0;j<n;j++){
    v[i][j]=0;
    }
    }

    svdcmp(m,n,a,w,v);

    return;
}
