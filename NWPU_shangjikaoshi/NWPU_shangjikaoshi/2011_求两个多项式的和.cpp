/******************************************************************/
/*题目1472：求两个多项式的和
时间限制：1 秒内存限制：128 兆特殊判题：否提交：40解决：9
题目描述：
输入两个多项式，计算它们的和。
每个多项式有若干对整数表示，每组整数中，第一个整数表示系数（非0），第二个整数表示该项的次数。
如由3 3 5 - 2 1 4 0表示3x ^ 5 - 2 * x + 4其中第一个3表示该多项式由三个整数对表示。

输入：
输入为两行，分别表示两个多项式。表示每项的整数
对按照次数大小降序给出。(次数绝对值小于1000，系数绝对值小于10000)

输出：
按照降次顺序输出表示和多项式的整数对（系数为0的整数对不用输出，整数对由空格分隔，最后一个整数对后不添加空格）

样例输入：
3 3 5 - 2 1 4 0
4 2 3 - 1 2 1 1 3 0
样例输出：
3 5 2 3 - 1 2 - 1 1 7 0
来源：2011年西北工业大学计算机研究生机试真题
/**************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>  
#include<string.h>  
#include<iostream>
using namespace std;
int mici[22];
int main()
{
	FILE * p = fopen("D:\\Github\\NWPU-shangjikaoshi\\NWPU_shangjikaoshi\\test data\\polyn.txt", "r+");
	int n1, n2;
	while (fscanf(p, "%d", &n1))
	{
		memset(mici, 0, sizeof(mici));

		//cin>>n1;
		for (int i = 0; i<n1; i++)
		{
			int xishu;
			int mi;
			fscanf(p, "%d", &xishu);//cin>>xishu;
			fscanf(p, "%d", &mi);//cin>>mi;
			mici[mi] = xishu;
		}
		fscanf(p, "%d", &n2);
		if (n1 == 0 && n2 == 0) break;//cin>>n2;
		for (int i = 0; i<n2; i++)
		{
			int xishu;
			int mi;
			fscanf(p, "%d", &xishu);//cin>>xishu;
			fscanf(p, "%d", &mi);//cin>>mi;
			mici[mi] = mici[mi] + xishu;
		}
		for (int i = 20; i >= 0; i--)
		{
			if (mici[i] == 0)
			{
				continue;
			}
			cout << mici[i] << ' ' << i << ' ';
		}
		cout << endl;
	}
}

//int arr[2001] = { 0 };
//
//int main() {
//	int n, m, i, a, b, first;
//	//int array[2001];
//	while (scanf("%d", &n) != EOF) {
//		first = 1;
//		memset(arr, 0, sizeof(arr));
//		//多项式一  
//		for (i = 0; i < n; i++) {
//			scanf("%d %d", &a, &b);
//			arr[b + 1000] = a;
//		}
//		//多项式二  
//		scanf("%d", &m);
//		for (i = 0; i < m; i++) {
//			scanf("%d %d", &a, &b);
//			//相同次数系数相加  
//			arr[b + 1000] += a;
//		}
//		//输出  
//		for (i = 2001; i >= 0; i--) {
//			//系数为0的整数对不用输出  
//			if (arr[i] == 0) {
//				continue;
//			}
//			//控制格式  
//			/*if (first) {
//				first = 0;
//			}
//			else {
//				printf(" ");
//			}*/
//			//printf("%d %d", array[i], i - 1000);
//			cout << arr[i] << ' ' << i - 1000 << ' ';
//		}
//		printf("\n");
//	}
//	return 0;
//}