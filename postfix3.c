#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define size 20
int stack[size],top=-1;
void push(int);
int pop();
int main()
{
	char post[20],k;
	int op1,op2,res=0,i=0;
	printf("\n enter postfix expression:");
	scanf("%s",post);
	while(post[i]!='\0')
	{
		k=post[i];
		if(isdigit(k))
		{
			push(k-'0');
		}
		else
		{
			op2=pop();
			op1=pop();
			switch(k)
			{
				case'+':res=op1+op2;
				        break;
				case'-':res=op1-op2;
				        break;
				case'*':res=op1*op2;
				        break;
				case'/':res=op1/op2;
				        break;
				case'%':res=op1%op2;
				        break;
				case'^':res=pow(op1,op2);
				        break;
				default:
					{
						printf("\n invalid operator");
					}
			}
			push(res);
		}
		i=i+1;
	}
	printf("\n the postfix value is %d",res);
}
void push(int ele)
{
	if(top==size-1)
	{
		printf("\n OVERFLOW");
	}
	else
	{
		top=top+1;
		stack[top]=ele;
	}
}
int pop()
{
	int x;
	if(top==-1)
	{
		printf("\n UNDERFLOW");
	}
	else
	{
		x=stack[top];
		top=top-1;
	}
	return x;
}
