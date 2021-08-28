#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void read(int array[MAX],int size);
void display(int array[MAX],int size);
int main()
{
	int array[MAX],size,test;
	printf("Enter the size of the array:");
	test=scanf("%d",&size);

	if (test!=1)
	{
	printf("Enter valid input.");
	}
	else if (size<=0)
	{
		printf("Size cannot be zero or negative.");
	}
	
	else if (size>100)
	{
		printf("Number of elements should be less tha 100.");
	}
	else
	{
		read(array,size);
		display(array,size);
	}
}
void read(int array[MAX],int size)
{
	int i,test;
	for (i=0;i<size;i++)
	{
		printf("array[%d]:",i);
		test=scanf("%d",&array[i]);
		
		if (test!=1)
		{
			printf("Enter valid data.");
		}
	}
}
void display(int array[MAX],int size)
{
	int i;
	for (i=0;i<size;i++)
	{
		printf("%d\t",array[i]);
	}
}
