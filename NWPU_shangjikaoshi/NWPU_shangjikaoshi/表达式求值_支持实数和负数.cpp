//所谓表达式求值，就是写一个微型计算器。例如输入：（1 + 9） * 2 / 2 - 1，输出计算结果 9。对于这样的问题，我们一般利用栈，模拟数学运算来完成。
//为了简化问题，在继续下面的分析之前，先在此作个约定：本文只讨论 + -*/ ()基本的四则运算，另外不对意外出现的符号（例如 ^）和不符合规范的数学表达式
//（例如 2 * -1）做异常处理。

//二：思路及分析
//我们用一个字符数组（即char s[1000]）来存储数学表达式，定义一个全局变量 g_pos 表示 s[] 的下标，下标从 0 开始。首先我们定义两个栈，optr 和 opnd，
//分别存储运算符和运算数，遇到运算数直接放进 opnd；遇到运算符，分四种情况：
//（1）：遇到负号；
//（2）：遇到右括号；
//（3）：遇到左括号；
//（4）：遇到 + -*/ ；
//
//前三种情况容易理解，这里就谈下第四种情况。我们都知道四则运算是遵循先乘除再加减的，因此对于每个运算符，我们都要和 optr 的栈顶符号等级比较，如果
//这个符号的等级比 optr 栈顶符号等级高，什么也不做，直接放进栈；如果小于等于，就需要把 opnd 的栈顶两个数字抽出来，进行计算。这里有个问题，在遇到
//第一个运算符时，此时 optr 为空，而我们又需要与 optr 栈顶运算符比较等级，这时候怎么办？为了解决这个问题，我们在初始化 optr 的时候，放进一个 #，设置其等级为最低。
//
//看到这里你可能还存有一个疑问，如何判定符号 - 是负号还是减号？例如 - 1 + 2 和 5 - 1 + 2。分析发现，出现负号只有两种情况：
//（1）：左边是左括号，例如（ - 1 + 5 * 3）；
//（2）：字符串的第一个字符，例如 - 5 * 6 - 1。
//
//为了方便代码书写，若出现负号，就在运算数栈加入一个数字 0（这也就是下面代码里出现 bool 值 is_minus 的原因），即转化一下表达式，例如 - 1 + 2 转化为 0 - 1 + 2。*/
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cmath>
using namespace std;

char s[1000];
int  g_pos;  // 字符数组的下标

			 /* 字符转数字 */
double Translation(int & pos)
{
	double integer = 0.0;    // 整数部分
	double remainder = 0.0;  // 余数部分

	while (s[pos] >= '0' && s[pos] <= '9')
	{
		integer *= 10;
		integer += (s[pos] - '0');
		pos++;
	}

	if (s[pos] == '.')
	{
		pos++;
		int c = 1;
		while (s[pos] >= '0' && s[pos] <= '9')
		{
			double t = s[pos] - '0';
			t *= pow(0.1, c);
			c++;
			remainder += t;
			pos++;
		}
	}

	return integer + remainder;
}

/* 返回运算符级别 */
int GetLevel(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '(':
		return 0;
	case '#':
		return -1;
	};
}

/* 对两个数进行运算 */
double Operate(double a1, char op, double a2)
{
	switch (op)
	{
	case '+':
		return a1 + a2;
	case '-':
		return a1 - a2;
	case '*':
		return a1 * a2;
	case '/':
		return a1 / a2;
	};
}

