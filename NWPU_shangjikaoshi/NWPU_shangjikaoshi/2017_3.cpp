/*经典算法-算术表达式求值
析用堆栈解析算术表达式的基本方法。给出的示例代码能解析任何包括+，-，*，/，()和0到9数字组成的算术表达式。

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
#include<iostream>
#include<string.h> 
#include<stdlib.h>
using namespace std;
template <class T>
class stack
{
public:
	stack() { top = -1; SIZE = 2; buffer = new T[SIZE]; }; //SIZE=2（过小）用于测试PUSH函数 
	~stack() { if (buffer) delete[]buffer; };//析构函数
	bool push(T element); //入栈
	T& pop();//出栈
	int size() { return top + 1; };//取元素个数
	bool isempty() { return top == -1; }
	void clear() { top = -1; }
private:
	T * buffer;
	int top;
	int SIZE;
};
template <class T>
bool stack<T>::push(T element)
{
	top++;
	if (top>SIZE - 1)
	{
		SIZE += 10;
		T* temp = new T[SIZE];
		//  for(int i=0;i<SIZE-10;i++)
		// temp[i]=buffer[i];//将对象 COPY 
		memcpy((void*)temp, (void*)buffer, (SIZE - 10) * sizeof(T));//两种方法都可 
		delete buffer;
		buffer = temp;
	}//满
	buffer[top] = element;
	return true;
}
template <class T>
T& stack<T>::pop()
{
	return buffer[top--];
}
bool IsOperand(char ch)
{
	char operators[] = { '+', '-', '*', '/', '(', ')' };
	for (int i = 0; i<6; i++)
		if (ch == operators[i])
			return false;
	return true;
}
int Priority(char ch)
{
	int priority;
	switch (ch)
	{
	case '+':
		priority = 1;
		break;
	case '-':
		priority = 1;
		break;
	case '*':
		priority = 2;
		break;
	case '/':
		priority = 2;
		break;
	default:
		priority = 0;
		break;
	}
	return priority;
}
double GetValue(char op, double ch1, double ch2)
{
	switch (op)
	{
	case '+':
		return ch2 + ch1;
	case '-':
		return ch2 - ch1;
	case '*':
		return ch2 * ch1;
	case '/':
		return ch2 / ch1;
	default:
		return 0;
	}
}
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
char* Parse(const char *expr)
{
	//  const char *exp = expr;
	int i, j = 0;
	char ch, ch1;
	const char* A = expr;
	char *B = new char[strlen(expr) + 1]; //最后生成的后缀表达式
	stack<char>  myStack;
	for (i = 0; ch = A[i]; i++)//A[I]='