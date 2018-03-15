#define _CRT_SECURE_NO_WARNINGS
/*http://blog.csdn.net/theonegis/article/details/45787955 */
#include <cstdio>
#include <cstring>
#include<iostream>
using namespace std;

#include <iostream>

using namespace std;

//const int N = 5;//皇后的个数
int N;
int positon[12];//存放皇后的位置
int cont = 0;//记录有多少种摆法

			  /*判断第row行放置的位置是否满足要求*/
bool valid(int row)
{
	for (int i = 0; i < row; ++i)
	{
		// 如果和前面放好位置的不在同一列，也不在对角线上，则返回true，否则返回false
		if (positon[i] == positon[row] || abs(positon[i] - positon[row]) == abs(i - row))
			return false;
	}
	return true;
}

/*输出摆放结果*/
void print()
{
	cout << "这是第" << ++cont << "种摆法：" << '\n';
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (positon[i] == j)
				cout << "⊙ ";
			else
				cout << "× ";
		}
		cout << '\n';
	}
	cout << endl;
}

/*回溯法搜索摆放位置*/
void trail(int row = 0)
{
	// 如果摆完完N行，则输出结果
	if (N == row)
	{
		print();
		return;
	}
	for (int column = 0; column < N; ++column)
	{
		positon[row] = column;// 放置在第row行第column列
							  // 如果满足条件，则进行下一行
		if (valid(row)) trail(row + 1);
		// 如果不满足条件，则进行下一次循环，即回溯回去在第row行重新寻找摆放的位置
	}
}

int main()
{
	cin >> N;
	trail();
	system("pause");
	return 0;
}
//#include <iostream>  
//#include <cmath>  
//#include <cstring>  
//using namespace std;
//
//int queen[9];
//
////数组初始化  
//void init()
//{
//	memset(queen, 0, 9 * sizeof(int));
//}
//
////输出结果  
//void print()
//{
//	for (int i = 1; i<9; i++) cout << queen[i] << "  ";
//	cout << endl;
//}
//
////剪枝函数  
//bool canPlaceQueen(int k)
//{
//	for (int i = 1; i < k; i++)
//	{
//		//判断是否处于同一列或同一斜线  
//		if (queen[i] == queen[k] || abs(k - i) == abs(queen[k] - queen[i])) return false;
//	}
//	return true;
//}
////迭代方法求解八皇后过程  
//void eightQueen_1()
//{
//	int k = 1;
//	while (k >= 1)
//	{
//		while (queen[k] <= 7)
//		{
//			queen[k] += 1;
//			if (k == 8 && canPlaceQueen(k))
//			{
//				print();
//			}
//			else if (canPlaceQueen(k))
//			{
//				k++;
//			}
//		}
//		queen[k] = 0;
//		k--;
//	}
//}
//
////递归方法求解八皇后过程  
//void eightQueen_2(int k)
//{
//	for (int i = 1; i<9; i++)
//	{
//		queen[k] = i;
//		if (k == 8 && canPlaceQueen(k))
//		{
//			print();
//			return;
//		}
//		else if (canPlaceQueen(k))
//		{
//			eightQueen_2(k + 1);
//		}
//	}
//}
//int main()
//{
//	init();
//	//eightQueen_1();
//	    eightQueen_2(1);  
//	system("pause");
//	return 0;
//}


//
//int a[15] = { 0 }, b[2][15] = { 0 }, st[9], pzl[9][9], ttl = 0;
//
//void print(void)
//{
//	memset(pzl, 0, sizeof(pzl));
//	for (int i = 1; i <= 8; ++i)
//		pzl[i][st[i]] = 1;
//
//	printf("%i:\n", ++ttl);
//	for (int i = 1; i <= 8; ++i) {
//		for (int j = 1; j <= 8; ++j)
//			printf("%c ", pzl[i][j] == 1 ? 'X' : 'O');
//		puts("");
//	}
//}
//
//void sch(int n) // 总问题
//{
//	for (int i = 1; i <= 8; ++i) { // 子问题
//		int x = n + i - 2, y = n - i + 7;
//
//		if (!a[i] && !b[0][x] && !b[1][y]) { // 子问题的解
//			st[n] = i;
//			a[i] = b[0][x] = b[1][y] = 1; // 保存位置
//
//			n == 8 ? print() : sch(n + 1); // 总问题出口判断
//
//			a[i] = b[0][x] = b[1][y] = 0; // 回溯位置
//		}
//	}
//}
//
//int main(void)
//{
//	sch(1);
//	system("pause");
//	return 0;
//}
