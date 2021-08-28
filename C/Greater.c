#include<stdio.h>
int main()
{
	int num1, num2, large;
	printf("Enter the two numbers:");
	scanf(" %d %d", &num1,&num2);
	
	large = num1 > num2? num1 : num2;
	printf("\n The larger number is:%d", large);
	return 0;
}

-----------------------------------------------------------------------------
#include<stdio.h>
int main()
{
	int num1,num2,num3;
	printf("enter three numbers:");
	scanf("%d %d %d",&num1,&num2,&num3);

	if (num1>num2 && num1>num3)
		printf("%d is greater",num1);
	else if (num2>num3)
		printf("%d is greater",num2);
	else
		printf("%d is greater",num3);
	return 0;
}
	
