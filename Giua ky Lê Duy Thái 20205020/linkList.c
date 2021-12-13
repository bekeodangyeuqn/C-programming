#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _address{
	char name[50];
	char tel[11];
	char mail[100];
}Address;

typedef struct _node{
	element data;
	struct _node *next;
}node;

typedef struct _list{
	node *top;
}list;

node *createNode(daTa data){
	node *p = (node*)malloc(sizeof(node));
	if (p==NULL) {
		printf("Cap phat that bai!");
		exit(-1);
	} else {
		p->data = data;
		p->next = NULL;
	}
	return p;
}

list *createList(){
	list *l = (list*)malloc(sizeof(list));
	if (l== NULL){
		printf("Cap phat that bai!");
	} else{
		l->top = NULL;
	}
	return l;
}

int listEmpty(list *l){
	if (l==NULL) return 1;
	if (l->top == NULL) return 1;
	else return 0;
}

void destroyList(list *l){
	node *p;
	for (p = l->top; p!=NULL; p = p->next){
		free(p);
	}
	free(l);
}


