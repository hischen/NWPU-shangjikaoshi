#include <stdio.h>
#include <stdlib.h>
int f(int m)
{
	int num=0;
	while(m/=5)
		num+=m;
	return num;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	long int* a=(long int*)malloc(n*sizeof(long int));
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
		printf("%ld\n",f(*(a+i)));
	}
	return 0;	
}
