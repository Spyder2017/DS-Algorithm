#define TRUE 1;
#define FALSE 0;
#define OK 1;
#define ERROR 0;
#define INFEASIBLE -1;
#define OVERFLOW -2;

typedef int Status;
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next; 
}LNode,*LinkList;

int m=sizeof(LNode);

LinkList creatLinkList(int n){
	int x, i;//xΪѭ�������ÿ���ڵ��dataֵ��iΪѭ������
	LinkList p,q,head;
	head=(LinkList)malloc(sizeof(m));//Ϊ���head����һ�οռ伴�ڿ�
	q=head;
	printf("��������Ԫ�ص�ֵ\r\n");
	for(i=0; i<n; i++){
		scanf("%d", &x);
		p=(LNode*)malloc(sizeof(m));//�ڿ�
		p->data=x;//���ܲ�
		q->next=p;
		q=p;
	}
	q->next=NULL;
	return head;//����ͷ���
}
//��ӡ�����ֵ
void PrintList(LinkList head){
	LinkList pt;
	pt=head->next;
	printf("�������Ϊ:\n");
	while(pt!=NULL){
		printf("%d\r\n", pt->data);
		pt=pt->next;
	}
}

//����i��Ԫ�ش���ʱ��ֵ����e������OK�����򷵻�ERROR
Status GetElem_L(LinkList L,int i,ElemType &e){
	//LΪ��ͷ�ڵ�ĵ������ͷָ��
	LinkList p;
	int j=1;
	p=L->next;
	while(p&&j<i){
		p=p->next;
		++j;
	}
	if(!p||j>i){//��i��Ԫ�ز�����
		return ERROR;
	}
	e=p->data;//ȡ��i��Ԫ��
	return OK;
}
//ɾ�������е��ظ�Ԫ��
LinkList deletRepeatElem(LinkList head){
	LinkList p, q, r;	
	p=head->next;
	while(p!=NULL){
		q=p;
		while(q->next!=NULL){
			r=q->next;
			if(r->data==p->data){
				if(r->next!=NULL){
					q->next=r->next;
					free(r);
				}else{
					q->next=NULL;
					free(r);
				}
			}else{
				q=r;
			}
		}
		p=p->next;
	}
	return head;
}
//��������ĳ���
int LengthOfLinkList(LinkList head){
	int length=0;
	LinkList p=head->next;
	while(p){
		length++;
		p=p->next;
	}
	return length;
}
/*��������*/
void destroyLinkList(LinkList head){
	while (head){
		LinkList temp = head;
		head = head->next;
		free(temp);
	}
}