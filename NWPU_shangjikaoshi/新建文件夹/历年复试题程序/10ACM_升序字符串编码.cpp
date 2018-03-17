#include <stdio.h>
#include <string.h>
int f(int n,int m)
{
	int i,sum=1;
	for(i=0;i<m;i++)
		sum*=(n-i);
	for(i=2;i<=m;i++)
		sum/=i;
	return sum;
}
int main()
{
	char s[6],c;
	int len,i,num=0;
	gets(s);
	len=strlen(s);
	if(len==1)
		num+=s[0]-'a'+1;
	else
	{
		for(i=1;i<len;i++)
			num+=f(26,i);
		for(i=0;i<len-1;i++)
		{
			if(i==0) c='a';
			else c=s[i-1]+1;
			while(c<s[i])
			{
				num+=f('z'-c,len-1-i);
				c++;
			}
		}
		num+=s[len-1]-s[len-2];
	}
	printf("%d\n",num);
	return 0;
}