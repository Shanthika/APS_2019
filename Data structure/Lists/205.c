#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
	char data;
	int index;
	struct node * next;
}; 
typedef struct node NODE;
//dynamic memory allocation
NODE *getnode()
{
	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	if(newnode==NULL)
		printf("MEMORY ALLOCATION FAILED\n");
	return newnode;
}
//storing data in nodes
void getdata(NODE *newnode,char x)
{
	newnode->data=x;
	newnode->next=NULL;
	
}
//insertion at end

NODE * store(NODE *start,char x)
{
	NODE *newnode;
	NODE *temp;
	static int i=0;
	newnode=getnode();
	getdata(newnode,x);
	if(newnode->data!='\0')
		newnode->index=i++;

	if (start==NULL)
		start=newnode;
	else
	{
		temp=start;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
	}
	return start;
}
//searching the string data
void search_string(NODE *start,NODE *searching,long int length)
{
	NODE *temp1;
	NODE *temp2;
	NODE *temp3,*temp4;
	temp1=start;
	temp2=searching;
	int n;
	static int j=0;
	int len=0;
	int loc[100];
	int flag=0;
	while(temp1->next!=NULL)
	{
		if(temp1->data==temp2->data)
		{
			n=temp1->index;
			int i=0;
			while(temp2->next!=NULL)
			{
				if(temp1->data==temp2->data)
				{
					i++;
				}
					temp1=temp1->next;
					temp2=temp2->next;
				
			}
			if(temp1->data==temp2->data && temp1->next!=NULL)
				i++;			

			if(i==length)
			{
				flag=1;
				loc[j++]=n;
				len++;

			}
		}
		{
			if(temp1->next!=NULL)
				temp1=temp1->next;
			temp2=searching;
		}
	}
	if(flag==1)
	{
		printf("Found at %d locations\n",len);
		printf("Following are the string indices\n");
		for(int i=0;i<len;i++)
		{
			printf("%d\n",loc[i]);
		}
	}
	else
		printf("String not found\n");
	return;
}
int main()
{
	char s[100],search[100];
	NODE *start;
	NODE *searching;
	searching=NULL;
	start=NULL;
	char x;
	long int size;
	printf("Enter the string\n");
	scanf("%[^\n]s",s);
	for(int i=0;i<=strlen(s);i++)
	{	
		x=s[i];	
		start=store(start,x);
	}
	getchar();

	printf("ENTER THE STRING TO BE SEARCHED\n");
	scanf("%[^\n]s",search);
	for(int i=0;i<=strlen(search);i++)
	{	
		x=search[i];	
		searching=store(searching,x);
	}
	getchar();

	size=strlen(search);

	search_string(start,searching,size);
	return 0;
}