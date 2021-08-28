#include <stdio.h>
#include <stdlib.h>
int largest(int n)
{
	int large;
	if(n==2)
		large=1;
	else if(n==3)
		large=7;
	else if(n==4)
		large=11;
	else if(n==5)
		large =71;
	else if(n==6)
		large=111;
	else if(n>=7)
		large= task(n);
	return large;
}
int task(int n)
{
	int large;
	if((n-3)%2==0)
		large= even(n);
	else if((n-3)%2!=0)
		large= odd(n);
	return large;

}
int even(int n)
{
	int large=7;
	n-=3;
	for(int i=0;i<(n/2);i++)
	{
		large=(large*10)+1;
	}
	return large;

}
int odd(int n)
{
	int large=77;
	n-=6;
	for(int i=0;i<(n/2);i++)
	{
		large=(large*10)+1;
	}
	return large;

}


int main()
{
	int t,n;
	int large_no,small_no;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		scanf("%d",&n);
		large_no=largest(n);
		small_no=smallest(n);

		printf("The largest no.that can be formed is %d\n",large_no);
		printf("The smallest no.that can be formed is %d\n",small_no);

	}
	return 0;
}
int smallest(int n)
{
	int small;
	small=task1(n);
	return small;
}
int task1(int n)
{
	int small;
	if(n==2)
		small=1;
	else if(n==3)
		small=7;
	else if(n==4)
		small=4;
	else if(n==5)
		small=2;
	else if(n==6)
		small=0;
	else if(n==7)
		small=8;
	else if(n>7)
		small=task2(n);
	return small;
}
int task2(int n)
{
	int small;
	if(n<=14)
	{
		if((n-2)<=7)
			small=task1(2)*10+task1(n-2);
		else if((n-5)<=7)
			small=task1(5)*10+task1(n-5);
		else if((n-7)<=7)
			small=task1(7)*10+task1(n-7);

	}
	else 
		small=task3(n);
	return small;
}
int task3(int n)
{
	int small;
	if((n-7)>7)
	{
		n-=7;
		small=8;
		small=task2(n)*10+small;
	}
	return small;
	
}
