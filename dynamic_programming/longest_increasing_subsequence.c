#include <stdio.h>
#include <string.h>

int main(){
	int n;
	printf("Enter n:\n");
	scanf("%d",&n);
	int a[n];
	int counter[n];
	for(int i=0;i<n;i++)counter[i]=1;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);	
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j] && counter[i]<(counter[j]+1))
				counter[i]=counter[j]+1;
		}
	}
	int max=0;
	for(int i=0;i<n;i++){
		if(max<counter[i])max=counter[i];
	}
	printf("%d\n",max);
}