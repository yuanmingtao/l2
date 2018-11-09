#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct node{
	DataType data;
	struct node * next;
}ListNode;
typedef ListNode * LinkList;

LinkList CreateListF()
{
	LinkList head;
	ListNode *p;
	char ch;
	head = NULL;
	ch = getchar();
	while(ch != '\n')
	{
		p = (ListNode *)malloc(sizeof(ListNode));
		p->data = ch;
		p->next = head;
		head = p;
		ch = getchar();
	}
	return head;
}

LinkList CreateListR()
{
	LinkList head, rear;
	ListNode *p;
	char ch;
	head = NULL;
	rear = NULL;
	ch = getchar();
	while(ch != '\n')
	{
		p = (ListNode *)malloc(sizeof(ListNode));
		p->data = ch;
		if (rear != NULL)
			rear->next = p;
		else
			head = p;
		rear = p;
		ch = getchar();
	}
	if (rear != NULL) rear->next = NULL;
	return head;
}

LinkList CreateListR1()
{
	LinkList head = (ListNode *)malloc(sizeof(ListNode));
	ListNode *p,*r;
	DataType ch;
	r = head;
	ch = getchar();
	while(ch != '\n')
	{
		p = (ListNode *)malloc(sizeof(ListNode));
		p->data = ch;
		r->next = p;
		r = p;
		ch = getchar();
	}
	r->next = NULL;
	return head;
}

//循环链表
LinkList CreateListRC()
{
	LinkList head = (ListNode *)malloc(sizeof(ListNode));
	ListNode *p,*r;
	DataType ch;
	r = head;
	ch = getchar();
	while(ch != '\n')
	{
		p = (ListNode *)malloc(sizeof(ListNode));
		p->data = ch;
		r->next = p;
		r = p;
		ch = getchar();
	}
	r->next = head;
	return head;
}

void InsertListC(LinkList L, int x)
{
	ListNode * p = (ListNode *)malloc(sizeof(ListNode));
	ListNode * q = L->next;
	ListNode * r;
	p->data = x;
	while(q != L && q->data > x)
	{
		r = q;
		q = q->next;
	}
	if (q == L)
	{
		p->next = L;
		r->next = p;
	}
	else
	{
		p->next = q;
		r->next = p;
	}
}

ListNode * GetNode(LinkList head, int i)
{
	int j = 0;
	ListNode * p = head;
	while(j < i && p != NULL)
	{
		p = p->next;
		j++;
	}
	if (j == i)
		return p;
	return NULL;
}


ListNode * LocationNodek(LinkList head,DataType k)
{
	ListNode * p;
    p = head->next;
	while(p != NULL && p->data != k)
		p = p->next;
	if (p->data == k) return p;
	return NULL;
}


void InsertList(LinkList head, int i,DataType x)
{
	ListNode * p = head;
	ListNode * q = (ListNode*)malloc(sizeof(ListNode));
	q->data = x;
	int j = 0;
	while(j < i-1 && p != NULL)
	{
		p = p->next;
		j++;
	}
	if (j == i-1)
	{
		q->next = p->next;
		p->next = q;
	}
	else
	{
		printf("fault");
		exit(0);
	}		
}


DataType DeleteList(LinkList head, int i)
{
	ListNode * p = head, *s;
	int j = 0;
	DataType x;
	while(j < i-1 && p != NULL)
	{
		p = p->next;
		j++;
	}
	if (j == i-1)
	{
		x = p->next->data;
		s = p->next;
		p->next = s->next;
		free(s);
		return x;
	}
	else
	{
		printf("fault");
		exit(0);
	}		
}

void split(LinkList a,LinkList b)
{
	ListNode * p = a->next,*q = b;
	while(p->next != NULL)
	{
			q->next = p->next;
			q = q->next;
			if (q->next != NULL)
			{
				p->next = q->next;
			    p = p->next;
			}
			else p->next = NULL;
	}
	q->next = NULL;
}

LinkList MergeList(LinkList La, LinkList Lb)
{
	LinkList Lc = (ListNode *)malloc(sizeof(ListNode));
	LinkList p = La->next;
	LinkList q = Lb->next;
	LinkList r = Lc;
	// while(p!=NULL)
	// {
		// while(q != NULL && q->data < p->data)
		// {
			// r->next = q;
			// r = q;
			// q = q->next;
		// }
		
		// r->next = p;
		// r = p;
		// p = p->next;
	// }
	// r->next = NULL;
	
	while(p != NULL && q !=NULL)
	{
		if (p->data <= q->data)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else
		{
			r->next = q;
			r = q;
			q = q->next;	
		}
	}
	
	r->next = p!= NULL ? p : q;
	return Lc;
}

void DisplayList(LinkList p)
{

	LinkList q = p->next;
	if (q == NULL)
	{
		printf("empty list");
		exit(0);
	}
	while(q!= NULL)
	{
		printf("%c ",q->data);
		q = q->next;
	}
}

/*第2章算法设计题*/
/*--------------------15---------------------*/
void f15(LinkList head, ListNode * p)
{
	ListNode *step = head->next;
	ListNode * q = head;
	if (head == p || p == NULL || head == NULL)
	{
		printf("exception");
		exit(1);
	}
	while(step != NULL && step != p)
	{
		q = step;
		step = step->next;
	}
	if (step != NULL)
	{
		q->next = step->next;
		step->next = step->next->next;
		q->next->next = step;
	}
}
/*-------------------------------------------*/

/*--------------------16---------------------*/
void f16(LinkList A, LinkList B, LinkList C)
{
	ListNode *p  = A->next;
	ListNode *q  = B->next;
	ListNode *s;
	LinkList  c  = C;
	while(p != NULL && q != NULL)
	{
		if (p->data == q->data)
		{
			s = (ListNode*)malloc(sizeof(ListNode));
			s->data = p->data;
			c->next = s;
			p = p->next;
			q = q->next;
			c = c->next;
		}
		else if(p->data > q->data)
			q = q->next;
		else
			p = p->next;
	}
	c->next = NULL;
}
/*-------------------------------------------*/



int main()
{
/*第2章算法设计题*/
/*--------------------15---------------------*/
	// LinkList p;
	// // LinkList q;
	// // LinkList r;
	// // p = CreateListF();
	// p = CreateListR1();
	// // q = CreateListR1();
	// DisplayList(p);
	// printf("\n");
	// f15(p,p->next);
	// DisplayList(p);
/*-------------------------------------------*/
/*--------------------16---------------------*/
	LinkList p;
	LinkList q;
	LinkList r;
	r = (ListNode *)malloc(sizeof(ListNode));
	r->next = NULL;
	p = CreateListR1();
	q = CreateListR1();
	DisplayList(p);
	printf("\n");
	DisplayList(q);
	printf("\n");
	f16(p,q,r);
	DisplayList(r);
/*-------------------------------------------*/
	// DisplayList(q);
	// r = MergeList(p,q);
	// printf("\n");
	// DisplayList(q);
	// printf("\n");
	// split(p,q);
	// DeleteList(p, 3);
	// InsertList(p, 4,'3');
	// DisplayList(p);
	// printf("\n");
	// DisplayList(q);
	// printf("\n%c\n",GetNode(p,2)->data);
	// printf("%c\n",LocationNodek(p,'9')->data);
}
