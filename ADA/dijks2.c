#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 7
int mindist(int dist[],bool sptset[])
{
	int min=INT_MAX,min_index;
	for(int v=0;v<V;v++)
		if(sptset[v]==false&&dist[v]<=min)
			min=dist[v],min_index=v;
	return min_index;
}
void printsl(int dist[])
{
	printf("Vertex\t\t Distance from source\n");
	for(int i=0;i<V;i++)
		printf("%d\t\t\t %d\n",i,dist[i]);
}
void dijk(int graph[V][V],int src)
{
	int dist[V];
	bool sptset[V];
	for(int i=0;i<V;i++)
		dist[i]=INT_MAX,sptset[i]=false;
	dist[src]=0;
	for(int count=0;count<V-1;count++)
	{
		int u=mindist(dist,sptset);
		sptset[u]=true;
		for(int v=0;v<V;v++)
			if(!sptset[v]&&graph[u][v]&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v])
				dist[v]=dist[u]+graph[u][v];
	}
	printsl(dist);
}
int main()
{
	int graph[V][V]={
		{0,1,0,0,0,1,0},
		{0,0,1,0,0,0,0},
		{0,0,0,1,1,0,0},
		{0,0,0,0,1,0,1},
		{0,0,0,0,0,0,1},
		{0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0}};
	dijk(graph,0);
	return 0;
}
