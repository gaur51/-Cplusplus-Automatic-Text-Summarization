#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cctype>
using namespace std;
string str[10000][100];
string title[100];
int countt[10000];
int tt_count_line[10000];
int th_count_line[10000];
extern int i=1;
extern int tit_count=0;

/*int main()
{
    std::ifstream infi("input3.txt");
    std::vector<std::string> data (
        (std::istream_iterator<std::string>(infi)),
         std::istream_iterator<std::string>());
    vector<string>::iterator itrbegin = data.begin();
    vector<string>::iterator itrend = data.end();
    string temp,temp1;
    size_t found;
    int j=1;
    string qwerty;
    while(itrbegin != itrend)
    {
        temp=*itrbegin;
        found =temp.find('.');
        //strcpy(temp1,temp);
        temp1=temp;
        str[i][j]=temp;
        qwerty = temp;
        //cout<<str[i][j]<<" ";
        if (found!=std::string::npos)
        {
            countt[i]=j-1;
            //cout<<"\n\n"<<i<<" "<<countt[i];
            i+=1;
            j=1;
            //cout<<"\n";
        }
        j+=1;
        itrbegin++;
    }
    //cout<<"i= "<<i<<"j= "<<j<<"\n"<<countt[2];
    //cout<<str[4][4]<<"   k";
    //cout<<i;
    return 0;
}*/
int found_check(string temp)
{
    for(int y=0;y<tit_count;y++)
    {
        //if(strcmp())
        if (temp.compare(title[y])== 0)
        return 1;
    }
    return 0;
}
void fun_to_create_input_for_network()
{
    std::ifstream infi("input3.txt");
    std::vector<std::string> data (
        (std::istream_iterator<std::string>(infi)),
         std::istream_iterator<std::string>());
    vector<string>::iterator itrbegin = data.begin();
    vector<string>::iterator itrend = data.end();
    int tot_words=0;
    string temp,temp1;
    size_t found;
    int j=1;
    string qwerty;
    while(itrbegin != itrend)
    {
        temp=*itrbegin;
        found =temp.find('.');
        temp1=temp;
        title[j]=temp;
        qwerty = temp;
        if (found!=std::string::npos)
        {
            tit_count=j-1;
            j=1;
            itrbegin++;
            break;

        }
        j+=1;
        itrbegin++;
    }
    cout<<i<<"i\n";
    std::ifstream inf("thesor.txt");
    //string temp;
    std::vector<std::string> sw (
        (std::istream_iterator<std::string>(inf)),
         std::istream_iterator<std::string>());
    vector<string>::iterator swbegin = sw.begin();
    vector<string>::iterator swend = sw.end();
    cout<<"line_no no_words title_words thesors_word\n";
    std::ofstream file_out("title_thesors_count.txt");
    std::ofstream file_out1("tot_no_of_words.txt");
    //file_out<<"Line_no word_count title_count thesor_count\n";
    while(itrbegin != itrend)
    {
        temp=*itrbegin;
        found =temp.find('.');
        //strcpy(temp1,temp);
        temp1=temp;
        str[i][j]=temp;
        if (find(sw.begin(), sw.end(), temp) == sw.end()==0)
        {
            th_count_line[i]+=1;
        }
        else
        {
            //cout<<temp<<" ";
        }
        if(found_check(temp)==1)
        {
            tt_count_line[i]+=1;
            //cout<<temp<<" ";
        }
        qwerty = temp;
        //cout<<str[i][j]<<" ";
        if (found!=std::string::npos)
        {
            countt[i]=j-1;
            cout<<i<<" "<<countt[i]<<"  "<<th_count_line[i]<<" "<<tt_count_line[i]<<"\n";
            tot_words+=countt[i];
            file_out<<i<<" "<<countt[i]<<"  "<<th_count_line[i]<<" "<<tt_count_line[i]<<"\n";
            i+=1;
            j=1;
            //cout<<"\n";
        }
        j+=1;
        itrbegin++;
    }
    file_out1<<tot_words;
    //cout<<"i= "<<i<<"j= "<<j<<"\n"<<countt[2];
    //cout<<str[4][4]<<"   k";
    //cout<<i;
    return;
}
