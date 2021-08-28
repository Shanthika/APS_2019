#include <stdio.h>
#include <stdlib.h>
#define max 10
void bfs(int m[max][max],int v,int source)
{
	int queue[20];
	int front=0;
	int rear=0;
	int u;
	int visited[max]={0};
	queue[rear]=source;
	visited[source]=1;
	while(front<=rear)
	{
		u=queue[front];
		printf("%d\n",u);
		front+=1;
		for(int i=0;i<v;i++)
		{
			if(m[u][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				rear+=1;
				queue[rear]=i;
			}
		}
	}

}
int main()
{
	int m[max][max];
	int v;
	int source;
	printf("Enter no.of vertices\n");
	scanf("%d",&v);
	printf("Enter source\n");
	scanf("%d",&source);
	printf("Enter adjacency matrix\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			printf("m[%d][%d]=",i,j);
			scanf("%d",&m[i][j]);
			printf("\n");
		}
	}
	bfs(m,v,source);
}