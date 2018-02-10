/*示例代码1*/
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	string s;
	getline(cin,s,'\n');
	int j=0;
	int n = s.length();
	//cout << n<<endl;
	//cout << s[n-1];
	for (int i = 0; i < n; i++)
	{
		//cout << s[i];
		if (s[i]==' ')
		{
			j++;
		}
	}
	cout << j << endl;
	cout << j;
	system("pause");
	return  0;
}


/*示例代码2*/
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char s[10000];
//	gets_s(s);
//	int j = 0;
//	for (int i = 0; s[i] != '\0'; i++)
//	{
//		if (s[i] == ' ')
//			j++;
//	}
//	printf("%d", j);
//	system("pause");
//	return 0;
//}