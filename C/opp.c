#include<stdio.h>
int main()
{
	int num1,num2,opp;
	printf("Enter two numbers:");
	scanf("%d%d",&num1,&num2);

	printf("Enter the number of the opperation to be performed:\n1.Add\n2.subtract\n3.multiply\n4.division\n5.modulodivision:\n");
	scanf("%d",&opp);

	switch(opp)
	{
		case 1:
			printf("Sum is:%d",num1+num2);
			break;
		case 2:
			printf("Difference is:%d",num1-num2);
			break;
		case 3:
			printf("Product is:%d",num1*num2);
			break;
		case 4:
			printf("Division is:%d",num1/num2);
			break;
		default:
			printf("Modulo division is:%d",num1%num2);
	}
}
