#include<stdio.h>
#include<stdlib.h>

int main()
{
	int len;
	int* ele;
	int i, j, min, temp, start;
	scanf("%d", &len);

	ele = (int*)malloc(len * sizeof(int));

	for (i = 0; i < len; i++)
	{
		scanf("%d", &ele[i]);
	}
	printf("Source:\n");
	
	printf("(");
	for (i = 0; i < len; i++)
	{
		printf("%d", ele[i]);
		if (i < len-1)
			printf(" ");
	}
	printf(")\n");

	printf("Select Sort:\n");

	for (start = 0; start < len; start++)
	{
		min = start;
		for (i = start + 1; i < len; i++)
		{
			if (ele[i] < ele[min])
				min = i;
		}
		if (min != start)
		{
			temp = ele[min];
			ele[min] = ele[start];
			ele[start] = temp;
		}
		if (start < len - 1)
		{
			printf("(");
			for (i = 0; i <= start; i++)
			{
				printf("%d", ele[i]);
				if (i < start)
					printf(" ");
			}
			printf(") ");
			for (; i < len; i++)
			{
				printf("%d", ele[i]);
				if (i < len-1)
					printf(" ");
			}
			printf("\n");
		}
	}
	printf("Result:\n");
	printf("(");
	for (i = 0; i <len; i++)
	{
		printf("%d", ele[i]);
		if (i <len-1)
			printf(",");
	}
	printf(")");

}