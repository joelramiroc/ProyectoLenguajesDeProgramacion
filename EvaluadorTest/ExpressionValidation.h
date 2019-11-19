#include <iostream>
#include <vector> 

using namespace std; 
#pragma once
class ExpressionValidation
{
private:
	vector<char> signs;
	void InitializeSigns();
	bool CorrectOperators(string expression);
	bool CorrectParentesis(string expression);
	bool IsSign(char sign);
public:
	ExpressionValidation();
	bool Validation(string expression);
};

