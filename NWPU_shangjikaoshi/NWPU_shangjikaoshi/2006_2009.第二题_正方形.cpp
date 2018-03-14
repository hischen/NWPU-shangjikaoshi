#include<fstream>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
double jl(int x1, int x2,int y1,int y2)
{
	double d = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	return d;
}
int main()
{
	fstream ceshi;
	ceshi.open("D:\\Github\\NWPU-shangjikaoshi\\NWPU_shangjikaoshi\\NWPU_shangjikaoshi\\test2.txt");
	struct zb
	{
		int x,y;
	}zb[5];
	int n;
	double juli[6];
	ceshi >> n;
	while (n--)
	{
		ceshi >> zb[1].x;
		ceshi >> zb[1].y;
		ceshi >> zb[2].x;
		ceshi >> zb[2].y;
		ceshi >> zb[3].x;
		ceshi >> zb[3].y;
		ceshi >> zb[4].x;
		ceshi >> zb[4].y;
		juli[0] = jl(zb[1].x, zb[2].x, zb[1].y, zb[2].y);
		juli[1] = jl(zb[1].x, zb[3].x, zb[1].y, zb[3].y);
		juli[2] = jl(zb[1].x, zb[4].x, zb[1].y, zb[4].y);
		juli[3] = jl(zb[2].x, zb[4].x, zb[2].y, zb[4].y);
		juli[4] = jl(zb[2].x, zb[3].x, zb[2].y, zb[3].y);
		juli[5] = jl(zb[3].x, zb[4].x, zb[3].y, zb[4].y);
		sort(juli, juli + 6);
		if (juli[0] == juli[1]&&juli[1] == juli[2]&&juli[2] == juli[3] && juli[4] == juli[5] && juli[5] == 2*juli[0])
			cout << "Yes"<<endl;
		else cout << "N0"<<endl;
	}
	ceshi.close();
	system("pause");
	return 0;
}