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
public:
    ConversionAPostFija();
    void Initializer();
    vector<string>* Convert(string cadena);
	int Precedencia(string val, string val2);
};

