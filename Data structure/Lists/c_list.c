#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;



NODE * getnode()
{
	NODE * newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	if(newnode==NULL)
		printf("Memory allocation failed\n");
	else 
		return newnode;
}
void getdata( NODE *newnode)
{
	printf("ENTER THE DATA\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
}
NODE * insert_at_start(NODE *last)
{
	NODE *newnode;
	newnode=getnode();
	getdata(newnode);
	if(last==NULL)
		last=newnode;
	else
	{
		newnode->next=last->next;
		last->next=newnode;
	}
	printf("%d added to list\n",newnode->data);
	return last;
}
NODE * insert_at_end(NODE * last)
{
	NODE * newnode;
	newnode=getnode();
	getdata(newnode);
	if(last==NULL)
		last=newnode;
	else
	{
		newnode->next=last->next;
		last->next=newnode;
		last=last->next;
	}
	printf("%d ADDED TO LIST\n",newnode->data);
	return last;

}
NODE * delete_from_start(NODE * last)
{
	NODE * temp;

	if(last==NULL)
		printf("LIST IS EMPTY\n");
	else
	{
		temp=last->next;
		last->next=temp->next;
	}
	printf("DELETED NODE IS %d\n",temp->data);
	free(temp);
	return last;
}
NODE * delete_from_end(NODE *last)
{
	NODE *temp1,*temp;
	if(last==NULL)
		printf("LIST IS EMPTY\n");
	else
	{
		temp=last->next;
		while (temp->next!=last)
			temp=temp->next;
		temp1=last;
		temp->next=last->next;
		last=temp;
	}
	printf("DELETED NODE IS %d\n",temp->data);
	free(temp1);
	return last;

}
void display(NODE * last)
{
	NODE * temp;
	if(last==NULL)
		printf("LIST IS EMPTY\n");
	else
	{
		temp=last->next;
		while(temp->next!=last)
		{
			printf("%d \n",temp->data);
			temp=temp->next;
		}
		printf("%d\n",last->data);
	}
}	
int main()
{
	NODE * last=NULL;
	int choice;
	while(1)
	{
		printf("1-INSERT AT START\n2-INSERT AT END\n3-DELETE FROM START\n4-DELTE FROM END\n5-DISPLAY\n6-EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				last=insert_at_start(last);
				break;
			case 2:
				last=insert_at_end(last);
				break;
			case 3:
				last=delete_from_start(last);
				break;
			case 4:
				last=delete_from_end(last);
				break;
			case 5:display(last);
				break;
			case 6:return;
		}
	}
	return 0;

}