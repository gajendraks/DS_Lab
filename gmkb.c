#include<stdio.h>
#include<stdlib.h>




struct node
{
    int data;
    struct node* next;
};

void insert_tail(struct node** , int );
void insert_head(struct node** , int );
void delete_head(struct node** );
void delete_tail(struct node** );
void delete_node(struct node**, int);
void reverse(struct node **p);
void display(struct node *);

int main()
{
    struct node* first;
    int ch,x,y;
    first=NULL;

    while(1)
    {
      display(first);
      printf("\n1.Insert Head\n");
      printf("2.Insert Tail\n");
      printf("3.Delete first\n");
      printf("4.Delete last\n");
      printf("5.Display\n");
      printf("6.Delete a node\n");
      printf("7.reverse\n");
      printf("8.exit");
      scanf("%d",&ch);
      switch(ch)
      { 
        case 1: printf("enter no.:");
            scanf("%d",&x);
            insert_head(&first,x); break;
        case 2: printf("enter no.:");
            scanf("%d",&x);
            insert_tail(&first,x); break;
        case 3: delete_head(&first);break;
        case 4: delete_tail(&first); break;
        case 5: display(first);break;
        case 6: printf("node to be deleted:");
            scanf("%d",&y);
            delete_node(&first,y);break;
        case 7: reverse(&first);
        case 8: exit(0);
      }
    }
}

            
void insert_head(struct node **p, int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if (*p==NULL) *p=temp;
    else 
    {
        temp->next=*p;
        *p=temp;
    }
}
 

void insert_tail(struct node** p, int x)
{    
    struct node* temp;
        struct node* q;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    //empty list, first node being inserted
    if(*p==NULL)
      *p=temp;
    else
    {
    //list present, go to the end of the list
    q=*p;//copy the address of first node into q
    while(q->next!=NULL)
        q=q->next;
    q->next=temp;
    }
}


void delete_head(struct node** p)
{
    struct node *q;
    q=*p;
    *p=(*p)->next;// or *p=q->next;
    free(q);    
}

void delete_tail(struct node** p) // delete_last(&first)
{
    struct node *q,*prev;
    q=*p;//copy the address of the first node
    prev=NULL;//keeps track of the prevous node
    
    //go to last node
    while(q->next!=NULL)
    { 
      prev=q;
      q=q->next;
    }
    if(prev==NULL)//only one node in the list
     *p=NULL;//make first as null
    else
     prev->next=NULL;//break link between prev and last node
    free(q);
}

void display(struct node *p)
{    if(p!=NULL)
    {
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    }
    else
        printf("empty list\n");
}

void delete_node(struct node** p , int y)
{
    struct node* q, *prev;
    q=*p;//copy the address of the first node
    prev=NULL;//tracks previous node

    //move forwared util you find the node to be deleted
//or you go beyond the end of the lists
    while( (q!=NULL) && (q->data!=y))
    {
        prev=q;
        q=q->next;
    }
    if(q==NULL)
        printf("not found");
    else if( prev==NULL)
        *p=q->next;
        
        
    else 
        prev->next=q->next;

    free(q);
}

void reverse(struct node **p)
{
    struct node *cur,*temp,*prev;
    prev=NULL;
    cur=*p;//copy address of the first node
    while(cur!=NULL)
    {
      temp=cur->next;
      cur->next=prev;
      prev=cur;
      cur=temp;
    }
    *p=prev;
}
