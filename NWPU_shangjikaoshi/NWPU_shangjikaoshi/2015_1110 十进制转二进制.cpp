#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int main()
{


		int n;
		vector<char> res;
		vector<char>::iterator pd;
		cin >> n;
		while (n / 2 > 0)
		{
			/*if (n / 2 = 0)
			{
				break;
			};*/
			char temp;
			//itoa(n % 2,res,2);
			temp = char(n % 2 + 48);
			res.push_back(temp);
			n = n / 2;
		}
		res.push_back(char(n + 48));
		reverse(res.begin(), res.end());



		for (pd = res.begin(); pd != res.end(); pd++)
			cout << *pd;

		//getchar();
		//getchar();
	
		return 0;
	
}