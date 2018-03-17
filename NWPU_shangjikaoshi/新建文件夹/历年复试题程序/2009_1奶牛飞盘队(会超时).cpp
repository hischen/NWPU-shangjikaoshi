#include <stdio.h>
#include <stdlib.h>
int n,f;
int count=0;
int* r;
int* a;
void result()
{
	int i,sum=0;
	for(i=0;i<n;i++)
		if(a[i]==1)
			sum+=r[i];
	if(sum%f==0&&sum!=0) count++;
}
void search(int m)
{
	if(m>=n)
	{
		result();
	}
	else
	{
		a[m]=1;
		search(m+1);
		a[m]=0;
		search(m+1);
	}
}
int main()
{
	int i;
	scanf("%d%d",&n,&f);
	r=(int*)malloc((n)*sizeof(int));
    a=(int*)malloc((n)*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",r+i);
		a[i]=0;
	}
	search(0);
	printf("%d\n",count%100000000);
	return 0;
}