#include <stdio.h>
int n,max;
char a[4][4];
void checkmax()
{
	int i,j,sum;
	sum=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(a[i][j]=='A')
				sum++;
		}
	if(sum>max) max=sum;
}
int canplace(int m)
{
	int i,row,col;
	row=m/n;
	col=m%n;
	if(a[row][col]=='.')
	{
		for(i=col-1;i>=0;i--)
		{
			if(a[row][i]=='A') return 0;
			else if(a[row][i]=='X') break;
		}
		for(i=col+1;i<n;i++)
		{
			if(a[row][i]=='A') return 0;
			else if(a[row][i]=='X') break;
		}
		for(i=row-1;i>=0;i--)
		{
			if(a[i][col]=='A') return 0;
			else if(a[i][col]=='X') break;
		}
		for(i=row+1;i<n;i++)
		{
			if(a[i][col]=='A') return 0;
			else if(a[i][col]=='X') break;
		}
	}
	else return 0;
	return 1;
}
void place(int m)
{
	int row,col;
	row=m/n;
	col=m%n;
	a[row][col]='A';
}
void takeout(int m)
{
	int row,col;
	row=m/n;
	col=m%n;
	a[row][col]='.';
}
void search(int m)
{
	if(m>=n*n)
		checkmax();
	else
	{
		search(m+1);
		if(canplace(m))
		{
			place(m);
			search(m+1);
			takeout(m);
		}
	}
}
int main()
{
	int i,j;
	char c;
	scanf("%d",&n);
	while(n!=0)
	{
		c=getchar();
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				scanf("%c",&a[i][j]);
			getchar();
		}
		search(0);
		printf("%d\n",max);
		max=0;
		scanf("%d",&n);
	}
}