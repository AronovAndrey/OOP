#include <iostream>
#include <string>
#include <stack>
#include <conio.h>
using namespace std;

class Calc
{
	stack <double> number;
	stack <string> symbol;
	string input;
	char Int;
	double a, b;
public:
	void Calcul()
	{
		cout << "Вводите числа и знаки по очереди через пробел после каждого операнда и оператора, в конце уравнения  поставьте равно и нажмите Enter.\n";
		while (input != "=")
		{
			cin >> input;
			if (input == ")")
			{
				while (symbol.top() != "(")
				{
					if (symbol.top() == "+")
					{
						b = number.top();
						number.pop();
						a = number.top();
						number.pop();
						b += a;
						number.push(b);
						symbol.pop();
					}
					else if (symbol.top() == "-")
					{
						a = number.top();
						number.pop();
						b = number.top();
						number.pop();
						if (a < 0)
							b += a;
						else
							b -= a;
						number.push(b);
						symbol.pop();
					}
					else if (symbol.top() == "*")
					{
						b = number.top();
						number.pop();
						a = number.top();
						number.pop();
						b *= a;
						number.push(b);
						symbol.pop();
					}
					else if (symbol.top() == "/")
					{
						a = number.top();
						number.pop();
						b = number.top();
						number.pop();
						b /= a;
						number.push(b);
						symbol.pop();
					}
				}
			}
			if (input == "*" || input == "/" || input == "-" || input == "+" || input == "(" || input == ")" || input == "=")
			{
				if (!symbol.empty() && (symbol.top() == "*" || symbol.top() == "/") && input != "(" && input != ")")
				{
					a = number.top();
					number.pop();
					b = number.top();
					number.pop();
					if (symbol.top() == "*")
					{
						b *= a;
						number.push(b);
						symbol.pop();
					}
					else if (symbol.top() == "/")
					{
						b /= a;
						number.push(b);
						symbol.pop();
					}
				}
				else if (!symbol.empty() && (symbol.top() == "+" || symbol.top() == "-") && input != "(" && input != ")" && input != "/" && input != "*")
				{
					a = number.top();
					number.pop();
					b = number.top();
					number.pop();
					if (symbol.top() == "+")
					{
						b += a;
						number.push(b);
						symbol.pop();
					}
					else if (symbol.top() == "-")
					{
						b -= a;
						number.push(b);
						symbol.pop();
					}
				}
				if (input != ")")
					symbol.push(input);
				if (symbol.top() == "(" && input == ")")
					symbol.pop();
			}
			else
			{
				number.push(atoi(input.c_str()));
			}
		}
		if (symbol.top() == "=")
			symbol.pop();
		stack <double> number2;
		stack <string> symbol2;
		while (!number.empty())
		{
			number2.push(number.top());
			number.pop();
		}
		while (!symbol.empty())
		{

			if (symbol.top() == "(" || symbol.top() == ")")
				symbol.pop();
			else
			{
				symbol2.push(symbol.top());
				symbol.pop();
			}
		}
		while (!symbol2.empty())
		{
			if (symbol2.top() == "+")
			{
				b = number2.top();
				number2.pop();
				a = number2.top();
				number2.pop();
				b += a;
				number2.push(b);
				symbol2.pop();
			}
			else if (symbol2.top() == "-")
			{
				b = number2.top();
				number2.pop();
				a = number2.top();
				number2.pop();
				a -= b;
				number2.push(a);
				symbol2.pop();
			}
			else if (symbol2.top() == "*")
			{
				b = number2.top();
				number2.pop();
				a = number2.top();
				number2.pop();
				b *= a;
				number2.push(b);
				symbol2.pop();
			}
			else if (symbol2.top() == "/")
			{
				b = number2.top();
				number2.pop();
				a = number2.top();
				number2.pop();
				a /= b;
				number2.push(b);
				symbol2.pop();
			}

		}
		cout << number2.top();

	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	Calc calc;
	calc.Calcul();
}

