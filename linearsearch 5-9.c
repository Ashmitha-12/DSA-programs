#include<stdio.h>
void main()
{
	int a[5],i,se,size;
	printf("\n enter array size:");
	scanf("%d",&size);
	printf("\n enter array elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n enter search element:");
	scanf("%d",&se);
	for(i=0;i<size;i++)
	{
		if(a[i]==se)
		{
			printf("\n element found at location %d",i);
			break;
		}
		if(i==size)
		{
			printf("\n element not found");
		}
	}
}
