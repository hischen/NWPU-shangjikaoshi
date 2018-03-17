#include <stdio.h>
#include <stdlib.h>
int main()
{
	int m,n,i,j,count;
	scanf("%d%d",&m,&n);
	int* a=(int*)malloc((m*n)*sizeof(int));
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",a+i*n+j);
	count=0;
	for(i=1;i<m-1;i++)
		for(j=1;j<n-1;j++)
		{
			if(*(a+i*n+j)>*(a+(i-1)*n+j)&&*(a+i*n+j)>*(a+(i+1)*n+j)&&*(a+i*n+j)<*(a+i*n+j-1)&&*(a+i*n+j)<*(a+i*n+j+1))
			{
				count++;
				printf("∞∞µ„A:%d\n",*(a+i*n+j));
			}
			else if(*(a+i*n+j)<*(a+(i-1)*n+j)&&*(a+i*n+j)<*(a+(i+1)*n+j)&&*(a+i*n+j)>*(a+i*n+j-1)&&*(a+i*n+j)>*(a+i*n+j+1))
			{
				count++;
				printf("∞∞µ„B:%d\n",*(a+i*n+j));
			}
		}
	printf("%d\n",count);
	return 0;
}