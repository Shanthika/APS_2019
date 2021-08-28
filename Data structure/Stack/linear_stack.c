#include <stdio.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0
struct stack
{
	int data[STACKSIZE];
	int top;
};
typedef struct stack STACK;

int overflow(STACK *s)
{
	if(s->top==STACKSIZE-1)
		return TRUE;
	else
		return FALSE;
}

int underflow(STACK *s)
{
	if(s->top==-1)
		return TRUE;
	else
		return FALSE;
}

void push(STACK *s)
{
	int data;
	printf("Enter data to be pushed:\n");
	scanf("%d",&data);
	if(overflow(s)==TRUE)
		printf("STACK IS FULL");
	else
	{
		s->data[++s->top]=data;
	}
}

void pop(STACK *s)
{
	int data;
	if(underflow(s)==TRUE)
		printf("STACK IS EMPTY");
	else
	{
		data=s->data[s->top--];
		printf("POPPED DATA IS %d\n",data);
	}
}

void peek(STACK *s)
{
	int data;
	if(underflow(s)==TRUE)
		printf("SATCK IS EMPTY");
	else
	{
		data=s->data[s->top];
		printf("PEEKED DATA IS %d\n",data);
	}

}

void display(STACK *s)
{
	int data;
	while(s->top>-1)
	{
		data=s->data[s->top--];
		printf("DATA IS %d\n",data);

	}

}


int main()
{
	STACK s;
	s.top=-1;
	
	int choice;
	while(1)
	{
		printf("1-Push\n2-Pop\n3-Peek\n4-Display\n5-Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push(&s);
				break;
			case 2:pop(&s);
				break;
			case 3:peek(&s);
				break;
			case 4:display(&s);
				break;
			case 5:return;
		}
	}
	return 0;
}