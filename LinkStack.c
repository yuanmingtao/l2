typedef int DataType;
typedef struct stacknode{
	DataType data;
	struct stacknode * next;
}StackNode;
typedef StackNode * LinkStack;

int StackEmpty(LinkStack top)
{
	return top == NULL;
}

LinkStack Push(LinkStack top ,DataType x)
{
	StackNode *p;
	p = (StackNode *)malloc(sizeof(StackNode));
	p->data = x;
	p->next = top;
	top = p;
}
/*top = NULL !important*/
LinkStack top; 
LinkStack Pop(LinkStack top, DataType *x)
{
	StackNode *p = top;
	if(StackEmpty(top))
	{
		printf("stack empty\n");
		exit(0);
	}
	else
	{
		top = p->next;
		*x = p->data;
		free(p);
	}
	return top;
}

DataType GetPop(LinkStack top)
{
	if(StackEmpty(top))
	{
		printf("stack empty\n");
		exit(0);
	}
	else
		return top->data;
}