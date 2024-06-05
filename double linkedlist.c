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
void minmax();
void evenodd();
void sorting();
struct Node
{
	int info;
	struct Node *next;
	struct Node *prev;
};
struct Node *start=NULL;
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
	printf("\n 9.min-max");
	printf("\n 10.evenodd");
	printf("\n 11.sorting");
	printf("\n 12.Exit");
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
				minmax();
				break;
			case 10:
				evenodd();
				break;
			case 11:
				sorting();
				break;
			case 12:
			    exit(0);
				break;
			default:printf("Invalid choice");
		}
	}
}
//create code
void create()
{
	struct Node *temp,*newnode;
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
		   temp->next=NULL;
		   temp->prev=NULL;
		   start =temp;
		   for(index=2;index<=total;index++)
		   {
			   newnode=(struct Node*)malloc(sizeof(struct Node));
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
	struct Node *temp;
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
	    while(temp->next!=NULL)
	    {
	    	temp=temp->next;
	    }
	    while(temp!=NULL)
	    {
	    	printf("%d \t",temp->info);
			temp=temp->prev;
	    		
		}
	    	
	}
		
}
//insertatbegin code
void insertatbegin()
{
	struct Node *newnode;
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
		newnode->next=NULL;
		newnode->prev=NULL;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			newnode->next=start;
			start->prev=newnode;
			start=newnode;
		}
	}
}
//insertatend code
void insertatend()
{
	struct Node *newnode,*temp;
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
		newnode->next=NULL;
		newnode->prev=NULL;
		if(start==NULL)
		{
			start==newnode;
		}
		else
		{
			temp=start;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->prev=temp;
		}
	}
}
//insertatlocation code
void insertatlocation()
{
	struct Node *newnode,*temp,*ptr;
	int item,count,loc;
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
		newnode->next=NULL;
		newnode->prev=NULL;
		if(start==NULL)
		{
			start==newnode;
		}
		else
		{
		    printf("\n enter location at which you want to insert:");
		    scanf("%d",&loc);
		    temp=start;
		    while(temp!=NULL && count!=loc)
		    {
		    	count++;
		    	ptr=temp;
		    	temp=temp->next;
		    	if(temp==NULL)
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
    }
}
//deleteatbegin code
void deleteatbegin()
{
	struct Node *temp;
	if(start==NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		temp=start;
		start=start->next;
		start->prev=NULL;
		printf("\n deleted value is %d",temp->info);
		free(temp);
	}
}
//deleteatend code
void deleteatend()
{
	struct Node *temp,*ptr;
	if(start==NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		temp=start;
		while(temp->next!=NULL)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=NULL;
		printf("\n deleted value is %d",temp->info);
		free(temp);
	}
}
//deleteatlocation code
void deleteatlocation()
{
	struct Node *temp,*ptr,*ptr1;
	int loc,count;
	if(start==NULL)
	{
		printf("\n list is empty");
	}
	else
	{ 
	    temp=start;
	    printf("\n enter location at which you want to delete:");
		scanf("%d",&loc);
		count=1;
		while(temp!=NULL && count!=loc)
		{
			ptr=temp;
		   	count=count+1;
		   	temp=temp->next;
		   	if(temp==NULL)
		   	{
		   		printf("\n Node is not present");
			}
			else
			{
				ptr1=temp->next;
				ptr->next=ptr1;
				ptr1->prev=ptr;
				printf("\n deleted value is %d",temp->info);
				free(temp);
			}
	    }
    }
}
void minmax()
{
	struct Node *temp;
	int large,small,i;
	temp=start;
	large=small=temp->info;
	for(i=0;temp!=NULL;i++)
	{
		if(large<temp->info)
		{
			large=temp->info;
		}
		if(small>temp->info)
		{
			small=temp->info;
		}
		temp=temp->next;
	}
	printf("\n maximum value=%d",large);
	printf("\n minimum value=%d",small);
}
void evenodd()
{
	struct Node *temp;
	int even,odd;
	temp=start;
	while(temp!=NULL)
	{
    	if(temp->info%2==0)
    	{
    		printf("\n%d is even number",temp->info);
    	}
    	else
     	{
	    	printf("\n%d is odd number",temp->info);
	    }
     	temp=temp->next;
    }
}
void sorting()
{
	struct Node *temp=NULL,*ptr=NULL;
	int temp1;
	printf("\n elements before sorting are:",temp->info);
	temp=start;
	if(start==NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		for(temp=start;temp->next!=NULL;temp=temp->next)
		{
			for(ptr=temp->next;ptr!=NULL;ptr=ptr->next)
			{
				if(temp->info>ptr->info)
				{
					temp1=temp->info;
					temp->info=ptr->info;
					ptr->info=temp1;
				}
			}
		}
	}
	while(temp-info!=NULL);
}
