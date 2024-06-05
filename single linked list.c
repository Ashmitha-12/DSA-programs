#include<stdio.h>
#include<stdlib.h>
void create();
void insertatbegin();
void insertatend();
void insertatlocation();
void traverse();
void deleteatbegin();
void deleteatend();
void deleteatlocation();
//node creates
struct Node
{
	int info;
	struct Node *next;
};
struct Node *start=NULL;
int main()
{
	int ch;
	printf("\n 1.create");
	printf("\n 2.insertatbegin");
	printf("\n 3.insertatend");
	printf("\n 4.insertatlocation");
	printf("\n 5.traverse");
	printf("\n 6.deleteatbegin");
	printf("\n 7.deleteatend");
	printf("\n 8.deleteatlocation");
	printf("\n 9.exit");
	while(1)
	{
		printf("\n enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					create();
					break;
				}
			case 2:
				{
					insertatbegin();
					break;
				}
			case 3:
				{
					insertatend();
					break;
					
				}
			case 4:
				{
					insertatlocation();
					break;
				}
			case 5:
				{
					traverse();
					break;
				}
			case 6:
				{
					deleteatbegin();
					break;
				}
			case 7:
				{
				    deleteatend();
					break;	
				}
			case 8:
				{
					deleteatlocation();
					break;
				}
			case 9:
				{
					exit(0);
					break;
				}
			default:
				{
					printf("\n invalid choice");
				}
		}	
	}
}
//create list
void create()
{ 
    int total,index,item;
	struct Node *temp,*newnode;
	if(start==NULL)
	{ 
     	printf("\n enter the no of nodes you want to create:");
     	scanf("%d",&total);
	    if(total<=0)
      	{
      		printf("\n list must be greater than zero");
     	}
     	else
     	{
     	    temp=(struct Node*)malloc(sizeof(struct Node));
     	    printf("\n enter the value to keep in node:");
     	    scanf("%d",&item);
     	    temp->info=item;
     	    temp->next=NULL;
     	    start=temp;
     	    for(index=2;index<=total;index++)
     	    {
     	    	newnode=(struct Node*)malloc(sizeof(struct Node));
     	    	printf("\n enter the value to keep in node:");
     	        scanf("%d",&item);
     	        newnode->info=item;
     	        newnode->next=NULL;
     	        temp->next=newnode;
     	        temp=newnode;
			}
			printf("\n list is created");
		}
    }
    else
    {
    	printf("\n list already present");
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
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			newnode->next=start;
			start=newnode;
		}
	}
}
//traverse code
void traverse()
{
	struct Node *temp;
	if(start==NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		temp=start;
		printf("\n values of linked list are:");
		while(temp!=NULL)
		{
			printf("%d \t",temp->info);
			temp=temp->next;
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
		}
	}
}
//insertatlocation code
void insertatlocation()
{
	struct Node *newnode,*temp,*ptr;
	int item,count,loc
	;
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
		newnode->next=temp;
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
	struct Node *temp,*ptr;
	int loc,count=1;
	if(start==NULL)
	{
		printf("\n list is empty");
	}
	else
	{ 
	    printf("\n enter location at which you want to delete:");
		scanf("%d",&loc);
		temp=start;
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
				ptr->next=temp->next;
				printf("\n deleted value is %d",temp->info);
				free(temp);
			}
	    }
    }
}
