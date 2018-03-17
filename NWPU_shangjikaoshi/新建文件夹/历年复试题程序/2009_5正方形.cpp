#include <stdio.h>
struct
{
	int x;
	int y;
}a[1000][4];
int flag[1000];
int dis[4][4];
int distance(int m,int i,int j)
{
	return (a[m][i].x-a[m][j].x)*(a[m][i].x-a[m][j].x)+(a[m][i].y-a[m][j].y)*(a[m][i].y-a[m][j].y);
}
int judge(int m)
{
	int i,j,max=0,min=2000000;
	for(i=0;i<3;i++)
		for(j=i+1;j<4;j++)
		{
			dis[i][j]=distance(m,i,j);
			if(dis[i][j]>max) max=dis[i][j];
			if(dis[i][j]<min) min=dis[i][j];
		}
	if(max==min*2) return 1;
	else return 0;
}
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
			scanf("%d%d",&a[i][j].x,&a[i][j].y);
		judge(i)?flag[i]=1:flag[i]=0;
	}
	for(i=0;i<n;i++)
		if(flag[i]==1) printf("Yes\n");
		else printf("No\n");
	return 0;
}