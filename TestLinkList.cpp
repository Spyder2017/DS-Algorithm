#include "stdio.h"
#include "stdlib.h"
#include "LinkList.h"

void main(){
	int e;
	LinkList L=creatLinkList(5);//初始化一个长度为5 的链表
	PrintList(L);//输出链表的值
	printf("%d\n",LengthOfLinkList(L));
	
	GetElem_L(L,3,e);//得到L链表中的第i个元素
	printf("%d\n",e);
	printf("输出去除重复的元素之后的链表\n");
	L=deletRepeatElem(L);
	PrintList(L);//输出链表的值

}