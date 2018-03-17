#include <iostream>  

using namespace std;

int status[1010];

void Search()
{
	//花生米数量小于10时，双方只能取1粒或者5粒  
	//在这种情况下，取一粒或者五粒的效果一样  
	//若先取，则始终取到奇数，否则，始终取到偶数  
	//显然，如果有i粒，偶数个，先取赢，奇数个，后取赢，  
	for (int i = 1; i < 10; i++)
	{
		if (i % 2 == 0)
			status[i] = 1;
		else
			status[i] = 0;
	}
	//花生米数量等于10时，同样先取1粒或者5粒  
	status[10] = 1;

	for (int i = 11; i <= 1000; i++)
	{
		//考虑i-1， i-5， i-10粒花生米  
		//如果这些数目的花生米情况，Jerry先取赢  
		//i-1， i-5， i-10粒花生米，Tom都可以取一粒，五粒或者十粒，最后一个取的就是Jerry了  
		//所以，Jerry应该后取  
		if (status[i - 1] == 1 && status[i - 5] == 1 && status[i - 10] == 1)
			status[i] = 0;
		//如果这些数目的花生米情况，存在Jerry先取输的  
		//假设i-1粒Jerry输，Jerry可以取了最后一粒，就会留下一粒给Tom从而胜利  
		//其他情况雷同  
		else
			status[i] = 1;

	}
}

int main()
{
	Search();
	int n;
	while (cin >> n && n)
		cout << status[n] << endl;
}