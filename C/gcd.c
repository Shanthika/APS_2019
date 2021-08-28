#include <stdio.h>
int gcd(int m,int n)
{
	int r;
	if(n==0)
		return m;
	else
	{
		r=m%n;
		m=n;
		n=r;
		return gcd(m,n);
	}
}
int main()
{
	int m,n,r;
	scanf("%d%d",&m,&n);
	r=gcd(m,n);
	printf("%d\n",r);
}