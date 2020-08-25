#include<stdio.h>
#include<stdlib.h>

int main()
{
	int len;
	int* ele;
	int i, j,insert ;
	scanf("%d", &len);

	ele = (int*)malloc(len * sizeof(int));
	
	for (i = 0; i < len; i++)
	{
		scanf("%d", &ele[i]);
	}
	printf("Source:\n");

	printf("(%d)",ele[0]);
	for (i = 1; i < len; i++)
		printf(" %d", ele[i]);
	printf("\n");

	printf("Insert Sort:\n");
	
	for (i = 1; i < len ; i++)
	{
		insert = ele[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (insert < ele[j])
				ele[j + 1] = ele[j];
			else break;
		}
		ele[j + 1] = insert;
		
		if(i<len)
		{
			printf("(%d",ele[0]);
			for (j = 1; j <= i; j++)
			{
				printf(" %d", ele[j]);
			}
			printf(")");
			for (; j < len; j++)
			{
				printf(" %d", ele[j]);
			}
			printf("\n");
		}
	}
	printf("Result:\n");
	printf("(");
	for (i = 0; i < len; i++)
	{
		printf("%d", ele[i]);
		if (i < len - 1)
			printf(" ");
	}
	printf(")\n");

}
