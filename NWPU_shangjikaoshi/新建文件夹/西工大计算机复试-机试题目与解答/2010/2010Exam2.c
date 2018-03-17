//×ÖÄ¸×ª»»

#include <stdio.h>
#define MAX 100

void main()
{
	char str[MAX], ch;
	int i = 0, len;
	
	ch = getchar();
	while(ch != '\n')
	{
		str[i] = ch;
		i++;
		ch = getchar();
	}
	len = i;
	
	for(i = 0; i < len; i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32; 
		else if(str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32; 
	}

	for(i = 0; i < len; i++)
		printf("%c", str[i]);

}
