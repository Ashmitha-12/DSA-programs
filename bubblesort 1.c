#include<stdio.h>
void main()
{
	int a[10],i,j,size,temp;
	printf("\n enter array size:");
	scanf("%d",&size);
	printf("\n enter array elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n array elements before sorting:");
	for(i=0;i<size;i++)
	{
		printf("%d \t",a[i]);
	}
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\n array elements after sorting:");
	for(i=0;i<size;i++)
	{
		printf("%d \t",a[i]);
	}
}
