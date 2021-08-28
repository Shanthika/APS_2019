///Slight error,incorrect output

#include <stdio.h>
#include <stdlib.h>

int w[20];
int v[20];
int V[20][20];
int value;


int max(int a,int b)
{
	if (a>b)
		return a;
	else 
		return b;
}
int knapsac(int i,int j)
{
	if(V[i][j]<0)
	{
		if(j<w[i])
			value=V[i-1][j];
		else
		{

			value=max(knapsac(i-1,j),(v[i]+knapsac(i-1,j-w[i])));
		}
		V[i][j]=value;
	}
	return V[i][j];
}

int main()
{
	int items,capacity;
	int data;
	printf("Enter the no.of items:\n");
	scanf("%d",&items);
	printf("Enter knapsac capacity:\n");
	scanf("%d",&capacity);
	for(int i=1;i<=items;i++)
	{
		printf("Enter weight of item %d:\n",i);
		scanf("%d",&w[i]);
		printf("Enter value of item %d:\n",i);
		scanf("%d",&v[i]);
	}
	for(int i=0;i<=items;i++)
		V[i][0]=0;
	for(int j=0;j<=items;j++)
		V[0][j]=0;
	for(int i=1;i<=items;i++)
	{
		for(int j=1;j<=capacity;j++)
			V[i][j]=-1;
	}
	
	data=knapsac(items,capacity);
	printf("MAX VALUE %d\n",data);
}
