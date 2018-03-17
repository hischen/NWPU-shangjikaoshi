#include<stdio.h>
#include<string.h>
int l[10001][10001];
int lcs_length(char x[], char y[] )
{
	int m,n,i,j;
	m=strlen(x);
	n=strlen(y);
	for(i=0;i<m+1;i++)
		l[i][0]=0;
	for(j=0;j<n+1;j++)
		l[0][j]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(x[i-1]==y[j-1])
				l[i][j]=l[i-1][j-1]+1;
			else if(l[i][j-1]>l[i-1][j])
				l[i][j]=l[i][j-1];
			else
				l[i][j]=l[i-1][j];
	return l[m][n];
}
int main()
{
	char x[10000],y[10000];
	int len;
	scanf("%s%s",x,y);
	len=lcs_length(x,y);
	printf("%d\n",len);
	return 0;
}
