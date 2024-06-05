#include<stdio.h>
#include<stdlib.h>
#define size 5
int a[size],front=-1,rear=-1;
void insert();
void delete();
void display();
void main()
{
	int ch;
	printf("\n 1.INSERT");
	printf("\n 2.DELETE");
	printf("\n 3.DISPLAY");
	printf("\n 4.EXIT");
	while(1)
	{
		printf("\n enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				insert();
				break;
			}
			case 2:
			{
				delete();
				break;
			}
			case 3:
			{
				display();
				break;
			}
			case 4:
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
void insert()
{
	int item;
	if(front==0&&rear==size-1||front==rear+1)
	{
		printf("\n QUEUE OVERFLOW");
	}
	else
	{
		int item;
		printf("\n enter item to insert:");
		scanf("%d",&item);
		if(rear==-1)
		{
			front=0;
			rear=0;
		}
		else if(rear==size-1)
		{
			rear=0;
		}
		else
		{
			rear=rear+1;
			a[rear]=item;
		}
	}
}
void delete()
{
	int item;
	if(front==-1)
	{
		printf("QUEUE UNDERFLOW");
	}
	else
	{
		printf("\n deleted element is %d",a[front]);
	    if(rear==front)
	    {
		    front=-1;
			rear=-1;
	    }
	    else if(front==size-1)
	    {
	      	front=0;
	    }
	    else
	    {
	    	front=front+1;
	    }
    }
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("\n QUEUE UNDERFLOW");
	}
	else 
	{
	    if(front<=rear)
	    {
	    	for(i=front;i<=rear;i++)
	    	    printf("\t %d",a[i]);
		}
		else
		{
			for(i=front;i<size;i++)
			    printf("%d \t",a[i]);
			for(i=0;i<=rear;i++)
			    printf("%d \t",a[i]);
		}
	}
}
