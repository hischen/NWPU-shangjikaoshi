#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int n;
	int a, b, c;
	bool res[1000];
	scanf_s("%d", &n);
	for(int j=0;j<n;j++)//while (n--)
	{
		
		scanf_s("%d %d %d", &a, &b, &c);
		if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2) || pow(c, 2) + pow(a, 2) == pow(b, 2))
			res[j] = true;//printf("YES\n");
		else
		{
			res[j] = false;//printf("NO\n");
		}
		//printf("%d\n",res[j]);
	}
	for (int i = 0; i <n; i++)
	{
		if (res[i]==true) printf("YES\n");
		else if (res[i] == false)printf("NO\n");
	}
	system("pause");
	return  0;
}