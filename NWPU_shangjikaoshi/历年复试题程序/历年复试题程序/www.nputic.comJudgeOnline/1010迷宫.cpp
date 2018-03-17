#include <stdio.h>
char a[20][20];
int canplace(int row,int col)
{
	if(row>=0&&row<20&&col>=0&&col<20&&a[row][col]=='.')
	{
		a[row][col]='A';
		return 1;
	}
	else return 0;
}
void search(int row,int col)
{
	int r,c;
	r=row-1;c=col;
	if(canplace(r,c))
		search(r,c);
	r=row+1;c=col;
	if(canplace(r,c))
		search(r,c);
	r=row;c=col-1;
	if(canplace(r,c))
		search(r,c);
	r=row;c=col+1;
	if(canplace(r,c))
		search(r,c);
}
int main()
{
	int n,i,j,k,x1,x2,y1,y2;
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(i=0;i<20;i++)
		{
			getchar();
			for(j=0;j<20;j++)
				scanf("%c",&a[i][j]);
		}
		search(x1,y1);
		if(a[x2][y2]=='A') printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}