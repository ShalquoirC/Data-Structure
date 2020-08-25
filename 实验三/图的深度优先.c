#include<stdio.h>
#include<stdlib.h>

typedef struct mGraph
{
	int** a;
	
	int num_apex;
	int num_edge;
}MGraph;



int Inin(MGraph* mg, int nSize, int nEdge)
{
	int i, j;
	mg->num_apex = nSize;
	mg->num_edge = nEdge;
	mg->a = (int**)malloc(nSize * sizeof(int));
	for (i = 0; i < mg->num_apex; i++)
	{
		mg->a[i] = (int*)malloc(nSize * sizeof(int));
		for (j = 0; j < mg->num_apex; j++)
			mg->a[i][j] = 0;
	}
	return 1;
}

void Destory(MGraph* mg)
{
	int i;
	for (i = 0; i < mg->num_apex; i++)
	{
		free(mg->a[i]);
	}
	free(mg->a);
}

void Output(MGraph g)
{
	for (int i = 0; i < g.num_apex; i++)
	{
		for (int j = 0; j < g.num_apex; j++)
			printf("%d ", g.a[i][j]);
		printf("\n");
	}
}

void DFS(int v, int visited[],MGraph g)
{
	int i;
	printf("%d ", v);
	visited[v] = 1;
	for (i = 0; i < g.num_apex; i++)
	{
		if (!visited[i] && g.a[v][i] != 0 && i != v)
			DFS(i, visited, g);

	}
}
void DFSGraph(MGraph g)
{
	int i;
	int *visited = (int*)malloc(g.num_apex * sizeof(int));
	for (i = 0; i < g.num_apex; i++)
	{
		visited[i] = 0;
	}
	for (i = 0; i < g.num_apex; i++)
	{
		if (!visited[i])
			DFS(i, visited, g);
	}
	free(visited);
}

int main()
{
	MGraph mg;
	int i, u, v, num, edge;
	i = 0;
	scanf_s("%d%d", &num, &edge);
	if (num < 1 || num>20 || edge < 0 || edge>190)
		return 0;
	Inin(&mg, num, edge);
	while (i < mg.num_edge)
	{
		scanf_s("%d%d", &u, &v);
		mg.a[u][v] = 1;
		mg.a[v][u] = 1;
		i++;
	}
	Output(mg);
	DFSGraph(mg);
	Destory(&mg);
	printf("\n");
	return 0;
}