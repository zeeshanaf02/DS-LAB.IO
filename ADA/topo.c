#include<stdio.h>
int toposort(int a[10][10],int n,int indeg[10]);
int main()
{
	int a[10][10],indeg[10]={0},i,j,n;
	printf("Enter the no of nodes:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==1)
				indeg[j]++;
		}
	}
	printf("The topological sorted array is:\n");
	toposort(a,n,indeg);
	return 0;
}
int toposort(int a[10][10],int n,int indeg[10])
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(indeg[i]==0)
		{
			printf("%d\t",i);
			indeg[i]--;
			for(j=1;j<=n;j++)
				if(a[i][j]==1)
					indeg[j]--;
			i=1;
		}
	}
	printf("\n");
}
