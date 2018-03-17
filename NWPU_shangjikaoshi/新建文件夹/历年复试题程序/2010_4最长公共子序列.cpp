#include <stdio.h>
#include <string.h>
void f(char a[],char b[])
{
	int i,j,lena,lenb,l[200][200];
	for(i=0;i<200;i++)
		l[i][0]=0;
	for(j=0;j<200;j++)
		l[0][j]=0;
	lena=strlen(a);
	lenb=strlen(b);
	for(i=1;i<=lena;i++)
		for(j=1;j<=lenb;j++)
		{
			if(a[i-1]==b[j-1])
				l[i][j]=l[i-1][j-1]+1;
			else if(l[i][j-1]>l[i-1][j])
				l[i][j]=l[i][j-1];
			else l[i][j]=l[i-1][j];
		}
	printf("%d\n",l[lena][lenb]);
}
int main()
{
	while(1)
	{
		char a[200],b[200];
		scanf("%s%s",a,b);
		f(a,b);
	}
	return 0;
}