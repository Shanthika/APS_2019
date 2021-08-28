#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
#define TRUE 1
#define FALSE 0
struct stack
{
	int top1;
	int top2;
	int data[MAXSIZE];
};
typedef struct stack STACK;

void push(STACK *s)
{
	int choice,x;
	printf("1-ACCENDING STACK\n2-DECENDING STACK\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		if(s->top1==MAXSIZE-1||s->top1==s->top2+1)
			printf("STACK IS FULL\n");
		else
		{
			printf("Enter the data\n");
			scanf("%d",&x);
			s->data[(s->top1)++]=x;
		}
	}
	else
	{
		if(s->top2==0||s->top2==s->top1-1)
			printf("STACK IS FULL\n");
		else 
		{
			printf("Enter the data\n");
			scanf("%d",&x);
			s->data[(s->top2)--]=x;

		}
	}
}
void pop(STACK *s)
{
	int x,choice;
	printf("1-ACCENDING STACK\n2-DECENDING STACK\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		if(s->top1==0)
			printf("STACK IS EMPTY\n");
		else
		{
			x=s->data[--(s->top1)];
			printf("DEQUEUED DATA IS %d\n",x);
		}
	}
	else
	{
		if(s->top2==MAXSIZE -1)
			printf("STACK IS EMPTY\n");
		else
		{
			x=s->data[++(s->top2)];
			printf("DEQUEUED DATA IS %d\n",x);

		}
		

	}
}
void peek(STACK *s)
{
	int x,choice;
	printf("1-ACCENDING STACK\n2-DECENDING STACK\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		if(s->top1==0)
			printf("STACK IS EMPTY\n");
		else
		{
			x=s->data[--(s->top1)];
			s->top1++;
			printf("%d\n",x);
		}
	}
	else
	{
		if(s->top2==MAXSIZE-1)
			printf("STACK IS EMPTy\n");
		else
		{
			x=s->data[++(s->top2)];
			s->top1--;
			printf("%d\n",x);
		}
	}
}
int main()
{
	STACK s;
	s.top1=0;
	s.top2=MAXSIZE-1;
	int choice;
	while(1)
	{
		printf("1-PUSH\n2-POP\n3-PEEK\n4-EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push(&s);
				break;
			case 2:pop(&s);
				break;
			case 3:peek(&s);
				break;
			case 4:return;
		}
	}
	return 0;
}