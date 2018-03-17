#include <stdio.h>
#include <math.h>
int a[8];
int n=1;
void printresult()
{
	int i,j;
	printf("No %d:\n",n);
	n++;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(a[i]==j) printf("A");
			else printf(".");
		}
		printf("\n");
	}
}
int canplace(int row,int col)
{
	int i;
	for(i=0;i<row;i++)
	{
		if(abs(i-row)==abs(a[i]-col)||a[i]==col)
			return 0;
	}
	return 1;
}
void search(int m)
{
	int i;
	if(m>=8)
		printresult();
	else
	{
		for(i=0;i<8;i++)
		{
			if(canplace(m,i))
			{
				a[m]=i;
				search(m+1);
				a[m]=-1;
			}
		}
	}
}
int main()
{
	search(0);
    return 0;
}