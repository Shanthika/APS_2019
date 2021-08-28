#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 5
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
struct stack
{
	int data[SIZE];
	int top;
};
typedef struct stack STACK;
struct  queue
{
	int data[SIZE];
	int front;
	int rear;
};
typedef struct queue QUEUE;
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
typedef struct tree TREE;



//Sum of array using for loop.
void sum1(int a[])
{
	int sum=0;
	for(int i=0;i<SIZE;i++)
		sum+=a[i];
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);
}
//Sum of array using recursion.
int sum2(int a[],int n,int *sum)
{
    if (n <0) 
        return;
    else
        *sum+=a[n];
    sum2(a,n-1,sum);
}
//Finding sum without using '+' operator.
int sum3_1(int sum,int a_i)
{
	return printf("%*c%*c",sum,'\r',a_i,'\r');
}
void sum3(int a[])
{
	int sum=0;
	for(int i=0;i<SIZE;i++)
		sum=sum3_1(sum,a[i]);
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum-1);
}
//Find sum of array using pointers.
void sum4(int a[])
{
	int *p;
	p=a;
	int sum=0;
	int i=0;
	while(i<SIZE)
	{
		sum+=*p;
		p++;
		i++;
	}
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);
}
//Find the sum of array elements using only 'increment operation'.
void sum5(int a[])
{
	int sum=0;
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<a[i];j++)
			sum++;
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);	
}
//Bubble sort and then find the sum of array using for loop.
void sum6(int a[])
{
	int temp;
	for(int i=0;i<=SIZE-2;i++)
		for(int j=0;j<=(SIZE-2-i);j++)
			if(a[j+1]<a[j])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	int sum=0;
	for(int i=0;i<SIZE;i++)
		sum+=a[i];
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);
}

//Selection sort and then find the sum of array using for loop.
void sum7(int a[])
{
	int temp;
	int min;
	for(int i=0;i<=(SIZE-2);i++)
	{
		min=i;
		for(int j=i+1;j<=(SIZE-1);j++)
		{
			if(a[j]<a[min])
				min=j;
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	int sum=0;
	for(int i=0;i<SIZE;i++)
		sum+=a[i];
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);
}
//Insertion sort and then find the sum of array using for loop.
void sum8(int a[])
{
	int temp;
	int j,n;
	for(int i=1;i<=(SIZE-1);i++)
	{
		n=a[i];
		j=i-1;
		while(j>=0 && a[j]>n)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=n;
	}
	int sum=0;
	for(int i=0;i<SIZE;i++)
		sum+=a[i];
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);
}
//Find the sum by sorting into even and odd numbers and find the sum of the array using for loop.

void sum9(int a[])
{
	int even[SIZE],odd[SIZE];
	int elen=0,olen=0;
	int e=0,o=0;
	for(int i=0;i<SIZE;i++)
	{
		if(a[i]%2==0)
		{
			even[e]=a[i];
			e++;
			elen++;
		}
		else
		{
			odd[o]=a[i];
			o++;
			olen++;
		}
	}

	int sum=0,esum=0,osum=0;
	for(int i=0;i<elen;i++)
		esum+=even[i];
	for(int i=0;i<olen;i++)
		osum+=odd[i];
	sum=esum+osum;
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);

}
//Find the sum of the array elements by adding the no.in increasing order.
int sum10_1(int a[])
{
	int small=a[0];
	int index;
	for(int i=0;i<SIZE;i++)
	{
		if(a[i]<small && a[i]!=-1)
		{
			small=a[i];
			index=i;
		}
	}
	a[index]=-1;
	return small;
}
void sum10(int a[])
{
	int sum=0;
	for(int i=0;i<SIZE;i++)
	{
		//break 201;
		sum+=sum10_1(a);
	}
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);
}

//Divide the array into two arrays and find the sum of the array using for loop.
void sum11(int a[])
{
	int a1[SIZE],a2[SIZE];
	int a_1=0,a_2=0;
	int i=0;
	while(i<SIZE/2)
	{
		a1[a_1]=a[i];
		a_1++;
		i++;
	}
	while(i<SIZE)
	{
		a2[a_2]=a[i];
		a_2++;
		i++;
	
	}

	int sum=0,a1sum=0,a2sum=0;
	for(int i=0;i<a_1;i++)
		a1sum+=a1[i];
	for(int i=0;i<a_2;i++)
		a2sum+=a2[i];
	sum=a1sum+a2sum;
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);

}
//Reverse an array and find the sum of the array using for loop.
void sum12(int a[])
{
	int sum=0;
	int temp;
	for(int i=0,j=(SIZE-1);i<(SIZE/2);i++,j--)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	for(int i=0;i<SIZE;i++)
		sum+=a[i];
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);

}

//Hash the array and then find the sum of the array using for loop.
void sum13(int a[])
{
	int hash_table[SIZE];
	int index=0;
	for(int i=0;i<SIZE;i++)
	{
		index=(a[i]%149)%SIZE;
		hash_table[index]=a[i];
	}
	int sum=0;
	for(int i=0;i<SIZE;i++)
		sum+=hash_table[i];
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);

}
//Store the array elements into list and then find the sum of the array using for loop.
NODE * sum14_getnode()
{
	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	if (newnode==NULL)
		printf("MEMORY ALLOCATION FAILED\n");
	return newnode;
}
void sum14_getdata(NODE *newnode,int a[])
{
	static int i=0;
	newnode->data=a[i];
	newnode->next=NULL;
	i++;
}
NODE * sum14_insert(NODE *start,int a[])
{
	int n=SIZE;
	while(n>0)
	{
		NODE *newnode;
		NODE *temp;
		newnode=sum14_getnode();
		sum14_getdata(newnode,a);
		if (start==NULL)
			start=newnode;
		else
		{
			temp=start;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=newnode;
		}
		n--;
	}
	return start;

}

