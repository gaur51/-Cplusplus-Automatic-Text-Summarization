#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int no_of_line(string line)
{
    int l=line.length(),ans=0,i;
    for(i=0;i<l;i++)
    {
        if(line[i]=='.')
        ans+=1;
    }
    return ans;
}
void generate_line_no_para_no()
{
    std::string line;
    std::ifstream infile("input.txt");
    std::ofstream file_out("line_no_in_para.txt");
    std::ofstream fle_o("para_no.txt");
    std::ofstream file_outl("tot_no_of_line.txt");
    std::ofstream file_out2("tot_no_of_para.txt");
    int i=0,j,k;
    k=0;
    int a, b,m,tot_line=0,tot_para=0;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);

        //std::cout<<line;
        //std::cout<<line.back();
        //std::cout<<*line.rbegin();
        //std::cout<<i<<line[3];
        //line+=1;
        //cout<<line;
        //cout<<line[2]<<"\n";
        //i++;

        j=no_of_line(line);
        if(k>0)
        {
            //cout<<j;
            tot_line+=j;
            for(m=1;m<=j;m++)
            {
                file_out<<m<<"\n";
                fle_o<<i<<"\n";
                tot_para=i;
            }
        }
        //cout<<tot_line<<" "<<line<<"\n\n";
        k+=1;
        i+=1;
        //cout<<"j "<<j<<"\n";
        //if (!(iss >> a >> b)) { break; } // error

        // process pair (a,b)
    }
    //cout<<tot_line<<"j";
    file_outl<<tot_line;
    file_out2<<tot_para;
    return;

}
