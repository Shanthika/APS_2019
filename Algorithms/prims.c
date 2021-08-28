#include <stdio.h>

int v;

int minkey(int key[],int mstset[]){
	int min = 10000000;
	int min_index;
	for(int i=0;i<v;i++){
		if(mstset[i] == 0 && key[i]<min){
			min = key[i];
			min_index = i;
		}

	}
	return min_index;
}

int printmst(int parent[],int n,int graph[v][v]){
	printf("Edge weight\n");
	for(int i=1;i<v;i++)
	printf("%d - %d   %d\n", parent[i],i,graph[i][parent[i]]);
}

void primalg(int adjmat[v][v]){
	int parent[v];
	int key[v];
	int mstset[v];

	for (int count=0;count<(v-1);count++){
		int u = minkey(key,mstset);
		mstset[u]=1;

		for(int i=0;i<v;i++){
			if(adjmat[u][i] &&mstset[i]==0 && adjmat[u][i]<key[i]){
				parent[i] = u;
				key[i] = adjmat[u][i];
			}

		}

	}
	printmst(parent,v,adjmat);
}



int main(){
	scanf("%d",&v);
	int adjmat[v][v];
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			scanf("%d",&adjmat[i][j]);
		}
	}

	primalg(adjmat);
}