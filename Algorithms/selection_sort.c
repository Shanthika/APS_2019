#include <stdio.h>
#include <stdlib.h>
#define N 10
 
int main()
{
	int a[N];
	for(int i=0;i<N;i++)
	{
		a[i]=20-i;
	}
	for(int i=0;i<N;i++)
		printf("%d\n",a[i]);
	int min,temp;
	for(int i=0;i<N-1;i++)
	{
		min=i;
		for(int j=i+1;j<N;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	for(int i=0;i<N;i++)
		printf("%d\n",a[i]);
}