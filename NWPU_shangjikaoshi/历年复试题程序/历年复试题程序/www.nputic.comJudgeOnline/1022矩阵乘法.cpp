#include <stdio.h>
double a[10][10],b[10][10],c[10][10];
void MultMatrix(int m,int n,int k)
{
	int r,s,t;
	for(r=0;r<m;r++)
		for(s=0;s<k;s++)
			for(t=0;t<n;t++)
				c[r][s]+=a[r][t]*b[t][s];
}
int main()
{
	int m,n,k,i,j;
	scanf("%d%d%d",&m,&n,&k);
	while(m!=0||n!=0||k!=0)
	{
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%lf",&a[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<k;j++)
				scanf("%lf",&b[i][j]);
		MultMatrix(m,n,k);
		for(i=0;i<m;i++)
		{
			for(j=0;j<k;j++)
				printf("%.1lf ",c[i][j]);
			printf("\n");
		}
		printf("\n");
		for(i=0;i<m;i++)
			for(j=0;j<k;j++)
				c[i][j]=0.0;
		scanf("%d%d%d",&m,&n,&k);
	}
	return 0;
}