#include<stdio.h>
#include<math.h>
void getnum(int);
int main()
{
	int n;
	printf("Enter the value upto which number is to be displayed:");
	scanf("%d",&n);

	getnum(n);
}
void getnum(int n)
{
	int i=2,flag=0;
	while(i<=sqrt(n))
	{
		if (n%i==0)
		{
			flag=1;
		}
	i++;
	}
	if (flag == 0)
	{
		printf(" prime");
	}
	else
	{
		printf(" not Prime");
	}
}	
