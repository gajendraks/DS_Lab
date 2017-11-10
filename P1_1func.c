#include "P1_1.h"

void insert_begi(struct node** p,int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	
	if(*p==NULL)
		*p=temp;
	else
	{
		temp->next=*p;
		*p=temp;
	}
}
void delete_num(struct node** p,int x)
{
	struct node *q;
	struct node *prev;
	prev=NULL;
	q=*p;
	
	while(q!=NULL && q->data!=x)
	{
		prev=q;
		q=q->next;
	}
	if(q==NULL)
		printf("no value");
	else if (prev==NULL)
		*p=q->next;
	else
		prev->next=q->next;
}

void display(struct node *p)
{
	while(p!=NULL)
	{
		printf("%d->",p->data);
	}
}
	
