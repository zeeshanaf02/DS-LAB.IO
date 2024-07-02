#include<stdio.h>
#include<stdbool.h>
bool subsetsum(int set[],int n,int sum)
{
	bool dp[n+1][sum+1];
	for(int i=0;i<=n;i++)
	dp[i][0]=true;
	
	for(int i=1;i<=sum;i++)
	dp[0][i]=false;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j<set[i-1])
			dp[i][j]=dp[i-1][j];
			else
			dp[i][j]=dp[i-1][j]||dp[i-1][j-set[i-1]];
		}
	}
	if(dp[n][sum])
	{
		printf("Subset with the given sum if found:");
		int i=n,j=sum;
		while(i>0&&j>0)
		{
			if(dp[i][j]&&!dp[i-1][j])
			{
				printf("%d ",set[i-1]);
				j-=set[i-1];
			}
			i--;
		}
		printf("\n");
		return true;
	}
	else
	{
		printf("No subset with the given sum exists.\n");
		return false;
	}
}
int main()
{
	int n,sum;
	printf("Enter the no of elements in the set:");
	scanf("%d",&n);
	
	int set[n];
	printf("Enter the elements of the set:\n");
	for(int i=0;i<n;i++)
	scanf("%d",&set[i]);
	printf("Enter the desired sum:");
	scanf("%d",&sum);
	subsetsum(set,n,sum);
	return 0;
}