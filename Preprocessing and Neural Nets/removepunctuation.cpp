#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cctype>
#include <ctype.h>
using namespace std;
void removepunctuation()
{
    int i;
    std::ifstream inf("input1.txt");
    std::ofstream out_file("input2.txt");
    std::ofstream file_out("tempepkrewa.txt");
    std::vector<std::string> data (
        (std::istream_iterator<std::string>(inf)),
         std::istream_iterator<std::string>());

    vector<string>::iterator itrbegin = data.begin();
    vector<string>::iterator itrend = data.end();
    char temp[1024];
    string a;
    while(itrbegin != itrend)
    {
      //cout<<*itrbegin;

      string q;
      int temp1;
      q=*itrbegin;
      strcpy(temp, q.c_str());
      file_out<<" ";
      bool t=0;
      temp1=0;
      for(i=0;temp[i]!='\0';i++)
      {
          //cout<<temp[i]<<"  ";
          if(temp[i]=='.')
          {
              //cout<<"HUDFFUKHJFJHFJKFKJF";
              //temp1=1;
              out_file<<temp[i]<<"\n";
          }
          else if(isalnum(temp[i])==0)
          {
              t=1;
              out_file<<" ";
              //break;
          }
          else
          {
              out_file<<temp[i];
          }

      }
      out_file<<" ";
      if(t==0)
      file_out<<*itrbegin;
      //temp1=*itrbegin;
      if(temp1==1)
      {
          cout<<"\n";
          file_out<<"\n";
      }
     itrbegin++;
    }
    inf.close();
    file_out.close();
    return;
}
//int main()
//{
//    int i;
//    std::ifstream inf("input1.txt");
//    std::ofstream out_file("input2.txt");
//    std::ofstream file_out("tempepkrewa.txt");
//    std::vector<std::string> data (
//        (std::istream_iterator<std::string>(inf)),
//         std::istream_iterator<std::string>());
//
//    vector<string>::iterator itrbegin = data.begin();
//    vector<string>::iterator itrend = data.end();
//    char temp[1024];
//    string a;
//    while(itrbegin != itrend)
//    {
//      //cout<<*itrbegin;
//
//      string q;
//      int temp1;
//      q=*itrbegin;
//      strcpy(temp, q.c_str());
//      file_out<<" ";
//      bool t=0;
//      temp1=0;
//      for(i=0;temp[i]!='\0';i++)
//      {
//          //cout<<temp[i]<<"  ";
//          if(temp[i]=='.')
//          {
//              //cout<<"HUDFFUKHJFJHFJKFKJF";
//              //temp1=1;
//              out_file<<temp[i]<<"\n";
//          }
//          else if(isalnum(temp[i])==0)
//          {
//              t=1;
//              out_file<<" ";
//              //break;
//          }
//          else
//          {
//              out_file<<temp[i];
//          }
//
//      }
//      out_file<<" ";
//      if(t==0)
//      file_out<<*itrbegin;
//      //temp1=*itrbegin;
//      if(temp1==1)
//      {
//          cout<<"\n";
//          file_out<<"\n";
//      }
//     itrbegin++;
//    }
//    inf.close();
//    file_out.close();
//    return 0;
//}
