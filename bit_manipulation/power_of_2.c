#include <stdio.h>

int main(){
	int n;
	int result;
	scanf("%d",&n);
	result=n&(n-1);
	if(result==0) printf("%d can be expressed in powers of 2\n",n);
	else printf("%d cannot be expressed in powers of 2\n",n);
}