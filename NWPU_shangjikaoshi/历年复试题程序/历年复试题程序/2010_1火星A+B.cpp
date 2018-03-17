#include <stdio.h>
int main()
{
	int a,b,sum;
	scanf("%d%d",&a,&b);
	if(a%3==0&&b%5==0) sum=a+b;
	else if(a%3!=0&&b%5==0)
	{
		while(a%3!=0) a--;
		sum=a+b;
	}
	else if(a%3==0&&b%5!=0)
	{
		while(b%5!=0) b++;
		sum=a+b;
	}
	else
	{
		while(a%3!=0) a--;
		while(b%5!=0) b++;
		sum=a+b;
	}
	printf("%d\n",sum);
}