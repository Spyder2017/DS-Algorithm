#include "stdio.h"
#include "stdlib.h"
#include "LinkList.h"

void main(){
	int e;
	LinkList L=creatLinkList(5);//��ʼ��һ������Ϊ5 ������
	PrintList(L);//��������ֵ
	printf("%d\n",LengthOfLinkList(L));
	
	GetElem_L(L,3,e);//�õ�L�����еĵ�i��Ԫ��
	printf("%d\n",e);
	printf("���ȥ���ظ���Ԫ��֮�������\n");
	L=deletRepeatElem(L);
	PrintList(L);//��������ֵ

}