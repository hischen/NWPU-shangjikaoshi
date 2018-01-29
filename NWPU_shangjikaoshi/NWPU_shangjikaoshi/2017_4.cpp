#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<cstdio>
#include<vector>
using namespace std; 

bool paren(const std::string &str)
{
	std::stack<char> s;
	for (auto i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case '(':s.push(str[i]); break;
		case '[':s.push(str[i]); break;
		case '{':s.push(str[i]); break;
		case ')':
			if (s.top() != '(')
				return false;
			else
				s.pop(); break;
		case ']':
			if (s.top() != '[')
				return false;
			else
				s.pop(); break;
		case '}':
			if (s.top() != '{')
				return false;
			else
				s.pop(); break;

		default:
			break;
		}
	}
	return s.empty();
}

int main()
{
	int n;
	cin >> n;
	int m = n;
	vector<string>result(n+1);
	while (n>0)
	{
		std::string strBuf;
		cin >> strBuf;
		//std::cout << "The string is : " << strBuf << " ";
		if (paren(strBuf))
		{
			//std::cout << "yes";
			result[n] = "yes";
		}
		else
		{	//std::cout << "no";
			result[n] = "no";
		}
		n--;
	}
	for (int i = m; i >0; i--)
	{
		cout << result[i] << endl;
	}
	//std::cout << std::endl;
	return 0;
}


/*括号匹配是栈最典型的应用了。
思路很简单，就是遇到一个左括号就压栈，遇到一个右括号就弹栈，看是否匹配就好了。最后检查下栈是否为空就行了。*/