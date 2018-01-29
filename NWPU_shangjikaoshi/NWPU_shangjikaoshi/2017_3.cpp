#include <iostream>
#include <stack>
#include<vector>
#include<string>


using namespace std;
/*使用vector类实现string的输入和输出*/
/*
int main()
{
	vector<string>str;
	string s;
	int a{0};
	while (cin >> s)
	{
		str.push_back(s);
		cout << str[a] << endl;
		++a;
	}
	
	return 0;
}
*/

/*对C++ 模板库STL库stack栈的常用操作的练习*/
/*
int main()
{
	stack<string> a;
	cout << "入栈过程："<<endl;
	for (int i = 0; i < 5; i++)
	{ 
		string s;
		cin >> s;
		a.push(s);
		cout <<"依次入栈的元素为："<< a.top()<<endl;
		cout << "栈内元素个数为：" << a.size() << endl;
	}
	cout << "出栈过程:"<<endl;
	while (!a.empty())
	{
		cout << "依次出栈的栈顶元素为：" << a.top() << endl;;
		a.pop();
		cout << "栈内元素个数为：" << a.size() << endl;
	}
	
	return  0;
}
*/

#include<iostream>  
#include<stack>  
#include<string>  
using namespace std;

/*判断符号间的优先关系函数
*1表示>,0表示=,-1表示<
*c1栈内的算符，c2栈外的算符
*/
int Judge(char c1, char c2)
{
	int a1, a2;
	if ('+' == c1 || '-' == c1) a1 = 3;
	if ('*' == c1 || '/' == c1)a1 = 5;
	if ('(' == c1) a1 = 1;
	if (')' == c1) a1 = 7;
	if ('#' == c1) a1 = 0;

	if ('+' == c2 || '-' == c2)a2 = 2;
	if ('*' == c2 || '/' == c2)a2 = 4;
	if ('(' == c2) a2 = 6;
	if (')' == c2) a2 = 1;
	if ('#' == c2) a2 = 0;
	if (a1>a2) return 1;
	if (a1 == a2) return 0;
	if (a1<a2) return -1;
}
//符号运算函数  
double run(char c, double d1, double d2)
{
	switch (c)
	{
	case '+':
		return d1 + d2;
		break;
	case '-':
		return d1 - d2;
		break;
	case'*':
		return d1 * d2;
		break;
	case '/':
		return d1 / d2;
		break;
	default:
		return 0.0;
		break;
	}
}

double calculate(string str)
{
	const char * op = "+-*/()#";
	//string str;
	//cin >> str;
	//给表达式字符串str添加'#'结束标识符  
	str.append(1, '#');
	stack<char> OPTR;//运算符栈  
	stack<double> OPND;//操作数栈  
	int a = -1;
	//先将#符号入栈  
	OPTR.push('#');
	while (true)
	{
		int b = a + 1;
		a = str.find_first_of(op, a + 1);
		if (a == string::npos) break;
		if (a != b)
		{
			string ss(str, b, a - b);
			double d = atof(ss.c_str());
			//数据先入栈  
			OPND.push(d);
		}
		//运算符优先级比较  
		int ju = Judge(OPTR.top(), str[a]);
		if (-1 == ju)//栈外优先级大直接入栈  
		{
			OPTR.push(str[a]);
		}
		if (0 == ju)//栈内外优先级相等则出栈  
		{
			OPTR.pop();
		}
		if (1 == ju)//栈内优先级大,出栈进行运算  
		{
			double d1 = OPND.top();
			OPND.pop();
			double d2 = OPND.top();
			OPND.pop();
			d1 = run(OPTR.top(), d2, d1);
			//运算结果入栈  
			OPND.push(d1);
			OPTR.pop();
			a--;
		}
	}
	//删除表达式最后的'#'结束标识符  
	str.erase(str.length() - 1, 1);
	return OPND.top();
}
int main()
{
	int n;	
	cin >> n;
	const int m = n;
	vector <double> display(n+1);
	//vector <string> biaodashi(n+1);
	while (n > 0)
	{
		string str;
		cin >> str;
		//biaodashi[n] = str;
		double result = calculate(str);
		display[n] = result;
		n--;
	};
	for(int j=m;j>0;j--)
	cout /*<< biaodashi[j] << " = "*/ << display[j] << endl;
	return 0;
}





















