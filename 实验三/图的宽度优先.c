#include<stdio.h>
#include<stdlib.h>

typedef struct mGraph
{
	int** a;

	int num;
	int edge;
}MGraph;

#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5

typedef int Status;

Status Inin(MGraph *mg, int nSize,int nEdge)
{
	int i, j;
	mg->num = nSize;
	mg->edge = nEdge;
	mg->a = (int**)malloc(nSize * sizeof(int));
	for (i = 0; i < mg->num; i++)
	{
		mg->a[i] = (int*)malloc(nSize * sizeof(int));
		for (j = 0; j < mg->num; j++)
			mg->a[i][j] = 0;
	}
	return OK;
}

void Destory(MGraph *mg)
{
	int i;
	for (i = 0; i < mg->num; i++)
	{
		free(mg->a[i]);
	}
	free(mg->a);
}

////////////////////////
typedef struct queue
{
	int front;
	int rear;

	int maxSize;

	int *element;
}Queue;

void Create(Queue *Q, int mSize)
{
	Q->maxSize = mSize;
	Q->element = (int*)malloc(sizeof(int) * mSize);
	Q->front = Q->rear = 0;
}

void DestroyQueue(Queue* Q)
{
	Q->maxSize = 0;
	free(Q->element);
	Q->front = Q->rear = -1;
}
void Clear(Queue *Q)
{
	Q->front = Q->rear=0;
}

int IsEmpty(Queue *Q)
{
	return Q->front == Q->rear;
}

int IsFull(Queue* Q)
{
	return (Q->rear + 1) % Q->maxSize == Q->front;
}

int Front(Queue  *Q, int* x)
{
	if (IsEmpty(Q))
		return 0;
	*x = Q->element[(Q->front + 1) % Q->maxSize];
	return 1;
}

int EnQueue(Queue *Q, int x)
{
	if (IsFull(Q))
		return 0;

	Q->rear = (Q->rear + 1) % Q->maxSize;
	Q->element[Q->rear] = x;

	return 1;
}

void DeQueue(Queue *Q)
{
	if (IsEmpty(Q))
		return 0;
	Q->front = (Q->front + 1) % Q->maxSize;
}
 

void Output(MGraph g)
{
	for (int i = 0; i < g.num; i++)
	{
		for (int j = 0; j < g.num; j++)
			printf("%d ", g.a[i][j]);
		printf("\n");
	}
}

void BFS(int v, int *visited, MGraph g)
{
	Queue q;
	Create(&q, g.num);
	visited[v] = 1;
	printf("%d ", v);
	EnQueue(&q, v);

	while (!IsEmpty(&q))
	{
		Front(&q, &v);
		DeQueue(&q);

		for (int j = 0; j < g.num; j++)
		{
			if (!visited[j]&&g.a[v][j])
			{
				visited[j] = 1;
				printf("%d ", j);
				EnQueue(&q, j);
			}
		}
	}
}

void BFSGraph(MGraph g)
{
	int i;
	int *visited = (int*)malloc(g.num * sizeof(int));

	for (i = 0; i < g.num; i++)
		visited[i] = 0;
	for (i = 0; i < g.num; i++)
		if (!visited[i])
			BFS(i, visited, g);
	free(visited);
}

int main()
{
	MGraph mg;
	int i , u, v, num, edge;
	i = 0;
	scanf_s("%d%d", &num, &edge);
	if (num < 1 || num>20 || edge < 0 || edge>190)
		return 0;
	Inin(&mg, num, edge);
	while (i < mg.edge)
	{
		scanf_s("%d%d", &u, &v);
		mg.a[u][v] = 1; 
		mg.a[v][u] = 1;
		i++;
	}
	Output(mg);
	BFSGraph(mg);
	Destory(&mg);
	return 0;
}


