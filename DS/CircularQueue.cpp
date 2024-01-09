#include<stdio.h>
#define SIZE 5
int CQ[SIZE];
int front=-1;
int rear=-1,ch;
int ISCQ_Full();
int ISCQ_Empty();
void CQ_Insert(int);
void CQ_delete();
void CQ_Display();
int main()
{
	printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
	while(1){
		int ele;
		printf("\nEnter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(ISCQ_Full())
			printf("Circular Queue Overflow\n");
			else{
				printf("Enter the element to be inserted:\n");
				scanf("%d",&ele);
				CQ_Insert(ele);
			}
			break;
			case 2:if(ISCQ_Empty())
			printf("Circular Queue Underflow\n");
			else
			CQ_delete();
			break;
			case 3:if(ISCQ_Empty())
			printf("circular Queue Underflow\n");
			else
			CQ_Display();
			break;
			default: printf("Invalid choice\n");
		}
	}
}
void CQ_Insert(int item)
{
	if(front==-1)
	front++;
	rear=(rear+1)%SIZE;
	CQ[rear]=item;
}
void CQ_delete()
{
	int item;
	item=CQ[front];
	printf("Deleted element is :%d",item);
	front=(front+1)%SIZE;
}
void CQ_Display()
{
	int i;
	if(front==-1)
	printf("Circular Queue is Empty\n");
	else
	{
		printf("Elements of the circular queue are:\n");
		for(i=front;i!=rear;i=(i+1)%SIZE)
		{
			printf("%d\t",CQ[i]);
		}
		printf("%d\n",CQ[i]);
		printf("The rear is are %d and front is at %d",rear,front);
	}
}
int ISCQ_Full()
{
	if(front==(rear+1)%SIZE)
	return 1;
	return 0;
}
int ISCQ_Empty()
{
	if(front==-1)
	return 1;
	else if(front==rear)
	{
		printf("Deleted elements is:%d\n",CQ[front]);
		front=-1;
		return 1;
	}
	return 0;
}