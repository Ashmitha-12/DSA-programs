#include<stdio.h>
#include<stdlib.h>
void create();
void traverse();
void insertatbegin();
void insertatend();
void insertatlocation();
void deleteatbegin();
void deleteatend();
void deleteatlocation();
struct Node
{
	int info;
	struct Node *next;
};
struct Node *start=NULL,*temp,*newnode,*ptr;
void main()
{
	int ch;
	printf("\n1.Create");
	printf("\n2.Traverse");
	printf("\n3.Insertatbegin");
	printf("\n4.Insertatend");
	printf("\n5.Insertatlocation");
	printf("\n6.Deleteatbegin");
	printf("\n7.Deleteatend");
	printf("\n8.Deleteatlocation");
	printf("\n9.Exit");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				traverse();
				break;
			case 3:
				insertatbegin();
				break;
			case 4:
				insertatend();
				break;
			case 5:
				insertatlocation();
				break;
			case 6:
				deleteatbegin();
				break;
			case 7:
				deleteatend();
				break;
			case 8:
				deleteatlocation();
				break;
			case 9:
				exit(0);
			default:
				printf("\nInvalid choice");
	    }
    }
}
void create()
{
	int total,i,item;
	if(start==NULL)
	{
		printf("\nEnter the number of nodes you want to create:");
	    scanf("%d",&total);
	    if(total<=0)
	    {
	    	printf("\nList must be greater than zero");
		}
		else
		{
			temp=(struct Node *)malloc(sizeof(struct Node));
			printf("\nEnter the value:");
			scanf("%d",&item);
			temp->info=item;
			temp->next=temp;
			start=temp;
			for(i=2;i<=total;i++)
			{
				newnode=(struct Node*)malloc(sizeof(struct Node));
				printf("\nEnter the value:");
			    scanf("%d",&item);
			    newnode->info=item;
			    newnode->next=newnode;
			    temp->next=newnode;
			    newnode->next=start;
			    temp=newnode;
			}
			printf("\nList is created");
		}
	}
	else
	{
		printf("\nList already present");
	}
}
void traverse()
{
	if(start==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		temp=start;
		printf("\nValues of linked list are:");
		do
		{
			printf("%d\t",temp->info);
			temp=temp->next;
		}
		while(temp!=start);
	}
}
void insertatbegin()
{
	int item;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	if(newnode==NULL)
	{
		printf("\nMemory is not allocated");
	}
	else
	{
		printf("\nEnter the value to insert:");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=newnode;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			temp=start;
			while(temp->next!=start)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->next=start;
			start=newnode;
		}
	}
}
void insertatend()
{
	int item;
	newnode=(struct Node *)malloc(sizeof(struct Node));
	if(newnode==NULL)
	{
		printf("\nMemory is not allocated");
	}
	else
	{
		printf("\nEnter the value to insert:");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=newnode;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			temp=start;
			while(temp->next!=start)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->next=start;
		}
	}
}
void insertatlocation()
{
	int count=1,loc,item;
	newnode=(struct Node *)malloc(sizeof(struct Node));
	temp=start;
    if(newnode==NULL)
	{
		printf("\nMemory is not allocated");
	}
	else
	{
		printf("\nEnter value to insert:");
        scanf("%d",&item);
        newnode->info=item;
		newnode->next=NULL;
		if(start==NULL)
		{
			start==newnode;
		}
		else
		{
		    printf("\n enter location at which you want to insert:");
		    scanf("%d",&loc);
		    temp=start;
		    do
		    {
			    count++;
			    ptr=temp;
			    temp=temp->next;
		    }while(temp!=start && count!=loc);
		    if(temp==NULL)
		    {
			    printf("\nNode is not present");
		    }
		    else
		    { 
			    ptr->next=newnode;
			    newnode->next=temp;
		    }
	    }
    }
}
void deleteatbegin()
{
	if(start==NULL)
	{
		printf("\n List is empty");
	}
	else
	{
		temp=start;
		ptr=start;
		while(ptr->next!=start)
		{		
			ptr=ptr->next;
		}
		printf("\n The deleted value is %d",temp->info);
		start=start->next;
		if(temp->next==ptr->next)
		{
			start=NULL;
		}
		ptr->next=start;
		free(temp);
	}
}
void deleteatend()
{
	if(start==NULL)
	{
		printf("\n List is empty");
	}
	else
	{
		temp=start;
		ptr=start;
		if(start->next==NULL)
		{
			start=NULL;
		}
		else
		{
			while(temp->next!=start)
			{
				ptr=temp;
				temp=temp->next;
			}
		    ptr->next=NULL;
		}
		printf("\n The deleted value is %d",temp->info);
		if(temp->next==ptr->next)
		{
			start=NULL;
		}
		ptr->next=start;
		free(temp);
	}
}
void deleteatlocation()
{
	int loc=0,count=1;
	if(start==NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		temp=start;
		if(start->next==start)
		{
			start=NULL;
			printf("\n The deleted value is %d",temp->info);
			free(temp);
		}
		else
		{
			printf("\n Enter the location which you want to delete:");
			scanf("%d",&loc);
			while(temp!=NULL && count!=loc)
			{
				ptr=temp;
				temp=temp->next;
				count++;
		    }
		    if(temp==NULL)
			{
				printf("\n Node is empty");
			}
			else
			{
				ptr->next=temp->next;
				printf("\n The deleted element is %d",temp->info);
				free(temp);
			}
		}
	}
}
