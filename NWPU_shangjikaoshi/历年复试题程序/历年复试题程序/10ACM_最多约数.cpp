#include <stdio.h>
int div(int x)
{
	int i,sum=0;
	for(i=1;i<=x;i++)
	{
		if(x%i==0)
			sum++;
	}
	return sum;
}
int main()
{
	int a,b,i,count,max=0;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
	{
		count=div(i);
		if(count>max)
			max=count;
	}
	printf("%d\n",max);
	return 0;
}