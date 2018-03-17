#include <stdio.h>
int a[250][250];
int xi[100000],xj[100000];
int search(int x,int y,int b)
{
	int i,j,max=0,min=a[x][y];
	for(i=x;i<x+b;i++)
		for(j=y;j<y+b;j++)
		{
			if(max<a[i][j])
				max=a[i][j];
			if(min>a[i][j])
				min=a[i][j];
		}
	return max-min;
}
int main()
{
	int n,b,k,i,j;
	scanf("%d%d%d",&n,&b,&k);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<k;i++)
	{
		scanf("%d%d",&xi[i],&xj[i]);
		printf("%d\n",search(xi[i]-1,xj[i]-1,b));
	}
	return 0;
}