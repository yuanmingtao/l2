#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct dlnode{
	DataType data;
	struct dlnode * prior, *next;
}DLNode;
typedef DLNode * DLinkList;

DLinkList CreateDLinkList()
{
	DataType ch;
	DLinkList  head = (DLNode*)malloc(sizeof(DLNode));
	DLNode *p,*node;
	p = head;
	ch = getchar();
	while(ch != '\n')
	{
		node = (DLNode*)malloc(sizeof(DLNode));
		node->data = ch;
		node->prior = p;
		p->next = node;
		ch = getchar();
		p = p->next;
	}
	p->next = head;
	head->prior = p;
	return head;
}
void DLInsert(DLNode * p,DataType x)
{
	DLNode * s = (DLNode *)malloc(sizeof(DLNode));
	s->data = x;
	s->prior = p->prior;
	s->next = p;
	p->prior->next = s;
	p->prior = s;	
}

void trans(DLinkList head)
{
	DLNode * p = head->next;
	DLNode * q = p;
	while(p != head)
	{
		p->prior = q;
		q = p;
		p = p->next;
	}
	p->prior = q;
}

DataType DLDelete(DLNode *p)
{
	int x;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	x = p->data;
	free(p);
	return x;
}

void DisplayList(DLinkList p)
{

	DLinkList q = p->next;
	if (q == p)
	{
		printf("empty list");
		exit(0);
	}
	while(q!= p)
	{
		printf("%c ",q->data);
		q = q->next;
	}
}
/*--------------------17---------------------*/
void f17(DLinkList head, DataType x, DataType y)
{
	DLNode * s = (DLNode *)malloc(sizeof(DLNode));
	DLNode * p = head->next;
	s->data = y;
	while(p != head && p->data != x)
		p = p->next;
	if (p == head)
	{
		printf("exception\n");
		exit(0);
	}
	else
	{
		s->prior = p->prior;
		s->next  = p;
		p->prior->next = s;
		p->prior = s;
	}	
}
/*-------------------------------------------*/

int main()
{
/*第2章算法设计题*/
/*--------------------17---------------------*/
	DLinkList p;
	DataType ch;
	p = CreateDLinkList();
	DisplayList(p);
	printf("\nInput insert number\n");
	ch = getchar();
	f17(p, ch, '9');
	DisplayList(p);
/*-------------------------------------------*/
	
}




