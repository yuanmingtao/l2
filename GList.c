/*广义表*/
#include<stdio.h>
#include<stdlib.h>
typedef char DataType;
typedef enum {atom,list} NodeTag; // atom=0,表示原子;list=1,表示子表
typedef struct node{
	NodeTag tag;                  //用以区分原子结点和表结点
	union
	{
		DataType data;            //用以存放原子结点值,其类型由用户自定义
		struct node * slink;      //指向子表的指针
	};
	struct node * next;           //指向下一个表结点
}GLNode;                          //广义表类型
typedef GLNode * GList;

GList p;
//(a,(b,c,d),e,(f,g))
GList CreateGList(GList gl)
{
	char ch;
	scanf("%c", &ch);
	if (ch != ' ')
	{
		gl = (GLNode *)malloc(sizeof(GLNode));
		if (ch == '(')
		{
			gl->tag = list;
			gl->slink = CreateGList(NULL);
		}
		else
		{
			gl->tag = atom;
			gl->data = ch;
		}
	}
	else gl = NULL;
	scanf("%c", &ch);
	if (gl != NULL)
		if (ch == ',')
			gl->next = CreateGList(NULL);
		else
			gl->next = NULL;
	return gl;
}

void PrintGList(GList gl)
{
	if (gl != NULL)
	{
		if (gl->tag == list)
		{
			printf("(");
			if (gl->slink == NULL) 
				printf(" ");
			else PrintGList(gl->slink);
			
		}
		else printf("%c", gl->data);
		if (gl->tag == list)
			printf(")");
		if (gl->next != NULL)
		{
			printf(",");
			PrintGList(gl->next);
		}
	}
}

void FindGListX(GList gl, DataType x, int *mark)
{
	if (gl != NULL)
	{
		if (gl->tag == 0 && gl->data == x)
		{
			*mark = 1;
			p = gl;
		}
		else
		{
			if (gl->tag  == 1) FindGListX(gl->slink, x, mark);
			FindGListX(gl->next, x, mark);
		}		
	}
}

GList head(GList gl)
{
	GList p;
	if (gl != NULL && gl->tag != 0)
	{
		p = gl->slink;
		p->next = NULL;
		return p;
	}
	else return NULL;
}

GList tail(GList gl)
{
	GList p;
	if (gl != NULL && gl->tag != 0)
	{
		p = gl->slink;
		p = p->next;
		gl->slink = p;
	}
	return p;
}

void depth(GList gl, int *maxdh)
{
	int h;
	if (gl->tag == 0) *maxdh = 0;
	else
		if (gl->tag == 1 && gl->slink == NULL)
			*maxdh = 1;
		else
		{
			gl = gl->slink;
			*maxdh = 0;
			do
			{
				depth(gl, &h);
				if (h > *maxdh) *maxdh = h;
				gl = gl->next;
			}while(gl != NULL);
		}
	*maxdh = *maxdh + 1;
}

int main()
{
	GList gl;
	int mark;
	gl = CreateGList(gl);
	PrintGList(gl);
	FindGListX(gl, 'h', &mark);
	printf("%d", mark);
}