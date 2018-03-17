//回文质数

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <windows.h>
//#pragma comment(lib,"winmm.lib")
#define MAXSIZE 10

int zhishu(int num)
{
	int i;

	for(i = 2; i < num; i++)
		if(num % i == 0)	return 0;

	return 1;
}

int huiwen(int num)
{
	char str[MAXSIZE];
	int i, len;

	for(i = 0; ; i++)
	{
		str[i] = (char)(num % 10 + 48);
		if(num > 9)
			num /= 10;
		else break;
	}
	len = i + 1;

	for(i = 0; i < len / 2; i++)
		if(str[i] != str[len - 1 - i])
			return 0;

	return 1;
}

void main()
{
	int i, a, b;	

	scanf("%d %d", &a, &b);
	if(a < 5 || b > 100000000)
	{
		printf("Error!\n");
		exit(0);
	}

	//std::DWORD dwStart = timeGetTime();

	for(i = a; i <= b; i++)
		if(huiwen(i) && zhishu(i))
			printf("%d\n", i);

	//std::dDWORD dwEnd = timeGetTime();

	//printf("%d\n", dwEnd - dwStart);
}