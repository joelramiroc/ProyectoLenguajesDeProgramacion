// EvaluadorTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector> 
#include "ExpressionValidation.h"
#include "ConversionAPostFija.h"
#include "PostFijaOperacion.h"

using namespace std;
int main()
{
	ExpressionValidation* expressionValidation = new ExpressionValidation();
	ConversionAPostFija* conversionAPostFija = new ConversionAPostFija();
	PostFijaOperacion* postFijaOperacion = new PostFijaOperacion();
	auto r = expressionValidation->Validation("[(2+5)");
	cout << postFijaOperacion->Operate(conversionAPostFija->Convert("[(2+5)")) << endl;
	//cout<<postFijaOperacion->Operate(conversionAPostFija->Convert("10+(1+2)*2+2/2"))<<endl;
	//cout << conversionAPostFija->HaveBadValues("10+2*5/[4]");
}