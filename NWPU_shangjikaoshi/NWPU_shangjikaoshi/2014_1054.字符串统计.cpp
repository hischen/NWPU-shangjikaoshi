/*方法一*/
//#include<iostream>
//#include<string>
//#include<cstdio>
//#include<cstring>
//#include<stdlib.h>
//using namespace std;
//int main()
//{
//	char t;
//	int a = 0;
//	int c = 0;
//	int d = 0;
//	int b = 0;
//	//scanf_s("%s", a);
//	while ((t = getchar()) != '\n')
//	{
//		if ((t >= 'A' && t <= 'Z') || (t >= 'a' && t <= 'z'))
//		{
//			a++;
//		}
//		else if (t == ' ')
//		{
//			b++;
//		}
//		else if (t >= '0' && t <= '9')
//		{
//			c++;
//		}
//		else
//		{
//			d++;
//		}
//    }
//	//cout << a << b << c << d << endl;
//	printf("%d %d %d %d\n", a, b, c, d);
//	system("pause");
//	return  0;
//}

/*另一种实现方法：利用C标准函数库中的ctype.h来实现。具体说明可参考http://www.runoob.com/cprogramming/c-standard-library-ctype-h.html*/
/*代码如下*/

#include<cctype>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	char ch[100];
	gets_s(ch);
	int l = strlen(ch);
	int a = 0; int b = 0; int c = 0;int d = 0;
	for (int i = 0; i < l; i++)
	{
		if (isalpha(ch[i]) != 0)
			a++;
		else if (isdigit(ch[i]) != 0)
			c++;
		else if (ch[i] == ' ')
			b++;
		else(d++);
	}
	printf("%d %d %d %d\n", a, b, c, d);
	system("pause");
	return 0;
}