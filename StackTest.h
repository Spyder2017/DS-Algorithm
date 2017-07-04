#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;

#define STACK_INIT_SIZE 100		//�洢�ռ��ʼ������
#define STACKINCREMENT	10		//�洢�ռ��������

typedef struct{
	SElemType *base;			//��ջ����֮ǰ������֮��base��ֵΪNULL
	SElemType *top;				//ջ��ָ��
	int stacksize;				//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

Status InitStack(SqStack &S)
{
	//����һ����ջ
	S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base)			//�洢����ʧ��
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
/*
Status DestroyStack(SqStack &S)
{
	//����ջS,S���ٴ���
	SqStack m;
	while(S.stacksize--)
	{
		m.top = S.top;
		m.base = S.base;
	}
}

Status ClearStack(SqStack &S)
{
	//��S��Ϊ��ջ
}
*/
Status StackEmpty(SqStack S)
{
	//��ջSΪ��ջ,�򷵻�TRUE,���򷵻�FALSE
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
	//����S��Ԫ�ظ���,��ջ�ĳ���
}
*/
Status GetTop(SqStack S,SElemType &e)
{
	//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if(S.top == S.base)
		return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S,SElemType e)
{
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if(S.top - S.base > S.stacksize)
	{//ջ����׷�Ӵ洢�ռ�
		S.base = (SElemType *)realloc(S.base,(S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S.base)			//�洢����ʧ��
			exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK;���򷵻�ERROR
	if(S.top == S.base)
		return ERROR;
	e = * --S.top;
	return OK;
}

/*
Status StackTraverse(SqStack S,Status(*visit)())
{
	//��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ��
}
*/

void conversion(SqStack &S)
{
	//�������������һ���Ǹ�ʮ������������ӡ��������ֵ����Ҫת�����Ľ�����
	int n,e=0,flag=0;
	InitStack(S);	//�����ջ
	printf("����Ҫת����ʮ��������\n");
	scanf("%d",&n);
	printf("Ҫת��Ϊ���ٽ��ƣ�2-16�������֣�\n");
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