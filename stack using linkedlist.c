#include<stdio.h>
struct node
{
   int data;
   struct node *next;
}*top = NULL,*temp,*newnode;

void push()
{
	newnode = (struct node*)malloc(sizeof(struct node));
   	printf("\n Enter Element : ");
   	scanf("%d",&newnode->data);
   	if(top == NULL)
	   newnode->next = NULL;
   	else
   	{
	   	newnode->next = top;
	}
	top = newnode;
   	printf("\nInsertion is Success!!!\n");
}

void pop()
{
	if(top == NULL)
		printf("\nStack is Empty!!!\n");
   	else
	{
      temp = top;
      printf("\nDeleted element: %d", temp->data);
      top = temp->next;
      free(temp);
   	}
}
void display()
{
	if(top == NULL)
		printf("\nStack is Empty!!!\n");
   	else
	{
      temp = top;
      while(temp != NULL)
	     {
	 	printf("%d--->",temp->data);
	 	temp = temp -> next;
                   }
   	}
}

void main()
{
   int choice;
   printf("\n:: Stack using Linked List ::\n");
   while(1)
   {
      printf("\n****** MENU ******\n");
      printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice)
	  {
	 		case 1: push();	break;
	 		case 2: pop(); break;
	 		case 3: display(); break;
	 		case 4: exit(0);
	 		default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}

