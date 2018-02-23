#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int i,j;
	int N, M;
	char caochang[100][100];
	scanf("%d %d", &M, &N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			//scanf("%c", &caochang[i][j]);
			cin >> caochang[i][j];
		}
		//fflush(stdin); rewind(stdin);
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cout<<caochang[i][j]<<' ';
		}
		cout << endl;
	

	system("pause");
	return 0;
}