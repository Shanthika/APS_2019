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
	if (q->rear==MAX-1)
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
void compaction(QUEUE *q)
{
	for(int i=0;i<MAX;i++)
	{
		if(q->data[i]==-1)
		{
			q->data[i]==q->data[++i];
			q->rear--;
		}
	}
}

void enqueue(QUEUE *q)
{
	int data;
	if(full(q)==TRUE)
	{
		compaction(q);
		if(full(q)==TRUE)
		printf("Queue is full\n");
	}
	else
	{
		printf("Enter data to be enqueued\n");
		scanf("%d",&data);
		q->data[++q->rear]=data;

	}
}

void dequeue(QUEUE *q)
{
	int data=0;
	if(empty(q)==TRUE)
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(int i=0;i<MAX;i++)
		{
			if(data!=-1 && data<q->data[i])
			{	
				data=q->data[i];
				q->data[i]=-1;
			}
		}
		printf("Dequeued data is %d\n",data);
	}
}
void display(QUEUE *q)
{
	for(int i=0;i<=q->rear;i++)
	{
		printf("%d\n",q->data[i]);
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
		printf("1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue(&q);
				break;
			case 2:
				dequeue(&q);
				break;
			case 3:
				display(&q);
				break;
			case 4:
				exit(0);
		}
	}
}