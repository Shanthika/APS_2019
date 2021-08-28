#include<stdio.h>
int getperfect(int);
int main()
{
	int num,SUM=0;
	printf("Enter the number:");
	scanf("%d",&num);

	if (num<0)
	{
		exit(0);
	}
	
	SUM = getperfect(num);

	if (SUM==num)
	{
		printf("%d is a perfect number.",num);
	}
	else
	{
		printf("%d is not a perfect number",num);
	}
}
int getperfect(int num)
{
	int i=1,sum=0;
	while(i<num)
	{
		if (num%i==0)
		{
			sum+=i;
		}
		i++;
	}
	return sum;
}
