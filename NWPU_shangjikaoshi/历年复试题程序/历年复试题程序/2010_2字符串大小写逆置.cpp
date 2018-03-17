#include <stdio.h>
#include <string.h>
int main()
{
	char a[10000];
	int i,len;
	scanf("%s",a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]>=65&&a[i]<=90)
			a[i]+=32;
		else a[i]-=32;
	}
	puts(a);
}