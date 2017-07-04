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
	int x, i;//x为循环输入的每个节点的data值，i为循环变量
	LinkList p,q,head;
	head=(LinkList)malloc(sizeof(m));//为结点head分配一段空间即挖坑
	q=head;
	printf("请输入结点元素的值\r\n");
	for(i=0; i<n; i++){
		scanf("%d", &x);
		p=(LNode*)malloc(sizeof(m));//挖坑
		p->data=x;//种萝卜
		q->next=p;
		q=p;
	}
	q->next=NULL;
	return head;//返回头结点
}
//打印链表的值
void PrintList(LinkList head){
	LinkList pt;
	pt=head->next;
	printf("链表输出为:\n");
	while(pt!=NULL){
		printf("%d\r\n", pt->data);
		pt=pt->next;
	}
}

//当第i个元素存在时其值赋给e并返回OK，否则返回ERROR
Status GetElem_L(LinkList L,int i,ElemType &e){
	//L为带头节点的单链表的头指针
	LinkList p;
	int j=1;
	p=L->next;
	while(p&&j<i){
		p=p->next;
		++j;
	}
	if(!p||j>i){//第i个元素不存在
		return ERROR;
	}
	e=p->data;//取第i个元素
	return OK;
}
//删除链表中的重复元素
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
//计算链表的长度
int LengthOfLinkList(LinkList head){
	int length=0;
	LinkList p=head->next;
	while(p){
		length++;
		p=p->next;
	}
	return length;
}
/*结点的销毁*/
void destroyLinkList(LinkList head){
	while (head){
		LinkList temp = head;
		head = head->next;
		free(temp);
	}
}