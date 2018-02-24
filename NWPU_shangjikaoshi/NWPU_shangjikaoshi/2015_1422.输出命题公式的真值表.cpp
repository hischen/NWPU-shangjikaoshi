/*1422.输出命题公式的真值表
时限：1000ms 内存限制：10000K  总时限：3000ms
描述
先输入一个正整数n（n小于等于10），表示共有n个命题变元，再输入一个类似于逆波兰表达式的字符串表示一个命题公式，约定在该字符串中用一位的十进制数表示一个命题变元，用a、o、n、i、e分别表示且、或、非、蕴含、等值，用类似于逆波兰表达式形式的字符串表示的命题公式的真值表波兰表达式（即二元运算，两个操作数在前，运算符在后；一元运算，一个操作数在前，运算符在后）。
 
输入
先输入一个小于等于10的正整数n，再输入一个字符串。
 
输出
输出该字符串表示的命题公式的真值表。
提示：
如果用P、Q、R分别表示这三个命题变元的话，
输入数据01a2i表示的命题公式是：((P∧Q)→R)
输入数据012ia表示的命题公式是：(P∧(Q→R))
输入数据0n表示的命题公式是：┐P
 
输入样例
3
01a2i
 
输出样例
0 0 0 1
0 0 1 1
0 1 0 1
0 1 1 1
1 0 0 1
1 0 1 1
1 1 0 0
1 1 1 1
 */
/*参考代码：https://www.cnblogs.com/codeyuan/p/4374999.html */
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std; int m = 0; int v = 0; int p = 0;
stack<int> s;
int n, l;
char str[100];
int ans[20];
void slove()
{
	v++;
	int top = 1;
	while (!s.empty()) s.pop();
	char s1, s2;
	//cout << ans[0];
	for (int i = 0; i<l; i++)
	{
		if (str[i] == 'a')
		{
			s2 = s.top(); s.pop();
			s1 = s.top(); s.pop();
			if (s1 == '0' || s2 == '0') s.push('0');
			else s.push('1');
		}
		else if (str[i] == 'o')
		{
			s2 = s.top(); s.pop();
			s1 = s.top(); s.pop();
			if (s1 == '0'&&s2 == '0') s.push('0');
			else s.push('1');
		}
		else if (str[i] == 'i')
		{
			s2 = s.top(); s.pop();
			s1 = s.top(); s.pop();
			if (s1 == '1'&&s2 == '0') s.push('0');
			else s.push('1');
		}
		else if (str[i] == 'e')
		{
			s2 = s.top(); s.pop();
			s1 = s.top(); s.pop();
			if (s1 == s2) s.push('1');
			else s.push('0');
		}
		else if (str[i] == 'n')
		{
			s1 = s.top(); s.pop();
			if (s1 == '0') s.push('1');
			else s.push('0');
		}
		else {
			//cout << ans[top]<<' ';
			char c = ans[top++] + '0'; //cout<<ans[top]<<' '<<c<<' ';
			s.push(c);
		}
	}
}
void print()
{
	p++;
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("%c\n", s.top());
}
void dfs(int point)
{
	m++;
	if (point>n) 
	{
		slove(); 
		print(); 
		return; 
	}
	for (int i = 0; i<2; i++)
	{
		ans[point] = i; //cout << point;
		dfs(point + 1);
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	l = strlen(str);
	dfs(1);
	//cout << m << ' ' << v << ' ' << p;;
	system("pause");
	return 0;
}