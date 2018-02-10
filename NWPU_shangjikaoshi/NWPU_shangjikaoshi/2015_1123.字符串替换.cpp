/*示例代码1*/
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string a, b, c,d;
//	cin >> a;
//	cin >> b;
//	cin >> c;
//	int n=a.find_first_of(b);
//	if (a.find_first_of(b) < size(a))
//	{
//		if (n != string::npos)
//			//删除指定索引開始的指定长度的字符
//			 a.erase(n, b.length()) ;
//		a.insert(n, c);
//	}
//	//int index = a.find(b);
//	cout << a;
//	system("pause");
//	return 0;
//}

/*示例代码2*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b, c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	int n = a.find_first_of(b);
	if (a.find_first_of(b) < size(a))
	{
		a.replace(n, size(b), c);
	}
	cout << a;
	system("pause");
	return 0;
}

/*String使用方法*/
//#include <iostream>  
//#include <string>  
//using std::cout;
//using std::endl;
//using std::string;
//int main(void) {
//	string str1 = "We can insert a string";
//	string str2 = "a str into ";
	////在字符串指定位置前面插入指定字符串  
	//cout << str1.insert(14, str2) << endl;
	////在字符串指定位置前面插入指定字符串的子串（从指定索引开始的指定个数的字符）  
	//cout << str1.insert(14, str2, 2, 9) << endl;
	////插入指定字符串的前n个字符  
	//cout << str1.insert(14, "test hello", 5) << endl;
	////插入n个相同字符到字符串中  
	//cout << str1.insert(14, 6, '*') << endl;

	////替换指定索引开始的指定长度的子串  
	//cout << str1.replace(3, 3, "may") << endl;
	//用给定字符串的指定子串来进行替换  
	//如下，实际上使用的是could来进行替换  
//	cout << str1.replace(3, 3, "can could", 4, 5) << endl;
//	//使用给定字符串的前n个字符来进行替换：can  
//	cout << str1.replace(3, 5, "can could", 3) << endl;
//	//使用指定个数的重复字符来进行替换  
//	cout << str1.replace(3, 3, 5, '*') << endl;
//
//	string word = "We";
//	size_t index = str1.find(word);
//	if (index != string::npos)
//		//删除指定索引开始的指定长度的字符  
//		cout << str1.erase(index, word.length()) << endl;
//	system("pause");
//	return 0;
//
//}

