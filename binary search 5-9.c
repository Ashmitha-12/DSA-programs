#include<stdio.h>
void main()
{
	int a[5],i,se,size,found,low,mid,high;
	printf("\n enter array size:");
	scanf("%d",&size);
	printf("\n enter array elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n enter search element:");
	scanf("%d",&se);
	low=0;
	high=size-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(se==a[mid])
		{
			printf("\n element found ata location %d",mid);
			found=1;
			break;
		}
		else if(se<a[mid])
		{
			high=mid-1;
		}
		else if(se>a[mid])
		{
			low=mid+1;
		}
	}
	if(found==0)
	{
		printf("\n element not found");
	}
}
