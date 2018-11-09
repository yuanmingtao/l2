#define QueueSize 100
typedef char DataType;
typedef struct {
	DataType data[QueueSize];
	int front, rear;
}CirQueue;

void InitQueue(CirQueue * q)
{
	q->front = q->rear = 0;
}

int QueueFull(CirQueue * q)
{
	return (q->rear + 1) % QueueSize == q->front;
}

int QueueEmpty(CirQueue * q)
{
	return q->front == q->rear;
}

void EnQueue(CirQueue * q, DataType x)
{
	if (QueueFull(q))
	{
		printf("queue overflow\n");
		exit(0);
	}
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % QueueSize;
}

DataType DeQueue(CirQueue * q)
{
	DataType x;
	if(QueueEmpty(q))
	{
		printf("queue underflow!\n");
		exit(0);
	}
	
	x = q->data[q->front];
	q->front = (q->front + 1) % QueueSize;
	return x;
}

DataType GetFront(CirQueue * q)
{
	if(QueueEmpty(q))
	{
		printf("queue empty!\n");
		exit(0);
	}
	else
		return q->data[q->front];
}
