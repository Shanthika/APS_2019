#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define TRUE 1
#define FALSE 0

struct queue
{
	int data[MAX];
	int front;
	int rear;

};
typedef struct queue QUEUE;

int full(QUEUE *q)
{
	if(q->front+1==q->rear || q->front==MAX-1 || q->rear==0)
		return TRUE;
	else
		return FALSE;
}

int empty(QUEUE *q)
{
	if(q->rear==MAX && q->front==-1)
		return TRUE;
	else
		return FALSE;
}

void enqueue(QUEUE *q)
{
	int data;
	int choice;
	if(full(q)==TRUE)
	{
		printf("QUEUE IS FULL\n");
		return;
	}
	else
	{
		printf("1-FRONT\n2-REAR\n");
		scanf("%d",&choice);
		printf("ENTER DATA TO BE ENQUEUED\n");
		scanf("%d",&data);
		switch(choice)
		{
			case 1:q->data[++q->front]=data;
				break;
			case 2:q->data[--q->rear]=data;
		
		}
	}
}
void dequeue(QUEUE *q)
{
	int data;
	int choice;
	if(empty(q)==TRUE)
	{
		printf("QUEUE IS EMPTY\n");
		return;
	}
	else
	{
		printf("1-FRONT\n2-REAR\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:data=q->data[q->front--];
				break;
			case 2:data=q->data[q->rear++];
		
		}
		printf("DATA DEQUEUED IS %d\n",data);
	}
}

int main()
{
	QUEUE q;
	q.front=-1;
	q.rear=MAX;
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
		case 3:exit(0);

	}
}
}