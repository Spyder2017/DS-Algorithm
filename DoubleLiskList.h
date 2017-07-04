//打印菜单选项选项
void printMenu(){
    printf("\n1.初始化双向链表\n2.打印双向链表\n3.逆序打印双向链表\n");
    printf("4.求链表长度\n5.判断链表是否为空\n6.清空链表\n");
    printf("7.插入元素\n8.删除元素\n9.删除链表\n0.退出\n");
}
//双向链表结构体的定义
typedef struct DuLnode{
    int data;              //数据
    struct DuLnode *prior; //前驱
    struct DuLnode *next;  //后继
}DuLnode,*DuLinkList;

//初始化双向链表
void initDlist(DuLinkList &L){
    char x;          //定义成char型是用于输入'q'时可以退出，其实定义成int也能退出
    DuLinkList p,q;

    L = (DuLinkList)malloc(sizeof(DuLnode));
    L->next = NULL;
    L->prior = NULL;        //构造头结点
    p = L;
    
    printf("输入双向链表的元素，每输入一个元素后按回车，输入q表示结束.\n");
    fflush(stdin);   //清空输入缓冲区
    x=getchar();
    while( x != 'q'){
        q = (DuLinkList)malloc(sizeof(DuLnode));
        q->data = x-48;  //得到的是输入字符的ASCII码，减去30H就变成想要的数字，十六进制30h即为十进制48
        q->next = NULL;
        q->prior = p;
        p->next = q;
        p = q;
        fflush(stdin);
        x=getchar();
    }
    if( x == 'q' ){
        printf("双向链表构造完毕!\n");
    }

}

//打印双向链表
void printDlist(DuLinkList &L){
    DuLinkList p;
    
    if(L == NULL){
        printf("链表不存在，请先初始化!\n");
    }
    else if(L->next == NULL){
        p = L->next;
        printf("链表为空!\n");
    }
    else{
        p = L->next;
        while(p){
            printf("%d ",p->data);
            p = p->next;
        }
    }
}

//逆序打印双向链表
void printDlistFromLast(DuLinkList &L){
    DuLinkList p;
    
    if(L == NULL){
        printf("链表不存在，请先初始化!\n");
    }
    else if( L->next == NULL ){
        p = L->next;
        printf("链表为空!\n");
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

//求链表长度
int lengthDlist(DuLinkList &L){
    int i = 0;

    if(L == NULL){
        printf("链表不存在，请先初始化!\n");
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

//判断链表是否为空
void isEmptyOrNotDlist(DuLinkList &L){
    if(L == NULL){
        printf("链表不存在，请先初始化!\n");
    }
    else if( L->next == NULL ){
        printf("链表为空!\n");
    }
    else{
        printf("链表非空!\n");
    }
}

//把双向链表置空
void clearTheDlist(DuLinkList &L){
    if(L==NULL){
        printf("链表不存在，请先初始化!\n");
    }
    else{
        DuLinkList p,q;
        p = q = L->next;   //是p、q指向第一个元素
        L->next = NULL;

        while(p){         //逐个释放元素所占内存        
            p = p->next;
            free(q);
            q = p;
        }
    }
}

//删除双向链表
void delTheDlist(DuLinkList &L){
    clearTheDlist(L);
    free(L);
    L = NULL;
}

//在双向链表中第i个位置后面插入元素m
void insertElmToDlist(DuLinkList &L){
    int i,m;
    printf("输入插入的元素:\n");
    scanf("%d",&m);
    printf("输入插入的位置:\n");
    scanf("%d",&i);
    DuLinkList p,q;
    p = L;
    int j = 0;
    
    if(L == NULL){
        printf("链表不存在，请先初始化!\n");
    }
    else if(L->next == NULL){
        printf("链表为空，请初始化后再进行插入数据操作!\n");
    }
    else if( i<1 || i>lengthDlist(L)+1 ){
        printf("插入位置错误!\n");
    }
    else{
        while( j<i ){
            p = p->next;
            j++;
        }
        
        if( j == lengthDlist(L) ){      //如果在最后一个元素后面插入m        
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

//删除双向链表中的第i个元素
void delElmFromDlist(DuLinkList &L){
    int i;
    printf("输入要删除的位置:");
    scanf("%d",&i);
    int j = 0;
    DuLinkList p = L;
    
    if(L == NULL){
        printf("链表不存在，请先初始化!\n");
    }
    else if( i<1 || i>lengthDlist(L) ){
        printf("删除的位置不存在!\n");
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