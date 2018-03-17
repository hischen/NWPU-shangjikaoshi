#include <stdio.h>
#include <stdlib.h>
int h(int n)
{
	if(n==0||n==1)
		return 1;
	else
	{
		return (4*n-2)*h(n-1)/(n+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",h(n));
	return 0;
}