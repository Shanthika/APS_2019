void push(STACK *s,int data)
{
	s->top++;
	s->data[s->top]=data;
}

void max_key(int H[],int n,STACK *s)
{
	int temp;
	int i=1;	
	while(n>0)
	{
		push(s,H[i]);
		printf("%d\n",H[i]);
		temp=H[i];
		H[i]=H[n];
		H[n]=temp;
		n--;
		heap(H,n);
		
	}

}
void heap(int H[],int n)
{
	int k,j,v,heap;
	for(int i=floor(n/2);i>0;i--)
	{
		k=i;
		v=H[k];
		heap=FALSE;
		while(heap!=TRUE && 2*k<=n)
		{
			j=2*k;
			if(j<n)
			{
				if(H[j]<H[j+1])
					j++;
			}
			if(v>=H[j])
				heap=TRUE;
			else
			{
				H[k]=H[j];
				k=j;
			}
		}
		H[k]=v;
	}
}
void display(STACK *s)
{
	int data;
	while(s->top>-1)
	{
		data=s->data[s->top];
		s->top--;
		printf("%d\n",data);	
	}

}

int main()
{
	int H[MAX];
	int n=10;
	STACK s;
	s.top=-1;
	for(int i=1;i<=n;i++)
	{
		H[i]=(rand()%20)*i;
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",H[i]);
	heap(H,n);
	max_key(H,n,&s);
	display(&s);

}