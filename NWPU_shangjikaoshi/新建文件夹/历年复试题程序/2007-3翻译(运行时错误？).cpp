#include <stdio.h>
#include <string.h>
char a[100][20];
char b[100][20];
int isTranslate(int na,int nb)
{
	int i,j;
	if(na!=nb) return 0;
	for(i=0;i<na;i++)
		for(j=i+1;j<na;j++)
		{
			if(strcmp(a[i],a[j])==0)
				if(strcmp(b[i],b[j])!=0)
					return 0;
		}
	return 1;
}
int main()
{
	char c;
	int n=0,i=0;
	int lena,lenb;
	while((c=getchar())!='\n')
	{
		if(c==' ')
		{
			n++;i=0;
		}
		else
			a[n][i++]=c;
	}
	lena=n+1;
	n=0;i=0;
	while((c=getchar())!='\n')
	{
		if(c==' ')
		{
			n++;i=0;
		}
		else
			b[n][i++]=c;
	}
	lenb=n+1;
	isTranslate(lena,lenb)?printf("Yes\n"):printf("No\n");
	return 0;
}