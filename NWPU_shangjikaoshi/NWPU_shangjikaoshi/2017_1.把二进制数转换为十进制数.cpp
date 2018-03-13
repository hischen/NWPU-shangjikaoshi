/*********************************************************************************
1.描述：

把二进制数转换成十进制数。

输入：
输入是一个8位的二进制数。
输出：
把输入的数转换为十进制数输出。
输入样例：
10000001
输出样例：
129
/*********************************************************************************/

#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int n;
	int a[8];  //只有0-7
	int i;
	int sjz = 0;
	cin >> n;
	for (i = 0; i<8; i++)
	{
		a[i] = n % 10;
		//   cout<<a[i]<<endl;
		n = n / 10;

	}
	for (i = 0; i<8; i++)
	{
		sjz = sjz + a[i] * pow(2, i);
	}
	cout << sjz << endl;;
	system("pause");
	return 0;
}
//int main()
//{
//    int n=0b10000001;
//    cout << n<< endl;
//    return 0;
//}