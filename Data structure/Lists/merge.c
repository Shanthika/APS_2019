#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;

NODE *getnode()
{
	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	if(newnode==NULL)
	{
		printf("Memory allocation failed\n");
	}
	return newnode;
}

NODE *insert(NODE *start,int data)
{
	NODE *newnode;
	NODE *temp;
	temp=start;
	newnode=getnode();
	newnode->data=data;
	newnode->next=NULL;
	if(start==NULL)
		start=newnode;
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
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

NODE *merge(NODE *start,NODE *start1,NODE *start2)
{
	NODE *temp,*temp1,*temp2;
	temp=start;
	temp1=start1;
	temp2=start2;

	while(temp1!=NULL || temp2!=NULL)
	{
		if(temp1->data<temp2->data)
		{
			start=insert(start,temp1->data);
			temp1=temp1->next;
		}
		else if(temp1->data>temp2->data)
		{
			start=insert(start,temp2->data);
			temp2=temp2->next;
		}
		else
		{
			start=insert(start,temp2->data);
			temp1=temp1->next;
			temp2=temp2->next;

		}
	}
	if(temp1==NULL)
	{
		while(temp2=NULL)
		{
			start=insert(start,temp2->data);
			temp2=temp2->next;
		}
	}
	else
	{
		while(temp1=NULL)
		{
			start=insert(start,temp1->data);
			temp1=temp1->next;
		}
	}
	return start;
}

int main()
{
	NODE *start,*start1,*start2;
	start=NULL;
	start1=NULL;
	start2=NULL;
	int choice;
	int data;
	while(1){
	printf("1-Enter data into list 1\n2-Enter data into list 2\n3-Merge\n4-Display\n5-Exit\n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			printf("Enter data to be inserted\n");
			scanf("%d",&data);
			start1=insert(start1,data);
			break;
		case 2:
			printf("Enter data to be inserted\n");
			scanf("%d",&data);
			start2=insert(start1,data);
			break;
		case 3:
			start=merge(start,start1,start2);
			break;
		case 4:
			display(start);
			break;
		case 5:exit(0);
	}
}

}
