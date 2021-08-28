#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 5
#define TRUE 1
#define FALSE 0
struct queue 
{
	int front;
	int rear;
	char data[20];
};
typedef struct queue QUEUE;
int empty(QUEUE *q)
{
	if(q->front==q->rear)
		return TRUE;
	else 
		return FALSE;
}
int full(QUEUE *q)
{
	if (q->rear+1==(q->front)%MAXSIZE)
		return TRUE;
	else
		return FALSE;
}

void insert_rear(QUEUE *q,int *overflow,char x)
{
	if(full(q))
		*overflow=TRUE;
	else
	{
		*overflow=FALSE;
		printf("ENTER THE SRING\n");
		scanf("%s",x);
		strcpy(x,q->data[(q->rear)++]);
	}
}
void insert_front(QUEUE *q,int *overflow,char x)
{
	if(full(q))
		*overflow=TRUE;
	else
	{
		*overflow=FALSE;
		printf("ENTER THE SRING\n");
		scanf("%s",x);
		strcpy(q->data[(q->front)--],x);
	}
}
void delete_rear(QUEUE *q,int *underflow,char x)
{
	if(empty(q))
		*underflow=TRUE;
	else
	{
		*underflow=FALSE;
		strcpy(x,q->data[(q->rear)--]);
		printf("THE DELETED STRING IS %s\n",x);
	}
}
void delete_front(QUEUE *q,int *underflow,char x)
{
	if(empty(q))
		*underflow=TRUE;
	else
	{
		*underflow=FALSE;
		strcpy(x,q->data[(q->front)]);
		printf("THE DELETED STRING IS %s\n",x);
		(q->front)=((q->front)++)%MAXSIZE;
	}
}
void display(QUEUE *q)
{
	char x;
	if(empty(q))
		printf("THE QUEUE IS EMPTY\n");
	else
	{
		while(q->front!=q->rear+1)
		{
			strcpy(x,q->data[q->front]++);
			printf("%s\n",x);
		}
		printf("%s\n",(q->data[q->front++])%MAXSIZE);
	}

}		

int main()
{
	QUEUE q;
	q.front=MAXSIZE-1;
	q.rear=MAXSIZE-1;
	int overflow,underflow;
	char x;
	int choice;
	while(1)
	{
		printf("1-INSERT AT REAR\n2-INSERT AT FRONT\n3-DELETE FROM REAR\n4-DELETE FROM FRONT\n5-EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert_rear(&q,&overflow,x);
				break;
			case 2:insert_front(&q,&overflow,x);
				break;
			case 3:delete_rear(&q,&underflow,x);
				break;
			case 4:delete_front(&q,&underflow,x);
				break;
			case 5:return;
		}
	}
}