#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int n; int j;
	int sum = 0; int a=0, b = 0;
	/*int x[100], y[100];*/
	vector<int> x;
	vector<int>y;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp1; int temp2;
		cin >>temp1 >>temp2;
		x.push_back(temp1);
		y.push_back(temp2);
	}
	/*cout << x.size()<<' '<<y.size()<<endl;*/
	for (j = 0; j < n; j++)
	{
		sum = sum + abs(x[j] - a);
		sum = sum + abs(y[j] - b);
		a = x[j];
		b = y[j];
	}
	sum = sum + abs(a - 0);
	sum = sum + abs(b - 0);
	cout << sum;
	/*getchar;
	getchar;*/
	system("pause");
	return 0;
}



























//#include<cstdio>
//#include<iostream>
//#include<cmath>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	int sum=0;
//	vector<int>::iterator pt;
//	vector<int>::iterator pd;
//	cin >> n;
//	vector<int> x;
//	vector<int> y;
//	x.push_back(0);
//	y.push_back(0);
//	for (int i = 1; i <= 4; i++)
//	{
//		int temp1, temp2;
//		cin >> temp1 >> temp2;
//		x.push_back(temp1);
//		y.push_back(temp2);
//	}
//	x.push_back(0);
//	y.push_back(0);
//	cout << x.size()<<endl;
//	for (pt = x.begin(); pt != x.end(); pt++)
//	{
//		cout << *pt << ' ';
//	}
//	cout << endl;
//	for (pt=x.end(),pd=y.end();pt!=x.begin(),pd!=x.begin();pt--,pd--)
//	{
//		sum = sum + (abs(*pt) - abs(*(pt-1)));
//		sum = sum + (abs(*pd) - abs(*(pd-1)));
//	}
//	printf("%d\n", sum);
//	getchar();
//	return 0;
//}



































/*#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, x[100], y[100], sum = 0, a = 0, b = 0, j;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}

	for (j = 0; j < n; j++)
	{
		sum += abs(x[j] - a);
		sum += abs(y[j] - b);
		a = x[j];
		b = y[j];
	}
	sum += abs(a - 0);
	sum += abs(b - 0);
	printf("%d\n", sum);
	return 0;
}
*/