#include <stdlib.h>
#include <stdio.h>
#include<math.h>

#define ERROR 0
#define OK 1
#define N 1000

typedef int Status;

typedef int ElemType;
typedef char ElemType2;
typedef double ElemType3;
typedef struct seqList
{
    int n;
    int maxLength;
    ElemType *element;
}SeqList;

typedef struct seqList2
{
    int n;
    int maxLength;
    ElemType2 *element;
}SeqList2;

typedef struct seqList3
{
    int n;
    int maxLength;
    ElemType3 *element;
}SeqList3;



Status Init(SeqList *L, int mSize)
{
    L->maxLength = mSize;
    L->n = 0;
    L->element = (ElemType*)malloc(sizeof(ElemType) * mSize);
    if(!L->element)
        return ERROR;
    
    return OK;
}
void Destroy(SeqList *L)
{
    L->n = 0;
    L->maxLength = 0;
    free(L->element);
}
void Delete(SeqList *L, ElemType x)
{
    int i,j;
	for(j=0;j<L->n;j++)
	{
		if(x==L->element[j])
		{
			for(i=j;i<L->n;i++)
				L->element[i]=L->element[i+1];
			L->n--;
			j--;
		}
	}
}
Status Insert(SeqList *L, int i, ElemType x)
{
    if(i<-1 || i>L->n-1)
        return ERROR;
    if(L->n == L->maxLength)
        return ERROR;
    L->element[i] = x;
    return OK;
}
void ReOutput(SeqList *L)
{
    int i;
    for(i =L-> n-1; i>-1; i--)
        printf("%d ", L->element[i]);
    printf("\n");
}


Status Init2(SeqList2 *L, int mSize)
{
    L->maxLength = mSize;
    L->n = 0;
    L->element = (ElemType2*)malloc(sizeof(ElemType2) * mSize);
    if(!L->element)
        return ERROR;
    
    return OK;
}
void Destroy2(SeqList2 *L)
{
    L->n = 0;
    L->maxLength = 0;
    free(L->element);
}
void Delete2(SeqList2 *L, ElemType2 x)
{
    int i,j;
	for(j=0;j<L->n;j++)
	{
		if(x==L->element[j])
		{
			for(i=j;i<L->n+1;i++)
				L->element[i]=L->element[i+1];
			L->n--;
			j--;
		}
	}
}
void ReOutput2(SeqList2 *L)
{
    int i;
    for(i =L-> n-1; i>-1; i--)
        printf("%c ", L->element[i]);
    printf("\n");
}


Status Init3(SeqList3 *L, int mSize)
{
    L->maxLength = mSize;
    L->n = 0;
    L->element = (ElemType3*)malloc(sizeof(ElemType3) * mSize);
    if(!L->element)
        return ERROR;
    
    return OK;
}
void Destroy3(SeqList3 *L)
{
    L->n = 0;
    L->maxLength = 0;
    free(L->element);
}
void Delete3(SeqList3 *L, ElemType3 x)
{
    int i,j;
	for(j=0;j<L->n;j++)
		if(fabs(x-L->element[j])<1e-6){
			for(i=j;i<L->n;i++)
				L->element[i]=L->element[i+1];
			L->n--;
			j--;
		}
}
void ReOutput3(SeqList3 *L)
{
    int i;
    for(i =L-> n-1; i>-1; i--)
        printf("%.1lf ", L->element[i]);
	printf("\n");
}



int main()
{
	ElemType y,x;
	ElemType2 x2;
	ElemType3 x3;
	int i;
	SeqList aList;
	SeqList2 aList2;
	SeqList3 aList3;

	Init(&aList,N);
	Init2(&aList2,N);
	Init3(&aList3,N);

	scanf("%d",&aList.n);
	for(i=0;i<aList.n;i++)
	{
		scanf("%d",&y);
		Insert(&aList,i,y );
	}
	scanf("%d",&x);
	//1
	scanf("%d",&aList2.n);
	getchar();
	for(i=0;i<aList2.n;i++)
	{
		scanf("%c",&aList2.element[i]);
		getchar();
	}
	scanf("%c",&x2);
	getchar();
	//2
	scanf("%d",&aList3.n);
	for(i=0;i<aList3.n;i++)
	{
		scanf("%lf",&aList3.element[i]);
	}
	scanf("%lf",&x3);
	//3

	ReOutput(&aList);
	Delete(&aList,x);
	ReOutput(&aList);

	ReOutput2(&aList2);
	Delete2(&aList2,x2);
	ReOutput2(&aList2);

	ReOutput3(&aList3);
	Delete3(&aList3,x3);
	ReOutput3(&aList3);

	Destroy(&aList);	
	Destroy2(&aList2);
	Destroy3(&aList3);
	return 0;
}
