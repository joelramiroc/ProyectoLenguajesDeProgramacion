#include "ConversionAPostFija.h"

ConversionAPostFija::ConversionAPostFija()
{
	this->Initializer();
}

void ConversionAPostFija::Initializer()
{
	this->operators = new stack <char>();
	this->numbers = new vector<string>();
	this->signs.push_back('+');
	this->signs.push_back('-');
	this->signs.push_back('*');
	this->signs.push_back('/');
	this->signs.push_back('^');
	this->signs.push_back('%');
}

vector<string>* ConversionAPostFija::Convert(string cadena)
{
	string numeroToConvert = "";
	double number = 0;
	char sign = NULL;
	bool isSign = false;

	for (int i = 0; i < cadena.length(); i++)
	{
		char read = cadena.at(i);
		for (auto it = signs.begin(); it != signs.end(); it++)
		{

			if (*it == read)
			{
				sign = *it;
				isSign = true;
				break;
			}
		}
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