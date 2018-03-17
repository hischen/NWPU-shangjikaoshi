#include <stdio.h>
int BtoD(char *a)
{
	int i,sum=0,q=1;
	for(i=7;i>=0;i--)
	{
		if(a[i]=='1') sum+=q;
		q*=2;
	}
	return sum;
}
int main()
{
	char a[8];
	scanf("%s",a);
	printf("%d\n",BtoD(a));
}