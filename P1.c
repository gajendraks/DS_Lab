#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void insert_begi(struct node**,int );
void delete_num(struct node**,int );
void display(struct node* );



int main()
{	

	struct node *list;
	list=NULL;
	int ch,x,y;
	while(1)
	{
	printf("\n1.Insert Head\n");
	printf("2.Delete a node\n");
	printf("3.Display\n");
	printf("4.exit");//printf("1. Insert at beginning\n 2. Delete the specific element from the list\n3.Display elements");
	scanf("%d",&ch);
	
	struct node *list;
	
	
	switch(ch)
	{
		
		case 1: printf("enter the no to add at the beginning\n");
				scanf("%d",&x);
				insert_begi(&list,x);
				break;
		case 2: printf("enter no to delete\n");
				scanf("%d",&y);
				delete_num(&list,y);
				break;
		case 3: display(list);
				break;
		case 4: exit(0);
				
	}
	
	}
}




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
	free(q);
}

void display(struct node *p)
{
	if(p!=NULL)
	{
		while(p!=NULL)
		{
			printf("%d->",p->data);
			p=p->next;
		}
	}
	else
		printf("empty");
}
	
