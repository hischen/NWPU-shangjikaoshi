#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
char caochang[100][100];
bool marked[100][100] = { false };
int N, M;
int near[][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1,
	-1,1,
	1,1,
	-1,-1,
	1,-1
};
void bfs(int x, int y)
{
	for (int l = 0; l < 8; l++)
	{
		int nx = x + near[l][0];
		int ny = y + near[l][1];
		if (nx <0 || ny <0 || nx > N || ny > M) continue;
		if (caochang[nx][ny] == '.') continue;
		if (caochang[nx][ny] == true)  continue;
		caochang[nx][ny] = true;
		bfs(nx, ny);
	}
		return;
  
}
int main()
{
	int count=0;
	int i,j;
	
	
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
	    cout << caochang[i][j] << ' ';
	   }
	    cout << endl;
	}
	for (int k = 0; k < N; k++)
	{
		for (int h = 0; h < M; h++)
		{
			if (marked[k][h] == true)  continue;
			if (caochang[k][h] == '.') continue;
			
			bfs(k, h);
			count++;
		}
	}

	cout << count<<endl;



	

	system("pause");
	return 0;
}