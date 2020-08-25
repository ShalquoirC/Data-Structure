#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct btnode
{
    char element;
    struct btnode *lChild;
    struct btnode *rChild;
}BTNode;

typedef struct btree
{
    BTNode *root;
}BTree;

void Create(BTree *bt)
{
    bt->root = NULL;
}

BTNode* NewNode(char x, BTNode *ln, BTNode *rn)
{
    BTNode *p = (BTNode*)malloc(sizeof(BTNode));
    
    p->element = x;
    p->lChild = ln;
    p->rChild = rn;
    
    return p;
}

BOOL Root(BTree *bt,char *x)
{
    if(bt->root!=NULL)
    {
        x = &bt->root->element;
        
        return TRUE;
    }
    else
        return FALSE;
}

void MakeTree(BTree *bt, char e, BTree *left, BTree *right)
{
    if(bt->root || left == right)
        return;
    
    bt->root = NewNode(e, left->root, right->root);
    
    left->root = right->root = NULL;
}


void PreOrder(BTNode *node)
{
	if(!node)
		return;
	printf("%c ",node->element);
	PreOrder(node->lChild);
	PreOrder(node->rChild);
}

void PreOrderTree(BTree *bt)
{
    PreOrder(bt->root);
}

void InOrder(BTNode *node)
{
	if(!node)
		return;
	InOrder(node->lChild);
	printf("%c ",node->element);
	InOrder(node->rChild);
}

void InOrderTree(BTree *bt)
{
    InOrder(bt->root);
}

void PostOrder(BTNode *node)
{
	if(!node)
		return;
	PostOrder(node->lChild);
	PostOrder(node->rChild);
	printf(" %c",node->element);
}

void PostOrderTree(BTree *bt)
{
    PostOrder(bt->root);
}

void Clear(BTNode *node)
{
	if(!node)
		return;
	Clear(node->lChild);
	Clear(node->rChild);
	free(node);
}
void TreeClear(BTree *bt)
{
	Clear(bt->root);
}

int main()
{
	BTree a, b,A,B,C,D,E,F,G,H,J,K;
    
    Create(&a); Create(&b); Create(&A); Create(&B); Create(&C);Create(&D); Create(&E); Create(&F);Create(&G); Create(&H);Create(&J); Create(&K); 

	MakeTree(&K,'K',&a,&b);
	MakeTree(&C,'C',&K,&b);
	MakeTree(&G,'G',&a,&C);
	MakeTree(&J,'J',&a,&b);
	MakeTree(&F,'F',&J,&G);

	MakeTree(&H,'H',&a,&b);
	MakeTree(&E,'E',&H,&F);

	MakeTree(&B,'B',&a,&b);
	MakeTree(&A,'A',&a,&B);

	MakeTree(&D,'D',&E,&A);

    printf("PreOrder:"); PreOrderTree(&D); printf("\n");
    printf("InOrder:"); InOrderTree(&D); printf("\n");
	printf("PostOrder:"); PostOrderTree(&D); 
    TreeClear(&D);
    
    return 0;
}