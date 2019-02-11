#include <stdio.h>
#include <string.h>

void print(int counter[5][6],int n,int w){
	for(int i=0;i<n+1;i++){
		for(int j=0;j<w+1;j++){
			printf("%d ",counter[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int max(int a,int b){
	if(a>b)return a;
	else return b;
}
int main(){
	int n;
	printf("Enter number of items:\n");
	scanf("%d",&n);
	int weight[n+1],value[n+1];
	weight[0]=value[0]=0;
	int w;
	printf("Enter weight and value:\n");
	for(int i=1;i<n+1;i++){
		scanf("%d %d",&weight[i],&value[i]);
	}
	printf("Enter capacity in weights:\n");
	scanf("%d",&w);
	int counter[n+1][w+1];
	memset(counter,0,sizeof(counter));

	for(int i=1;i<n+1;i++){
		for(int j=1;j<w+1;j++){
			if((j-weight[i])<0) counter[i][j]=counter[i-1][j];
			else counter[i][j]=max(counter[i-1][j],value[i]+counter[i-1][j-weight[i]]);
		}
		print(counter,n,w);

	}
	printf("%d\n",counter[n][w]);
	print(counter,n,w);
}