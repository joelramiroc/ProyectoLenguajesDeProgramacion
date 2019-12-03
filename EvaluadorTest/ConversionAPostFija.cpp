#include "ConversionAPostFija.h"

bool ConversionAPostFija::IsSign(char val)
{
	for (auto it = signs.begin(); it != signs.end(); it++)
	{

		if (*it == val)
		{
			return true;
		}
	}

	return false;
}

bool ConversionAPostFija::isNumber(char val)
{

	return false;
}

ConversionAPostFija::ConversionAPostFija()
{
	this->Initializer();
}

void ConversionAPostFija::Initializer()
{
	this->operators = new stack <char>();
	this->numbers = new vector<string>();
	//c++ 11
	this->signs = { '+' ,'-','*', '/' ,'^' ,'%' };
	this->numbersP = { '1' ,'2' ,'3','4','5','6','7','8','9','0','.' };
}

vector<string>* ConversionAPostFija::Convert(string cadena)
{
	string numeroToConvert = "";

	//c++ 11
	double number = 0;
	char sign = NULL;

	//c++ 11
	bool isSign = bool();

	for (int i = 0; i < cadena.length(); i++)
	{
		isSign = false;
		char read = cadena.at(i);
		isSign = IsSign(read);
		if (!isSign)
		{
			if (read == '(')
			{
				this->operators->push(read);
			}
			else if (read == ')')
			{
				if (numeroToConvert != "")
				{
					this->numbers->push_back(numeroToConvert);
				}
				numeroToConvert = "";

				bool isOpen = false;
				while (!isOpen)
				{
					char chars = this->operators->top();
					this->operators->pop();

					if (chars == '(')
					{
						isOpen = true;
					}
					else
					{
						string val = string(1, chars);
						this->numbers->push_back(val);
					}
				}
			}
			else if (read == '[')
			{
				this->operators->push(read);
			}
			else if (read == ']')
			{
				if (numeroToConvert != "")
				{
					this->numbers->push_back(numeroToConvert);
				}
				numeroToConvert = "";

				bool isOpen = false;
				while (!isOpen)
				{
					char chars = this->operators->top();
					this->operators->pop();

					if (chars == '[')
					{
						isOpen = true;
					}
					else
					{
						string val = string(1, chars);
						this->numbers->push_back(val);
					}
				}
			}
			else
			{
				numeroToConvert = numeroToConvert + read;
			}
		}
		else
		{
			if (numeroToConvert != "")
			{
				this->numbers->push_back(numeroToConvert);
			}
			numeroToConvert = "";

			if (this->operators->empty())
			{
				this->operators->push(read);
			}
			else
			{
				char chars = this->operators->top();
				string first = string(1, chars);
				string second = string(1, read);
				int result = this->Precedencia(first, second);
				bool c = true;
				while (c)
				{
					if (result == 0 || result == -1)
					{
						this->numbers->push_back(first);
						this->operators->pop();

						if (!this->operators->empty())
						{
							chars = this->operators->top();
							first = string(1, chars);
							result = this->Precedencia(first, second);
						}
						else
						{
							this->operators->push(read);
							c = false;
						}
					}
					else
					{
						this->operators->push(read);
						c = false;
					}
				}
			}
		}

		isSign = false;
	}
	this->numbers->push_back(numeroToConvert);

	while (!this->operators->empty())
	{
		char chars = this->operators->top();
		this->operators->pop();
		string val = string(1, chars);
		this->numbers->push_back(val);
	}
	return this->numbers;
}

int ConversionAPostFija::Precedencia(string val, string val2)
{
	if (val == "+")
	{
		if (val2 == "+" || val2 == "-")
		{
			return 0;
		}
		return 1;
	}
	else if (val == "-")
	{
		if (val2 == "+" || val2 == "-")
		{
			return 0;
		}
		return 1;
	}
	else if (val == "*")
	{
		if (val2 == "+" || val2 == "-")
		{
			return -1;
		}
		if (val2 == "*" || val2 == "/")
		{
			return 0;
		}
		return 1;
	}
	else if (val == "/")
	{
		if (val2 == "+" || val2 == "-")
		{
			return -1;
		}
		if (val2 == "*" || val2 == "/")
		{
			return 0;
		}
		return 1;
	}
	else if (val == "%")
	{
		if (val2 == "+" || val2 == "-" || val2 == "*" || val2 == "/")
		{
			return -1;
		}
		if (val2 == "%")
		{
			return 0;
		}
		return 1;

	}
	else if (val == "^")
	{
		if (val2 == "+" || val2 == "-" || val2 == "*" || val2 == "/" || val2 == "%")
		{
			return -1;
		}
		if (val2 == "^")
		{
			return 0;
		}
		return 1;
	}

	return -3;
}