#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;
#include <stdlib.h>  

//void ReverseWord(char *front, char *end)
//{
//	while (front<end)
//	{
//		char temp = *front;
//		*front++ = *end;
//		*end-- = temp;
//	}
//}
//
//char * Reverse(char *s)
//{
//	char *pre = s;
//	char *current = s;
//
//	while (*current != '\0')
//	{
//
//		if (*current == ' ')
//		{
//			ReverseWord(pre, current - 1);
//			current++;
//			pre = current;
//		}
//		else
//		{
//			current++;
//		}
//
//	}
//	ReverseWord(pre, current - 1);
//	ReverseWord(s, current - 1);
//	return s;
//}
//
//
//int main(int argc, char *argv[])
//{
//	char a[100]; //= "how are you ?";
//	//scanf("%s",a);
//	gets_s(a);
//	printf("Ô­Ê¼×Ö·û´®:%s\n", a);
//	printf("ÄæÐòÖ®ºóµÄ×Ö·û´®:%s\n", Reverse(a));
//	system("pause");
//	return 0;
//}

/*************************************************************************************************************/
//#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(int arc, char** argv)
{
	string str;// = "I come from liaoning.";
	getline(cin, str);
	stack<string> works;
	int len = str.length();
	while (1)
	{
		int start = str.find_first_not_of(" "); cout << start << ' ';
			int end = str.find_first_of(" "); cout << end << endl;
		int wlen = end - start; //cout << wlen<<endl;
		if (end != -1)
		{
			string temp = str.substr(start, wlen);
			works.push(temp);
		}
		else
		{
			works.push(str);
			break;
		}
		str = str.substr(end + 1, len - wlen); cout << str << endl;
	}
	while (!works.empty())
	{
		string temp = works.top();
		cout << temp << " ";
		works.pop();
	}
	cout << endl;
	system("pause");
	return 0;
}
/**********************************************************************************************************/