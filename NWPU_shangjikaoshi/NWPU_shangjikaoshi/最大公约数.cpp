#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int gcd1(int a, int b)  //欧几里德算法 递归
{
	if (a == 0 & b == 0) return -1;
	//else if (a == 0) return b ;
	else if (b == 0) return a;
	else  return gcd1(b, a%b);
}
int gcd2(int a, int b)   //非递归
{
	while (b != 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd1(a, b)<<endl;
	cout << gcd2(a, b) << endl;
	system("pause");
	return 0;
}