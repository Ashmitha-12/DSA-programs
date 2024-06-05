#include<stdio.h>
#include<stdlib.h>
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
void del1();
int main()
{
	int ch;
	printf("\n 1.insert");
	printf("\n 2.inorder");
	printf("\n 3.preorder");
	printf("\n 4.postorder");
	printf("\n 5.deleteleafnode");
	printf("\n 6.exit");
	while(1)
	{
		printf("\n enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				if(root==NULL)
				{
					printf("\n tree is empty");
				}
				else
				{
					printf("\n inorder traversal is:");
					inorder(root);
				}
				break;
			case 3:
				if(root==NULL)
				{
					printf("\n tree is empty");
				}
				else
				{
					printf("\n preorder traversal is:");
					preorder(root);
				}
				break;
			case 4:
				if(root==NULL)
				{
					printf("\n tree is empty");
				}
				else
				{
					printf("\n preorder traversal is:");
					postorder(root);
				}
				break;
			case 5:
				del1();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\n invalid choice");
		}
	}
}
void insert()
{
	struct Node *temp,*ptr,*par;
	int item;
	temp=(struct Node *)malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		printf("\n memory is not allocated");
	}
	else
	{
		printf("\n enter the value:");
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
					printf("\n duplicate values cannot be inserted");
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
		inorder(temp->lchild);                  //leftchild//
		printf("%d \t",temp->info);              //node//
		inorder(temp->rchild);                  //rightchild//
	}
}
void preorder(struct Node *temp)
{
	if(temp!=NULL)
	{
		printf("%d \t",temp->info);              //node//
		preorder(temp->lchild);                  //leftchild//
		preorder(temp->rchild);                  //rightchild//
	}
}
void postorder(struct Node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->lchild);                  //leftchild//
		postorder(temp->rchild);                 //rightchild//
		printf("%d \t",temp->info);              //node//
	}
}
void del1()
{
	struct Node *ptr,*par;
	int item;
	if(root==NULL)
	{
		printf("\n tree is empty");
	}
	else
	{
		ptr=root;
		par=NULL;
		printf("\n enter item to delete:");
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
			printf("\n node not present");
		}
		printf("\n the deleted value is %d",ptr->info);
		if(ptr->lchild==NULL&&ptr->rchild==NULL)
		{
			casea(par,ptr);
		}
		else if(ptr->lchild!=NULL&&ptr->rchild!=NULL)
		{
			casec(par,ptr);
		}
		else
		{
			caseb(par,ptr);
		}
	}
}
casea(struct Node *par,struct Node *ptr)
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
caseb(struct Node *par,struct Node *ptr)
{
	if(par==NULL)
	{
		root=NULL;
		free(ptr);
	}
	else
	{
	    if(par->lchild=NULL)
	    {
	    	ptr=root->rchild;
		}
		else
		{
			ptr=root->lchild;
		}
		free(ptr);
	}
}
void casec(struct Node *par,struct Node *ptr)
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
		caseb(ppar,pptr);
	}
	else
	{
		casea(ppar,pptr);
	}
}
