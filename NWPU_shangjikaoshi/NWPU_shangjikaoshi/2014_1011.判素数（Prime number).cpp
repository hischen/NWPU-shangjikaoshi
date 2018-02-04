#include<iostream>
#include<cstdio>
using namespace std;
bool judge(int m)
{
	if (m % 2 == 0) return false;
	for (int i = 3; i < m; i=+2)
	{
		if (m%i == 0)
		{ 
			return false;
		}
		else
		{
			
			return true;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	if(judge(n))
		printf("YES");
	else
	{
		printf("NO");
	}
	system("pause");
	return 0;
}