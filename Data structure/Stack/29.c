#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
#define TRUE 1
#define FALSE 0
struct stack
{
	int top;
	int data[MAXSIZE];
};
typedef struct stack STACK;

void push(STACK *s)
{
	int x;
	if(s->top==MAXSIZE)
		printf("STACK IS FULL\n");
	else
	{
		printf("Enter data\n");
		scanf("%d",&x);
		s->data[s->top]=x;
		s->top++;
	}
}
void pop(STACK *s)
{
	int x;
	if(s->top==0)
		printf("STACK IS EMPTY\n");
	else
	{
		s->top--;
		x=s->data[s->top];
		printf("POPPED DATA IS %d\n",x);
	}
}
void peek(STACK *s)
{
	printf("%d\n",s->data[--(s->top)]);
	s->top++;
}

int main()
{
	STACK s;
	s.top=0;
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
				case 4:return ;
		}
	}
}