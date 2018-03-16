#include<vector>
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

	/* @param s: The Reverse Polish Notation
	* @return: the value
	*/
	int add(char s[]) {
		// write your code here
		int size = strlen(s);
		if (size <= 0) {
			return 0;
		}
		stack<int> stack;
		for (int i = 0; i < size; i++) {
			if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/') {
				stack.push((s[i])-'0');//stack.push(atoi(&s[i]));//.c_str()));
				//cout << stack.top()<<endl;
			}
			else {
				int num1 = stack.top();
				stack.pop();
				int num2 = stack.top();
				stack.pop();
				int num3 = 0;
				if (s[i] == '+') {
					num3 = num2 + num1;
				}
				else if (s[i] == '-') {
					num3 = num2 - num1;
				}
				else if (s[i] == '*') {
					num3 = num2 * num1;
				}
				else if (s[i] == '/') {
					num3 = num2 / num1;
				}
				stack.push(num3);
			}
		}
		return stack.top();
	}
	int main()
	{
		char s[100];
		cin >> s;
		cout << add(s)<<endl;
		system("pause");
	}