#pragma once
#include<string>
#include <iostream>
#include <stack> 
#include <vector> 
#include <regex> 
#include <conio.h> 

using namespace std;
class ConversionAPostFija
{
private:
    vector<char> signs;
    vector<char> numbersP;
    //c++ 11
    stack <char>* operators = nullptr;
    //c++ 11
    vector<string>* numbers = nullptr;

	//c++ 14 auto deduce el valor a retornar una funcion
    auto IsSign(char val);
    bool isNumber(char val);
public:
    ConversionAPostFija();
    void Initializer();
    vector<string>* Convert(string cadena);
	int Precedencia(string val, string val2);
};

