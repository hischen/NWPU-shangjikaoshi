#include <stdio.h>
int count[10];
int main()
{
	int n,i,j,k,p;
	scanf("%d",&n);
	if(n<10)
	{
		k=n%10;
		for(i=1;i<=k;i++)
			count[i]++;
	}
	else if(n>=10&&n<100)
	{
		j=n/10;
		k=n%10;
		for(i=0;i<10;i++)//个位
			count[i]+=j;
		count[0]-=1;
		for(i=0;i<=k;i++)//个位
			count[i]++;
		for(i=1;i<j;i++)//十位
			count[i]+=10;
		count[j]+=k+1;//十位
	}
	else if(n>=100&&n<1000)
	{
		p=n/100;         //百位
		j=(n-p*100)/10;  //十位
		k=n%10;          //个位
		//0-99:0出现9次，其余出现20次
		//00-99:0-9均出现20次
		//计算出现百位的情况
		for(i=0;i<10;i++)
			count[i]+=p*20;
		count[0]-=11;
		for(i=1;i<p;i++)
			count[i]+=100;
		count[p]+=j*10+k+1;
		//再计算十位和个位
		for(i=0;i<10;i++)//个位
			count[i]+=j;
		for(i=0;i<=k;i++)//个位
			count[i]++;
		for(i=0;i<j;i++)//十位
			count[i]+=10;
		count[j]+=k+1;//十位 
	}
	else
	{
		for(i=1;i<10;i++)
			count[i]+=300;
		count[0]+=192;
		count[1]++;
	}
	for(i=0;i<10;i++)
		printf("%d\n",count[i]);
	return 0;
}