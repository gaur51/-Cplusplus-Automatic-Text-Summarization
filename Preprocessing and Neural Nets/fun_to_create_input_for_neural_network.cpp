#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cctype>
using namespace std;
void fun_to_create_input_for_neural_network()
{
    std::ifstream inf("para_no.txt");
    std::vector<std::string> pn (
        (std::istream_iterator<std::string>(inf)),
         std::istream_iterator<std::string>());
    vector<string>::iterator pnbegin = pn.begin();
    vector<string>::iterator pnend = pn.end();
    std::ifstream inf1("line_no_in_para.txt");
    std::vector<std::string> ln (
        (std::istream_iterator<std::string>(inf1)),
         std::istream_iterator<std::string>());
    vector<string>::iterator lnbegin = ln.begin();
    vector<string>::iterator lnend = ln.end();
    std::ifstream inf2("title_thesors_count.txt");
    std::vector<std::string> ttc (
        (std::istream_iterator<std::string>(inf2)),
         std::istream_iterator<std::string>());
    vector<string>::iterator ttcbegin = ttc.begin();
    vector<string>::iterator ttcend = ttc.end();
    std::ifstream inf3("tot_no_of_line.txt");
    std::vector<std::string> tot_l_c (
        (std::istream_iterator<std::string>(inf3)),
         std::istream_iterator<std::string>());
    vector<string>::iterator tot_l_co = tot_l_c.begin();
    //vector<string>::iterator ttcend = tot_l_c.end();
    std::ifstream inf4("tot_no_of_para.txt");
    std::vector<std::string> tot_p_c (
        (std::istream_iterator<std::string>(inf4)),
         std::istream_iterator<std::string>());
    vector<string>::iterator tot_p_co = tot_p_c.begin();
        std::ifstream inf5("tot_no_of_words.txt");
    std::vector<std::string> tot_w_c (
        (std::istream_iterator<std::string>(inf5)),
         std::istream_iterator<std::string>());
    vector<string>::iterator tot_w_co = tot_w_c.begin();
    //vector<string>::iterator ttcend = tot_l_c.end();
    string para_no,line_no,ttco,tot_l_count,tot_p_count,tot_w_count;
    int ipara_no,iline_no,ittco,itot_l_count,itot_p_count,itot_w_count;
    tot_l_count=*tot_l_co;
    tot_p_count=*tot_p_co;
    tot_w_count=*tot_w_co;
    itot_l_count=atoi(tot_l_count.c_str());
    itot_p_count=atoi(tot_p_count.c_str());
    itot_w_count=atoi(tot_w_count.c_str());
    std::ofstream file_out("input_for_neural_network.txt");
    float a[8];
    while(pnbegin!=pnend)
    {
        para_no=*pnbegin;
        line_no=*lnbegin;
        ttcbegin++;
        ttco=*ttcbegin;
        ipara_no=atoi(para_no.c_str());
        iline_no=atoi(line_no.c_str());
        if(ipara_no==1)
        {
            a[1]=0.8;
            //file_out<<"1\t"<<ipara_no<<"\t"<<iline_no<<"\t";
        }

        else
        {
            a[1]=0.2;
            //file_out<<"0\t"<<ipara_no<<"\t"<<iline_no<<"\t";
        }
        if(iline_no==1)
        {
            a[4]=0.8;
            //file_out<<"1\t";
        }
        else
        {
            a[4]=0.2;
            //file_out<<"0\t";
        }
        a[2]=ipara_no/itot_p_count;
        a[3]=iline_no/itot_l_count;
        ittco=atoi(ttco.c_str());
        a[5]=(float)ittco/itot_w_count;
        a[5]*=5;
        //cout<<a[5];
        //file_out<<ittco<<"\t";//no_of_words
        ttcbegin++;
        ttco=*ttcbegin;
        ittco=atoi(ttco.c_str());
        a[6]=(3*ittco);
        a[6]/=20;
        if(a[6]==0)
        a[6]=0.1;
        //file_out<<ittco<<"\t";//no_of_thesor
        ttcbegin++;
        ttco=*ttcbegin;
        ittco=atoi(ttco.c_str());
        a[7]=(0.2*ittco);
        a[7]+=0.1;
        file_out<<a[1]<<"\t"<<a[2]<<"\t"<<a[3]<<"\t"<<a[4]<<"\t"<<a[5]<<"\t"<<a[6]<<"\t"<<a[7]<<"\n";
        //file_out<<ittco<<"\n";//no_of_title
        //cout<<"pnbegin "<<*pnbegin<<"\n\n\n";
        pnbegin++;
        if(pnbegin==pnend)
        break;
        //cout<<"pnbegin "<<*pnbegin<<"\n\n\n";
        lnbegin++;
        ttcbegin++;



    }


}
