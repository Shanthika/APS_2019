#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
int curnode;

NODE *getnode()
{
	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	if(newnode==NULL)
		printf("MEMORY ALLOCATION FAILED\n");
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
NODE *insert_at_start(NODE *last)
{
	NODE *newnode;
	newnode=getnode();
	getdata(newnode);
	if(last==NULL)
	{
		last=newnode;
		last->next=newnode;
	}

	else
	{
		newnode->next=last->next;
		last->next=newnode;
	}
	printf("%d ADDED\n",newnode->data);
	return last;
}
NODE *insert_at_end(NODE * last)
{
	NODE *newnode;
	newnode=getnode();
	getdata(newnode);
	if(last==NULL)
	{
		last=newnode;
		last->next=newnode;
	}
	else
	{
		newnode->next=last->next;
		last->next=newnode;
		last=last->next;
	}
	printf("%d ADDED\n",newnode->data);	
	return last;

}
NODE * delete_from_start(NODE *last)
{
	NODE *temp;
	if(last==NULL)
	{
		printf("LIST IS EMPTY\n");
		return last;
	}
	else
	{
		if(last->next==last)
		{
			printf("%d IS DELETED\n",last->data);
			last=NULL;
			last->next==NULL;
			return last;
		}
		else
		{
			temp=last->next;
			last->next=temp->next;
			printf("%d IS DELETED\n",temp->data);
			free(temp);
			return last;
		}
	}
	curnode--;
	
}
NODE *delete_from_end(NODE *last)
{
	NODE *temp1,*temp;
	if(last==NULL)
	{	
		printf("LIST IS EMPTY\n");
		return  last;
	}
	else 
	{
		if(last==last->next)
		{	
			printf("%d IS DELETED\n",last->data);
			last=NULL;
			last->next==NULL;
			return last;
		}
		else
		{
			temp=last->next;
			while(temp->next!=last)
				temp=temp->next;
			temp->next=last->next;
			temp1=last;
			last=temp;
			temp=temp1;
			printf("%d IS DELETED\n",temp->data);
			free(temp);
			return last;		
		}
	}
	curnode--;
	
}
void display(NODE *last)
{	
	NODE *temp;
	if(last==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{	
		temp=last->next;
		while(temp->next!=last)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);
		printf("%d\n",last->data);
	}
	return ;

}
int main()
{
	NODE *last;
	last=NULL;
	int choice;
	while(1)
	{
		printf("1-Insert at start\n2-Insert at end\n3-Delete from start\n4-Delete from end\n5-Display\n6-Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:last=insert_at_start(last);
				break;
			case 2:last=insert_at_end(last);
				break;
			case 3:last=delete_from_start(last);
				break;
			case 4:last=delete_from_end(last);
				break;
			case 5:display(last);
				break;
			case 6:exit(1);
		}
	}
	return 0;
}

