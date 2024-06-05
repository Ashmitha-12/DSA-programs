#include <stdio.h>
#include <stdlib.h>
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
	struct Node *prev;
};
struct Node *start=NULL,*temp,*newnode,*ptr;
int main()
{
	int ch;
	printf("\n 1.Create");
	printf("\n 2.Traverse");
	printf("\n 3.insertatbegin");
	printf("\n 4.insertatend");
	printf("\n 5.insertatlocation");
	printf("\n 6.deleteatbegin");
	printf("\n 7.deleteatend");
	printf("\n 8.deleteatlocation");
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
				break;
			default:printf("Invalid choice");
		}
	}
}
//create code
void create()
{
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
		   temp=(struct Node*)malloc(sizeof(struct Node));
		   printf("\n Enter value to keep in node:");
		   scanf("%d",&item);
		   temp->info=item;
		   temp->next=temp;
		   temp->prev=temp;
		   start =temp;
		   for(index=2;index<=total;index++)
		   {
			   newnode=(struct Node*)malloc(sizeof(struct Node));
			   printf("\n Enter value to keep in node:");
		       scanf("%d",&item);
		       newnode->info=item;
		       newnode->next=start;
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
	if(start==NULL)
	{
		printf("\n List is empty");
	}
	else
	{
		temp =start;
		printf("\n Values of Linked list are:");
		do
		{
			printf("%d \t",temp->info);
			temp=temp->next;
	    }
		while(temp!=start);
    }
}
//insertatbegin code
void insertatbegin()
{
	int item;
	newnode=(struct Node *)malloc(sizeof(struct Node));
	if(newnode==NULL)
	{
		printf("\n memory is not allocated");
	}
	else
	{
		printf("\n enter the value to insert");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=newnode;
		newnode->prev=newnode;
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
			newnode->next=newnode;
			newnode->next=start;
			newnode->prev=temp;
			start=newnode;
		}
	}
}
//insertatend code
void insertatend()
{
	int item;
	newnode=(struct Node *)malloc(sizeof(struct Node));
	if(newnode==NULL)
	{
		printf("\n memory is not allocated");
	}
	else
	{
		printf("\n enter value to insert");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=newnode;
		newnode->prev=newnode;
		if(start==NULL)
		{
			start==newnode;
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
			newnode->prev=temp;
		}
	}
}
//insertatlocation code
void insertatlocation()
{
	int item,count=1,loc;
	newnode=(struct Node *)malloc(sizeof(struct Node));
	if(newnode==NULL)
	{
		printf("\n memory is not allocated");
	}
	else
	{
		printf("\n Enter a location to insert:");
	    scanf("%d",&loc);
		printf("\n Enter a value to insert:");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=newnode;
		newnode->prev=newnode;
		temp=start;
		do
		{
			count++;
			ptr=temp;
			temp=temp->next;
		}while(temp!=NULL && count!=loc);
		if(temp==NULL )
		{
			printf("\n Node is not present");
		}
		else
		{
			ptr->next=newnode;
			newnode->prev=ptr;
			newnode->next=temp;

		}
	}
}
//deleteatbegin code
void deleteatbegin()
{
	if(start==NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		temp=start;
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		printf("\n deleted value is %d",temp->info);
		start=start->next;
		free(temp);
	}
}
//deleteatend code
void deleteatend()
{
	if(start==NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		temp=start;
		ptr=NULL;
		if(start->next!=NULL)
		{
			start=NULL;
		}
		else
		{
	     	while(temp->next!=NULL)
	     	{
	    		ptr=temp;
	    		temp=temp->next;
	    	}
	    	if(ptr=NULL)
	    	{
	    		printf("\n deleted value is %d",temp->info);
	    		free(temp);
	    		start=NULL;
			}
			else
			{
		        ptr->next=start;
	        	printf("\n deleted value is %d",temp->info);
	        	start->prev=ptr;
	        	free(temp);
	        }
	    }
	}
}
//deleteatlocation code
void deleteatlocation()
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
			do
			{
				ptr=temp;
				temp=temp->next;
				count++;
		    }while(temp!=NULL && count!=loc);
		    if(temp==NULL)
			{
				printf("\n Node is empty");
			}
			else
			{
				ptr->next=temp->next;
				temp->prev=ptr;
				printf("\n The deleted element is %d",temp->info);
				free(temp);
			}
		}
	}
}