/* 利用两个栈进行模拟计算 */
double Compute()
{
	stack<char> optr;    // 操作符栈
	stack<double> opnd;  // 操作数栈

	optr.push('#');
	int len = strlen(s);
	bool is_minus = true;  // 判断'-'是减号还是负号

	for (g_pos = 0; g_pos < len;)
	{
		//1. 负号  
		if (s[g_pos] == '-' && is_minus)  // 是负号
		{
			opnd.push(0);
			optr.push('-');
			g_pos++;
		}
		//2. 是右括号 ) 
		else if (s[g_pos] == ')')
		{
			is_minus = false;
			g_pos++;

			while (optr.top() != '(')
			{
				double a2 = opnd.top();
				opnd.pop();
				double a1 = opnd.top();
				opnd.pop();
				char op = optr.top();
				optr.pop();

				double result = Operate(a1, op, a2);
				opnd.push(result);
			}

			optr.pop();  // 删除'('  
		}
		//3. 数字  
		else if (s[g_pos] >= '0' && s[g_pos] <= '9')
		{
			is_minus = false;
			opnd.push(Translation(g_pos));
		}
		//4. ( 左括号  
		else if (s[g_pos] == '(')
		{
			is_minus = true;
			optr.push(s[g_pos]);
			g_pos++;
		}
		//5. + - * / 四种  
		else
		{
			while (GetLevel(s[g_pos]) <= GetLevel(optr.top()))
			{
				double a2 = opnd.top();
				opnd.pop();
				double a1 = opnd.top();
				opnd.pop();
				char op = optr.top();
				optr.pop();

				double result = Operate(a1, op, a2);
				opnd.push(result);
			}

			optr.push(s[g_pos]);
			g_pos++;
		}
	}

	while (optr.top() != '#')
	{
		double a2 = opnd.top();
		opnd.pop();
		double a1 = opnd.top();
		opnd.pop();
		char op = optr.top();
		optr.pop();

		double result = Operate(a1, op, a2);
		opnd.push(result);
	}

	return opnd.top();
}

int main()
{
	while (cin >> s)
		cout << "结果为：" << Compute() << endl << endl;

	return 0;
}

