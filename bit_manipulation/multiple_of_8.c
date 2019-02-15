#include <stdio.h>

int main(){
	int n;
	int result;
	printf("Enter value of n:\n");
	scanf("%d",&n);

	result=n;
	result=(result>>3)<<3;
	if(result==n) printf("%d is multiple of 8\n",n);
	else printf("%d is not a multiple of 8\n",n);
}