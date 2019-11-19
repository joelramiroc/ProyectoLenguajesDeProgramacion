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
    stack <char>* operators;
    vector<string>* numbers;
    int Precedencia(string val, string val2);
    void Initializer();
public:
    ConversionAPostFija();
    vector<string>* Convert(string cadena);
};

