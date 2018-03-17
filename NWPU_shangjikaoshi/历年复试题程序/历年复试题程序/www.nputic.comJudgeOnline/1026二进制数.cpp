#include <stdio.h>
#include <stdlib.h>
int binary[200];
int dtob(int m)
{
	int i=0;
	while(m/2!=0)
	{
		if(m%2==1) binary[i++]=1;
		else binary[i++]=0;
		m/=2;
	}
	binary[i++]=1;
	return i;
}
void print(int k)
{
	int i,j;
	for(i=0,j=0;i<k;i++)
	{
		if(binary[i]==1)
			printf("%d ",i);
	}
	printf("\n");
}
int main()
{
	int n,i,count;
	scanf("%d",&n);
	int* a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
		count=dtob(*(a+i));
		print(count);
	}
	return 0;
}