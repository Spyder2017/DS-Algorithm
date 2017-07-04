#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

typedef struct Yoserf
{
	ElemType data;
	struct Yoserf *next;
}Yoserf,*LinkList;

int n;

//创建链表并赋值
LinkList Create_List()
{
	LinkList head,p,l;
	int i,num;
	head = (LinkList)malloc(sizeof(Yoserf));
	head->next = NULL;
	l = head;
	printf("请输入约瑟夫环的元素个数：");
	scanf("%d",&n);
	printf("请依次输入该约瑟夫环的所有元素：\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		p = (LinkList)malloc(sizeof(Yoserf));
		p->data = num;
		l->next = p;
		l = p;
	}
	l->next = head->next;
	return head;
}

//输出所有元素
void print(LinkList head)
{
	int nm = 1;
	LinkList p;
	p = head->next;
	printf("约瑟夫环元素排列顺序：\n");
	while(nm)
	{
		printf("%d\t",p->data);
		p = p->next;
		if(p == head->next)
		{
			nm--;
		}
	}
	printf("\n");
}

void Calcul_List(LinkList head)
//遍历约瑟夫环，数到三自杀的数输出
{
	LinkList p,q;
	int m = 0;
	p = head->next;
	printf("约瑟夫环元素自杀顺序：\n");
	while(n-1)
	{
		m++;
		if(m == 2)
		{
			printf("%d\t",p->next->data);
			q = p->next;
			p->next = q->next;
			free(q);
			m = 0;
			n--;
		}
		p = p->next;
	}
	printf("%d\n",p->data);
}

//插入操作
LinkList Insert_List(LinkList head)
{
	LinkList p,m;
	int numb,nm = 1;
	printf("请输入需插入结点的前驱结点元素：");
	scanf("%d",&numb);
	p = head->next;
	while(nm)
	{
		if(p->data == numb)
		{
			m = (LinkList)malloc(sizeof(Yoserf));
			printf("请依次输入该约瑟夫环要插入的元素：\n");
			scanf("%d",&(m->data));
			m->next = p->next;
			p->next = m;
			n++;
			nm--;
		}
		p = p->next;
	}
	return head;
}

//删除操作
LinkList Delete_List(LinkList head)
{
	LinkList p,q;
	int numb,nm = 1;
	printf("请输入需删除结点的元素：\n");
	scanf("%d",&numb);
	p = head;
	while(nm)
	{
		if(p->next->data == numb)
		{
			q = p->next;
			p->next = p->next->next;
			free(q);
			nm--;
			n--;
		}
		p = p->next;
	}
	return head;
}