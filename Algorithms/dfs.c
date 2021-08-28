#include <stdio.h>
#include <stdlib.h>
#define max 10

int visited[10];
int order[20];
int oi;
void dfs(int m[max][max],int v,int source)
{
	int i;
	for(int i=0;i<v;i++)
	{
		if(m[source][i]==1 && visited[i]==0)
		{
			visited[i]=1;
			order[oi++]=i;
			dfs(m,v,i);
		}
	}
}
int main()
{
	int m[max][max];
	int v;
	int source;
	for(int i=0;i<10;i++)
		visited[i]=0;
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
	visited[source]=1;
	printf("%d\n",source);
	order[oi++]=source;
	dfs(m,v,source);

	for (int i=0;i<oi;i++){
		printf("%d\n",order[i]);
	}
}