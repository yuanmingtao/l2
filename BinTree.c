#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct node{
	DataType data;
	struct node * lchild, * rchild;
}BinTNode;
typedef BinTNode * BinTree;

/*(A(B(C,D),E));*/
/*广义表创建二叉树*/
BinTree CreateTree(char *str)
{
	BinTNode *st[100];
	BinTNode *p = NULL;
	int top,k,j=0;
	char ch = str[j];
	BinTNode * b = NULL;
	top = -1;
	while(ch != '\0')
	{
		switch(ch)
		{
			case '(':
				top++;
				st[top] = p;
				k = 1;
				break;
			case ')':
				top--;
				break;
			case ',':
				k = 2;
				break;
			default:
				p = (BinTNode *)malloc(sizeof(BinTNode));
				p->data = ch;
				p->lchild = p->rchild = NULL;
				if (b == NULL)
					b = p;
				else
				{
					switch(k)
					{
						case 1:
							st[top]->lchild = p;
							break;
						case 2:
							st[top]->lchild = p;
							break;
					}
				}
		}
		j++;
		ch = str[j];
	}
	return b;
}

void PreOrder(BinTree bt)
{
	if (bt != NULL)
	{
		printf("%2c", bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

int main()
{
	char str[20];
	BinTree bt;
	printf("input general table\n");
	scanf("%s",str);
	bt = CreateTree(str);
	PreOrder(bt);
	printf("\n");
}