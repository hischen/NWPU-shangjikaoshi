//#include "stdafx.h"
#include <string>
#include <iostream>
#include <ctype.h>
#include <cstdio>
using namespace std;
int main(int argc, char* argv[])
{
	//数组中存放各个字母出现的次数
	unsigned short statistic[26] = { 0 };
	//出现的最大次数
	unsigned short max = 0;
	int i, j;
	/**输入各行数据并统计每个字母出现的次数
	*/

	for (i = 0; i < 4; i++)
	{
		string s;
		getline(cin, s);
		for (j = 0; j < s.size(); j++) {
			if (toupper(s[j]) && isalpha(s[j]))
				statistic[s[j] - 'A']++;
		}
	}
	//找出字母出现的最大次数
	for (i = 0; i < 26; i++) {
		if (statistic[i] >max)
			max = statistic[i];
	}
	//从统计图中最高的柱子出发：即从最上层 字母出现次数最多的那一层，自顶向下计算
	for (i = max; i > 0; i--)
	{
		for (j = 0; j < 25; j++)
		{
			//寻找当前行中字母出现次数不小于当前行的最大峰值时
			if (statistic[j] >= i)
				cout << "* ";  //输出 一个 *  和一个空格
			else
				cout << "  "; //否则输出两个连续的空格
		}
		if (j == 25)
		{
			if (statistic[j] >= i)
				cout << "*";  //输出 一个 *  和一个空格
			else
				cout << " "; //否则输出两个连续的空格
		}
		cout << endl;
	}
	//输出最下面一行的A-Z字母
	for (i = 0; i < 25; i++)
	{
		printf("%c ", 'A' + i);
	}
	if (i == 25)cout << 'Z';
	//cout << endl;
	system("pause");
	return 0;
}