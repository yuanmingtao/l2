#include<stdio.h>
#include<stdlib.h>
#define ListSize 100
typedef int DataType;
typedef struct {
	DataType data[ListSize];
	int length;
}SeqList;
void Initialize(SeqList * L)
{
	int i = 0;
	L->length = 0;
	while(i < 10)
	{
		L->data[i++] = rand()%10 + 10;
		L->length ++;
	}
}

void ListSort(SeqList *L)
{
	int i = 0,j,offset;
	DataType x, tmp;
	while(i < L->length -1)
	{
		x = L->data[i];
		tmp = x;
	    j = i + 1;
		while(j < L->length)
		{
			if (tmp > L->data[j])
			{
				tmp = L->data[j];
				offset = j;
			}
			j++;
		}

		L->data[i] = tmp;
		L->data[offset] = x;
		i++;
	}
}

void PrintList(SeqList *L)
{
	int i = 0;
	if (L->length ==0)
	{
		printf("empty list");
		return;
	}
	while(i < L->length)
		printf("%3d", L->data[i++]);
}
void InsertList(SeqList * L, int i, DataType x)
{
	int j;
	if (i < 1 || i > L->length + 1)
	{
		printf("position error");
		return;
	}
	
	if(L->length >= ListSize)
	{
		printf("overflow");
		return;
	}
	for(j=L->length - 1; j >= i-1; j--)
		L->data[ j + 1] = L->data[j];
	L->data[j+1] = x;
	L->length++;
}
DataType DeleteList(SeqList * L, int i)
{
	int j;
	DataType x;
	if (L->length == 0 || i > L->length)
	{
		printf("error");
		exit(0);
	}
	x = L->data[i];
	for (j = i; j < L->length - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	return x;
}
void Converts(SeqList *L)
{
	int i;
	DataType tmp;
	for(i = 0; i < L->length / 2; i++)
	{
		tmp = L->data[i];
		L->data[i] = L->data[L->length - 1 - i];
		L->data[L->length - 1 -i] = tmp;
	}
}
void MaxMin(SeqList * L,DataType * max, DataType * min,int * k,int *j)
{
	int i;
	i = 0;
	*max = L->data[0];
	*min = L->data[0];
	while(i < L->length)
	{
		if (L->data[i] > *max) 
		{
			*max = L->data[i];
			*k = i;
		}
		if (L->data[i] < *min) 
		{
			*min = L->data[i];
			*j = i;
		}
		i++;
	}
}

/*第2章 算法设计题*/
/*--------------------14-------------------------------*/
void f14(SeqList * A, SeqList * B)
{
	int i = 0, j = 0,k;
	while(i < B->length)
	{
		while(j < A->length && B->data[i] > A->data[j])
			j++;
		if (B->data[i] == A->data[j])
		{
			k = j;
			while(k < A->length - 1)
			{
				A->data[k]=A->data[k+1];
				k++;
			}
			A->length--;
		}
		i++;
	}
}
/*-------------------------------------------------------*/

int main()
{
	/*第2章算法设计题*/
	/*--------------------14---------------------*/
	SeqList * A,*B;
	A = (SeqList *)malloc(sizeof(SeqList));
	B = (SeqList *)malloc(sizeof(SeqList));
	Initialize(A);
	Initialize(B);
	printf("\n-----A------\n");
	PrintList(A);
	ListSort(A);
	printf("\n-----A------\n");
	PrintList(A);
	printf("\n------B-----\n");
	PrintList(B);
	ListSort(B);
	printf("\n-----B------\n");
	PrintList(B);
	f14(A,B);
	printf("\n------A-B-----\n");
	PrintList(A);
	/*-------------------------------------------*/
	// SeqList * L;
	// DataType max, min, k, j;
	// L = (SeqList *)malloc(sizeof(SeqList));
	// Initialize(L);
	// PrintList(L);
	// // InsertList(L,1,5);
	// printf("\n---------%d------------\n", L->length);
	// Converts(L);
	// PrintList(L);
	// MaxMin(L,&max,&min,&k,&j);
	// printf("\n max of L is L->data[%d] = %d\n",k,max);
	// printf("\n min of L is L->data[%d] = %d\n",j,min);
	// printf("\n---------%d------------\n", DeleteList(L,5));
	// PrintList(L);
}
