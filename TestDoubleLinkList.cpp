#include <stdio.h>
#include <stdlib.h>
#include "DoubleLiskList.h"
int main()
{
    int i;
    DuLinkList L = NULL;
    printMenu();
    printf("���������:");
    scanf("%d",&i);
    while( 0 != i)
    {
        switch(i)
        {
        case 1:initDlist(L);
            break;
        case 2:printDlist(L);
            break;
        case 3:printDlistFromLast(L);
            break;
        case 4:printf("������Ϊ:%d\n",lengthDlist(L));
            break;
        case 5:isEmptyOrNotDlist(L);
            break;
        case 6:clearTheDlist(L);
            break;
        case 7:insertElmToDlist(L);
            break;
        case 8:delElmFromDlist(L);
            break;
        case 9:delTheDlist(L);
            break;
        default:printf("�����������������!\n");
            break;
        }
        printMenu();
        printf("���������:");
        scanf("%d",&i);
		printf("\n");
    }
    if(0 == i)
    {
        printf("�����˳�....\n");
    }
    return 0;
}