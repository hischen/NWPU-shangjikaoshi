/********************************************************************************************************/
/*给定两个字符串S1和S2，合并成一个新的字符串S。
合并规则为，S1的第一个字符为S的第一个字符，将S2的最后一个字符作为S的第二个字符；
将S1的第二个字符作为S的第三个字符，将S2的倒数第二个字符作为S的第四个字符，以此类推。

输入：
包含多组测试数据，每组测试数据包含两行，代表长度相等的两个字符串S1和S2（仅由小写字母组成，长度不超过100）。

输出：
合并后的新字符串S

样例输入：
abc
def
样例输出：
afbecd
/*********************************************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

//string a, b;
//int main()
//{
//	int i, n;
//	while (cin >> a >> b)
//	{
//		n = a.length();
//		for (i = 0; i<n; i++)
//			cout << a[i] << b[n - 1 - i];
//		cout << endl;
//	}
//	return 0;
//}


/*********************************************************************************/
//int main() {
//	int i, j, len1, len2, k;
//	char S1[101], S2[101], S[250];
//	while (scanf("%s", S1) != EOF) {
//		//输入  
//		scanf("%s", S2);
//		len1 = strlen(S1);
//		len2 = strlen(S2);
//		k = 0;
//		for (i = 0, j = len2 - 1; i < len1 || j >= 0;) {
//			if (i < len1) {
//				S[k++] = S1[i++];
//			}
//			if (j >= 0) {
//				S[k++] = S2[j--];
//			}
//		}
//		//输出  
//		for (i = 0; i < len1 + len2; i++) {
//			printf("%c", S[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
/****************************************************************************************/
//int main()
//{
//	string s1, s2;
//	string s;
//	int i, j;
//	
//	while (cin >> s1>>s2)
//	{
//		reverse(s2.begin(), s2.end());
//		size_t l=s1.size();
//		for (i = 0; i < l; i++)
//		{
//			s = s + s1[i];
//			s = s + s2[i];
//		}
//		cout << s<<endl;
//		s.clear();
//	}
//	return 0;
//}
/*********************************************************************************************/
int main()
{
	char s1[100], s2[100]; char s[200];
	while (scanf("%s%s", &s1,&s2) != EOF)
	{
		size_t l = strlen(s1);
		int k = 0;
		int i = 0, j = l - 1;
		while(i < l&&j>=0)
		{
			s[k++] = s1[i++];
			s[k++] = s2[j--];
		}
		for (i = 0; i < k; i++)
		{
			printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}