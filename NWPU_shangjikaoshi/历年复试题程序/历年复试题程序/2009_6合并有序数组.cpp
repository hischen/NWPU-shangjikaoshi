#include <stdio.h>
int a[10000],b[10000],c[20000];
void merge(int m,int n)
{
	int i=0,j=0,k=0;
	while(i<m&&j<n)
		if(a[i]<b[j]) c[k++]=a[i++];
		else c[k++]=b[j++];
	while(i<m) c[k++]=a[i++];
	while(j<n) c[k++]=b[j++];
}
int main()
{
	int i,m,n;
	scanf("%d",&m);
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	merge(m,n);
	for(i=0;i<(m+n);i++)
		printf("%d\n",c[i]);
	return 0;
}