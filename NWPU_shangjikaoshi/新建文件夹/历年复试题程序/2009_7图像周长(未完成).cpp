#include <stdio.h>
#include <stdlib.h>
char* p;
int* a;
int m,n,circle;
int cangoon(int row,int col)
{
	if(row>=1&&row<=m&&col>=1&&col<=n&&*(a+(row-1)*m+col-1)==0)
		return 1;
	else return 0;
}
int cancount(int row,int col)
{
	if(row==0||row==(m+1)||col==0||col==(n+1))
		return 1;
	else if(*(p+(row-1)*m+col-1)=='.')
		return 1;
	else return 0;
}
void search(int row,int col)
{
	int r,c;
	*(a+(row-1)*m+col-1)=1;
	if(*(p+(row-1)*m+col-1)=='X'row==1||row==m||col==1||col==n)
	r=row;c=col-1;//左
	if(*(p+(row-1)*m+col-1)=='X'&&cancount(r,c))
		circle++;
	if(cangoon(r,c)) search(r,c);
	r=row;c=col+1;//右
	if(*(p+(row-1)*m+col-1)=='X'&&cancount(r,c))
		circle++;
	if(cangoon(r,c)) search(r,c);
	r=row-1;c=col;//上
	if(*(p+(row-1)*m+col-1)=='X'&&cancount(r,c))
		circle++;
	if(cangoon(r,c)) search(r,c);
	r=row+1;c=col;//下
	if(*(p+(row-1)*m+col-1)=='X'&&cancount(r,c))
		circle++;
	if(cangoon(r,c)) search(r,c);
/*	r=row-1;c=col-1;//左上
	if(*(p+(row-1)*m+col-1)=='X'&&cancount(r,c))
		circle++;
	if(cangoon(r,c)) search(r,c);
	r=row+1;c=col-1;//左下
	if(*(p+(row-1)*m+col-1)=='X'&&cancount(r,c))
		circle++;
	if(cangoon(r,c)) search(r,c);
	r=row-1;c=col+1;//右上
	if(*(p+(row-1)*m+col-1)=='X'&&cancount(r,c))
		circle++;
	if(cangoon(r,c)) search(r,c);
	r=row+1;c=col+1;//右下
	if(*(p+(row-1)*m+col-1)=='X'&&cancount(r,c))
		circle++;
	if(cangoon(r,c)) search(r,c);
*/
}
int main()
{
	int i,j,x,y;
	scanf("%d%d%d%d",&m,&n,&x,&y);
	while(m!=0||n!=0||x!=0||y!=0)
	{
		p=(char*)malloc((m*n)*sizeof(char));
		a=(int*)malloc((m*n)*sizeof(int));
		getchar();
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%c",p+(i-1)*m+j-1);
				*(a+(i-1)*m+j-1)=0;
			}
			getchar();
		}
		for(for)
		search(x,y);
		printf("%d\n",circle);
		scanf("%d%d%d%d",&m,&n,&x,&y);
		circle=0;
	}
	return 0;
}