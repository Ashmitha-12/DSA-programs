#include<stdio.h>
void main()
{
	int a[10],i,j,size,key;
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
	for(i=0;i<size;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0&&key<=a[j])
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	printf("\n array elements after sorting:");
	for(i=0;i<size;i++)
	{
		printf("%d \t",a[i]);
	}
}
