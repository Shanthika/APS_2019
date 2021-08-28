#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void read(int a[MAX][MAX],int rows,int cols);
void display(int a[MAX][MAX],int rows,int cols);
main()
{
	int a[MAX][MAX],cols,rows,test=0;
	printf("Enter the number of rows and columns in the matrix:");
	test=scanf("%d%d",&rows,&cols);

	if (test!=2)
	{
		printf("Enter valid data.\n");
	}
	
	else if (rows<=0 || cols<=0)
	{
		printf ("Number of rows and columns cannot be negative or zero.\n");
	}
	
	else if (rows>100 || cols>100)
	{
		printf("Order of matrix should be less than or equal to 100.\n");
	}
	
	else
	{

	read(a,rows,cols);
	display(a,rows,cols);

	}
}


void read(int a[MAX][MAX],int rows,int cols)
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			printf("A[%d][%d]=",i,j);
			scanf ("%d",&a[i][j]);
		}
	}
}

void display(int a[MAX][MAX],int rows,int cols)
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
