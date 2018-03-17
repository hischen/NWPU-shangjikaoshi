#include <stdio.h>
#include <math.h>
int isPrime(int n)
{
	int i,k;
	k=sqrt(n);
	for(i=2;i<=k;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int huiwen(int n)
{
	int m=0,pre_n=n;
	while(n!=0)
	{
		m=m*10+n%10;
		n/=10;
	}
	if(m==pre_n) return 1;
	else return 0;
}
int main()
{
	int a,b,i;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
		if(isPrime(i))
			if(huiwen(i))
				printf("%d\n",i);
	return 0;
}