#include<stdio.h>
int main()
{
	int num1,num2;
	int add_res=0, sub_res=0, mul_res=0, idiv_res=0, modiv_res=0;
	float fdiv_res=0;
	printf("\n Enter the first number:");
	scanf("%d", &num1);
	printf("\n Enter the second number:");
	scanf("%d",&num2);

	add_res = num1 + num2;
	sub_res = num1 - num2;
	mul_res = num1 * num2;
	idiv_res = num1 / num2;
	modiv_res= num1 % num2;
	fdiv_res =(float) num1 / num2;

	printf("\n %d + %d = %d",num1,num2,add_res);
	printf("\n %d - %d = %d",num1,num2,sub_res);
	printf("\n %d * %d = %d",num1,num2,mul_res);
	printf("\n %d / %d = %d",num1,num2,idiv_res);
	printf("\n %d %% %d = %d", num1,num2,modiv_res);
	printf("\n %d / %d = %.4f",num1,num2,fdiv_res);
	return 0;
}
