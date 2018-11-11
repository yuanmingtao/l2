/*第4章 多维数组和广义表*/
#include<stdio.h>
#include<stdlib.h>
#define M 10
#define N 10

void initialize(int *p, int m, int n)
{
	int i, j;
	int *q = p;
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
		{
			*q = rand()%10 + 10;
			q++;
		}
}

void displayArray(int *p, int n, int m)
{
	int * q = p;
	int i = n * m;
	while(*q != '\0' && i-- > 0)
	{
		printf("%2d", *q);
		if (i % m == 0)
			printf("\n");
		q++;
	}
}
/*A[m][n] 的转置矩阵 B[n][m]*/
void trsmat(int a[][8],int b[][5],int m, int n)
{
	int i,j;
	for(j = 0; j < m; j++)
		for(i = 0; i < n; i++)
			b[i][j] = a[j][i];
}

/*求矩阵马鞍点 该行最小值 该列最大值*/
void MaxMin(int A[4][5],int m, int n)
{
	int i,j,k;
	int max, min;
	int pointH[M], pointV[N];
	for(i = 0; i < m; i++)
	{
		min = A[i][0];
		k = 0;
		for(j = 0; j < n; j++)
		{
			if (A[i][j] < min)
			{
				min = A[i][j];
				k = j;
			}
		}
		pointH[i] = k;
	}
	
	for(j = 0; j < n; j++)
	{
		max = A[0][j];
		k = 0;
		for(i = 0; i < m; i++)
		{
			if (A[i][j] > max)
			{
				max = A[i][j];
				k = i;
			}
		}
		pointV[j] = k;
	}
	i = 0;
	while( i < m)
	{
		if (i == pointV[ pointH[i] ])
			printf("(%d, %d)\n", i, pointH[i]);
		i++;
	}
	
}

/* n * n阶对称矩阵乘积*/
void MatrixMulti(int a[], int b[], int c[][2], int n)
{
	int i,j,k,l1,l2,s;
	for(i = 0; i < 2; i++)	
		for(j = 0; j < 2; j++)
		{ 
			s = 0;
			for( k = 0; k < n; k++)
			{
				if (i >= k)
					l1 = i * (i + 1) / 2 + k;
				else
					l1 = k * (k + 1) / 2 + i;				
				
				if (k >= j)
					l2 = k * (k + 1) / 2 + j;
				else
					l2 = j * (j + 1) / 2 + k;
				s += a[l1] * b[l2];
			}
			c[i][j] = s;
		}
}

int main()
{
	
	int a[3] = {1, 1, 1};
	int b[3] = {1, 1, 1};
	int c[2][2];
	MatrixMulti(a, b, c, 2);
	displayArray(&c[0][0], 2, 2);
	// int a[4][5];
	// initialize(&a[0][0], 4, 5);
	// a[1][0] = 100;
	// a[1][1] = 200;
	// a[1][2] = 300;
	// a[1][3] = 400;
	// a[1][4] = 500;
	
	// displayArray(&a[0][0], 4, 5);
	// MaxMin(a, 4, 5);
	// int a[5][8];
	// int b[8][5];
	// initialize(&a[0][0], 5, 8);
	// displayArray(&a[0][0], 5, 8);
	// printf("\n-------------\n");
	// trsmat(a, b, 5, 8);
	// displayArray(&b[0][0], 8, 5);
	// int a[2][2];
	// a[0][0] = 1;
	// a[0][1] = 2;
	// a[1][0] = 3;
	// a[1][1] = 5;
	// displayArray(&a[0][0], 2, 2);
}