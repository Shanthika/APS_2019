#include<stdio.h>
int main()
{
	char gender;
	float age,no_of_stages,rate =0, discount=0;
	
	printf("\nEnter the gender:");
	scanf("%c",&gender);
	printf("\nEnter the age:");
	scanf("%f",&age);
	printf("\nEnter the number of stations:");
	scanf("%f",&no_of_stages);

	if (no_of_stages<=5)
		discount = 0;
	else
		discount =  0.05 * 8 * no_of_stages;
	if (gender == 'm')
	{
		if (age<18)
			discount += 0.15*8*no_of_stages;
		else if (age>=18 && age<=60)
			discount += 8 * no_of_stages;
		else
			discount += 0.3 * 8 * no_of_stages;
	}
	
	else if (gender== 'f')
	{
		if (age<18)
			discount += 0.2*8*no_of_stages;
		else if (age>=18 && age<=60)
			discount += 8 * no_of_stages;
		else
			discount += 0.35 * 8 * no_of_stages;
	}

	rate = (8 * no_of_stages) - discount;
	printf("\nrate = %f", rate);

	return 0;
}

