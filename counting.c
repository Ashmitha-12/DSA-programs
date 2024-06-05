#include <stdio.h>
void countingsort(int a[],int size)
{
	int output[20];
	int max=a[0];
	int i;
	for(i=1;i<size;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	int count[20];
	for(i=0;i<=max;++i)
	{
		count[i]=0;
	}
	for( i=0;i<size;i++)
	{
		count[a[i]]++;
	}
	for( i=1;i<=max;i++)
	{
		count[i]+=count[i-1];
	}
	for( i=size-1;i>=0;i--)
	{
		output[count[a[i]]-1]=a[i];
		count[a[i]]--;
	}
	for( i=0;i<size;i++)
	{
		a[i]=output[i];
	}
}
void printarray(int a[],int size)
	{
		int i;
		for(i=0;i<size;i++)
		{
			printf("%d\n",a[i]);
		}
		printf("\n");
	}

int main()
{
	int a[]={1,0,8,6,8,4,2,1,0,1,2,6,8,9,1};
	int n=sizeof(a)/sizeof(a[0]);
	countingsort(a,n);
	printarray(a,n);
}
