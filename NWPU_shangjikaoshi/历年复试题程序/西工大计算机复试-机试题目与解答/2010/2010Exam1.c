//»ðÐÇ¼Ó·¨

#include <stdio.h>

void main()
{
	unsigned int A, B, sum = 0;

	scanf("%d\n%d", &A, &B);

	if(A % 3 == 0 && B % 5 == 0)
	{
		sum = A + B;
	}
	if(A % 3 != 0 && B % 5 == 0)
	{
		int max = 0, i = 0;
		while(i < A)
		{
			if(i % 3 == 0 && i > max)
				max = i;
			i++;
		}
		sum = max + B;
	}
	if(A % 3 == 0 && B % 5 != 0)
	{
		int min = B + 1;
		while(1)
		{
			if(min % 5 == 0)
				break;
			min++;
		}
		sum = A + min;
	}
	if(A % 3 != 0 && B % 5 != 0)
	{
		int max = 0, i = 0, min = B + 1;
		while(i < A)
		{
			if(i % 3 == 0 && i > max)
				max = i;
			i++;
		}
		while(1)
		{
			if(min % 5 == 0)
				break;
			min++;
		}
		sum = max + min;
	}
	
	printf("%d\n", sum);
}