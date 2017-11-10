#include "P1_1.h"
#include "P1_1func.c"

int main()
{	
	int ch;
	printf("1. Insert at beginning\n 2. Delete the specific element from the list\n3.Display elements");
	scanf("%d",&ch);
	
	struct node *list;
	
	switch(ch)
	{
		int x;
		case 1: printf("enter the no to add at the beginning\n");
				scanf("%d",&x);
				insert_begi(&list,x);
				break;
		case 2: printf("enter no to delete\n");
				scanf("%d",&x);
				delete_num(&list,x);
				break;
		case 3: display(list);
				break;
	}
}
