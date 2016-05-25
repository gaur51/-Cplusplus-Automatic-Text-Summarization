#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cctype>
#include <ctype.h>
using namespace std;
void file_for_creating_input4_txt()
{
    std::ifstream inf("stopwords.txt");
    string temp;
    std::vector<std::string> sw (
        (std::istream_iterator<std::string>(inf)),
         std::istream_iterator<std::string>());

    std::ifstream infi("input3.txt");
    std::ofstream file_out("input4.txt");
    std::vector<std::string> data (
        (std::istream_iterator<std::string>(infi)),
         std::istream_iterator<std::string>());

    vector<string>::iterator swbegin = sw.begin();
    vector<string>::iterator swend = sw.end();
    string swsrt;
    vector<string>::iterator itrbegin = data.begin();
    vector<string>::iterator itrend = data.end();
    //cout<<"k";
    while(itrbegin != itrend)
    {
        //swsrt=*itrbegin;

        temp=*itrbegin;
        size_t found =temp.find('.');
        if (found!=std::string::npos)
        {
            file_out<<".\n";
        }
        else
        {
            file_out<<*itrbegin;
            file_out<<" ";
        }


        itrbegin++;
    }
    infi.close();
    inf.close();
    file_out.close();
    return;
}
//int main()
//{
//    std::ifstream inf("stopwords.txt");
//    string temp;
//    std::vector<std::string> sw (
//        (std::istream_iterator<std::string>(inf)),
//         std::istream_iterator<std::string>());
//
//    std::ifstream infi("input3.txt");
//    std::ofstream file_out("input4.txt");
//    std::vector<std::string> data (
//        (std::istream_iterator<std::string>(infi)),
//         std::istream_iterator<std::string>());
//
//    vector<string>::iterator swbegin = sw.begin();
//    vector<string>::iterator swend = sw.end();
//    string swsrt;
//    vector<string>::iterator itrbegin = data.begin();
//    vector<string>::iterator itrend = data.end();
//    //cout<<"k";
//    while(itrbegin != itrend)
//    {
//        //swsrt=*itrbegin;
//
//        temp=*itrbegin;
//        size_t found =temp.find('.');
//        if (found!=std::string::npos)
//        {
//            file_out<<".\n";
//        }
//        else
//        {
//            file_out<<*itrbegin;
//            file_out<<" ";
//        }
//
//
//        itrbegin++;
//    }
//    infi.close();
//    inf.close();
//    file_out.close();
//    return 0;
//}
