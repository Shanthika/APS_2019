#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct node
{
	float data;
	struct node *next;
	struct node *prev;
};
typedef struct node NODE;

NODE *getnode()
{
	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	if(newnode==NULL)
		printf("MEMMORY ALLOCATION FAILED\n");
	return newnode;
}

void getdata(NODE *newnode)
{
	printf("ENTER THE DATA\n");
	scanf("%f",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
}

NODE * insert_at_start(NODE *start)
{
	NODE *newnode;
	newnode=getnode();
	getdata(newnode);

	if(start==NULL)
		start=newnode;
	else
	{
		newnode->next=start;
		start->prev=newnode;
		start=newnode;
		printf("Added datat is %f\n",start->data);
	}
	return start;
}
NODE *insert_at_end(NODE * start)
{
	NODE *newnode;
	NODE *temp;
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
		newnode->prev=temp;
		printf("THE DATA ADDED IS %f\n",newnode->data);
	}
	return start;
}
NODE * delete_from_start(NODE *start)
{
	NODE *temp;
	if(start->next=NULL)
	{
		start=NULL;
		start->next=NULL;
		start->prev=NULL;
		free(start);

	}
	else
	{
		temp=start;
		start=temp->next;
		start->prev=NULL;
	}
	printf("DATA DELETED IS %f\n",temp->data);
	free(temp);
	return start;		

}

NODE * delete_from_end(NODE * start)
{
	NODE *temp;
	if(start->next==NULL)
	{
		temp=start;
		start=NULL;
	}
	else
	{
		temp=start;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->prev->next=NULL;
	}
	printf("DATA DELETED IS %f\n",temp->data);
	free(temp);
	return start;		

}
int main()
{
	NODE *start;
	start=NULL;
	int choice;
	while(1)
	{
		printf("1-INSERT AT START\n2-INSERT AT END\n3-DELETE FROM START\n4-DELTE FROM END\n5- EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert_at_start(start);
				break;
			case 2:insert_at_end(start);
				break;
			case 3:delete_from_start(start);
				break;
			case 4:delete_from_end(start);
				break;
			case 5:
			exit(1);
		}
	}
}