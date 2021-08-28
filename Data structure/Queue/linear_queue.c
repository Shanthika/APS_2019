#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
#define TRUE 1
#define FALSE 0

struct queue
{
	int data[MAXSIZE];
	int front;
	int rear;
};
typedef struct queue QUEUE;

int full(QUEUE *q)
{
	if(q->rear==MAXSIZE-1)
		return TRUE;
	else
		return FALSE;
}

int empty(QUEUE *q)
{
	if(q->front>q->rear)
		return TRUE;
	else
		return FALSE;
}
void enqueue(QUEUE *q)
{
	int data;
	if(full(q)==TRUE)
	{
		printf("QUEUE IS FULL\n");
		return;
	}
	else
	{
		printf("ENTER DATA TO BE ENQUEUED\n");
		scanf("%d",&data);
		q->data[++q->rear]=data;
	}
}
void dequeue(QUEUE *q)
{
	int data;
	if(empty(q)==TRUE)
	{
		printf("QUEUE IS EMPTY\n");
		return;
	}
	else
	{
		data=q->data[q->front++];
		printf("DATA DEQUEUED is %d\n",data);
		
	}
}

int main()
{
	QUEUE q;
	q.front=0;
	q.rear=-1;
	int choice;
	while(1)
	{
		printf("1-ENQUEUE\n2-DEQUEUE\n3-EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:enqueue(&q);
				break;
			case 2:dequeue(&q);
				break;
			case 3:return;
		}
	}
	return 0;
}