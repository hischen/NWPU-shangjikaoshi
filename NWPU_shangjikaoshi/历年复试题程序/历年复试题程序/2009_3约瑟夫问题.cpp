#include <stdio.h>
int main()
{
	int i,m,n,p;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		p=i*m;
		while(p>n)
			p=p-n+(p-n-1)/(m-1);
	}
	printf("%d\n",p);
	return 0;
}
/*
#include <stdio.h>
int main()
{
	int m,n,i,result;
    scanf("%d%d",&n,&m);
	for (i=1,result=0;i<=n;i++)
		result=(result+m)%i;
    printf("%d",result+1);
	return 0;
}	
*/
