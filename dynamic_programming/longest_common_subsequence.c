/*Longest common subsequence of given string*/
#include <stdio.h>
#include <string.h>

int max(int a,int b){
	if(a>b) return a;
	else return b;
}


int main(){
	char str1[20],str2[20];
	int s1,s2;
	printf("Enter the strings:\n");
	scanf("%s",str1);
	scanf("%s",str2);
	s1=strlen(str1);
	s2=strlen(str2);
	int counter[s1+1][s2+1];

	memset(counter[0],0,(s2+1)*sizeof(counter[0]));


	for(int i=1;i<s1+1;i++){
		for(int j=1;j<s2+1;j++){
			if(str1[i-1]==str2[j-1]){
				counter[i][j]=1+counter[i-1][j-1];
			}
			else counter[i][j]=max(counter[i-1][j],counter[i][j-1]);
		}
	}
	printf("%d\n",counter[s1][s2]);

}