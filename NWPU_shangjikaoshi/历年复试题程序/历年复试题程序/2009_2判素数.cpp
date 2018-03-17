#include <stdio.h>
#include <math.h>
int main()
{
	int i,k,n,flag=1;
	scanf("%d",&n);
	k=(int)sqrt(n);
	for(i=2;i<=k;i++)
	{
		if(n%i==0)
		{
			flag=0;
			break;
		}
	}
	flag?printf("Yes\n"):printf("No\n");
	return 0;
}
