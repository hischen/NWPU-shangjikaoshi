#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
int xingqiji(int y, int m, int d)
{
	int whichday;
	if (m == 1 || m == 2)
	{
		m = 12 + m;
		y--;
	}
	whichday = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7; //基姆拉尔森计算公式
		switch (whichday)
		{
		case 0:return 1/*printf("1\n")*/; break;
		case 1:return 2/*printf("2\n")*/; break;
		case 2:return 3/*printf("3\n")*/; break;
		case 3:return 4/*printf("4\n")*/; break;
		case 4:return 5/*printf("5\n")*/; break;
		case 5:return 6/*printf("6\n")*/; break;
		case 6:return 7/*printf("7\n")*/; break;
		}
}
int main()
{
	vector<int> o;
	vector<int>::iterator pd;
	int t;
	scanf_s("%d", &t);
	while (t--)
	{
		int n, y, r;
		scanf_s("%d%d%d", &n, &y, &r);
		o.push_back(xingqiji(n, y, r));
	}
	for (pd=o.begin(); pd!=o.end(); pd++)
	{
		printf("%d\n", *pd);
	}
	system("pause");
	return 0;
}