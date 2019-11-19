#include "PostFijaOperacion.h"

PostFijaOperacion::PostFijaOperacion()
{
	this->Inicializator();
}

void PostFijaOperacion::Inicializator()
{
	this->signs.push_back("+");
	this->signs.push_back("-");
	this->signs.push_back("*");
	this->signs.push_back("/");
	this->signs.push_back("^");
	this->signs.push_back("%");
}

double PostFijaOperacion::Operate(vector<string>* postFijaOperation)
{
	double result = 0;
	stack <double>* pila = new stack<double>();

	for (auto i = postFijaOperation->begin(); i != postFijaOperation->end(); ++i)
	{
		if (!this->IsSign(*i))
		{
			pila->push(atof((*i).c_str()));
		}
		else
		{
			double firstNum = pila->top();
			pila->pop();
			double secondNum = pila->top();
			pila->pop();
			pila->push(this->BasicOperation(firstNum, secondNum,*i));
		}
	}

	result = pila->top();
	pila->pop();

	return result;
}

bool PostFijaOperacion::IsSign(string sign)
{
	bool contains = find(signs.begin(), signs.end(), sign) != signs.end();
	return contains;
}

double PostFijaOperacion::BasicOperation(double n1, double n2, string operatorV)
{
	if (operatorV == "+")
	{
		return n1 + n2;
	}
	else if (operatorV == "-")
	{
		return n1 - n2;
	}
	else if (operatorV == "*")
	{
		return n1 * n2;
	}
	else if (operatorV == "/")
	{
		return n1 / n2;
	}
	else if (operatorV == "%")
	{
		return n1 * n2 / 100;
	}
	else if (operatorV == "^")
	{
		return pow(n1, n2);
	}
	return 0.0;
}
