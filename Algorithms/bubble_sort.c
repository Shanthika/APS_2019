#include <stdio.h>
#define N 10
void insertion_sort(int a[])
{
	int temp;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}

	}
	for(int i=0;i<N;i++)
		printf("%d\n",a[i]);
}
int main()
{
	int a[N];
	for(int i=0;i<N;i++)
		a[i]=rand()%50;
	for(int i=0;i<N;i++)
		printf("%d\n",a[i]);
	insertion_sort(a);
}