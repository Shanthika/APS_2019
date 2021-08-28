#include<stdio.h>
int main()
{
	int i=0,num,positives=0,negetives=0,zeros=0;
	
	printf("Enter any number:");
	scanf("%d",&num);

	while (num != -1)
	{
		if (num>0)
			positives++;
		else if (num<0)
			negetives++;
		else 
			zeros++;
			printf("Enter any number:");
			scanf("%d",&num);
	}
	printf("Positive values entered:%d",positives);
	printf("Negetive values enteres:%d",negetives);
	printf("Zeros entered:%d",zeros);
}
