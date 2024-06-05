#include<stdio.h>
#include<stdlib.h>
#define size 5
int a[size],front=-1,rear=-1;
void ENQUEUE();
void DEQUEUE();
void DISPLAY();
void main()
{
	int ch;
	printf("\n 1.ENQUEUE");
	printf("\n 2.DEQUEUE");
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
				ENQUEUE();
				break;
			}
			case 2:
			{
				DEQUEUE();
				break;
			}
			case 3:
			{
				DISPLAY();
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
void ENQUEUE()
{
	int data;
	if(rear==size-1)
	{
		printf("\n QUEUE OVERFLOW");
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		printf("\n enter data to ENQUEUE:");
		scanf("%d",&data);
		rear++;
		a[rear]=data;
	}
}
void DEQUEUE()
{
	if(front==-1||front>rear)
	{
		printf("\n QUEUE UNDERFLOW");
	}
	else
	{
		printf("\n the dequeued element is %d",a[front]);
		front++;
	}
}
void DISPLAY()
{
	int i;
	if(front==-1||front>rear)
	{
		printf("\n QUEUE UNDERFLOW");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d \t",a[i]);
		}
	}
}
