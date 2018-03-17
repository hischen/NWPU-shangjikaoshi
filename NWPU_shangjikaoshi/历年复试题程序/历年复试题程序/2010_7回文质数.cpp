#include<stdio.h>
#include<math.h>
int isPrime(int n)
{
    int i,k;
    k=sqrt(n);
    for(i=2;i<=k;i++)
        if(n%i==0)
           return 0;
	return 1;
}
int main()
{
    int a,b,num[4]={1,3,7,9},c[100000]={5,7,11},n;
    int k=3,i,i1,i2,i3;
    for(i=0;i<4;i++)
        for(i1=0;i1<=9;i1++)
        {
            n=num[i]*100+i1*10+num[i];
            if(isPrime(n)) c[k++]=n;
        }
    for(i=0;i<4;i++)
        for(i1=0;i1<=9;i1++)
            for(i2=0;i2<=9;i2++)
            {
                n=num[i]*10000+i1*1000+i2*100+i1*10+num[i];
                if(isPrime(n)) c[k++]=n;
            }
    for(i=0;i<4;i++)
        for(i1=0;i1<=9;i1++)
            for(i2=0;i2<=9;i2++)
                for(i3=0;i3<=9;i3++)
                {
                    n=num[i]*1000000+i1*100000+i2*10000+i3*1000+i2*100+i1*10+num[i];
                    if(isPrime(n)) c[k++]=n;
                }
	scanf("%d%d",&a,&b);
    for(i=0;i<k;i++)
    {
		if(c[i]>=a&&c[i]<=b)
			printf("%d\n",c[i]);
    }
    return 0;
}