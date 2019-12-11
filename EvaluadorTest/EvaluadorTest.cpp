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
	bool cont = true;
	string xpression;
	int o;
	while (cont)
	{
		cout << "Ingrese expresion" << endl;
		cin >> xpression;
		//xpression = ReplaceAll(xpression, std::string(" "), std::string(""));
		/*xpressionstd::replace(xpression.begin(), xpression.end(), ' ', '');*/
		auto r = expressionValidation->Validation(xpression);
		if (r)
		{
			cout << postFijaOperacion->Operate(conversionAPostFija->Convert(xpression)) << endl;
		}
		else
		{
			cout << "Expresion incorrecta" << endl;
		}

		cout << "Desea continuar : 1. Si" << endl;
		cin >> o;
		switch (o)
		{
		case 1:
		{
		}
		break;
		default:
		{
			cont = false;
		}
			break;
		}
	}
	//cout<<postFijaOperacion->Operate(conversionAPostFija->Convert("10+(1+2)*2+2/2"))<<endl;
	//cout << conversionAPostFija->HaveBadValues("10+2*5/[4]");
}