#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cctype>
#include "intit_o.cpp"
using namespace std;
void new_neural_network()
{

        std::ifstream inf("tot_no_of_line.txt");
    float w[29][29];
    string temp;
    int line,i,j;
    float d;
    for(i=0;i<29;i++)
    {
        for(j=0;j<29;j++)
        w[i][j]=0.5;
    }
    i=0;
    double itemp;
    std::vector<std::string> sw (
        (std::istream_iterator<std::string>(inf)),
         std::istream_iterator<std::string>());
    vector<string>::iterator swbegin = sw.begin();
    vector<string>::iterator swend = sw.end();
    string totl;
    int totline;
    totl=*swbegin;
    totline=atoi(totl.c_str());
    std::ifstream inf2("input_for_neural_network.txt");
    std::vector<std::string> ln (
        (std::istream_iterator<std::string>(inf2)),
         std::istream_iterator<std::string>());
    vector<string>::iterator lnbegin = ln.begin();
    vector<string>::iterator lnend = ln.end();
    std::ofstream res("result.txt");
    float o[29],b[29],r=0.5;
//    int j;
    for(line=1;line<=totline;line++)
    {
        for(i=1;i<29;i++)
        {
            o[i]=0;
            //b[i]=0;
        }
        //cout<<"line no    "<<line<<"\n\n";
        temp=*lnbegin;
        //cout<<"value of o["<<"] is "<<*lnbegin<<"  ";
        //temp = "0.6";
        //itemp=atof(temp);
        itemp = ::atof(temp.c_str());
        o[22]=(float)itemp;
        //cout<<"value of o["<<"] is "<<o[22]<<"\n\n\n";
        lnbegin++;
        temp=*lnbegin;
        itemp = ::atof(temp.c_str());
        o[23]=(float)itemp;
        lnbegin++;
        temp=*lnbegin;
        itemp = ::atof(temp.c_str());
        o[24]=(float)itemp;
        lnbegin++;
        temp=*lnbegin;
        itemp = ::atof(temp.c_str());
        o[25]=(float)itemp;
        //cout<<"value of o[25]"<<itemp<<"\n\n\n\n";
        lnbegin++;
        temp=*lnbegin;
        itemp = ::atof(temp.c_str());
        o[26]=(float)itemp;
        lnbegin++;
        temp=*lnbegin;
        itemp = ::atof(temp.c_str());
        o[27]=(float)itemp;
        lnbegin++;
        temp=*lnbegin;
        itemp = ::atof(temp.c_str());
        o[28]=(float)itemp;
        lnbegin++;

        init_o(o,w);
//        cout<<o[1]<<"\n";
        res<<o[1]<<"\n";

    }
    return;

}
