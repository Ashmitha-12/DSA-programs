#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int info;
	struct Node *lchild;
	struct Node *rchild;
};
struct Node *root=NULL;
void insert();
void inorder(struct Node *);
void preorder(struct Node *);
void postorder(struct Node *);
int delete1();
caseA(struct Node *par,struct Node *ptr)
{
	if(par==NULL)
	{
		root=NULL;
		free(ptr);
	}
	else
	{
	   if(ptr->info<par->info)
	   {
		  par->lchild=NULL;
	   }
	   else
	   {
		  par->rchild=NULL;
	   }
	   free(ptr);
    }   
}
caseB(struct Node *par,struct Node *ptr)
{
	if(par==NULL)
	{
		root=NULL;
		free(ptr);
	}
	else
	{
    if(par->lchild==NULL)
    {
    	ptr = root->rchild;	
	}
    else
    {
    	ptr = root->lchild;
	}
	free(ptr);
    }
	
}
void caseC(struct Node *par,struct Node *ptr)
{
	struct Node *pptr,*ppar;
	pptr = ptr->rchild;
	ppar = ptr;
	while(pptr->lchild!=NULL)
	{
		ppar = pptr;
		pptr = pptr->lchild;
	}
	ptr->info = pptr->info;
	if(pptr->rchild!=NULL)
	{
		caseB(ppar,pptr);
	}
	else
	{
		caseA(ppar,pptr);
	}
}
int main()
{
	int ch;
	printf("1.insertion");
	printf("\n2.Inorder traverse");
	printf("\n3.preorder traverse");
	printf("\n4.postorder traverse");
	printf("\n5.Deleteleafnode");
	printf("\n6.Exit");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				if(root==NULL)
				{
					printf("\nTree is empty");
				}
				else
				{
					printf("\nInorder traversal is:");
					inorder(root);
				}
				break;
			case 3:
				if(root==NULL)
				{
					printf("\nTree is empty");
				}
				else
				{
					printf("\npreorder traversal is:");
					preorder(root);
				}
				break;
			case 4:
				if(root==NULL)
				{
					printf("\nTree is empty");
				}
				else
				{
					printf("\npostorder traversal is:");
					postorder(root);
				}
				break;
			case 5:
				delete1();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\nInvalid choice");
		}
	}
}
void insert()
{
	int item;
	struct Node *temp,*ptr,*par;
	temp=(struct Node*)malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		
		printf("\nMemory is not allocated");
	}
	else
	{
		printf("\nEnter data to insert:");
		scanf("%d",&item);
		temp->info=item;
		temp->lchild=NULL;
		temp->rchild=NULL;
		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			ptr=root;
			while(ptr!=NULL)
			{
				par=ptr;
				if(item<ptr->info)
				{
					ptr=ptr->lchild;
				}
				else if(item>ptr->info)
				{
					ptr=ptr->rchild;
				}
				else
				{
					printf("Duplicate elements cannot be inserted");
					break;
				}
			}
			if(ptr==NULL)
			{
				if(item<par->info)
				{
					par->lchild=temp;
				}
				else
				{
					par->rchild=temp;
				}
			}
		}
	}
	
}
void inorder(struct Node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->lchild); //left subtree
		printf("%d\t",temp->info);//node
		inorder(temp->rchild);//right
		
	}
}
void preorder(struct Node *temp)
{
	if(temp!=NULL)
	{
		printf("%d\t",temp->info);//node
		preorder(temp->lchild); //left subtree
		preorder(temp->rchild);//right
		
	}
}
void postorder(struct Node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->lchild); //left subtree
		postorder(temp->rchild);//right
		printf("%d\t",temp->info);//node
		
	}	
	
}
int delete1()
{
	struct Node *ptr,*par;
	int item;
	if(root==NULL)
	{
		printf("\nTree is empty");
	}
	else
	{
		ptr=root;
		par=NULL;
		printf("\nEnter item to delete:");
		scanf("%d",&item);
		while(ptr!=NULL)
		{
		    if(ptr->info==item)
		    {
		    	break;	
			}
			par=ptr;
			if(item<ptr->info)
			{
				ptr=ptr->lchild;
			}
			else
			{
				ptr=ptr->rchild;
			}
		}
		if(ptr==NULL)
		{
			printf("\nItem not present");
		}
		printf("\nThe deleted value is %d",ptr->info);
		if(ptr->lchild==NULL&&ptr->rchild==NULL)
		{
			caseA(par,ptr);
		}
		else if(root->lchild==NULL || root->rchild==NULL)
        {
            caseB(par,ptr);
        }
        else
        {
        	caseC(par,ptr);
		}
	}
}
