#include <stdio.h>

int main(){
	int n;
	printf("Enter value of n:\n");
	scanf("%d",&n);
	if((n&1)==0)printf("%d is even.\n",n);
	else printf("%d is odd.\n",n);
}