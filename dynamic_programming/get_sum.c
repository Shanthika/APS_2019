/*Number of ways to get the sum from given set of numbers*/

#include <stdio.h>
#include <string.h>

int main(){
	int n;
	int sum;
	printf("Enter n:\n");
	scanf("%d",&n);
	printf("Enter sum:\n");
	scanf("%d",&sum);
	int a[n];
	int counter[sum+1];
	printf("Enter array of numbers:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	int j=0,i;
	memset(counter,0,(sum+1)*sizeof(counter[0]));
	counter[0]=1;
	for(int k=0;k<n;k++){
        i=a[k];
        for(j=0;i<sum+1;j++){
            counter[i]+=counter[j];
            i++;
        }
    }

	printf("%d\n",counter[sum]);

}