//char s[1000];
//int  g_pos;  // 字符数组的下标
//
//			 /* 字符转数字 */
//double Translation(int & pos)
//{
//	double integer = 0.0;    // 整数部分
//	double remainder = 0.0;  // 余数部分
//
//	while (s[pos] >= '0' && s[pos] <= '9')
//	{
//		integer *= 10;
//		integer += (s[pos] - '0');
//		//integer = atof(&s[pos]);
//		pos++;
//	}
//
//	if (s[pos] == '.')
//	{
//		pos++;
//		int c = 1;
//		while (s[pos] >= '0' && s[pos] <= '9')
//		{
//			double t = s[pos] - '0';
//			t =t* pow(0.1, c);
//			c++;
//			remainder += t;
//			pos++;
//		}
//	}
//
//	return integer + remainder;
//}
//
///* 返回运算符级别 */
//int GetLevel(char ch)
//{
//	switch (ch)
//	{
//	case '+':
//	case '-':
//		return 1;
//	case '*':
//	case '/':
//		return 2;
//	case '(':
//		return 0;
//	case '#':
//		return -1;
//	};
//}
//
///* 对两个数进行运算 */
//double Operate(double a1, char op, double a2)
//{
//	switch (op)
//	{
//	case '+':
//		return a1 + a2;
//	case '-':
//		return a1 - a2;
//	case '*':
//		return a1 * a2;
//	case '/':
//		return a1 / a2;
//	};
//}
//
///* 利用两个栈进行模拟计算 */
//double Compute(char *s)
//{
//	stack<char> optr;    // 操作符栈
//	stack<double> opnd;  // 操作数栈
//
//	optr.push('#');
//	int len = strlen(s);
//	bool is_minus = true;  // 判断'-'是减号还是负号
//
//	for (g_pos = 0; g_pos < len;)
//	{
//		//1. 负号  
//		if (s[g_pos] == '-' && is_minus)  // 是负号
//		{
//			opnd.push(0);
//			optr.push('-');
//			g_pos++;
//		}
//		//2. 是右括号 ) 
//		else if (s[g_pos] == ')')
//		{
//			is_minus = false;
//			g_pos++;
//
//			while (optr.top() != '(')
//			{
//				double a2 = opnd.top();
//				opnd.pop();
//				double a1 = opnd.top();
//				opnd.pop();
//				char op = optr.top();
//				optr.pop();
//
//				double result = Operate(a1, op, a2);
//				opnd.push(result);
//			}
//
//			optr.pop();  // 删除'('  
//		}
//		//3. 数字  
//		else if (s[g_pos] >= '0' && s[g_pos] <= '9')
//		{
//			is_minus = false;
//			opnd.push(Translation(g_pos));
//		}
//		//4. ( 左括号  
//		else if (s[g_pos] == '(')
//		{
//			is_minus = true;
//			optr.push(s[g_pos]);
//			g_pos++;
//		}
//		//5. + - * / 四种  
//		else
//		{
//			while (GetLevel(s[g_pos]) <= GetLevel(optr.top()))
//			{
//				double a2 = opnd.top();
//				opnd.pop();
//				double a1 = opnd.top();
//				opnd.pop();
//				char op = optr.top();
//				optr.pop();
//
//				double result = Operate(a1, op, a2);
//				opnd.push(result);
//			}
//
//			optr.push(s[g_pos]);
//			g_pos++;
//		}
//	}
//
//	while (optr.top() != '#')
//	{
//		double a2 = opnd.top();
//		opnd.pop();
//		double a1 = opnd.top();
//		opnd.pop();
//		char op = optr.top();
//		optr.pop();
//
//		double result = Operate(a1, op, a2);
//		opnd.push(result);
//	}
//
//	return opnd.top();
//}
//
//int main()
//{
//	//while (cin >> s)
//	int n;
//	cin >> n;
//	while (n--)
//	{		
//		cin >> s;	
//		cout << "结果为：" << Compute(s) << endl;
//	}
//	system("pause");
//	return 0;
//}
//char str[50];
//const char * p = "+-*/";
//int i;
//using namespace std;
//int cmp(char c)
//{
//	if (c == '+' || c == '-') return 1;
//	if (c == '*' || c == '/') return 2;
//	if (c == '(') return 0;
//	if (c == '#') return -1;
//
//}
//double run(double x, double y, char c)
//{
//	switch (c)
//	{
//	case '+':return x + y;
//	case '-':return x - y;
//	case '*':return x * y;
//	case '/':return x / y;
//	};
//
//}
//double trs(int i)
//{
//	double integer = 0.0;
//	double remainder = 0.0;
//	while (str[i] >= '0'&&str[i] <= '9')
//	{
//		integer = integer * 10;
//		integer += (str[i] - '0');
//		i++;
//	}
//	if (str[i] == '.')
//	{
//		i++;
//		int s = 1;
//		while (str[i] >= '0'&&str[i] <= '9')
//		{
//			double t = str[i] - '0';
//			t = t * pow(0.1, s);
//			s++;
//			remainder += t;
//			i++;
//		}
//	}
//	return integer + remainder;
//}
//double calc()
//{
//	stack<char> sgn;
//	stack<double> num;
//	sgn.push('#');
//	bool is_f = true;
//	int t = strlen(str);
//	for (i = 0; i<t;)
//	{
//		if (str[i] == '-'&&is_f)
//		{
//			num.push(0);
//			sgn.push('-');
//			i++;
//		}
//		else if (str[i] == '(')
//		{
//			is_f = true;
//			sgn.push(str[i]);
//			i++;
//		}
//		else if (str[i] >= '0'&&str[i] <= '9')
//		{
//			is_f = false;
//			num.push(trs(i));
//			cout << trs(i);
//		}
//		else if (str[i] == ')')
//		{
//			is_f = false;
//			i++;
//			while (sgn.top() != '(')
//			{
//				double a2 = num.top();
//				num.pop();
//				double a1 = num.top();
//				num.pop();
//				char op = sgn.top();
//				sgn.pop();
//				num.push(run(a1, a2, op));
//			}
//			sgn.pop();
//		}
//		else //if(str[i]==*p)
//		{
//			is_f = false;
//			while (cmp(str[i]) <= cmp(sgn.top()))
//				//		sgn.push(str[i]);
//				//	else {
//			{
//				double a2 = num.top();
//				num.pop();
//				double a1 = num.top();
//				num.pop();
//				char op = sgn.top();
//				sgn.pop();
//				num.push(run(a1, a2, op));
//				sgn.push(str[i]);
//			}
//			sgn.push(str[i]);
//			i++;
//
//		}
//
//		while (sgn.top() != '#')
//		{
//			double a2 = num.top();
//			num.pop();
//			double a1 = num.top();
//			num.pop();
//			char op = sgn.top();
//			sgn.pop();
//			num.push(run(a1, a2, op));
//		}
//
//	}
//	return num.top();
//}
//int main()
//{
//	//scanf("%s",str);
//	cin >> str;
//	cout << calc();
//	system("pause");
//	return 0;
//}