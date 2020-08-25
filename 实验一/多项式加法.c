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
    struct node *link;
}Node;
typedef struct headerList
{
    Node *head;
}HeaderList;

Status Init(HeaderList *h)
{
    h->head = (Node*)malloc(sizeof(Node));
    if(!h->head)
        return ERROR;
    h->head->link = NULL;
    return OK;
}
void Destroy(HeaderList *h)
{
    Node *p;
    while(h->head->link)
    {
        p = h->head->link->link;
        free(h->head->link);
        h->head->link = p;
    }
    free(h->head);
}

Status Insert(HeaderList *h, int i, ElemType x,ElemType y)
{
    Node *p, *q;
    int j,k;
    p = h->head;
    for(j = 0; j <i; j++)
	{
        p = p->link;
/*		if(p->pow==y&&i!=0)
		{
			k=p->coe;
			p->coe=k+x;
			return OK;
		}
		*/
	}
	q = (Node*)malloc(sizeof(Node));
	q->coe= x;
	q->pow=y;
	q->link=NULL;

    p->link = q;
    return OK;
}
Status Input(HeaderList *h)
{
	int i=0;
	int x=1,y=1;
		do{
		scanf("%d%d",&x,&y);
		if((x==0)&&(y==-1))
			break;
		else
			Insert(h,i++,x,y);
		}while((x!=0)||(y!=-1));

	return OK;
}
void Merge(HeaderList h1,HeaderList h2,HeaderList *h3)
{
	Node *p1,*p2;
	int x,y,i=0;
	p1=h1.head->link;
	p2=h2.head->link;
	while(p1!=NULL||p2!=NULL)
	{
		if(p1!=NULL&&p2!=NULL)
		{
			if(p1->pow==p2->pow)
			{
				y=p1->pow;
				x=p1->coe+p2->coe;
		     	p1=p1->link;
		     	p2=p2->link;
	     	}
	    	else if(p1->pow>p2->pow){
			    y=p1->pow;
			    x=p1->coe;
			    p1=p1->link;
			}
		    else if(p1->pow<p2->pow){
			    y=p2->pow;
			    x=p2->coe;
			   p2=p2->link;
		    }
		}
		else if(p1==NULL){
			y=p2->pow;
			x=p2->coe;
			p2=p2->link;
		}
		else if(p2==NULL){
			y=p1->pow;
			x=p1->coe;
			p1=p1->link;
		}
		Insert(h3,i++,x,y);
	}
}

Status Output(HeaderList *h)
{
    Node *p;
	int fir=1;
    p = h->head->link;
    while(p!=NULL)
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
	HeaderList h1,h2,h3;

	Init(&h1);Init(&h2);Init(&h3);

	Input(&h1);Input(&h2);


	Output(&h1);Output(&h2);Output(&h3);
	Destroy(&h1);Destroy(&h2);Destroy(&h3);
	return 0;
}