/*
	输入一行字符（字符个数小于255），统计其中不同的大写和小写字母的个数。每个数字占一行。
	输入数据：一行测试数据。
	输出数据：不同的大写和小写字母的个数，每个数字占一行。
	Sample input
	Da; cDb。。." D
	Sample output
	1
	3
*/

#include <stdio.h>

#define MAXSIZE 256

int Input(char str[])
{
	int i = 0;
	char ch;

	scanf("%c", &ch);
	while(ch != '\n')
	{
		str[i++] = ch;
		scanf("%c", &ch);
	}
	return i;
}

int countBig(char str[], int len)
{
	int i, j, count = 0;

	for(i = 0; i < len; i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			for(j = i + 1; j < len; )
			{
				if(str[i] != str[j]) j++;
				else break;
			}
			if(j >= len) count += 1;
		}
	}
	return count;
}

int countLittle(char str[], int len)
{
	int i, j, count = 0;

	for(i = 0; i < len; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			for(j = i + 1; j < len; )
			{
				if(str[i] != str[j]) j++;
				else break;
			}
			if(j >= len) count += 1;
		}
	}
	return count;
}

void main()
{
	char str[MAXSIZE];
	int len, i;

	len = Input(str);
	printf("%d\n",countBig(str, len));
	printf("%d\n",countLittle(str, len));

}