#include<stdio.h>
#include<stdlib.h>
#define ShareStackSize 6
typedef int DataType;
/*共享存储空间*/
DataType data[ShareStackSize];
typedef struct {
	int top;
}SeqShareStack;

void InitBottomStack(SeqShareStack *s)
{
	s->top = -1;
}

void InitTopStack(SeqShareStack *s)
{
	s->top = ShareStackSize;
}
int StackEmpty(SeqShareStack *s)
{
	return s->top == -1 || s->top == ShareStackSize;
}
int StackFull(SeqShareStack *s1, SeqShareStack *s2)
{
	return s1->top == s2->top - 1;
}
void PushToBottom(SeqShareStack *s, DataType x)
{
	data[++s->top] = x;
}

void PushToTop(SeqShareStack *s, DataType x)
{
	data[--s->top] = x;
}

void Push(SeqShareStack *s1, SeqShareStack *s2, DataType x, DataType y)
{
	if (StackFull(s1, s2))
		printf("stack overflow\n");
	else
	{
		PushToBottom(s1, x);
		if (StackFull(s1, s2))
			printf("stack overflow\n");
		else
			PushToTop(s2, y);
	}
}

DataType PopBottom(SeqShareStack * s)
{
	if (StackEmpty(s))
	{
		printf("stack underflow\n");
		exit(0);
	}
	else
		return data[s->top--];
}

DataType PopTop(SeqShareStack * s)
{
	if (StackEmpty(s))
	{
		printf("stack underflow\n");
		exit(0);
	}
	else
		return data[s->top++];
}

DataType GetTop(SeqShareStack * s)
{
	if (StackEmpty(s))
	{
		printf("stack empty\n");
		exit(0);
	}
	else
		return data[s->top];
}

int main()
{
	SeqShareStack s1,s2;
	InitBottomStack(&s1);
	InitTopStack(&s2);
	Push(&s1, &s2, 1, 2);
	Push(&s1, &s2, 3, 7);	
	Push(&s1, &s2, 5, 4);
	printf("%2d\n",PopTop(&s2));
	printf("%2d\n",GetTop(&s2));
	printf("%2d\n",PopTop(&s2));
	printf("%2d\n",PopTop(&s2));
}
