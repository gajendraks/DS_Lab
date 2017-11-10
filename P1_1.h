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

