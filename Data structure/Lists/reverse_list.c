#include <stdio.h>
#include <stdlib.h>
#define Max 100

struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;

NODE *insert(NODE *start,int x)
{
	NODE *newnode;
	NODE *temp;
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=x;
	newnode->next=NULL;
	temp=start;
	if(start==NULL)
		start=newnode;
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
	}
	return start;
}
void display(NODE *start)
{
	NODE *temp;
	temp=start;
	while(temp->next!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}

void reverse(NODE *start)
{
	NODE *temp;
	NODE *current;
	current=NULL;
	while(start!=NULL)
	{
		temp=start;
		start=start->next;
		temp->next=current;
		current=temp;
	}
	display(current);
}


int main()
{
	NODE *start;
	start=NULL;
	int choice,x;
	while(1)
	{
		printf("1-Insert data\n2-Display\n3-Reverse\n4-Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data to be inserted\n");
				scanf("%d",&x);
				start=insert(start,x);
				break;
			case 2:
				display(start);
				break;
			case 3:
				reverse(start);
				break;
			case 4:exit(0);
		}
	}
}