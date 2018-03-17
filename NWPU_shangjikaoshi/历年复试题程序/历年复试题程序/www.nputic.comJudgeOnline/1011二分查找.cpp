#include <iostream>
#include <vector>
using namespace std;
vector<int> a,k;
int search_binary(int low,int high,int key)
{
	int mid;
	if(low>high) return 0;
	else
	{
		mid=low+(high-low)/2;
		if(a[mid]==key) return 1;
		else if(a[mid]>key)
			search_binary(low,mid-1,key);
		else search_binary(mid+1,high,key);
	}
}
int main()
{
	int i,n,num,m,key;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cin>>m;
		a.push_back(m);
	}
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		cin>>key;
		k.push_back(key);
	}
	for(i=0;i<num;i++)
	{
		if(search_binary(0,n-1,k[i]))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}