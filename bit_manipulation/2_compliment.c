#include <stdio.h>

int main(){
	int n;
	int result;
	printf("Enter value of n:\n");
	scanf("%d",&n);
	result = (~n)+1;
	printf("%d\n",result);
}