#include <stdlib.h>
#include <stdio.h>

#define ERROR 0
#define OK 1

typedef int Status;
typedef int ElemType;
typedef struct node
{
	ElemType coe;//系数
	ElemType pow;//次方
	struct node* link;
}Node;
typedef struct headerList
{
	Node* head;
}HeaderList;

Status Init(HeaderList* h)
{
	h->head = (Node*)malloc(sizeof(Node));
	if (!h->head)
		return ERROR;
	h->head->link = NULL;
	return OK;
}
void Destroy(HeaderList* h)
{
	Node* p;
	while (h->head->link)
	{
		p = h->head->link->link;
		free(h->head->link);
		h->head->link = p;
	}
	free(h->head);
}

Status Insert(HeaderList* h, int i, ElemType x, ElemType y)
{
	Node* p, * q;
	int j;
	p = h->head;
	for (j = 0; j < i; j++)
		p = p->link;
	q = (Node*)malloc(sizeof(Node));
	q->coe = x;
	q->pow = y;
	q->link = NULL;

	p->link = q;
	return OK;
}
//链表预处理
void Swap(Node* n1, Node* n2)
{
	ElemType coe, pow;
	coe = n1->coe;
	pow = n1->pow;
	n1->coe = n2->coe;
	n1->pow = n2->pow;
	n2->coe = coe;
	n2->pow = pow;

}
HeaderList* Bubble(HeaderList* h, int length)
{
	int x, y, len = length;
	Node* j;
	int isSwap = 0;
	for (x = 0; x < len; len--)
	{
		j = h->head->link;
		for ( y = 0; y < len-1; y++)
		{
			if (j->pow < j->link->pow)
			{
				Swap(j, j->link);
				isSwap = 1;
			}
			j = j->link;
		}
		if (!(isSwap))
			break;
	}
	return h;
}
void NoSamePow(HeaderList* h, int length)
{
	int x, y;
	Node* i, * j;
	i = h->head->link;
	for (x = 0; x < length; x++, i = i->link)
	{
		for (j = i->link, y = x;    y < length-1;        y++, j = j->link)
		{
			if (i->pow == j->pow)
			{
				i->coe = i->coe + j->coe;
				j->coe = 0;
			}
		}
	}

}

int Input(HeaderList* h)
{
	int i = 0;
	int x = 1, y = 1;
	do {
		scanf_s("%d%d", &x, &y);
		if ((x == 0) && (y == -1))
			break;
		else
			Insert(h, i++, x, y);
	} while ((x != 0) || (y != -1));
	h=Bubble(h, i);

	return i;
}
void Merge(HeaderList h1, HeaderList h2, HeaderList* h3)
{
	Node* p1, * p2;
	int x, y, i = 0;
	p1 = h1.head->link;
	while (p1 != NULL)
	{
		p2 = h2.head->link;
		while (p2 != NULL)
		{
			y = p1->pow + p2->pow;
			x = p1->coe * p2->coe;
			p2 = p2->link;
			Insert(h3, i++, x, y);
		}
		p1 = p1->link;
		Bubble(h3, i);
		NoSamePow(h3, i);
	}
}

Status Output(HeaderList* h)
{
	Node* p;
	int fir = 1;
	p = h->head->link;
	while (p != NULL)
	{
		if (p->pow == 0)
		{
			if (fir)
			{
				printf("%d", p->coe);
				fir = 0;
			}
			else if (p->coe != 0)printf("%+d", p->coe);//带符号输出
		}
		else
		{
			if (p->coe == 0)
			{
				p = p->link;
				continue;
			}
			if (fir)
			{
				if (p->coe == -1)printf("-");
				else if (p->coe != 1)printf("%d", p->coe);
				fir = 0;
			}
			else
			{
				if (p->coe == -1)printf("-");
				else if (p->coe != 1)printf("%+d", p->coe);
				else printf("+");
			}
			printf("X");
			if (p->pow != 1)
			{
				printf("^%d", p->pow);
			}
		}
		p = p->link;
	}
	printf("\n");
	return OK;
}

int main()
{
	HeaderList h1, h2, h3;

	Init(&h1); Init(&h2); Init(&h3);

	Input(&h1); Input(&h2);

	Merge(h1, h2, &h3);
	Output(&h1); Output(&h2); Output(&h3);
	Destroy(&h1); Destroy(&h2); Destroy(&h3);
	return 0;
}