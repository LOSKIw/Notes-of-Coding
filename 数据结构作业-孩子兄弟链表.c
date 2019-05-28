#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct csnode
{
	char c;
	struct csnode *chi,*bro;
}cbnode,*cbtree;

typedef struct queue
{
	cbtree* t;
	int head,back;
}queue;

int enqueue(queue* q,cbtree t)
{
	q->t[q->back++]=t;
	return 0;
}

cbtree dequeue(queue* q)
{
	return q->t[q->head++];
}

cbtree geth(queue* q)
{
	return q->t[q->head];
}

int crtt(cbtree* T)
{
	queue q;
	q.back=0;
	q.head=0;
	q.t=(cbtree*)malloc(sizeof(cbtree)*MAX);
	*T=NULL;
	char fa,ch;
	cbtree p,s,r;
	scanf("%c %c",&fa,&ch);
	getchar();
	while(ch!='#')
	{
		p=(cbtree)malloc(sizeof(cbnode));
		p->c=ch;
		p->bro=p->chi=NULL;
		enqueue(&q,p);
		if(fa=='#')
		{
			*T=p;
		}
		else
		{
			s=geth(&q);
			while(s->c!=fa)
			{
				dequeue(&q);
				s=geth(&q);
			}
			if(s->chi==NULL)
			{
				s->chi=p;
				r=p;
			}
			else
			{
				r->bro=p;
				r=p;
			}
		}
		scanf("%c %c",&fa,&ch);
		getchar();
	}
	return 0;
}

int pri(cbtree T)
{
	if(T!=NULL)
	{
		printf("%c",T->c);
		cbtree p=T;
		pri(p->chi);
		pri(p->bro);
	}
	return 0;
}

int depth(cbtree T)
{
	int d1,d2,max;
	if(T==NULL)
		return 0;
	else
	{
		d1=depth(T->bro);
		d2=depth(T->chi);
		d2++;
		max=d1;
		if(d2>d1)
			max=d2;
	}
	return max;
}


int main()
{
	printf("请依次输入边:\n");
	cbtree T;
	crtt(&T);
	printf("先根遍历:");
	pri(T);
	printf("\n");
	int num;
	num=depth(T);
	printf("深度:%d\n",num);
	return 0;
}