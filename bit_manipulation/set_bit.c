#include <stdio.h>

int main(){
	int n;
	int k;
	int result;

	printf("Enter value of n:\n");
	scanf("%d",&n);
	k=n;
	result=0;
	while(n){
		result+=1;
		n=n&(n-1);

	}
	printf("Number of set bits in %d is %d\n",k,result);
}