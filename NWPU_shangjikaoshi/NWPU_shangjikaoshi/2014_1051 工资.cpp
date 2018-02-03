#include<iostream>
using namespace std;
int add_salary(int year,int wage)
{		
	if (year>=20)
	{
		if (wage > 2000)
			return 200;
		else return 180;
	}
	else
	{
		if (wage > 1500)
			return 150;
		else return 120;
	}
}
int main()
{
	int year, wage;
	cin >> year >> wage;
	cout<<wage+add_salary(year,wage)<<endl;
	//cin.get();
	//cin.get();
	return 0;
}