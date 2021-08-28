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

int empty(QUEUE *q)
{
	if(q->front==q->rear)
		return TRUE;
	else
		return FALSE;
}

int full(QUEUE *q)
{
	if((q->rear+1)%MAXSIZE==q->front)
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
	printf("Enter data to be enqueued:\n");
	scanf("%d",&data);
	q->rear=(q->rear+1)%MAXSIZE;
	q->data[q->rear]=data;
}
void dequeue(QUEUE *q)
{
	int data;
	if(empty(q)==TRUE)
	{
		printf("QUEUE IS EMPTY\n");
		return;
	}
	q->front=(q->front+1)%MAXSIZE;
	data=q->data[q->front];
	printf("DEQUEUED DATA IS %d\n",data);
}

int main()
{
	QUEUE q;
	q.front=0;
	q.rear=0;
	
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