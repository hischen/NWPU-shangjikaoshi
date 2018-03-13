#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
//int main()
//{
//	int a[20000];
//	//int b[10000];
//	//int c[10000];
//	int n;
//	int m;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", a + i);
//	}
//	cin >> m;
//	for (int j = n; j <n+m; j++)
//	{
//		scanf("%d", a + j);
//	}
//	sort(a, a + n + m,less<int>())
//		;
//	for (int k = 0; k <n + m; k++)
//	{
//		cout << a[k]<<endl;
//	}
//
//	system("pause");
//	
//	return 0;
//}

/********************************************************************************/
int main()
{
	vector<int>a;
	vector<int>b;
	vector<int>::iterator p;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	cin >> m;
	for (int j= 0; j< m; j++)
	{
		int temp;
		cin >> temp;
		b.push_back(temp);
	}	
	a.insert(a.end(), b.begin(), b.end());
	/*for (p = a.begin(); p != a.end(); p++)
	{
		cout << *p << ' ';
	}
	cout << endl;*/
	sort(a.begin(), a.end(), less<int>());
	/*for (p = a.begin(); p != a.end(); p++)
	{
		cout << *p << ' ';
	}
	cout << endl;*/
	for (p = a.begin(); p != a.end(); p++)
	{
		cout << *p<<' ';
	}
	cout << endl;
	system("pause");
	return 0;
}