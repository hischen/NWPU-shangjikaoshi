#include <stdio.h>
int a[1000000];
int main()
{
	int i,n,num,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		a[num]++;
	}
	for(i=0;i<1000000;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	printf("%d\n",max);
	return 0;
}