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

	printf("(%d", ele[0]);
	for (i = 1; i < len; i++)
		printf(" %d", ele[i]);

	printf(")\n");

	printf("Bubble Sort:\n");

	for (start = 0; start < len; start++)
	{
		
		for (i = 0; i < len-1-start ; i++)
		{
			if (ele[i] > ele[i + 1])
			{
				temp = ele[i];
				ele[i] = ele[i + 1];
				ele[i + 1] = temp;
			}
		}
		if (start < len - 1)
		{
			printf("(");
			printf("%d", ele[0]);
			for (i = 1; i <len-start-1; i++)
			{
				printf(" %d", ele[i]);

			}
			printf(")");
			for (; i < len; i++)
			{
				printf(" %d", ele[i]);
			}
			printf("\n");
		}
	}
	printf("Result\n");
	printf("(%d", ele[0]);
	for (i = 1; i < len; i++)
	{
		printf(" %d", ele[i]);

	}
	printf(")\n");

}