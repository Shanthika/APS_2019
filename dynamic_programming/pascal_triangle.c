#include <stdio.h>
#include <stdio.h>
int min(int a,int b){
	if(a<b) return a;
	else return b;
}
int main(){
	int n;
	printf("Enter value of n:");
	scanf("%d",&n);

	int counter[n+1][n+1];
	counter[0][0]=1;
	for(int i=0;i<n+1;i++){
		for(int j=0;j<min(i,j)+1;j++){
			if(j==0 || i==j) counter[i][j]=1;
			else counter[i][j] = counter[i-1][j-1]+counter[i-1][j];
		}
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<min(i,j)+1;j++){
			printf("%d ",counter[i][j]);
		}printf("\n");
	}
	
}