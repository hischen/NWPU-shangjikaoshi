#include<iostream>
using namespace std;
//函数功能: 计算Catalan数列的第n项  
//函数参数: 项数n  
//返回值:   第n个Catalan数  
//long Catalan(int n)
//{
//	if (n <= 1)
//		return 1;
//	long *h = new long[n + 1]; //保存临时结果  
//	h[0] = h[1] = 1;        //h(0)和h(1)  
//	for (int i = 2; i <= n; i++)    //依次计算h(2),h(3)...h(n)  
//	{
//		h[i] = 0;
//		for (int j = 0; j < i; j++) //根据递归式计算 h(i)= h(0)*h(i-1)+h(1)*h(i-2) + ... + h(i-1)h(0)  
//			h[i] += (h[j] * h[i - 1 - j]);
//	}
//	long result = h[n]; //保存结果  
//	delete[] h;       //注意释放空间  
//	return result;
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cout << Catalan(n)<<endl;
//	}
//	return 0;
//}
#include <iostream>
using namespace std;
//卡特兰数列原理及应用
int catalan(int n) {

	if (n == 1)return 1;
	if (n == 2)return 1;
	int res = 0;
	for (int i = 1; i <= n - 1; i++) {
		res =res+ catalan(i)*catalan(n - i);
	}
	return res;

}
//测试函数
int main() {
	int n;
	while (cin >> n) {

		cout << catalan(n) << endl;
	}
	return 0;
}