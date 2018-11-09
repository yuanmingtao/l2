/*第4章 多维数组和广义表*/
#include<stdio.h>
#include<stdlib.h>
#define M 10;
#define N 10;

int ** initialize(int m, int n)
{
	int **a;
	int i, j;
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			a[i][j] = rand()%10 + 10;
	return a;
}

void displayArray(int **a)
{
	int i = 0,j = 0;
	while(a[i] != NULL)
	{
		while(a[i][j]!='\0')
			printf("%3d",a[i++][j++]);
		printf("\n");
	}
}
/*A[m][n] 的转置矩阵 B[n][m]*/
void trsmat(int a[][8],int b[][5],int m, int n)
{
	
}

int main()
{
	int **p = initialize(5, 8);
	displayArray(p);
}