#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
//vector<int> run(vector<int> s)
//{
//	sort(s.begin(), s.end());
//	return s;
//}
int main()
{
	int n;
	cin >> n;
	int m = n;
	vector<int>::iterator pd;
	vector<vector<int>>::iterator iter;
	vector<int> vec_tmp;
	vector<vector<int>> output(n);
	for (int k = 0; k < n; k++)
	{
		vector<int> s;
		int temp;
		while (scanf_s("%d", &temp))//(cin>>temp&&temp!=EOF)
		{
			s.push_back(temp);

			if (getchar() == '\n')
				break;
		};
		//vector<int> run(vector<int> s);
		sort(s.begin(), s.end());
		for (pd = s.begin(); pd != s.end(); pd++)
		{
			output[k].push_back(*pd);
			//cout << *pd<<' ';
		}
		//output.push_back(vector<int>(s));
		//n--;
	}
	for (iter = output.begin(); iter != output.end(); iter++)
	{
		vec_tmp = *iter;
		for (pd = vec_tmp.begin(); pd != vec_tmp.end(); pd++)
			cout << *pd << " ";
		cout << endl;
	}
	/*for (int i = 0; i < output.size(); i++)
	{
		for (int j = 0; j < output[0].size(); j++)
			cout << output[i][j] << " ";
		cout << endl;
	}*/
	//getchar();
	return 0;
}































//int main()
//{
//	int n;
//	cin >> n;
//	if (n==2)                                                        //for (int i = 0; i < n; i++)
//	{
//
//		vector<int> s1;
//		vector<int> s2;
//		vector<int>::iterator pd;
//		vector<int>::iterator pt;
//		int temp1;
//		while (scanf_s("%d", &temp1))//(cin>>temp&&temp!=EOF)
//		{
//			s1.push_back(temp1);
//
//			if (getchar() == '\n')
//				break;
//		};
//		sort(s1.begin(), s1.end());
//		int temp2;
//		while (scanf_s("%d", &temp2))//(cin>>temp&&temp!=EOF)
//		{
//			s2.push_back(temp2);
//
//			if (getchar() == '\n')
//				break;
//		};
//		sort(s2.begin(), s2.end());
//
//		for (pd = s1.begin(); pd != s1.end(); pd++)
//		{
//			cout << *pd << " ";
//		};
//		cout << endl;
//		for (pt = s2.begin(); pt != s2.end(); pt++)
//		{
//			cout << *pt << " ";
//		};
//		
//	}
//	
//	return 0;
//}



























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
