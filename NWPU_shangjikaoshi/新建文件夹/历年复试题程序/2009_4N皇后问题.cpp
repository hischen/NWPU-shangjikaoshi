#include <stdio.h>
#include <math.h>
int n,count=0,a[20];
int canplace(int row,int col)
{
	int i;
	for(i=0;i<row;i++)
		if(abs(i-row)==abs(a[i]-col)||a[i]==col)
			return 0;
	return 1;
}
void search(int m)
{
	int i;
	if(m>=n)
		count++;
	else
	{
		for(i=0;i<n;i++)
			if(canplace(m,i))
			{
				a[m]=i;
				search(m+1);
				a[m]=-1;
			}
	}
}
int main()
{
	scanf("%d",&n);
	search(0);
	printf("%d\n",count);
	return 0;
}