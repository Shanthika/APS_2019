#include<stdio.h>
int main()
{
	float radius;
	double area, circumference;
	printf("Enter the radius of the circle:");
	scanf("%f",&radius);

	area = 3.14 * radius * radius;
	circumference = 2 * 3.14 * radius;
	printf("\n Area = %.2f",area);
	printf("\n Circumference = %.2e", circumference);
	return 0;
}
