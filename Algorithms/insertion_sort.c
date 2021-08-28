#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int main()
{
	int j=0,v;
	int a[SIZE];
	for(int i=0;i<SIZE;i++)
		a[i]=20+i;
	//Increasing order.
	for(int i=1;i<SIZE;i++)
	{
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
	}
	//Decreasing order.
	/*for(int i=(SIZE-1);i>=0;i--)
	{
		v=a[i];
		j=i+1;
		while(j<SIZE && a[j]>v)
		{
			a[j-1]=a[j];
			j++;
		}
		a[j-1]=v;
	}*/
	for(int i=0;i<SIZE;i++)
		printf("%d\n",a[i]);
		

}