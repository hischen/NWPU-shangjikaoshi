#include <stdio.h>
#include <string.h>
char a[1000],b[1000];
int c[1000000];
int main()
{
	
	int i,j,k,lena,lenb;
	gets(a);
	lena=strlen(a);
	gets(b);
	lenb=strlen(b);
	if((lena==1&&a[0]=='0')||(lenb==1&&b[0]=='0'))
	{
		printf("0\n");
		return 0;
	}
	for(i=lena-1;i>=0;i--)
	{
		k=999999-(lena-1-i);
		for(j=lenb-1;j>=0;j--)
		{
			c[k]+=(a[i]-'0')*(b[j]-'0');
			c[k-1]+=c[k]/10;
			c[k]%=10;
			k--;
		}
	}
	for(i=0;c[i]==0;i++);
	for(j=i;j<1000000;j++)
		printf("%d",c[j]);
	printf("\n");
	return 0;
}