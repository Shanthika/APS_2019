#include <stdio.h>
#include <stdlib.h>
int length(char *p)
{
	static int len=0; 
	if(*p=='\0')
		return len;
	else
	{
		p++;
		len++;
	}
	return length(p);
}
int main()
{
	char s[20];
	char *p;
	p=s;
	int len=0;
	printf("Enter string\n");
	scanf("%s",s);
	printf("LENGTH OF THE STRING IS %d\n",length(p));
}