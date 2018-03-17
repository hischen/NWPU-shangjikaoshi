#include <stdio.h>
#include <string.h>
int ishuiwen(int n)
{
	int c[22];
	int i,j,k=0;
	while(n!=0)
	{
		c[k++]=n%2;
		n/=2;
	}
	for(i=0,j=k-1;i<j;i++,j--)
		if(c[i]!=c[j])
			return 0;
	return 1;
}
int main()
{
	char a[22],b[22];
	int i,j,lena,lenb,sa=0,sb=0,count=0;
	gets(a);
	lena=strlen(a);
	for(i=lena-1,j=1;i>=0;i--)
	{
		if(a[i]=='1')
			sa+=j;
		j*=2;
	} 
	gets(b);
	lenb=strlen(b);
	for(i=lenb-1,j=1;i>=0;i--)
	{
		if(b[i]=='1')
			sb+=j;
		j*=2;
	}
	for(i=sa;i<=sb;i++)
	{
		if(ishuiwen(i))
			count++;
	}
	printf("%d\n",count);
	return 0;
}