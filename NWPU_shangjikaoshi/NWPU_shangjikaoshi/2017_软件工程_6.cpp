#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<string>
#include <cctype> 
using namespace std;
int main()
{
	fstream danci;
	danci.open("D:\\Github\\NWPU-shangjikaoshi\\NWPU_shangjikaoshi\\NWPU_shangjikaoshi\\软件工程2017_6.txt");
	string s1,s2,s,s3;
	int num=0;
	cin>>s3;
	transform(s3.begin(), s3.end(), back_inserter(s1), ::toupper);
	transform(s3.begin(), s3.end(), back_inserter(s2), ::tolower);
	//cout << s1 <<"  "<< s2<<endl;
	while (danci >> s)
	{
		if (s == s1 || s == s2)
			num++;
	}
	cout << num<<endl;
	danci.close();
	system("pause");
	return 0;
}

/************************************************************/
/*
char*strupr(char *string)

功能：将字符串string中的小写字母转换为大写，并返回指向string的指针。

char*strlwr(char *string)

功能：将字符串string中的大写字母转换为小写，并返回指向string的指针。





#include<iostream>  
#include<string.h>  
#include <string>  
using namespace std;
void main(void)
{
	char *p;
	std::string  m("Design and implementation of the remote location robot and control system ");
	p = strupr((char *)m.c_str());
	cout << p << "      " << m << endl;
	std::string n("DFGRADGHHEVGV");
	p = strlwr((char*)n.c_str());
	cout << p << "    " << n << endl;
	getchar();
}
/********************************************************************************/