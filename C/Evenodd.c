#include<stdio.h>
int main()
{
	int num,rem;
	printf("Enter any number:");
	scanf("%d",&num);

	rem = num % 2;

	switch (rem)
	{
	case 0:
		printf("EVEN");
		break;
	case 1:
		printf("ODD");
		break;
	}
	return 0;
}
