#include<iostream>
#include<vector>
using namespace std;
//void average(int m1, int s1,int ms1,int m2,int s2,int ms2,int m3,int s3,int ms3)
//{
//	//struct result res;
//	int sum1 = m1 * 60 * 1000 + s1 * 1000 + ms1;
//	int sum2 = m2 * 60 * 1000 + s2 * 1000 + ms2;
//	int sum3 = m3 * 60 * 1000 + s3 * 1000 + ms3;
//	int ave_ms = (sum1 + sum2 + sum3) / 3;
//	res.m = ave_ms % 6000;
//	res.s= (ave_ms % 6000)%1000;
//	res.ms = (ave_ms % 6000) / 1000;
//
//};
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> res(n);
	vector<int> temp;
	vector<int>::iterator on;
	vector<vector<int>>::iterator ow;
	for (int i = 0; i <n;i++)
	{
		int m1, s1, ms1;
		int m2, s2, ms2;
		int m3, s3, ms3;
		cin >> m1 >> s1 >> ms1 >> m2 >> s2 >> ms2 >> m3 >> s3 >> ms3;
		int sum1 = m1 * 60 * 1000 + s1 * 1000 + ms1;
			int sum2 = m2 * 60 * 1000 + s2 * 1000 + ms2;
			int sum3 = m3 * 60 * 1000 + s3 * 1000 + ms3;
			int ave_ms = (sum1 + sum2 + sum3) / 3;
			res[i].push_back(ave_ms/60000);
			res[i].push_back((ave_ms % 60000)/1000);
			res[i].push_back ((ave_ms % 60000) % 1000);
	}
	for (ow = res.begin(); ow != res.end(); ow++)
	{
		temp = *ow;
		for (on = temp.begin(); on != temp.end(); on++)
			cout << *on<<' ';
		cout << endl;
	}
	return 0;
}