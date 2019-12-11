#pragma once
#include <stack> 
#include <iostream>
#include <queue> 
#include <string> 
using namespace std;

class PostFijaOperacion
{
private:
	vector<string> signs;
	bool IsSign(string sign);
	double BasicOperation(double n1, double n2, string operatorV);
public:
	PostFijaOperacion();
	void Inicializator();
	double Operate(vector<string>* postFijaOperation);
};

