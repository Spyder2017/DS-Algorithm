//��ӡ�˵�ѡ��ѡ��
void printMenu(){
    printf("\n1.��ʼ��˫������\n2.��ӡ˫������\n3.�����ӡ˫������\n");
    printf("4.��������\n5.�ж������Ƿ�Ϊ��\n6.�������\n");
    printf("7.����Ԫ��\n8.ɾ��Ԫ��\n9.ɾ������\n0.�˳�\n");
}
//˫������ṹ��Ķ���
typedef struct DuLnode{
    int data;              //����
    struct DuLnode *prior; //ǰ��
    struct DuLnode *next;  //���
}DuLnode,*DuLinkList;

//��ʼ��˫������
void initDlist(DuLinkList &L){
    char x;          //�����char������������'q'ʱ�����˳�����ʵ�����intҲ���˳�
    DuLinkList p,q;

    L = (DuLinkList)malloc(sizeof(DuLnode));
    L->next = NULL;
    L->prior = NULL;        //����ͷ���
    p = L;
    
    printf("����˫�������Ԫ�أ�ÿ����һ��Ԫ�غ󰴻س�������q��ʾ����.\n");
    fflush(stdin);   //������뻺����
    x=getchar();
    while( x != 'q'){
        q = (DuLinkList)malloc(sizeof(DuLnode));
        q->data = x-48;  //�õ����������ַ���ASCII�룬��ȥ30H�ͱ����Ҫ�����֣�ʮ������30h��Ϊʮ����48
        q->next = NULL;
        q->prior = p;
        p->next = q;
        p = q;
        fflush(stdin);
        x=getchar();
    }
    if( x == 'q' ){
        printf("˫�����������!\n");
    }

}

//��ӡ˫������
void printDlist(DuLinkList &L){
    DuLinkList p;
    
    if(L == NULL){
        printf("�������ڣ����ȳ�ʼ��!\n");
    }
    else if(L->next == NULL){
        p = L->next;
        printf("����Ϊ��!\n");
    }
    else{
        p = L->next;
        while(p){
            printf("%d ",p->data);
            p = p->next;
        }
    }
}

//�����ӡ˫������
void printDlistFromLast(DuLinkList &L){
    DuLinkList p;
    
    if(L == NULL){
        printf("�������ڣ����ȳ�ʼ��!\n");
    }
    else if( L->next == NULL ){
        p = L->next;
        printf("����Ϊ��!\n");
    }
    else{
        p = L->next;
        while(p->next){
            p = p->next;
        }

        while(p->prior){
            printf("%d ",p->data);
            p = p->prior;
        }
    }
}

//��������
int lengthDlist(DuLinkList &L){
    int i = 0;

    if(L == NULL){
        printf("�������ڣ����ȳ�ʼ��!\n");
    }
    else{
        DuLinkList p = L->next;
        while(p){
			++i;
            p = p->next;
        }
    }

    return i;
}

//�ж������Ƿ�Ϊ��
void isEmptyOrNotDlist(DuLinkList &L){
    if(L == NULL){
        printf("�������ڣ����ȳ�ʼ��!\n");
    }
    else if( L->next == NULL ){
        printf("����Ϊ��!\n");
    }
    else{
        printf("����ǿ�!\n");
    }
}

//��˫�������ÿ�
void clearTheDlist(DuLinkList &L){
    if(L==NULL){
        printf("�������ڣ����ȳ�ʼ��!\n");
    }
    else{
        DuLinkList p,q;
        p = q = L->next;   //��p��qָ���һ��Ԫ��
        L->next = NULL;

        while(p){         //����ͷ�Ԫ����ռ�ڴ�        
            p = p->next;
            free(q);
            q = p;
        }
    }
}

//ɾ��˫������
void delTheDlist(DuLinkList &L){
    clearTheDlist(L);
    free(L);
    L = NULL;
}

//��˫�������е�i��λ�ú������Ԫ��m
void insertElmToDlist(DuLinkList &L){
    int i,m;
    printf("��������Ԫ��:\n");
    scanf("%d",&m);
    printf("��������λ��:\n");
    scanf("%d",&i);
    DuLinkList p,q;
    p = L;
    int j = 0;
    
    if(L == NULL){
        printf("�������ڣ����ȳ�ʼ��!\n");
    }
    else if(L->next == NULL){
        printf("����Ϊ�գ����ʼ�����ٽ��в������ݲ���!\n");
    }
    else if( i<1 || i>lengthDlist(L)+1 ){
        printf("����λ�ô���!\n");
    }
    else{
        while( j<i ){
            p = p->next;
            j++;
        }
        
        if( j == lengthDlist(L) ){      //��������һ��Ԫ�غ������m        
            q = (DuLinkList)malloc(sizeof(DuLnode));
            q->data = m;
            q->next = NULL;
            q->prior = p;
            p->next = q;
        }
        else{
            q = (DuLinkList)malloc(sizeof(DuLnode));
            q->data = m;
            q->next = p->next;
            p->next->prior = q;
            p->next = q;
            q->prior = p;
        }
    }
}

//ɾ��˫�������еĵ�i��Ԫ��
void delElmFromDlist(DuLinkList &L){
    int i;
    printf("����Ҫɾ����λ��:");
    scanf("%d",&i);
    int j = 0;
    DuLinkList p = L;
    
    if(L == NULL){
        printf("�������ڣ����ȳ�ʼ��!\n");
    }
    else if( i<1 || i>lengthDlist(L) ){
        printf("ɾ����λ�ò�����!\n");
    }
    else{
        while( j<i ){
            p = p->next;
            j++;
        }

        if( j == lengthDlist(L) ){
            p->prior->next = NULL;
            free(p);
        }
        else{
            p->prior->next = p->next;
            p->next->prior = p->prior;
            free(p);
        }
    }
}