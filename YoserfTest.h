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

//����������ֵ
LinkList Create_List()
{
	LinkList head,p,l;
	int i,num;
	head = (LinkList)malloc(sizeof(Yoserf));
	head->next = NULL;
	l = head;
	printf("������Լɪ�򻷵�Ԫ�ظ�����");
	scanf("%d",&n);
	printf("�����������Լɪ�򻷵�����Ԫ�أ�\n");
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

//�������Ԫ��
void print(LinkList head)
{
	int nm = 1;
	LinkList p;
	p = head->next;
	printf("Լɪ��Ԫ������˳��\n");
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
//����Լɪ�򻷣���������ɱ�������
{
	LinkList p,q;
	int m = 0;
	p = head->next;
	printf("Լɪ��Ԫ����ɱ˳��\n");
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

//�������
LinkList Insert_List(LinkList head)
{
	LinkList p,m;
	int numb,nm = 1;
	printf("��������������ǰ�����Ԫ�أ�");
	scanf("%d",&numb);
	p = head->next;
	while(nm)
	{
		if(p->data == numb)
		{
			m = (LinkList)malloc(sizeof(Yoserf));
			printf("�����������Լɪ��Ҫ�����Ԫ�أ�\n");
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

//ɾ������
LinkList Delete_List(LinkList head)
{
	LinkList p,q;
	int numb,nm = 1;
	printf("��������ɾ������Ԫ�أ�\n");
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