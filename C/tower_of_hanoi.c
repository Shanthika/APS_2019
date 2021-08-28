#include <stdio.h>
void tower(int n,char from,char to, char aux)
{
	if(n==1)
	{
		printf("Move disk from %c to %c\n",from ,to);
	}
	else
	{
		tower(n-1,from,aux,to);
		printf("Move %d from %c to %c\n",n,from ,to);
			tower(n-1,aux,to,from);
	}
}
int main()
{
	int n;
	char A,B,C;
	scanf("%d",&n);
	tower(n,'A','C','B');
}