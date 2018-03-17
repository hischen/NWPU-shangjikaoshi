#include <iostream>
#include <vector>
using namespace std;
vector<int> a,b;
void merge(int left,int i,int right)
{
	int p=left,q=i+1;
	int ori_left=left;
	int j;
	while(left<=i&&q<=right)
	{
		if(a[left]<a[q]) b[p++]=a[left++];
		else b[p++]=a[q++];
	}
	while(left<=i) b[p++]=a[left++];
	while(q<=right) b[p++]=a[q++];
	for(j=ori_left;j<=right;++j)
		a[j]=b[j];
}
void mergesort(int low,int high)
{
	int i;
	i=low+(high-low)/2;
	if(low<high)
	{
		mergesort(low,i);
		mergesort(i+1,high);
		merge(low,i,high);
	}
}
int main()
{
	int i,m,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>m;
		a.push_back(m);
	}
	b.reserve(a.size());
	mergesort(0,n-1);
	for(i=0;i<n;i++)
		cout<<a[i]<<endl;
	return 0;
}