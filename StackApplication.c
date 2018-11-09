#include<stdio.h>
#include<stdlib.h>
#include "SeqStack.c"  //字符顺序栈
#include "SeqStack1.c" //整型顺序栈
#include "CirQueue.c"  //循环字符顺序队列

#define max 8
int queen[max], sum=0; /* max为棋盘最大坐标 */
/*圆括号匹配*/
int Expr()
{
	SeqStack s;
	DataType ch,x;
	InitStack(&s);
	ch = getchar();
	while(ch != '\n')
	{
		if (ch == '(')
			Push(&s, ch);
		else
			if (ch == ')')
				if (StackEmpty(&s)) return 0;
				else x = Pop(&s);
		ch = getchar();
	} //end of while
	if (StackEmpty(&s)) return 1;
	else return 0;
}

/*字符串回文判断*/
int Symmetry(char str[])
{
	SeqStack s;
	int i = 0,j;
	InitStack(&s);
	while(str[i] != '\0')
		i++;
	for (j = 0 ;j < i / 2; j++)
		Push(&s, str[j]);
	j = (i + 1) / 2;
	while(j < i && Pop(&s) == str[j])
		j++;
	if (j == i) return 1;
	else return 0;
}

/*数制转换*/
void coversion(int N, int d)
{
	SeqStack s;
	int i, j;
	i = N;
	InitStack(&s);
	while(i > 0)
	{
		j =  i % d;
		Push(&s, j);
		i = i / d;
	}
	while(!StackEmpty(&s))
		printf("%d", Pop(&s));
}

 /*-------------------八皇后问题--------------------------*/
void show() /* 输出所有皇后的坐标 */
{
    int i;
    for(i = 0; i < max; i++)
    {
         printf("(%d,%d) ", i, queen[i]);
    }
    printf("\n");
    sum++;
}
 
int check(int n) /* 检查当前列能否放置皇后 */
{
    int i;
    for(i = 0; i < n; i++) /* 检查横排和对角线上是否可以放置皇后 */
    {
        if(queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i))
        {
            return 1;
        }
    }
    return 0;
}
 
void put(int n) /* 回溯尝试皇后位置,n为横坐标 */
{
    int i;
    for(i = 0; i < max; i++)
    {       
        queen[n] = i; /* 将皇后摆到当前循环到的位置 */
        if(!check(n))
        {           
            if(n == max - 1)
            {
                show(); /* 如果全部摆好，则输出所有皇后的坐标 */
            }         
            else
            {
                put(n + 1); /* 否则继续摆放下一个皇后 */
            }
        }
    }
}
/*-------------------八皇后问题--------------------------*/

/*-------------------汉诺塔问题--------------------------*/

void hanoi ( int n, char a,  char b,  char c )         
{  
	if  (1 == n)                                         
		printf("%c-->%c\n",a,c);
    else
	{
         hanoi( n-1,  a,  c,  b );    
         printf("%c-->%c\n",a , c);
         hanoi( n-1,  b,  a,  c );
    }
}
/*-------------------汉诺塔问题--------------------------*/

long int Fibonacci (int n)         
{  
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n > 1)
		return Fibonacci(n-1) + Fibonacci(n-2);
}

long int fact(int n)
{
	int temp;
	if (n == 0)
		return 1;
	else
		temp = n * fact(n-1);
	return temp;
}

float fu(int n)
{
	if (n < 2)
		return (n + 1);
	else
		return fu(n / 2) * fu(n / 4);
}

/*----------------计算表达式--------------*/
/*仅支持个位 四则运算*/
int Priority(DataType op)
{
	switch(op)
	{
		case '(':
		case '#':
			return 0;
		case '-':
		case '+':
			return 1;
		case '*':
		case '/':
			return 2;
	}
	return -1;
}

void CTPostExp(CirQueue * q)
{
	SeqStack s;
	char c, t;
	InitStack(&s);
	Push(&s, '#');
	do{
		c = getchar();
		switch(c)
		{
			case ' ': break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': EnQueue(q, c);break;
			case '(': Push(&s,c); break;
			case ')':
			case '#':
				do
				{
					t = Pop(&s);
					if (t != '(' && t != '#' && t != 8)
						EnQueue(q,t);
				}while(t != '(' && !StackEmpty(&s));
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				while(Priority(c) <= Priority(GetTop(&s)))
				{
					t = Pop(&s);
					EnQueue(q, t);
				}
				Push(&s, c);
				break;
		}
		
	}while(c != '#');
}

int CPosExp(CirQueue *q)
{
	
	SeqStack1 s;
	char ch;
	int x, y;
	InitStack1(&s);
	while(!QueueEmpty(q))
	{
		//9-5*(5+4)/5+6#
		ch = DeQueue(q);
		if (ch >= '0' && ch <= '9')
			Push1(&s, ch - '0');
		else
		{
			y = Pop1(&s);
			x = Pop1(&s);
			switch(ch)
			{
				case '+':
					Push1(&s, x + y);
					break;				
				case '-':
					Push1(&s, x - y);
					break;				
				case '*':
					Push1(&s, x * y);
					break;				
				case '/':
					Push1(&s, x / y);
					break;
			}
		}		
	}

	return GetTop1(&s);
}
/*----------------计算表达式--------------*/


int main()
{

/*----------------计算表达式--------------*/
	CirQueue q;
	InitQueue(&q);
	CTPostExp(&q);
	printf("%d\n", CPosExp(&q));
	
/*----------------计算表达式--------------*/



	// printf("%d", Fibonacci(19));
	// printf("fu= %f\n", fu(10));
	// // printf("%d", fact(4));
	// DataType x;
	// char test[6];
	// // char  str[6] = {'a','b','c','c','b','a'};
	// // printf("input char for check Symmetry.\n");
	// scanf("%s", test);
	// printf("%d", Expr());
	// printf("%d", Symmetry(str));	
	// coversion(3553, 8);	
	// coversion(10, 2);	
	// 
/*-------------------八皇后问题--------------------------*/
// 	put(0); /* 从横坐标为0开始依次尝试 */
//     printf("%d", sum);
// -------------------八皇后问题--------------------------

/*-------------------汉诺塔问题--------------------------*/
  // int  n;
  // printf( "Input the number of diskes:");
  // scanf("%d",&n);
  // hanoi ( n, 'A', 'B', 'C' );
/*-------------------汉诺塔问题--------------------------*/
}