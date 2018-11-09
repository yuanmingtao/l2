//完全二叉树顺序表
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
#define M 10
typedef struct {
	DataType data[M];
	int length;
}SeqBinTNode;
typedef SeqBinTNode * SeqBinTree;


SeqBinTree CreateBinTree()
{
	SeqBinTree bt = (SeqBinTNode *)malloc(sizeof(SeqBinTNode));
	int i = 0;
	bt->length = 0;
	while(i < 10)
	{
		bt->data[i] = rand()%10 + 10;
		bt->length ++;
		i++;
	}
	return bt;
}

void DisplayBinTree(SeqBinTree bt)
{
	int i = 0;
	do
	{
		printf("%3d",bt->data[i]);
	}while(++i < bt->length);
}

int Depth(SeqBinTree bt)
{
	int left,right;
	int high = 1,stack = 0, memo;
	int gotten = 0,dep = 1;
	if (bt == NULL || bt->data[0] == 0)
	{
		printf("empty tree\n");
		exit(1);
	}
	while(!gotten)
	{
		left  = 2 * stack + 1;
		while(left < bt->length && bt->data[left] != 0)
		{
			high++;
			left = 2 * left + 1;
			
		}
		if (dep < high)
		  dep = high;
	  	if (left == bt->length - 1)
			gotten = 1; //得到高度
		memo = (left -1) / 2;//父亲结点
		memo = (memo - 1) / 2; //上级节点
		right = 2 * memo + 2;
		high--;
		while (right > = bt->length || bt->data[right] == 0)
		{
			memo = (memo -1) / 2;//父亲结点
			high--;
			right = 2 * memo + 2;
		}
		
		if (right == bt->length - 1)
			gotten = 1; //得到高度
		r = right;
		high ++;
	}
	return dep;
}

void Leaves(SeqBinTree bt, int *p)
{
	
}

int main()
{
	SeqBinTree bt = CreateBinTree();
	DisplayBinTree(bt);
	printf("%d",Depth(bt));
}