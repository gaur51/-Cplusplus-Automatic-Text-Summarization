#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

// transform a string in-place to lower case
struct StrLower
{
    void operator()(std::string& s) const
    {
        for (std::string::iterator it = s.begin(); it != s.end(); ++it)
        {

           *it = static_cast<char>(std::tolower(static_cast<unsigned char>(*it)));
           //cout<<*it;
        }
    }
};
void converttosmall()
{
    std::ifstream inf("input.txt");
    std::ofstream file_out("input1.txt");
    string temp;
    std::vector<std::string> data (
        (std::istream_iterator<std::string>(inf)),
         std::istream_iterator<std::string>());

    // for each string in the vector, transform to lower case.
    for_each(data.begin(), data.end(), StrLower());
    vector<string>::iterator itrbegin = data.begin();
    vector<string>::iterator itrend = data.end();
    while(itrbegin != itrend)
    {
      cout<<*itrbegin<<" ";
      file_out<<*itrbegin;
      file_out<<" ";
      temp=*itrbegin;
      size_t found =temp.find('.');
      if (found!=std::string::npos)
      {
          cout<<"\n";
          file_out<<"";
      }


     itrbegin++;
    }
    // display all the transformed strings
    inf.close();
    file_out.close();
    return;
}
//int main(int argc, char *argv[])
//{
//    // build a vector of std::string from the input file
//    std::ifstream inf("input.txt");
//    std::ofstream file_out("input1.txt");
//    string temp;
//    std::vector<std::string> data (
//        (std::istream_iterator<std::string>(inf)),
//         std::istream_iterator<std::string>());
//
//    // for each string in the vector, transform to lower case.
//    for_each(data.begin(), data.end(), StrLower());
//    vector<string>::iterator itrbegin = data.begin();
//    vector<string>::iterator itrend = data.end();
//    while(itrbegin != itrend)
//    {
//      cout<<*itrbegin<<" ";
//      file_out<<*itrbegin;
//      file_out<<" ";
//      temp=*itrbegin;
//      size_t found =temp.find('.');
//      if (found!=std::string::npos)
//      {
//          cout<<"\n";
//          file_out<<"";
//      }
//
//
//     itrbegin++;
//    }
//    // display all the transformed strings
//    inf.close();
//    file_out.close();
//    return 0;
//}
//int main()
//{
//    converttosmall();
//    return 0;
//}