/*经典算法-算术表达式求值
思想主要是用到了栈先进后出的数据结构。在该程序中建有两个栈：一个用于存储运算符，另一个用于存储操作数或运算结果。基本
过程是：

（1）：首先设置操作数栈为空栈，设置运算符栈以‘#’为栈底元素（其优先级最低）。

（2）：通过为栈内栈外运算符设置值而比较其优先级

（3）：依次去找到表达式中的所有运算符和操作数，对于操作数直接入栈，运算符则和运算符栈的

栈顶运算进行比较优先级，若栈内优先级大，则进行相应操作并操作数和栈内运算符都出栈，若优先级相等只需

栈内运算符出栈继续查找下一个运算符即可，若栈内优先级低则栈外运算符入栈。依次循环知道分析完表达式中

的所有运算符和操作数即可。

（4）：最后在操作数栈中将只会剩下唯一的一个元素，而该元素也将就会是所求表达式的值。

2 中缀表达式和后缀表达式

中缀表达式就是通常所说的算术表达式，比如(1+2)*3-4。

后缀表达式是指通过解析后，运算符在运算数之后的表达式，比如上式解析成后缀表达式就是12+3*4-。这种表达式可以直接利用栈来求解。

3 运算符的优先级

优先级 运算符
1 括号()
2 负号-
3 乘方**
4 乘*，除/，求余%
5 加+，减-
6 小于<，小于等于<=，大于>，大于等于>=
7 等于==，不等于!=
8 逻辑与&&
9 逻辑或||
大致的规律是，一元运算符 > 二元运算符 > 多元运算符。
*/

//将中缀表达式解析成后缀表达式
/*
中缀表达式翻译成后缀表达式的方法如下：
（1）从右向左依次取得数据ch。
（2）如果ch是操作数，直接输出。
（3）如果ch是运算符（含左右括号），则：
a：如果ch = '('，放入堆栈。
b：如果ch = ')'，依次输出堆栈中的运算符，直到遇到'('为止。
c：如果ch不是')'或者'('，那么就和堆栈顶点位置的运算符top做优先级比较。
1：如果ch优先级比top高，那么将ch放入堆栈。
2：如果ch优先级低于或者等于top，那么输出top，然后将ch放入堆栈。
（4）如果表达式已经读取完成，而堆栈中还有运算符时，依次由顶端输出。
如果我们有表达式(A-B)*C+D-E/F，要翻译成后缀表达式，并且把后缀表达式存储在一个名叫output的字符串中，可以用下面的步骤。

（1）读取'('，压入堆栈，output为空
（2）读取A，是运算数，直接输出到output字符串，output = A
（3）读取'-'，此时栈里面只有一个'('，因此将'-'压入栈，output = A
（4）读取B，是运算数，直接输出到output字符串，output = AB
（5）读取')'，这时候依次输出栈里面的运算符'-'，然后就是'('，直接弹出，output = AB-
（6）读取'*'，是运算符，由于此时栈为空，因此直接压入栈，output = AB-
（7）读取C，是运算数，直接输出到output字符串，output = AB-C
（8）读取'+'，是运算符，它的优先级比'*'低，那么弹出'*'，压入'+"，output = AB-C*
（9）读取D，是运算数，直接输出到output字符串，output = AB-C*D
（10）读取'-'，是运算符，和'+'的优先级一样，因此弹出'+'，然后压入'-'，output = AB-C*D+
（11）读取E，是运算数，直接输出到output字符串，output = AB-C*D+E
（12）读取'/'，是运算符，比'-'的优先级高，因此压入栈，output = AB-C*D+E
（13）读取F，是运算数，直接输出到output字符串，output = AB-C*D+EF
（14）原始字符串已经读取完毕，将栈里面剩余的运算符依次弹出，output = AB-C*D+EF/-
*/