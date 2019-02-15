#include <stdio.h>
#include <limits.h>

int main(){
	int n;
	printf("Enter n:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter array elements:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int max=0,tmax=0,max_val=INT_MIN;
	for(int i=0;i<n;i++){
		tmax+=a[i];
		if(max_val<a[i]) max_val=a[i];
		if(tmax<0){
			tmax=0;
		}
		else if(max<tmax){
			max=tmax;
		}
	}
	if(max==0)
		printf("%d\n",max_val);
	else printf("%d\n",max);
}