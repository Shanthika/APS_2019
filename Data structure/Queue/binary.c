#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct queue
{
	int data[MAX];
	int front;
	int rear;
};
typedef struct queue QUEUE;

void print(QUEUE *q,int num)
{
	int x=1;
	int number;
	printf("1\n");
	num--;
	while(num>0)
	{
		number=x*10+0;
		printf("%d\n",number);
		q->data[++q->rear]=number;
		num--;
		if(num<=
			0)
			break;
		number=x*10+1;
		printf("%d\n",number);
		q->data[++q->rear]=number;
		x=q->data[q->front++];
		num--;
	}

}

int main()
{
	QUEUE q;
	q.front=0;
	q.rear=-1;

	int  num;
	printf("Enter Number\n");
	scanf("%d",&num);
	print(&q,num);
}