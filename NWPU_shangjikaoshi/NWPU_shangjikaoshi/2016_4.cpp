#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
float Heron(int x, int y, int z)
{
	float p = (x + y + z) / 2;
	if (x + y < z || x + z < y || y + z<x || x - y>z || y - x>z || x - z>y || z - x > y || z - y > x || y - z > x)
		return(0.00);
	else
	{
		return sqrt(p*(p - x)*(p - y)*(p - z));
	}
}

int main()
{
	int n;
	cin >> n;
	vector<float> result(n);
	vector<float>::iterator pt;
	for (int i = 0; i < n; i++)
	{
		int x, y, z, s;
		cin >> x >> y >> z;
		result[i] = Heron(x, y, z);
	}
	for (pt=result.begin(); pt!=result.end(); pt++)
	{
		cout << fixed << setprecision(2) << *pt<<endl;
	}
	return  0;
}