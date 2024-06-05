//program on binary tree
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *lchild;
	int data;
	struct node *rchild;
}*root=NULL;
void insert(int key)
{
	struct node *t=root;
	struct node *r,*p;
	
	if(root==NULL)
	{
		p=(struct node*)malloc(sizeof(struct node));
		p->data=key;
		p->lchild=p->rchild=NULL;
		root=p;
		return ;
	}
	while(t!=NULL)
	{
		r=t;
		if(key<t->data)
		{
			t=t->lchild;
		}
		else if(key>t->data)
		{
			t=t->rchild;
		}
		else
		{
			return ;
		}
	}
	p=(struct node*)malloc(sizeof(struct node));
	p->data=key;
	p->lchild=p->rchild=NULL;
	if(key<r->data)
	{
		r->lchild=p;
	}
	else
	{
		r->rchild=p;
	}
}
void inorder(struct node *p)
{
	if(p)
	{
		inorder(p->lchild);
		printf("%d\t",p->data);
		inorder(p->rchild);
	}
}
void preorder(struct node *p)
{
	if(p)
	{
	    printf("%d\t",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void postorder(struct node *p)
{
	if(p)
	{
		postorder(p->lchild);
		postorder(p->rchild);	
		printf("%d\t",p->data);
	}
}

struct node *search(int key)
{
	struct node *t=root;
	while(t)
	{
		if(key==t->data)
		{
			return t;
		}
		else if(key<t->data)
		{
			t=t->lchild;
		}
		else
		{
			t=t->rchild;
		}
	}
	return NULL;
}
struct node* deleteNode(struct node* root, int key)
{
	struct node *t=root;
    if (t == NULL)
        return t;
    if (key < t->data)
        t->lchild = deleteNode(t->lchild, key);

    else if (key > t->data)
        t->rchild = deleteNode(t->rchild, key);
    else 
	{
        if (t->lchild==NULL &&  t->rchild==NULL)
            return NULL;
        else if (t->lchild == NULL)
		{
            struct node* temp = t->rchild;
            free(t);
            return temp;
        }                               
        else if (t->rchild == NULL) 
        {
            struct node* temp = t->lchild;
            free(t);
            return temp;
        }
    }
}
rbst(struct node *t,int key)
{
	if(t==NULL)
	{
		printf("no tree exist\n");
    }
		if(key==t->data)
		{return 1;
		}
		if(key<t->data)
		{
		return rbst(t->lchild,key);
		}
		else if(key>t->data)
		{
		return rbst(t->rchild,key);
		}
		else
		{
		return ;
		}
	}
int main()
{
	int choice,s,d;
	struct node *temp,*temp1;
	while(1)
	{
	insert(5);
	insert(10);
	insert(25);
	insert(8);
	insert(30);
	rbst(root,5);
	printf("1.INORDER\n");
	printf("2.PREORDER\n");
	printf("3.POSTORDER\n");
	printf("4.SEARCH\n");
	printf("5.DELETE\n");
	printf("EXIT\n");
	printf("enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
     case 1:
	        inorder(root);
	        break;
	case 2:
	       preorder(root);
	       break;
	case 3:
	      postorder(root);
	      break;
	case 4:
		printf("enter search element:");
		scanf("%d",&s);
	      temp=search(s);
	 	   if(temp)
	       {
	     	printf("element %d is found\n",temp->data);
	       }   
	        else
	       {
		    printf("not found\n");
	       }
	       break;
	case 5:
	        printf("enter element to delete:");
	     	scanf("%d",&d);
	        root = deleteNode(root,d);
            inorder(root);
            break;
	case 6:
	        exit(1);  
			break;        
	default:
		    printf("invalid entry");
	}
	printf("\n");
   }
}
