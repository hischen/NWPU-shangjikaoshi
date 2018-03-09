#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;

int main()
{
	int n; int i, j;
	int mat[11][11];
	//cin >> n;
	//fstream matrix("D:\\matrix.txt");
	fstream matrix;
	matrix.open("D:\\matrix.txt");
	while (matrix >> n)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				//scanf("%d",mat[i]+j);
				matrix >> mat[i][j];
			}
		}
		for (j = 1; j <= n; j++)
		{
			int max = mat[j][j];
			int row = j;
			for (i = j + 1; i <= n; i++)
			{
				if (mat[i][j] > max)
				{
					max = mat[i][j];
					row = i;
				}
			}
			for (i = 1; i <= n; i++)
			{
				int temp = mat[j][i];
				mat[j][i] = mat[row][i];
				mat[row][i] = temp;
			}
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				cout << mat[i][j] << ' ';
			}
			cout << endl;
		}
	}
	matrix.close();
	system("pause");
	return 0;
}

//const int maxn = 12;
//int matrix[maxn][maxn];
//int n, i, j;

//int main() {
//	while (scanf("%d", &n) != EOF) {
//		for (i = 0; i < n; i++) {
//			for (j = 0; j < n; j++) {
//				scanf("%d", &matrix[i][j]);
//			}
//		}
//		for (j = 0; j < n; j++) {
//			int maxValue = matrix[j][j];
//			int maxCol = j;
//			for (i = j + 1; i < n; i++) {
//				if (matrix[i][j] > maxValue) {
//					maxValue = matrix[i][j];
//					maxCol = i;
//				}
//			}
//			for (i = 0; i < n; i++) {
//				int temp = matrix[j][i];
//				matrix[j][i] = matrix[maxCol][i];
//				matrix[maxCol][i] = temp;
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j <=n - 1; j++) {
//				printf("%d ", matrix[i][j]);
//			}
//			//printf("%d", matrix[i][n - 1]);
//			printf("\n");
//		}
//	}
//	return 0;
//}