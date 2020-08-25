#include<stdio.h>
#include<stdlib.h>

//同一层输出同一次序
//输出顺序

/// /////////////////////////////////////////////////////


typedef struct mGraph
{
	int** a;//邻接矩阵

	int num_apex;//角
	int num_edge;//边
}MGraph;
typedef struct edge
{
	int u;
	int v;
}Edge;


void Inin(MGraph* mg, int nSize, int nEdge)
{
	int i, j;
	mg->num_apex = nSize;
	mg->num_edge = nEdge;
	mg->a = (int**)malloc(nSize * sizeof(int));
	for (i = 0; i < mg->num_apex; i++)
	{
		mg->a[i] = (int*)malloc(nSize * sizeof(int));
		for (j = 0; j < mg->num_apex; j++)
			mg->a[i][j] = 999;
	}
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




//void Find_next(int v,int num, int* visited, MGraph *g)
//{
//	//printf("%d ", v);
//	//for (int j = 0; j < g->num_apex; j++)
//	//{
//	//	if (visited[j] == num)
//    //		{
//	for (int i = 0; i < g->num_apex; i++)
//	{
//		if (g->a[v][i] != 999)
//		{
//			visited[i] = num + 1;
//			//printf("%d ", j);
//		}
//	}
//
//	
//}
//
//void Switch_line(MGraph g,int home)
//{
//	int i;
//	int num;//记录层数。
//	
//	int* visited = (int*)malloc(g.num_apex * sizeof(int));
//	for (i = 0; i < g.num_apex; i++)
//		visited[i] = -1;
//	visited[home] = 0;
//	//起点出发
//	Find_next(home, 0, visited, &g);
//	//边
//	for (num = 1;num<g.num_edge+1 ; num++)
//	{
//		for (i = 0; i < g.num_apex; i++)
//		{
//			if (visited[i] == num)
//				Find_next(i, num, visited,&g);
//		}
//	}
//	Output(g);
//	//free(visited);
//}

int Choose(int* Closest, int* Validation, int length)
{
	int i, minpos;
	int min;
	min = 999;//默认最大
	minpos = -1;
	for(i=1;i<length;i++)
		if (Closest[i] < min && Validation[i] == 0)
		{
			min = Closest[i];
			minpos = i;
		}
	return minpos;
}

int Dijkstra(int apex, MGraph g)
{
	int i, k, w;
	int* validation; int* closest, * path;
	if (apex<0 || apex>g.num_apex - 1)
		return 0;
	validation = (int*)malloc(sizeof(int) * g.num_apex);
	closest = (int*)malloc(sizeof(int) * g.num_apex);
	//path = (int*)malloc(sizeof(int) * g.num_apex);
	for (i = 0; i < g.num_apex; i++)
	{
		validation[i] = 0;
		closest[i] = g.a[apex][i];
		//if (i != apex && closest[i] < 999)
		//	path[i] = apex;
		//else
		//	path[i] = -1;
	}
	validation[apex] = 1; closest[apex] = 0;
	for (i = 1; i < g.num_apex - 1; i++)
	{
		k = Choose(closest, validation, g.num_apex);
		if (k == -1)
			continue;
		validation[k] = 1;
		//printf("Choose    %d ", k);
		for (w = 0; w < g.num_apex; w++)
		{
			if (validation[w] == 0 && closest[k] + g.a[k][w] < closest[w])
			{
				closest[w] = closest[k] + g.a[k][w];
				//path[w] = k;
			}
		}
	}
	for (i = 0; i < g.num_apex; i++)
	{
		if (i == apex)
			continue;
		if (closest[i] != 999)
			printf("%d\n", closest[i]);
		else
			printf("-1\n");
	}
	return 0;
}
int main()
{
	MGraph mg;
	int i, u, v, num, edge,home;

	i = 0;
	scanf_s("%d%d%d", &num, &edge,&home);
	if (num < 1 || num>20 || edge < 0 || edge>190)
		return 0;
	Inin(&mg, num, edge);
	//单向赋值
	while (i < mg.num_edge)
	{
		
		scanf_s("%d%d", &u, &v);
		if (u >= num || v >= num)
			return 3;
		mg.a[u][v] = 1;
		i++;
	}
	Output(mg);
	//Switch_line(mg,home);
	//Destory(&mg);
	Dijkstra(home, mg);
	return 0;
}