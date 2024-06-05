#include<stdio.h>
void partition();
void mergesort();
int main()
{
	int a[30],size,i;
	printf("\n enter array size:");
	scanf("%d",&size);
	printf("\n enter array elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	partition(a,0,size-1);
	printf("\n sorted array is");
	for(i=0;i<size;i++)
	{
		printf("%d \t",a[i]);
	}
}
void partition(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		partition(a,low,mid);
		partition(a,mid+1,high);
		mergesort(a,low,mid,high);
	}
}
void mergesort(int list[],int low,int mid,int high)
{
	int i,mi,k,lo,temp[50];
	lo=low;
	i=low;
	mi=mid+1;
	while(lo<=mid&&mi<=high)
	{
		if(list[lo]<=list[mi])
		{
			temp[i]=list[lo];
			lo++;
		}
		else
		{
			temp[i]=list[mi];
			mi++;
		}
		i++;
	}
	if(lo>mid)
	{
		for(k=mi;k<=high;k++)
		{
			temp[i]=list[k];
			i++;
		}
	}
	else
	{
		for(k=lo;k<=mid;k++)
		{
			temp[i]=list[k];
			i++;
		}
	}
	for(k=low;k<=high;k++)
	{
		list[k]=temp[k];
	}
}
