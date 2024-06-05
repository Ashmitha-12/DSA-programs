#include<stdio.h>
#include<stdlib.h>
void create();
void traverse();
void insertatbegin();
void insertatend();
void insertatloc();
void deleteatbegin();
void deleteatloc();
void deleteatend();
struct node
{
	int info;
	struct node *next;
	struct node *prev;
};
struct node *start=NULL,*newnode,*temp,*ptr;
void main()
{
	int ch;
	printf("\n 1.Create");
	printf("\n 2.Traverse");
	printf("\n 3.Insert at begin");
	printf("\n 4.Insert at end");
	printf("\n 5.Insert at specific location");
	printf("\n 6.Delete at begin");
	printf("\n 7.Delete at end");
	printf("\n 8.Delete at specific location");
	printf("\n 9.Exit");
	while(1)
	{
		printf("\n Enter your choice:");
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
				insertatloc();
				break;
			case 6:
				deleteatbegin();
				break;
			case 7:
				deleteatend();
				break;
			case 8:
				deleteatloc();
				break;
			case 9:
				exit(0);
			default:
			printf("\n Invalid option");
	    }
	} 
}
//create code
void create()
{
	struct node *temp,*newnode;
	int total,index,item;
	if(start==NULL)
	{
		printf("\n Enter the total number of nodes you want to create:");
		scanf("%d",&total);
	    if(total<=0)
	    {
		   printf("\n List must be greater than zero");
	    }
	    else
	    {
		   temp=(struct node*)malloc(sizeof(struct node));
		   printf("\n Enter value to keep in node:");
		   scanf("%d",&item);
		   temp->info=item;
		   temp->next=NULL;
		   temp->prev=NULL;
		   start =temp;
		   for(index=2;index<=total;index++)
		   {
			   newnode=(struct node*)malloc(sizeof(struct node));
			   printf("\n Enter value to keep in node:");
		       scanf("%d",&item);
		       newnode->info=item;
		       newnode->next=NULL;
		       newnode->prev=temp;
		       temp->next=newnode;
		       temp=newnode;
		   }
		   printf("\n List is created");
	    }   
    }
    else
    {
    	printf("\n List is already present");
	}
}
//traverse code
void traverse()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("\n List is empty");
	}
	else
	{
		temp =start;
		printf("\n Values of Linked list are:");
		while(temp!=NULL)
		{
			printf("%d \t",temp->info);
			temp=temp->next;
	    }
	    temp=start;
	    printf("\n Values of Linkedlist in reverse order are:");
	    do
	    {
	    	temp=temp->next;
		} while(temp->next!=NULL);
		do
		{
			printf("%d \t",temp->info);
			temp=temp->prev;
		}while(temp!=NULL);
	}
}
void insertatbegin()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n Enter a value to insert:");
	scanf("%d",&newnode->info);
	newnode->next=newnode;
	newnode->prev=newnode;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		temp=start;
		do
		{			
			temp=temp->next;
		}while(temp->next!=start);
		temp->next=newnode;
		newnode->next=start;
		newnode->prev=start->prev;
		start->prev=newnode;
		start=newnode;
	}
}
void insertatend()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n Enter a value to insert:");
	scanf("%d",&newnode->info);
	newnode->next=NULL;
	newnode->prev=NULL;
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
			newnode->prev=temp;
			newnode->next=start;
	}
}
void insertatloc()
{
	struct node *ptr;
	int loc,count=1;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n Memory is not allocated");
	}
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\n Enter a location to insert:");
	    scanf("%d",&loc);
		printf("\n Enter a value to insert:");
		scanf("%d",&newnode->info);
		newnode->next=NULL;
		newnode->prev=NULL;
		temp=start;
		while(temp!=NULL && count!=loc)
		{
			count++;
			ptr=temp;
			temp=temp->next;
		}
		if(temp==NULL )
		{
			printf("\n Node is not present");
		}
		else
		{
			ptr->next=newnode;
			newnode->next=temp;
			temp->prev=newnode;
			newnode->prev=ptr;
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
		else
		{
		ptr->next=start;
		start->prev=ptr;
		free(temp);
		}
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
		ptr=NULL;
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
			if(ptr==NULL)
			{
				printf("\n The deleted value is %d",temp->info);
				free(temp);
				start=NULL;
			}
			else
			{
			ptr->next=start;
		    printf("\n The deleted value is %d",temp->info);
		    start->prev=ptr;
		    free(temp);
			}
		}
	}
}
void deleteatloc()
{
	struct node *ptr1;
	int loc=0,count=1;
	if(start==NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		temp=start;
		if(start->next==NULL)
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
				ptr1=temp->next;
				ptr->next=ptr1;
				ptr1->prev=ptr;
				printf("\n The deleted element is %d",temp->info);
				free(temp);
			}
		}
	}
}
