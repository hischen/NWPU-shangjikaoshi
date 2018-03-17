#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i,n,sum,max;
	string s;
	cin>>s;
	for(i=0,n=0,sum=0,max=0;i<s.length();i++,sum++)
		if(s[i]==','||s[i]=='.') 
		{
			if(sum>max) max=sum;
			n++;
			sum=-1;
		}
	for(i=0;i<n;i++)
	{
		char* c=(char*)malloc((max+1)*sizeof(char));
		for(j=0,m=0;j<s.length();j++,m++)
		{
			*c[m]=s[j];
			if(s[i]==','||s[i]=='.')
			{
				m=0;
			}
		}
	}

	cout<<s.length()<<endl;
	cout<<n<<endl;
	cout<<max<<endl;
	return 0;
}