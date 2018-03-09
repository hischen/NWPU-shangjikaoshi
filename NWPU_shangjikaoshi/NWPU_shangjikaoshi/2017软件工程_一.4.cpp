#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
//long long jiecheng(int x)
//{
//	if (x == 0 || x == 1)
//		return 1;
//	else return x * jiecheng(x-1);
//}
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		cout << jiecheng(n)<<endl;
//	}
//	system("pause");
//	return 0;
//}

/*******************·ÇµÝ¹é×ö·¨******************************************/
long long jiecheng(int x)
{
	long long jc=1;
	if (x == 0) return 1;
	for (int i = 1; i <= x; i++)
	{
		jc = jc*i;
		
	}
	return jc;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << jiecheng(n)<<endl;
	}

	return 0;
}

/**********************************************************************/