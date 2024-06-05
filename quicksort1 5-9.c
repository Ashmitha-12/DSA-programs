#include<stdio.h>
void quicksort();
void main()
{
	int a[10],i,size;
	printf("\n enter array size:");
	scanf("%d",&size);
	printf("\n enter array elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,size-1);
	printf("\n sorted array is:");
	for(i=0;i<size;i++)
	{
		printf("%d \t",a[i]);
	}
}
void quicksort(int a[],int first,int last)
{
	int i,j,pivot,temp;
	if(first<last)
	{
		i=first;
		j=last;
		pivot=first;
	    while(i<j)
	    {
	    	while(a[i]<a[pivot]&&i<last)
	    	i++;
	    	while(a[j]>a[pivot])
	    	j--;
	    	if(i<j)
	    	{
	    		temp=a[i];
	    		a[i]=a[j];
	    		a[j]=temp;
			}
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		quicksort(a,0,j-1);
		quicksort(a,j+1,last);
	}
}
