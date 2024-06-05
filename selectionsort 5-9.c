#include<stdio.h>
void main()
{
	int a[5],i,j,size,min,temp;
	printf("\n enter array size:");
	scanf("%d",&size);
	printf("\n enter array elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<size-1;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
    printf("\n sorted array is:");
	for(i=0;i<size;i++)
	{
		printf("%d\t",a[i]);
	}
}
