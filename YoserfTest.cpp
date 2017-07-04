#include <stdio.h>
#include <stdlib.h>
#include "YoserfTest.h"

int main()
{
	LinkList head;
	head = Create_List();
	print(head);
	head = Insert_List(head);
	print(head);
	head = Delete_List(head);
	print(head);
	Calcul_List(head);
	return 0;
}