void sum14(int a[])
{
	NODE *start;
	start=NULL;
	start=sum14_insert(start,a);
	int sum=0;
	NODE *temp;
	temp=start;
	while(temp->next!=NULL)
	{
		sum+=temp->data;
		temp=temp->next;
	}
	sum+=temp->data;
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);
}

//Store the array elements into stack and then find the sum of the array using for loop.
void sum15_push(STACK *s,int data)
{
	s->top++;
	s->data[s->top]=data;
}
int sum15_pop(STACK *s)
{
	int data;
	data=s->data[s->top];
	s->top--;
	return data;
}
void sum15(int a[])
{
	STACK s;
	s.top=-1;
	int sum=0;
	for(int i=0;i<SIZE;i++)
		sum15_push(&s,a[i]);
	for(int i=0;i<SIZE;i++)
		sum+=sum15_pop(&s);
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);
}
//Store the array elements into queue and then find the sum of the array using for loop.
void sum16_enqueue(QUEUE *q,int data)
{
	q->rear++;
	q->data[q->rear]=data;
}
int sum16_dequeue(QUEUE *q)
{
	int data;
	data=q->data[q->front];
	q->front++;
	return data;
}

void sum16(int a[])
{
	int sum=0;
	QUEUE q;
	q.front=0;
	q.rear=-1;
	for(int i=0;i<SIZE;i++)
		sum16_enqueue(&q,a[i]);
	for(int i=0;i<SIZE;i++)
		sum+=sum16_dequeue(&q);
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);
}
//Convert the array into binary tree and then find the sum of the array using for loop.
TREE *sum17_insert(TREE *root,int data)
{
	TREE *newnode;
    TREE *parent=NULL;
    TREE *currnode;
    newnode=(TREE *)malloc(sizeof(TREE));
    if(newnode==NULL)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return root;
    }
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    if(root==NULL)
    {
        root=newnode;
        return root;
    }
    currnode=root;
    while(currnode!=NULL)
    {
        parent=currnode;
        if(newnode->data < currnode->data)
            currnode=currnode->left;
        else
        {
            currnode=currnode->right;
        }
    }
    if(newnode->data<parent->data)
        parent->left=newnode;
    else
        parent->right=newnode;
    return root;

}
void sum17_sum(TREE * root,int *sum)
{
	if(root!=NULL)
    {
        sum17_sum(root->left,sum);
        *sum+=root->data;
        sum17_sum(root->right,sum);
    }
}
void sum17(int a[])
{
	TREE *root;
	root=NULL;
	int sum=0;
	for(int i=0;i<SIZE;i++)
		root=sum17_insert(root,a[i]);
	sum17_sum(root,&sum);
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);
	sum=0;
}
//Transpose of the matrix and then find the sum.

void sum18(int a[])
{
	int sum=0;
	int transpose[SIZE][1];
	for(int i=0;i<SIZE;i++)
		transpose[i][0]=a[i];
	for(int i=0;i<SIZE;i++)
		sum+=transpose[i][0];
	printf("SUM OF THE ARRAY ELEMENTS IS %d\n",sum);
	
}
//Rotate the array and find the sum.
void sum19(int a[])
{
	int temp;
	int sum=0;
	temp=a[0];
	for(int i=0;i<(SIZE-1);i++)
		a[i]=a[i+1];
	a[SIZE-1]=temp;
	for(int i=0;i<SIZE;i++)
		sum+=a[i];
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);


}
//Sort the array in wave form and then find the sum of the array.
void sum20(int a[])
{
	int temp;
	int j,n; 
	for(int i=1;i<=(SIZE-1);i++)
	{
		n=a[i];
		j=i-1;
		while(j>=0 && a[j]>n)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=n;
	}
	int b=0,c=0;
	int sum=0;
	for(int i=0;c<SIZE;i++)
	{
		c=b+(i+2);
		b+=(i+1);
		temp=a[b];
		a[b]=a[c];
		a[c]=temp;
		
	}
	for(int i=0;i<SIZE;i++)
		sum+=a[i];
	printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);


}
//MAIN

int main()
{
	int a[SIZE];
	int sum=0;
	int choice;
	
	while (1)
	{
		printf("ENTER A NUMBER BETWEEN 1 TO 20\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum1((a));
				break;
			case 2:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum2(a,SIZE-1,&sum);
				printf("SUM OF ARRAY ELEMENTS IS %d\n",sum);
				sum=0;
				break;
			case 3:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum3(a);
				break;
			case 4:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum4(a);
				break;
			case 5:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum5(a);
				break;
			case 6:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum6(a);
				break;
			case 7:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum7(a);
				break;
			case 8:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum8(a);
				break;
			case 9:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum9(a);
				break;
			case 10:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum10(a);
				break;
			case 11:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum11(a);
				break;
			case 12:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum12(a);
				break;
			case 13:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum13(a);
				break;
			case 14:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum14(a);
				break;
			case 15:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum15(a);
				break;
			case 16:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum16(a);
				break;
			case 17:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum17(a);
				break;
			case 18:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum18(a);
				break;	
			case 19:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum19(a);
				break;
			case 20:
				for(int i=0;i<SIZE;i++)
					a[i]=18-i;
				sum20(a);
				break;
			/*case 21:
				sum21(a);
				break;
			case 22:
				sum22(a);
				break;
			case 23:
				sum23(a);
				break;
			case 24:
				sum24(a);
				break;
			case 25:
				sum25(a);
				break;*/
		}
	}

}