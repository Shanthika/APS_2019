#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
struct stack
{
	int top;
	int items[MAXSIZE];
};
typedef struct stack STACK;

void push (STACK *s,int x)
{
	if(s->top==MAXSIZE-1)
		printf("Stack is full\n");
	else 
	{
		s->top++;
		s->items[s->top]=x;
	}

}
int pop (STACK *s)
{
	int x;
	if(s->top==-1)
		return TRUE;

	else 
	{
		x=s->items[s->top];
		s->top--;
		return x;

	}
}
void optr(STACK *s,char x)
 {
 	int oprd1,oprd2;
 	int value;
 	oprd2=pop(&s);
 	oprd1=pop(&s);
 	switch (x)
 	{
 		case '+':value=oprd1 + oprd2;
 			break;
 		case '-':value=oprd1 - oprd2;
 			break;
 		case '*':value=oprd1 * oprd2;
 			break;
 		case '/':value=oprd1 / oprd2;
 			break;
 		case '$':value=pow(oprd1,oprd2);
 		break;
 	}
 	push(&s,value);

 }
 
 int main()
 {
 	STACK s;
 	s.top=-1;
 	char x;
 	int value;
 	while (1)
 	{
 		printf("Enter the expresion string\nEnter -1 to exit\n");
 		scanf("%c",&x);
 		if(x==-1)
 			break;
 		else if(isdigit(x))
 			push(&s,x);
 		else
 			optr(&s,x);
 	}
 	value=pop(&s);
 	printf("The result of the expression is %d\n",value);

 }
