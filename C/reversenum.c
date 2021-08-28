#include<stdio.h>
void getrev(int);
int main()
{
	int num;
	printf("Enter a number:");
	scanf("%d",&num);
	
	getrev(num);
}
void getrev(int num)
{
	int i=1,rem=0,rev=0;
	while(num>0)
	{
		rem = num%10;
		rev = rev*10+rem;
		num/=10;
		i++;
	}
	printf("The reverse form of the number is:%d",rev);
}
