#include<iostream>
#include<fstream>
#include<string>
#include<stack>

using namespace std;

bool delimitersOk(const string& expression)
{
	stack<char> delimitersStack;


	for (int i=0; i<expression.length() ; i++)
	{
		char ch = expression[i];

		if (ch == '(' || ch == '[')
		{

			delimitersStack.push(ch);
		}
		else if (ch == ')' || ch == ']')
		{
			if (delimitersStack.empty())
			{
				return false; 
			}          

			char top = delimitersStack.top();

			delimitersStack.pop();

			if ((ch == ')' && top != '(') || (ch == ']' && top != '['))
			{
				return false; 
			}
		}
	}
	return delimitersStack.empty();
}

int main()
{
	fstream inputFile("input.txt");

	if (!inputFile)
	{
		cout << "No file exist" << endl;
		return 1;
	}

	int totalExpressions;

	inputFile >> totalExpressions;

	inputFile.ignore(); //ignore the new line

	string expression;

	if (delimitersOk(expression))
	{
		cout << "Valid" << endl;
	}
	else
	{
		cout << "Invalid" << endl;
	}

	inputFile.close();
	return 0;
	
}