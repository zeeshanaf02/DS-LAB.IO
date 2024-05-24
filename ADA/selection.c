#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionsort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}
int main()
{
	int n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int arr[n];
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		arr[i]=rand()%1000;
	}
	clock_t start_time=clock();
	selectionsort(arr,n);
	clock_t end_time=clock();
	double time_taken=((double)(end_time-start_time))/CLOCKS_PER_SEC;
	printf("Time taken to sort %d elements:%lf seconds.\n",n,time_taken);
	return 0;
}
