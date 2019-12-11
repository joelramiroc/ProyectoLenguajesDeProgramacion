#include "ExpressionValidation.h"
#include <regex>

void ExpressionValidation::InitializeSigns()
{
	this->signs.push_back('+');
	this->signs.push_back('-');
	this->signs.push_back('*');
	this->signs.push_back('/');
	this->signs.push_back('^');
	this->signs.push_back('%');
}

ExpressionValidation::ExpressionValidation()
{
	this->InitializeSigns();
}

bool ExpressionValidation::Validation(string expression)
{
	if (this->signs.empty())
	{
		this->InitializeSigns();
	}

	if (this->CorrectOperators(expression) && this->CorrectParentesis(expression) && this->HaveCorrectCharacters(expression))
	{
		return true;
	}

	return false;
}

bool ExpressionValidation::CorrectOperators(string expression)
{
	char lastRead = NULL;

	for (int i = 0; i < expression.length(); i++)
	{
		char element = expression.at(i);
		if (lastRead != NULL)
		{
			if (element == ')' || element == ']')
			{
				for (auto it = signs.begin(); it != signs.end(); it++)
				{

					if (*it == lastRead || lastRead == '[' || lastRead == '(')
					{
						return false;
					}
				}
			}

			if ((element == '(' || element == '[') && (lastRead == ')' || lastRead == ']'))
			{
				return false;
			}

			if (this->IsSign(lastRead) && this->IsSign(element))
			{
				return false;
			}
		}
		else
		{
			if (element == '*' || element == '/' || element == '^' || element == '%')
			{
				return false;
			}
		}
		lastRead = element;
	}

	for (auto it = signs.begin(); it != signs.end(); it++)
	{

		if (*it == lastRead)
		{
			return false;
		}
	}

	return true;
}

bool ExpressionValidation::CorrectParentesis(string expression)
{
	int openParentesis = 0;
	int closedParentesis = 0;
	int openCorchetes = 0;
	int closedCorchetes = 0;
	char lastRead = '-';


	for (int i = 0; i < expression.length(); i++)
	{
		if (expression.at(i) == '(')
		{
			lastRead = '(';
			openParentesis++;
		}

		if (expression.at(i) == '[')
		{
			lastRead = '[';
			openCorchetes++;
		}

		if (expression.at(i) == ']')
		{
			closedCorchetes++;

			if (closedCorchetes > openCorchetes)
			{
				return false;
			}

			if (openParentesis > closedParentesis&& lastRead == '(')
			{
				return false;
			}

			lastRead = ']';
		}

		if (expression.at(i) == ')')
		{
			closedParentesis++;

			if (closedParentesis > openParentesis)
			{
				return false;
			}

			if (openCorchetes > closedCorchetes&& lastRead == '[')
			{
				return false;
			}
			lastRead = ')';
		}
	}

	if (openParentesis != closedParentesis)
	{
		return false;
	}

	if (openCorchetes != closedCorchetes)
	{
		return false;
	}

	return true;
}

bool ExpressionValidation::IsSign(char sign)
{
	bool contains = find(signs.begin(), signs.end(), sign) != signs.end();
	return contains;
}

bool ExpressionValidation::HaveCorrectCharacters(string cadena)
{
	/*
	C++11 definió la sintaxis para sufijos literales definidos por el usuario, pero la biblioteca estándar no utilizó ninguno de ellos. C++14 agrega los siguientes literales estándar.
	"s", para la creación de los diversos tipos std::basic_string.
	"h", "min", "s", "ms", "us", "ns", para la creación de los correspondientes intervalos de tiempo std::chrono::duration.
	*/
	//c++ 14 auto asigna el valor de la variable, en este caso la s al final significa casteo o conversion a string. si fuese s seria conversion a segundos
	auto regexValue = "[0-9|'.'|'*'|'/'|'+'|'-'|'('|')'|'['|'\\]'|'^'|'%']{1,}"s;
	return regex_match(cadena, regex(regexValue));
}
