#include<stdio.h>
#define INF 9999
#define MAX 10
void dijks(int G[MAX][MAX],int n,int stnode);
int main()
{
	int G[MAX][MAX],i,j,n,u;
	printf("Enter the no of vertices:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	printf("Enter the starting node:");
	scanf("%d",&u);
	dijks(G,n,u);
	return 0;
}
void dijks(int G[MAX][MAX],int n, int stnode)
{
	int cost[MAX][MAX],dist[MAX],pred[MAX];
	int visited[MAX],count,mindist,nextnode,i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INF;
			else
				cost[i][j]=G[i][j];
	for(i=0;i<n;i++)
	{
		dist[i]=cost[stnode][i];
		pred[i]=stnode;
		visited[i]=0;
	}
	dist[stnode]=0;
	visited[stnode]=1;
	count=1;
	while(count<n-1)
	{
		mindist=INF;
		for(i=0;i<n;i++)
			if(dist[i]<mindist&&!visited[i])
			{
				mindist=dist[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i<n;i++)
			if(!visited[i])
				if(mindist+cost[nextnode][i]<dist[i])
				{
					dist[i]=mindist+cost[nextnode][i];
					pred[i]=nextnode;
				}
		count++;
		for(i=0;i<n;i++)
			if(i!=stnode)
			{
				printf("\nDistance of node %d=%d",i,dist[i]);
				printf("\nPath=%d",i);
				j=i;
				do
				{
					j=pred[j];
					printf("<-%d",j);
				}while(j!=stnode);
			}
	}
}
