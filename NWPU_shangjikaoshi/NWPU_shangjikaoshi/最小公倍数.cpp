#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	return (b != 0) ? gcd(b, a%b): a;
}
int lcm(int a,int b)
{
	int x=a,y=b;
	while (b != 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	return x*y/a;
}
int main()
{
	int a, b;
	cin >> a>>b;
	cout << a*b/gcd(a, b)<<endl;
	cout << lcm(a, b)<<endl;
	system("pause");
	return 0;
}