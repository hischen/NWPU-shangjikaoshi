#include <stdio.h>
#include <math.h>
int isPrime(int n)
{
	int i,k;
	k=sqrt(n);
	for(i=2;i<=k;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	int a,b,i;
	scanf("%d%d",&a,&b);
	for(i=a+1;i<b;i++)
		if(isPrime(i))
			printf("%d\n",i);
}