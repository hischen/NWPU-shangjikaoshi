#include <string.h>
#include <iostream>
using namespace std;
#define MAX 10000
#define OFFSET 1

char str1[MAX];
char str2[MAX];
int len[MAX+1][MAX+1];

int main()
{
    while (scanf("%s %s",str1,str2)!=EOF)
    {
        memset(len,0,sizeof len);
        for (int k=0;k<MAX;k++)
        {
            len[0][k] = 0;
            len[k][0] = 0;
        }
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        for (int i=0;i<len1;i++)
        {
            for (int j=0;j<len2;j++)
            {
                if (str1[i]==str2[j])
                    len[i+OFFSET][j+OFFSET] = len[i-1+OFFSET][j-1+OFFSET]+1;
                else
                    len[i+OFFSET][j+OFFSET] = len[i-1+OFFSET][j+OFFSET] > len[i+OFFSET][j-1+OFFSET] ? len[i-1+OFFSET][j+OFFSET] : len[i+OFFSET][j-1+OFFSET];
            }
        }
        cout<<len[len1][len2]<<endl;
    }
    return 0;
}

