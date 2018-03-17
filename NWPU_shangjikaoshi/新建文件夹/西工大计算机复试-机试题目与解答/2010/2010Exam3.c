//CatalanÊı

#include <stdio.h>
#include <string.h>

int catalan(int n)
{
	int i, count = 0;

	if(n == 0 || n == 1)
		count = 1;
	else 
	{
		for(i = 0; i < n; i++)
			count += (catalan(i) * catalan(n - 1 - i));
	}	
	return count;
}

void main()
{
	int n;

	scanf("%d", &n);
	if(n < 1) exit(0);

	printf("%d\n", catalan(n));
}
