#include <stdio.h>
char f[50][50];
struct
{
	int up;
	int down;
	int left;
	int right;
}a[11];
void init()
{
	a[0].up=1;a[0].down=0;a[0].left=1;a[0].right=0;
	a[1].up=1;a[1].down=0;a[1].left=0;a[1].right=1;
	a[2].up=0;a[2].down=1;a[2].left=1;a[2].right=0;
	a[3].up=0;a[3].down=1;a[3].left=0;a[3].right=1;
	a[4].up=1;a[4].down=1;a[4].left=0;a[4].right=0;
	a[5].up=0;a[5].down=0;a[5].left=1;a[5].right=1;
	a[6].up=1;a[6].down=0;a[6].left=1;a[6].right=1;
	a[7].up=1;a[7].down=1;a[7].left=1;a[7].right=0;
	a[8].up=0;a[8].down=1;a[8].left=1;a[8].right=1;
	a[9].up=1;a[9].down=1;a[9].left=0;a[9].right=1;
	a[10].up=1;a[10].down=1;a[10].left=1;a[10].right=1;
}
int search(int m,int n)
{
	int i,j,count=m*n;
	for(i=0;i<m-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[f[i][j]-'A'].right==1&&a[f[i][j+1]-'A'].left==1)
					count--;
			if(a[f[i][j]-'A'].down==1&&a[f[i+1][j]-'A'].up==1)
						count--;
			if(a[f[i][j]-'A'].right==1&&a[f[i][j+1]-'A'].left==1&&a[f[i][j]-'A'].down==1&&a[f[i+1][j]-'A'].up==1&&
				a[f[i+1][j]-'A'].right==1&&a[f[i+1][j+1]-'A'].left==1&&a[f[i+1][j+1]-'A'].up==1&&a[f[i][j+1]-'A'].down==1)
					count++;
		}
	}
	for(i=0,j=n-1;i<m-1;i++)
		if(a[f[i][j]-'A'].down==1&&a[f[i+1][j]-'A'].up==1)
			count--;
	for(i=m-1,j=0;j<n-1;j++)
		if(a[f[i][j]-'A'].right==1&&a[f[i][j+1]-'A'].left==1)
					count--;
	return count;
}
int main()
{
	init();
	int i,j,m,n;
	scanf("%d%d",&m,&n);
	getchar();
	while(m!=-1||n!=-1)
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				scanf("%c",&f[i][j]);
			getchar();
		}
		printf("%d\n",search(m,n));
		scanf("%d%d",&m,&n);
		getchar();
	}
	return 0;
}