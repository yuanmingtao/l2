/*整型顺序栈*/
#define StackSize 100
typedef struct {
	int data[StackSize];
	int top;
}SeqStack1;

void InitStack1(SeqStack1 *s)
{
	s->top = -1;
}
int StackEmpty1(SeqStack1 *s)
{
	return s->top == -1;
}
int StackFull1(SeqStack1 *s)
{
	return s->top == StackSize - 1;
}
void Push1(SeqStack1 *s, int x)
{
	if (StackFull1(s))
		printf("stack overflow\n");
	else
		s->data[++s->top] = x;
}
int Pop1(SeqStack1 * s)
{
	if (StackEmpty1(s))
	{
		printf("stack underflow\n");
		exit(0);
	}
	else
		return s->data[s->top--];
}

int GetTop1(SeqStack1 * s)
{
	if (StackEmpty1(s))
	{
		printf("stack empty\n");
		exit(0);
	}
	else
		return s->data[s->top];
}