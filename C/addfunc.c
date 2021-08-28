#include<stdio.h>
int sum(int a, int b)
{
	return printf("%*c%*c",a,'\r',b,'\r');
	
}

int main()
{
	int add=0;
	add=sum(4,5);
	printf("%d\n",add);
}