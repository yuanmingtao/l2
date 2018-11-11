/*稀疏矩阵*/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100 //假设非零元素个数的最大为100个
#define MaxRow 10
typedef int DataType;
typedef struct {
	int i, j; //非零元素的下标
	DataType v; //非零元素值
}TriTupleNode;

typedef struct {
	TriTupleNode data[MaxSize]; //存储三元组的数组
	int m,n,t; //矩阵的行数、列数和非零元素个数
}TSMatrix; //稀疏矩阵类型

/*行逻辑链接的顺序表*/
typedef struct {
	TriTupleNode data[MaxSize]; 
	int RowPos[MaxRow]; //每行第一个非零元素的位置表
	int m,n,t; 
}RLSMatrix; //带行表的三元组表

/*创建三元组表*/
void CreateTriTable(TSMatrix *b, int a[][2], int m, int n)
{
	int i, j, k = 0;
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			if(a[i][j] != 0)
			{
				b->data[k].v = a[i][j];
				b->data[k].i = i;
				b->data[k].j = j;
				k++;
			}
	b->m = m;
	b->n = n;
	b->t = k;
}

/*三元组表转置*/
/*时间复杂度 o(n*t)*/
void TransMatrix(TSMatrix a, TSMatrix *b)
{
	int p, q, col;
	b->m = a.n;
	b->n = a.m;
	b->t = a.t;
	if (b->t <= 0)
		printf("M中无非零元素!");
	else
	{
		q = 0;
		for (col = 0; col < a.n; ++col)
			for (p = 0; p < a.t; p++)
				if (a.data[p].j == col)
				{
					b->data[q].i = a.data[p].j;
				    b->data[q].j = a.data[p].i;
					b->data[q].v = a.data[p].v;
					q++;
				}
	}
}

/*快速转置算法*/
void FastTran(TSMatrix a, TSMatrix *b)
{
	int col, p, t, q;
	int *num, *rownext;
	num = (int *)calloc(a.n + 1, 4); //a中每列非零元素个数
	rownext = (int *)calloc(a.n + 1, 4); //b中每一行的元素在一维数组的存储位置
	b->m = a.n;
	b->n = a.m;
	b->t = a.t;
	if (b->t > 0)
	{
		for (col = 0; col < a.n; ++col)
			num[col] = 0;
		for (t = 0; t < a.t; t++)
			++num[a.data[t].j];
		rownext[0] = 0;
		for (col = 1; col < a.n; ++col)
			rownext[col] = rownext[col - 1] + num[col - 1];
		for (p = 0; p < a.t; p++)
		{
			col = a.data[p].j;
			q = rownext[col];
			b->data[q].i = a.data[p].j;
			b->data[q].j = a.data[p].i;
			b->data[q].v = a.data[p].v;
			rownext[col]++;
		}
	}	
}
void displayTSMatrix(TSMatrix *p)
{
	int i = 0;
	while(i < p->t)
	{
		printf("(%d, %d, %d)", p->data[i].i, p->data[i].j, p->data[i].v);
		printf("\n");
		i++;
	}
	
}
void displayArray(int *p, int n, int m)
{
	
	int * q = p;
	int i = n * m;
	
	while(i > 0)
	{
		printf("%3d", *q);
		if ((i - 1) % m == 0)
			printf("\n");
		i--;
		q++;
	}
}

int main()
{
	TSMatrix b, c;
	int a[2][2];
	a[0][0] = 0;
	a[0][1] = 10;
	a[1][0] = 12;
	a[1][1] = 0;
	displayArray(&a[0][0], 2, 2);
	CreateTriTable(&b, a, 2, 2);
	displayTSMatrix(&b);
	// TransMatrix(b, &c);
	FastTran(b, &c);
	displayTSMatrix(&c);
}