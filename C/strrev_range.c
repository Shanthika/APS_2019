#include <stdio.h>
int main()
{
	char s[20];
	int length=0;
	int m,n;
	printf("Enter the string\n");
	scanf("%s",s);
	printf("Enter range\n");
	scanf("%d%d",&m,&n);
	char *p,*p1,*p2;
	char temp;
	p=s;
	while(length!=(m-1))
	{
		p++;
		length++;
	}
	p1=p;
	p2=s+n-1;
	
	for(int i=m;i<((m+n)/2);i++)
	{
		temp=*p1;
		*p1=*p2;
		*p2=temp;
		p1++;
		p2--;
	}

	printf("REVERSE %s\n",s);
}