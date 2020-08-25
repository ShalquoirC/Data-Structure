#include<stdio.h>
#include<stdlib.h>

int QuickSort(int* ele,int len,int low, int high)
{
	int k, temp,m;
	if (low < high)
	{
		int i = low, j = high + 1;
		int dev = ele[low];
		do {
			do i++;   while (i <= high && ele[i] < dev);
			do j--;   while (ele[j] > dev);
			if (i < j)
			{
				temp = ele[i];
				ele[i] = ele[j];
				ele[j] = temp;
			}
		} while (i < j);
		temp = ele[low];
		ele[low] = ele[j];
		ele[j] = temp;
		QuickSort(ele,len,low, j - 1);
		QuickSort(ele,len, j + 1, high);
	}
	//for (m = 1; m < len; m++)
	//{
	//	printf(" %d", ele[m]);
	//}
	//printf("\n");
}
int quick(int *ele,int len)
{
	int i;
	QuickSort(ele,len,0,len-1);
	//printf("%d", ele[0]);
	//for (i = 1; i < len; i++)
	//{
	//	printf(" %d", ele[i]);
	//}
}

int main()
{
	int len;
	int* ele;
	int i, j, low, high, temp, start;
	scanf("%d", &len);

	ele = (int*)malloc(len * sizeof(int));

	for (i = 0; i < len; i++)
	{
		scanf("%d", &ele[i]);
	}
	quick(ele, len);
	printf("%d", ele[0]);
	for (i = 1; i < len; i++)
	{
		printf(" %d", ele[i]);
	}
	printf("\n");
	return 0;
}