#include <stdio.h>
int sum;
int s(int n)
{
	if(n==2||n==3)
		return sum+1;
	else
	{
		if(n%3==0)
		{
			sum++;
			s(n/3);
		}
		else
		{
			sum++;
			s(n/3+1);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",s(n));
	return 0;
}