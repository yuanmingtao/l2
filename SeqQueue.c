#include<stdio.h>
#include<stdlib.h>
#define QueueSize 100
typedef int DataType;
typedef struct {
	DataType data[QueueSize];
	int front, rear;
}SeqQueue;

void InitQueue(SeqQueue * q)
{
	q->front = q->rear = 0;
}

int QueueEmpty(SeqQueue * q)
{
	return q->front == q->rear;
}

void EnQueue(SeqQueue * q, DataType x)
{
	q->data[q->rear++] = x;
}

DataType DeQueue(SeqQueue * q)
{
	if(QueueEmpty(q))
	{
		printf("queue underflow!\n");
		exit(0);
	}
	else
		return q->data[q->front++];
}

DataType GetFront(SeqQueue * q)
{
	if(QueueEmpty(q))
	{
		printf("queue empty!\n");
		exit(0);
	}
	else
		return q->data[q->front];
}

int main()
{
	SeqQueue q;
	InitQueue(&q);
	EnQueue(&q, 10);
	EnQueue(&q, 9);
	EnQueue(&q, 8);
	printf("%2d\n", DeQueue(&q));
	printf("%2d\n", DeQueue(&q));
	printf("%2d\n", DeQueue(&q));
	printf("%2d\n", GetFront(&q));
}
