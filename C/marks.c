#include<stdio.h>
int main()
{
	int marks;
	printf("Enter the marks obtained:");
	scanf("%d",&marks);

	if (marks>=75)
		printf("Distinction");
	else if (marks<75 && marks>=60)	
		printf("First class");
	else if (marks<60 && marks>=50)
		printf("Second class");
	else if (marks<50 && marks>=35)
		printf("Third class");
	else 
		printf("Fail");
	return 0;
}
