#include<stdio.h>
#include<stdlib.h>
int graph[10][10],visited[10],total,arr[50];
static int k=0,count=0;
void DFS(int);
void main()
{
	int i,j;
	printf("\n enter total no of vetices:");
	scanf("%d",&total);
	printf("\n enter adjacency matrix for a graph:");
	for(i=0;i<total;i++)
	{
		for(j=0;j<total;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	for(i=0;i<total;i++)
	{
		visited[i]=0;
	}
	printf("\n DFS traversal is:");
	DFS(0);
}
void DFS(int vertex)
{
	int j,c=0;
	count++;
	printf("\n%d",vertex);
	visited[vertex]=1;
	for(j=1;j<total;j++)
	{
		if(!visited[j]&&graph[vertex][j]==1)
		{
			arr[++k] =j;
			c=1;
		}
		if(count==total)
		{
			exit(0);
		}
    }
		if(c==1)
		{
			DFS(arr[k]);
		}
		else
		{
			k--;
			DFS(arr[k]);
		}
}
