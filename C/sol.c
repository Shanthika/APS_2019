#include<stdio.h>
     
int main()
{
    long  num;

    task:
    	scanf("%ld",&num);
    	

    if(num!=42)
    {
    	printf("%ld\n",num);
    	goto task;
    }
    
}
