#define StackSize 100
typedef char DataType;
typedef struct {
	DataType data[StackSize];
	int top;
}SeqStack;

void InitStack(SeqStack *s)
{
	s->top = -1;
}
int StackEmpty(SeqStack *s)
{
	return s->top == -1;
}
int StackFull(SeqStack *s)
{
	return s->top == StackSize - 1;
}
void Push(SeqStack *s, DataType x)
{
	if (StackFull(s))
		printf("stack overflow\n");
	else
		s->data[++s->top] = x;
}
DataType Pop(SeqStack * s)
{
	if (StackEmpty(s))
	{
		printf("stack underflow\n");
		exit(0);
	}
	else
		return s->data[s->top--];
}

DataType GetTop(SeqStack * s)
{
	if (StackEmpty(s))
	{
		printf("stack empty\n");
		exit(0);
	}
	else
		return s->data[s->top];
}