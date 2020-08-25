#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;

static int totalNum;
static int leaNum;
static int SingleNodeNum;

typedef struct btree
{
	char element;
	struct btree* lChild;
	struct btree* rChild;
}BTree;

BTree* Create(BTree** bt,char x)//调用指针地址
{
	* bt = (BTree*)malloc(sizeof(BTree));
	BTree* t=*bt;
	t->element = x;
	t->lChild = NULL;
	t->rChild = NULL;
	return t;
}

void PreInput(BTree** bt)
{
	char ch;
	ch = getchar();
	if (getchar() == '\n')
		return;
	if (ch == '#')
	{
		*bt= NULL;
		return;
	}
	else if (ch != '#')
	{
		*bt=Create(bt, ch);
		BTree* tree = *bt;
		PreInput(&tree->lChild);
		PreInput(&tree->rChild);
	}
}
void PreOrder(BTree* bt)
{
	if (!bt)
		return;
	totalNum++;
	if ((bt->lChild && !bt->rChild) || (!bt->lChild && bt->rChild))
	    SingleNodeNum++;
	if (!bt->lChild && !bt->rChild)
		leaNum++;
	printf(" %c", bt->element);
	PreOrder(bt->lChild);
	PreOrder(bt->rChild);
}
void InOrder(BTree* bt)
{
	if (!bt)
		return;
	InOrder(bt->lChild);
	printf(" %c", bt->element);
	InOrder(bt->rChild);
}
void PostOrder(BTree* bt)
{
	if (!bt)
		return;
	PostOrder(bt->lChild);
	PostOrder(bt->rChild);
	printf(" %c", bt->element);
}
void Clear(BTree* bt)
{
	if (!bt)
		return;
	Clear(bt->lChild);
	Clear(bt->rChild);
	free(bt);
}

int Height(BTree* bt)
{
	if (!bt)
		return 0;
	int lHeight, rHeight, i;
	lHeight = Height(bt->lChild);
	rHeight = Height(bt->rChild);
	if (lHeight > rHeight)
		i = lHeight+1;
	else
		i = rHeight+1;
	return i;
}
int main()
{
	BTree** t=(BTree**)malloc(sizeof(BTree*));
	*t = NULL;
	PreInput(t);
	printf("PreOrder:"); PreOrder(*t); printf("\n");
	printf("InOrder:"); InOrder(*t); printf("\n");
	printf("PostOrder:"); PostOrder(*t); printf("\n");
	
	printf("%d\n", Height(*t));
	Clear(*t);
	printf("%d %d %d", totalNum, leaNum, SingleNodeNum);
	return 0;
}