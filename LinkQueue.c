#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct qnode{
	DataType data;
	struct qnode * next;
}QueueNode;

typedef struct{
	QueueNode * front;
	QueueNode * rear;
}LinkQueue;

void InitQueue(LinkQueue * q)
{
	q->front = (QueueNode *)malloc(sizeof(QueueNode));
	q->rear  = q->front;
	q->rear->next = NULL;
}

int QueueEmpty(LinkQueue * q)
{
	return q->front == q->rear;
}

void EnQueue(LinkQueue * q, DataType x)
{
	QueueNode * p = (QueueNode *)malloc(sizeof(QueueNode));
	p->data = x;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

DataType GetFront(LinkQueue * q)
{
	if (QueueEmpty(q))
	{
		printf("Queue empty\n");
		exit(0);
	}
	else
		return q->front->next->data;
}

DataType DeQueue(LinkQueue *q)
{
	if (QueueEmpty(q))
	{
		printf("Queue underflow\n");
		exit(0);
	}
	QueueNode * p = q->front;
	q->front = q->front->next;
	free(p);
	return q->front->data;
}
int main()
{
	LinkQueue q;
	InitQueue(&q);
	EnQueue(&q,10);
	EnQueue(&q,9);
	EnQueue(&q,8);
	EnQueue(&q,7);

	printf("%2d\n", DeQueue(&q));
	printf("%2d\n", DeQueue(&q));
	printf("%2d\n", DeQueue(&q));
	printf("%2d\n", DeQueue(&q));
	EnQueue(&q,20);
	printf("%2d\n", GetFront(&q));
	printf("%2d\n", DeQueue(&q));
}
