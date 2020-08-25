#include<stdio.h>
#include<stdlib.h>
//typedef struct maxheap{
//	int n,MaxSize;
//	int D[MaxSize];
//}MaxHeap;

void AdjustDown(int heap[], int current, int border)
{
    int p = current;
    int minChild;
    int temp;
    
    while(2*p+1 <= border)
    {
        if( (2*p+2 <= border) && (heap[2*p+1] > heap[2*p+2]) )
            minChild = 2*p+2;
        else
            minChild = 2*p+1;
        
        if(heap[p] <= heap[minChild])
            break;
        else
        {
            temp = heap[p];
            heap[p] = heap[minChild];
            heap[minChild] = temp;
            p = minChild;
        }
    } 
}

void Swap(int heap[],int x,int y)
{
	int temp;
	temp=heap[x];
	heap[x]=heap[y];
	heap[y]=temp;
}
int main()
{
	int len;
	int* ele;
	int i;
	scanf("%d", &len);

	ele = (int*)malloc(len * sizeof(int));
	
	for (i = 0; i < len; i++)
	{
		scanf("%d", &ele[i]);
	}
	for(i=(len-2)/2;i>=0;i--)
	{
		AdjustDown(ele,i,len-1);
	}
	for(i=len-1;i>0;i--)
	{
		Swap(ele,0,i);
		AdjustDown(ele,0,i-1);
	}

	
	printf("%d",ele[len-1]);
	for(i=len-2;i>-1;i--)
		printf(" %d",ele[i]);
	printf("\n");
}