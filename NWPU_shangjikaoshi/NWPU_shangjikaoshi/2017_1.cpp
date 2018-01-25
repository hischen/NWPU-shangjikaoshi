#include<iostream>
using namespace std;

int main()
{
	int t1_h, t1_m, t1_s;
	int t2_h, t2_m, t2_s;
	cout << "请输入时间1:" << endl;
	cin >> t1_h >> t1_m >> t1_s;
	cout << "请输入时间2:" << endl;
	cin >> t2_h >> t2_m >> t2_s;

	int sum, sum1_s, sum2_s;
	sum1_s = t1_h * 3600 + t1_m * 60 + t1_s;
	sum2_s = t2_h * 3600 + t2_m * 60 + t2_s;
	sum = (sum1_s + sum2_s) / 2;
	//cout << sum<<endl;

	int h, r_s, m, s;
	h = sum / 3600; r_s = sum % 3600;
	//	cout << h <<endl<< r_s;
	m = r_s / 60; s = r_s % 60;
	cout << h << " " << m << " " << s;

	//getchar();
	//getchar();
	return 0;



}