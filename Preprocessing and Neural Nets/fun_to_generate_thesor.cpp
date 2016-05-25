#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cctype>
#include <ctype.h>
#include <map>

using namespace std;
string thr_words[20];
typedef map<int,int>      MyClassSet;
typedef map<string, MyClassSet> MyClassSetMap;
void fun_to_generate_thesor()
{
    int sen=0,term=0;
    std::map<string,int> mymap;
    string tq;
    std::pair<std::map<string,int>::iterator,bool> ret;
    MyClassSetMap tsm;
    ifstream inf("input4.txt");
    vector<string> sw (
        (istream_iterator<string>(inf)),
         istream_iterator<string>());

    ofstream ts("term_sen.txt");
    vector<string>::iterator str = sw.begin();

    while(str!=sw.end())                    //the most important part of the term sentence matrix generation
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
    cout<<term<<" "<<sen<<"p\n";

    int tt=0;
    for(MyClassSetMap::iterator it=tsm.begin();it!=tsm.end();it++)
    {
        ts<<it->first;
        for(int y=0;y<20-strlen((it->first).c_str());y++){
        ts<<" ";
        }
        tq=it->first;
        tt=0;
        for(int x=0;x<sen;x++)
        {
            ts<<(it->second)[x]<<" ";
            tt+=(it->second)[x];
        }
        ret = mymap.insert ( std::pair<string,int>(tq,tt) );
        ts<<endl;
    }
    map<string,int>::iterator it = mymap.begin();
    multimap<int,string> mymultimap;
    for (it=mymap.begin(); it!=mymap.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << '\n';
        mymultimap.insert ( std::pair<int,string>(it->second,it->first) );

    }

    std::multimap<int,string>::reverse_iterator rit;
    int r=0;
    for (rit=mymultimap.rbegin(); rit!=mymultimap.rend(); ++rit)
    {
        std::cout << rit->first << " => " << rit->second << '\n';
        if(r<10)
        {
            thr_words[r]=rit->second ;
            r+=1;
        }
    }
    cout<<"\n";
    ofstream th("thesor.txt");
    for(r=0;r<10;r++)
    {
        cout<<thr_words[r]<<" ";
        th<<thr_words[r]<<"\n";
    }

    return;
}
//int main()
//{
//    int sen=0,term=0;
//    std::map<string,int> mymap;
//    string tq;
//    std::pair<std::map<string,int>::iterator,bool> ret;
//    MyClassSetMap tsm;
//    ifstream inf("input4.txt");
//    vector<string> sw (
//        (istream_iterator<string>(inf)),
//         istream_iterator<string>());
//
//    ofstream ts("term_sen.txt");
//    vector<string>::iterator str = sw.begin();
//
//    while(str!=sw.end())                    //the most important part of the term sentence matrix generation
//    {
//        if(*str==".")sen++;
//        else if(tsm.find(*str)==tsm.end()){
//            tsm[*str][sen]=1;
//            ++term;
//        }
//        else{
//            (((tsm.find(*str))->second)[sen])++;
//        }
//        str++;
//    }
//    cout<<term<<" "<<sen<<"p\n";
//
//    int tt=0;
//    for(MyClassSetMap::iterator it=tsm.begin();it!=tsm.end();it++)
//    {
//        ts<<it->first;
//        for(int y=0;y<20-strlen((it->first).c_str());y++){
//        ts<<" ";
//        }
//        tq=it->first;
//        tt=0;
//        for(int x=0;x<sen;x++)
//        {
//            ts<<(it->second)[x]<<" ";
//            tt+=(it->second)[x];
//        }
//        ret = mymap.insert ( std::pair<string,int>(tq,tt) );
//        ts<<endl;
//    }
//    map<string,int>::iterator it = mymap.begin();
//    multimap<int,string> mymultimap;
//    for (it=mymap.begin(); it!=mymap.end(); ++it)
//    {
//        std::cout << it->first << " => " << it->second << '\n';
//        mymultimap.insert ( std::pair<int,string>(it->second,it->first) );
//
//    }
//
//    std::multimap<int,string>::reverse_iterator rit;
//    int r=0;
//    for (rit=mymultimap.rbegin(); rit!=mymultimap.rend(); ++rit)
//    {
//        std::cout << rit->first << " => " << rit->second << '\n';
//        if(r<10)
//        {
//            thr_words[r]=rit->second ;
//            r+=1;
//        }
//    }
//    cout<<"\n";
//    ofstream th("thesor.txt");
//    for(r=0;r<10;r++)
//    {
//        cout<<thr_words[r]<<" ";
//        th<<thr_words[r]<<"\n";
//    }
//    fun_to_generate_thesor();

//    return 0;
//}
