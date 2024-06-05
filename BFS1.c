#include<stdio.h>
#include<stdlib.h>
int graph[10][10],visited[10],total;
void BFS(int);
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
	printf("\n BFS traversal is:");
	BFS(0);
}
void BFS(int vertex)
{
	int j;
	printf("\n%d",vertex);
	visited[vertex]=1;
	for(j=1;j<total;j++)
	{
		if(!visited[j]&&graph[vertex][j]==1)
		{
			BFS(j);
		}
	}
}
