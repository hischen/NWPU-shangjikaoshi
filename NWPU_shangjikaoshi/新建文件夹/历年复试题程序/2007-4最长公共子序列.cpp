#include <stdio.h>
#include <string.h>
char a[10000];
char b[10000];
int l[10001][10001];
int compare(int na,int nb)
{
	int i,j;
	for(i=0;i<na+1;i++)
		l[i][0]=0;
	for(j=0;j<nb+1;j++)
		l[0][j]=0;
	for(i=1;i<=na;i++)
		for(j=1;j<=nb;j++)
			if(a[i-1]==b[j-1])
				l[i][j]=l[i-1][j-1]+1;
			else if(l[i-1][j]>l[i][j-1])
				l[i][j]=l[i-1][j];
			else l[i][j]=l[i][j-1];
	return l[na][nb];
}
int main()
{
	int lena,lenb;
	scanf("%s%s",a,b);
	lena=strlen(a);
	lenb=strlen(b);
	printf("%d\n",compare(lena,lenb));
}