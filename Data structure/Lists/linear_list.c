#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
int curnode=0;

NODE * getnode()
{
	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	if(newnode==NULL)
	{
		printf("MEMORY ALLOCATION FAILED\n");
	}
	return newnode;
}

void getdata(NODE *newnode)
{
	int x;
	printf("ENTER THE DATA\n");
	scanf("%d",&x);

	newnode->data=x;
	newnode->next=NULL;
	curnode++;
	return;
}
NODE * insert_start(NODE *start)
{
	NODE *newnode;
	newnode=getnode();
	getdata(newnode);
	if(start==NULL)
		start=newnode;
	else
	{
		newnode->next=start;
		start=newnode;
	}
	printf("%d IS ADDED\n",newnode->data);
	return start;
}
NODE * insert_end(NODE *start)
{
	NODE *temp;
	NODE *newnode;
	newnode=getnode();
	getdata(newnode);
	if(start==NULL)
		start=newnode;
	else
	{
		temp=start;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;

	}
	printf("%d IS ADDED\n",newnode->data);
	return start;
}
NODE *insert(NODE *start,int x)
{
	NODE *temp;
	NODE *newnode;
	newnode=getnode();
	getdata(newnode);
	int count=0;
	temp=start;
	if(x>curnode)
	{
		printf("ENTER VALID INPUT\n");
		return start;
	}
	else
	{
		while(count!=(x-1))
		{
			temp=temp->next;
			count++;
		}
		newnode->next=temp->next;
		temp->next=newnode;
		printf("%d IS ADDED\n",newnode->data);
		return start;
	}

}
NODE *delete_start(NODE *start)
{
	NODE *temp;
	temp=start;
	if(start==NULL)
	{
		printf("LIST IS EMPTY\n");
		return start;
	}
	else if(start->next==NULL)
		start=NULL;
	else
	{
		start=start->next;
	}
	curnode--;
	printf("%d IS DELETED\n",temp->data);
	return start;
}
NODE * delete_end(NODE *start)
{
	NODE *temp,*prev;
	temp=start;
	if(start==NULL)
	{
		printf("LIST IS EMPTY\n");
		return start;	
	}
	else if(start->next==NULL)
		start=NULL;
	else
	{
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		curnode--;
		prev->next=NULL;
		
	}
	printf("%d IS DELETED\n",temp->data);
	return start;
}
NODE * delete(NODE *start,int x)
{
	NODE *temp,*prev;
	temp=start;
	int count=0;
	if(start==NULL)
	{	
		printf("LIST IS EMPTY\n");
	}
	else if(x>curnode)
	{
		printf("Enter valid input\n");
	}
	else if(x==1)
	{
		start=start->next;
	}
	else{
		while(count!=(x-1))
		{
			prev=temp;
			temp=temp->next;
			count++;
		}
		prev->next=temp->next;
		
	}
	curnode--;
	printf("%d IS DELETED\n",temp->data);
	free (temp);
	return start;
}
void display(NODE *start)
{
	NODE *temp;
	temp=start;
		if(start==NULL)
		{	
			printf("LIST IS EMPTY\n");
		}
		else
		{
			while(temp->next!=NULL)
			{
				printf("%d\n",temp->data);
				temp=temp->next;

			}
			printf("%d\n",temp->data);
		}
	return;

}
int main()
{
	NODE *start;
	start=NULL;
	int x;
	int choice;
	while(1)
	{
	printf("1-INSERT AT START\n2-INSERT AT END\n3-INSERT AT POSITION\n4-DELETE FROM START\n5-DELETE FROM END\n6-DELETE FROM POSITION\n7-DISPLAY\n8-EXIT\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			start=insert_start(start);
			break;
		case 2:
			start=insert_end(start);
			break;
		case 3:
			printf("ENTER THE POSITION\n");
			scanf("%d",&x);
			start=insert(start,x);
			break;
		case 4:
			start=delete_start(start);
			break;
		case 5:
			start=delete_end(start);
			break;
		case 6:
			printf("ENTER  THE POSITION\n");
			scanf("%d",&x);
			start=delete(start,x);
			break;
		case 7:
			display(start);
			break;
		case 8:
			exit(1);

	}
}
}