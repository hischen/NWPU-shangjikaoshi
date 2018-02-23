#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int N;
	int m,n;
	char str;
	scanf("%d", &N); 
	scanf("%d %d\n", &m, &n); 
	//fflush(stdin); rewind(stdin);
	scanf("%c", &str); 
	
	switch (str)
	{
	case 'w': {if (m == 0) printf("N\n"); else printf("Y\n"); } break;
	case 's': {if (m == N - 1) printf("N\n"); else printf("Y\n"); } break;
	case 'a': {if (n == 0) printf("N\n"); else printf("Y\n"); }break;
	case 'd': {if (n == N - 1) printf("N\n"); else printf("Y\n"); }break;
	default:break;
	}
	system("pause");
	return 0;
}