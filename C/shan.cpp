#include<stdio.h>
int main()
{
	int num,rem,test;
	scanf("%d",&test);
	scanf("%d",&num);
	while(num>0)
	{
		rem = num%10;
		num/=10;
		printf("%d",num);
	}
	printf("\n");
}
