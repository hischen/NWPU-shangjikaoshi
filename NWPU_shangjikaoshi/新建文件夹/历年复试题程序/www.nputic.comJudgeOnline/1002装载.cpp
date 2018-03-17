#include <stdio.h>
int c1,c2,n,flag;
int w[10],a[10];
int result()
{
	int i,s1,s2;
	for(i=0,s1=0,s2=0;i<n;i++)
		if(a[i]==1)
			s1+=w[i];
		else s2+=w[i];
	if(s1<=c1&&s2<=c2) return 1;
	else return 0;
}
void search(int m)
{
	if(m>=n)
	{
		if(result()==1)
		{
			flag=1;
			return;
		}
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
	scanf("%d%d%d",&c1,&c2,&n);
	while(n!=0)
	{
		for(i=0;i<n;i++)
			scanf("%d",&w[i]);
		search(0);
		flag?printf("Yes\n"):printf("No\n");
		scanf("%d%d%d",&c1,&c2,&n);
		for(i=0;i<n;i++)
			a[i]=0;
		flag=0;
	}
	return 0;
}