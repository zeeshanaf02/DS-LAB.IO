#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int usn;
	char name[20];
	char branch[20];
	int sem;
	char phone[20];
}student;
struct node
{
	int usn;
	char name[20];
	char branch[20];
	int sem;
	char phone[20];
	struct node *link;
};
typedef struct node* NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("Out of the memory\n");
		exit(0);
	}
	return x;
}
NODE insert_front(student item, NODE first)
{
	NODE temp;
	temp=getnode();
	temp->usn=item.usn;
	strcpy(temp->name,item.name);
	strcpy(temp->branch,item.branch);
	temp->sem=item.sem;
	strcpy(temp->phone,item.phone);
	temp->link=NULL;
	if(first==NULL)
	return temp;
	temp->link=first;
	return temp;
}
NODE insert_rear(student item, NODE first)
{
	NODE temp,cur;
	temp=getnode();
	temp->usn=item.usn;
	strcpy(temp->name,item.name);
	strcpy(temp->branch,item.branch);
	temp->sem=item.sem;
	strcpy(temp->phone,item.phone);
	temp->link=NULL;
	if(first==NULL)
	return temp;
	cur=first;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=temp;
	return first;
	
}
NODE delete_front(NODE first)
{
	NODE temp;
	if(first==NULL)
	{
		printf("Student list is empty\n");
		return NULL;
	}
	temp=first;
	temp=temp->link;
	printf("delete student record: USN=%d\n",first->usn);
	free(first);
	return temp;
}
NODE delete_rear(NODE first)
{
	NODE cur,prev;
	if(first==NULL)
	{
		printf("Student list is empty connot delete\n");
		return first;
	}
	if(first->link==NULL)
	{
		printf("delete student record: USN=%d\n",first->usn);
		free(first);
		return NULL;
	}
	prev=NULL;
	cur=first;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	printf("delete student record: USN=%d\n",cur->usn);
	free(cur);
	prev->link=NULL;
	return first;
}
void display(NODE first)
{
	NODE cur;
	int count=0;
	if(first==NULL)
	{
		printf("Student list is empty\n");
		return;
	}
	cur=first;
	while(cur!=NULL)
	{
		printf("%d\t%s\t%s\t%d\t%s\t\n",cur->usn,cur->name,cur->branch,cur->sem,cur->phone);
		cur=cur->link;
		count++;
	}
	printf("Number of the student=%d\n",count);
}
int main()
{
	NODE first;
	int ch;
	student item;
	first=NULL;
	for(;;)
	{
		printf("1.Insert_front\n2.insert_rear\n3.delete_front\n4.delete_rear\n5.display\n6.exit\n");
		printf("Enter the choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("USN:\n");
			scanf("%d",&item.usn);
			printf("Name:\n");
			scanf("%d",item.name);
			printf("branch:\n");
			scanf("%s",item.branch);
			printf("semester:\n");
			scanf("%d",&item.sem);
			printf("phone:\n");
			first=insert_front(item,first);
			break;
			case 2:printf("USN:\n");
			scanf("%d",&item.usn);
			printf("name:\n");
			scanf("%s",item.name);
			printf("branch:\n");
			scanf("%s",item.branch);
			printf("semester:\n");
			scanf("%d",&item.sem);
			printf("phone:\n");
			scanf("%s",item.phone);
			first=insert_rear(item,first);
			break;
			case 3:first=delete_front(first);
			break;
			case 4:first=delete_rear(first);
			break;
			case 5:display(first);
			break;
			default: exit(0);
		}
	}
}