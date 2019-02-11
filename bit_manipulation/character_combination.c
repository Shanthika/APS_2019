/*
Code to generate subsets of charaters in given string
Note : No repeatation of characters in the string
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	int n;
	printf("Enter size of string\n");
	scanf("%d",&n);
	char str[n];
	unsigned int size=pow(2,n);
	printf("Enter string:\n");
	scanf("%s",str);
	for(int i=0;i<size;i++){
		for(int j=0;j<n;j++){
			if((i) & (1<<j))
				printf("%c",str[j]);
		}
		printf("\n");
	}
}
