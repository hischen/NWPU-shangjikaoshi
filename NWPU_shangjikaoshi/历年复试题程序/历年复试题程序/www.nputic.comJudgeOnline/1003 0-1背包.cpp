#include <stdio.h>
int n,c;
int max;
int w[10],v[10],a[10];
void checkmax()
{
	int i,weigh,value;
	weigh=0;value=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			weigh+=w[i];
			value+=v[i];
		}
	}
	if(weigh<=c)
	{
		if(value>max)
			max=value;
	}
}
void search(int m)
{
	if(m>=n)
		checkmax();
	else
	{
		a[m]=0;
		search(m+1);
		a[m]=1;
		search(m+1);
	}
}
int main()
{
	int i;
	scanf("%d%d",&n,&c);
	while(n!=0||c!=0)
	{
		for(i=0;i<n;i++)
			scanf("%d",&w[i]);
		for(i=0;i<n;i++)
			scanf("%d",&v[i]);
		search(0);
		printf("%d\n",max);
		max=0;
		for(i=0;i<n;i++)
			a[i]=0;
		scanf("%d%d",&n,&c);
	}
	return 0;
}