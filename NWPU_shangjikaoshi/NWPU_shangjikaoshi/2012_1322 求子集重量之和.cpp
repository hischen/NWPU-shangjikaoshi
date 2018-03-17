#include<iostream>
using namespace std;
int main()
{
	int n,zl[100],sum=0;
	bool zj[100];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> zl[i];
	}
	for (int j = 1; j <= n; j++)
	{
		cin >> zj[j];
	}
	for (int k = 1; k <= n; k++)
	{
		if (zj[k] != 0)
		{
			sum = sum + zl[k];
		}
	}
	cout << sum<<endl;
	system("pause");
	return 0;
}