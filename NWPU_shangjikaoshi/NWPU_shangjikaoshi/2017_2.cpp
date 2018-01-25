#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n==2)                                                        //for (int i = 0; i < n; i++)
	{

		vector<int> s1;
		vector<int> s2;
		vector<int>::iterator pd;
		vector<int>::iterator pt;
		int temp1;
		while (scanf_s("%d", &temp1))//(cin>>temp&&temp!=EOF)
		{
			s1.push_back(temp1);

			if (getchar() == '\n')
				break;
		};
		sort(s1.begin(), s1.end());
		int temp2;
		while (scanf_s("%d", &temp2))//(cin>>temp&&temp!=EOF)
		{
			s2.push_back(temp2);

			if (getchar() == '\n')
				break;
		};
		sort(s2.begin(), s2.end());

		for (pd = s1.begin(); pd != s1.end(); pd++)
		{
			cout << *pd << " ";
		};
		cout << endl;
		for (pt = s2.begin(); pt != s2.end(); pt++)
		{
			cout << *pt << " ";
		};
		
	}
	
	return 0;
}



























/*
	vector<int> s1;
	vector<int> s2;

	vector<int>::iterator pd;

	int temp;
	while (cin >> temp)
		s1.push_back(temp);

	//cout << s1.size()<<endl;
	/*for (pd = s1.begin(); pd != s1.end(); pd++)
	{
		cout << *pd << " ";
	}

// cout << endl;

	sort(s1.begin(),s1.end());
	for (pd = s1.begin(); pd != s1.end(); pd++)
		cout << *pd << " ";

	return 0;
	
}
*/
