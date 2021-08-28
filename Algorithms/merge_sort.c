#include <stdio.h>
#include <stdlib.h>
#define N 10
void copy(int a[],int b[],int c[],int n)
{
	int i;
	for(i=0;i<ceil(n/2);i++)
		b[i]=a[i];
	for(;i<n;i++)
		c[i]=a[i];

}
void merge_sort(a)
{
	static int n=N;
	int b[N],c[N];
	if(n>1)
	{
		copy(a,b,c,n);
		merge_sort(b);
		merge_sort(c);
		merge(b,c,a);

	}
}
void merge(b,c,a)
{
	int i=0,j=0,k=0;
	while()
}
int main()
{
	int a[N];
	for(int i=0;i<N;i++)
		a[i]=rand()%50;
	merge_sort(a);
}