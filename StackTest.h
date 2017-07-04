#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;

#define STACK_INIT_SIZE 100		//存储空间初始分配量
#define STACKINCREMENT	10		//存储空间分配增量

typedef struct{
	SElemType *base;			//在栈构造之前和销毁之后，base的值为NULL
	SElemType *top;				//栈顶指针
	int stacksize;				//当前已分配的存储空间，以元素为单位
}SqStack;

Status InitStack(SqStack &S)
{
	//构造一个空栈
	S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base)			//存储分配失败
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
/*
Status DestroyStack(SqStack &S)
{
	//销毁栈S,S不再存在
	SqStack m;
	while(S.stacksize--)
	{
		m.top = S.top;
		m.base = S.base;
	}
}

Status ClearStack(SqStack &S)
{
	//把S置为空栈
}
*/
Status StackEmpty(SqStack S)
{
	//若栈S为空栈,则返回TRUE,否则返回FALSE
	if(S.top == S.base)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
/*
int StackLength(SqStack S)
{
	//返回S的元素个数,即栈的长度
}
*/
Status GetTop(SqStack S,SElemType &e)
{
	//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
	if(S.top == S.base)
		return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S,SElemType e)
{
	//插入元素e为新的栈顶元素
	if(S.top - S.base > S.stacksize)
	{//栈满，追加存储空间
		S.base = (SElemType *)realloc(S.base,(S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S.base)			//存储分配失败
			exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK;否则返回ERROR
	if(S.top == S.base)
		return ERROR;
	e = * --S.top;
	return OK;
}

/*
Status StackTraverse(SqStack S,Status(*visit)())
{
	//从栈底到栈顶依次对栈中每个元素调用函数visit()。一旦visit()失败，则操作失败
}
*/

void conversion(SqStack &S)
{
	//对于输入的任意一个非负十进制整数，打印输出与其等值的需要转换到的进制数
	int n,e=0,flag=0;
	InitStack(S);	//构造空栈
	printf("输入要转化的十进制数：\n");
	scanf("%d",&n);
	printf("要转化为多少进制（2-16）填数字：\n");
	scanf("%d",&flag);
	while(n)
	{
		Push(S,n%flag);
		n = n/flag;
	}
	while(!StackEmpty(S))
	{
		Pop(S,e);
		switch(e)
		{
		case 10:printf("A");break;
		case 11:printf("B");break;
		case 12:printf("C");break;
		case 13:printf("D");break;
		case 14:printf("E");break;
		case 15:printf("F");break;
		default:printf("%d",e);break;
		}
	}
	printf("\n");
}