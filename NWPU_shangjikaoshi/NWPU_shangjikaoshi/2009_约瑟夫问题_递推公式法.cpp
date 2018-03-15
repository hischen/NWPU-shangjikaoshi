/*约瑟夫问题满足这个公式f[i] = (f[i - 1] + m) % i; */
#include<iostream>
using namespace std;
int main()
{
	int n;
	int k;
	cin >> n >> k;
	if (n == 0 && k== 0) return 0;
	int m = 0;
	for (int i = 1; i <= n; i++)
	{
		m = (m + k) % i;
	}
	cout << endl;
	cout << m + 1<<endl;
	system("pause");
	return 0;
}