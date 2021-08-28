#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node NODE;


NODE * getnode()
{
	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	if(newnode==NULL)
		printf("Memory allocation failed\n");
	else
		return newnode;
}
void getdata(NODE *newnode)
{
	int x;
	printf("Enter the data\n");
	scanf("%d",&x);
	newnode->data=x;
	newnode->next=NULL;
	newnode->prev=NULL;
}

NODE * insert_at_start(NODE *start)
{
	NODE *newnode;
	newnode=getnode();
	getdata(newnode);
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		newnode->next=start;
		start->prev=newnode;
		start=newnode;
	}
	return start;
}

NODE * insert_at_end(NODE *start)
{
	NODE *newnode;
	NODE *temp;
	
	newnode=getnode();
	getdata(newnode);
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		temp=start;
		while(temp->next!=NULL)
			temp=temp->next;
		newnode->prev=temp;
		temp->next=newnode;
	}
	return start;
}
NODE * delete_from_start(NODE *start)
{
	if(start== NULL)
		printf("List is empty\n");
	else
	{
		printf("Deleted data is %d\n",start->data);
		start=start->next;
		start->prev=NULL;
	}
	return start;
}
NODE * delete_from_end(NODE *start)
{
	NODE *temp;
	
	if(start== NULL)
		printf("List is empty\n");
	else
	{
		temp=start;
		if (start->next==NULL)
		{
			temp=start;
			start=NULL;
		}
		else
		{
			while (temp->next!=NULL)
				temp=temp->next;
			temp->prev->next=NULL;
		}
		printf("Deleted data is %d\n",temp->data);
		free(temp);
	}
	return start;
}
void display(NODE *start)
{
	NODE *temp;
	
	while(temp->next!=NULL)
	{
		temp=start;
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);

}
int main()
{
	NODE *newnode;
	NODE *start;
	start=NULL;
	int choice;
	while(1){
	printf("Enter your choice\n");
	printf("1-INSERT AT START\n2-INSERT AT END\n3-DELETE FROM START\n4-DELETE FROM END\n5-DISPLAY\n6-EXIT\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			start=insert_at_start(start);
			break;
		case 2:
			start=insert_at_end(start);
			break;
		case 3:
			start=delete_from_start(start);
			break;
		case 4:
			start=delete_from_end(start);
			break;
		case 5:display(start);
			break;
		case 6:return;
	}
}
	return 0;
}