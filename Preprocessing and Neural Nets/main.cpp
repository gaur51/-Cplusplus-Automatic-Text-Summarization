#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cctype>
#include <ctype.h>
#include "removestopword.cpp"
#include "converttosmall.cpp"
#include "removepunctuation.cpp"
#include "file_for_creating_input4_txt.cpp"
#include "generate_line_no_para_no.cpp"
#include "fun_to_generate_thesor.cpp"
#include "fun_to_create_input_for_network.cpp"
#include "fun_to_create_input_for_neural_network.cpp"
#include "new_neural_network.cpp"
using namespace std;
int main()
{
    converttosmall();
    removepunctuation();
    removestopword();
    file_for_creating_input4_txt();
    generate_line_no_para_no();
    fun_to_generate_thesor();
    fun_to_create_input_for_network();
    fun_to_create_input_for_neural_network();
    new_neural_network();
    return 1;

}
