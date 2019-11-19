#pragma once
#include<string>
#include <iostream>
#include <stack> 
#include <vector> 

using namespace std;
class ConversionAPostFija
{
private:
    vector<char> signs;
    //c++ 11
    stack <char>* operators = nullptr;
    //c++ 11
    vector<string>* numbers = nullptr;
public:
    ConversionAPostFija();
    void Initializer();
    vector<string>* Convert(string cadena);
	int Precedencia(string val, string val2);
};

