#include<stdio.h>
struct node
{
   int data;
   struct node *next;
}*front = NULL,*rear = NULL,*newnode,*temp;

void enqueue()
{
   newnode = (struct node*)malloc(sizeof(struct node));
   printf("\n Enter the Data : ");
   scanf("%d",&newnode->data);
   newnode -> next = NULL;

   if(front == NULL)
     	 front = rear = newnode;
   else
   {
      rear -> next = newnode;
      rear = newnode;
   }
   printf("\n Insertion is Success!!!\n");
}
void dequeue()
{
   if(front == NULL)
      printf("\n Queue is Empty!!!\n");
   else
   {
      temp = front;
      front = front -> next;
      printf("\n Deleted element: %d ", temp->data);
      free(temp);
   }
}
void display()
{
	if(front == NULL)
		printf("\nQueue is Empty!!!\n");
   	else
   	{
		temp = front;
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
   printf("\n:: Queue Implementation using Linked List ::\n");
   while(1)
   {
      printf("\n****** MENU ******\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice)
	  {
		case 1: enqueue();	break;
		case 2: dequeue(); 	break;
	            case 3: display(); 	break;
	 	case 4: exit(0);
	 	default: printf("\n Wrong selection!!! Please try again!!!\n");
      }
   }
}

