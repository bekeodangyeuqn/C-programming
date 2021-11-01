#include<stdio.h>
#include<stdlib.h>

#define LENGTH 10

typedef struct Node{
	int num;
	struct Node* next;
}Node;

Node *makeNode(int num){
	Node *p = (Node*)malloc(sizeof(Node));
	p->num = num;
	p->next = NULL;
}

Node *top;
Node *tail;

void queInit(){
	top = NULL;
	tail = NULL;
}

int queEmpty(){
	return top == NULL;
}

void Enque(Node *p){
	if (tail == NULL){
		top = p;
		tail = p;
	} else {
		tail->next = p;
		tail = tail->next;
	}
}

Node *Deque(){
	if (queEmpty()) return ;
	Node *p = top;
	top = top->next;
	if (top == NULL) tail == NULL;
	return p;
}

void taoDanhSach(){
	int i;
	for (i=0;i<LENGTH;i++){
		int num;
		printf("Nhap gia tri Node %d: ",i); scanf("%d",&num);
		Node *p = makeNode(num);
		Enque(p);
		//free(p);
	}
}

Node *themVaRut(){
	int num;
	printf("Nhap gia tri Node can them: "); scanf("%d",&num);
	Node *p = Deque();
	Node *q = makeNode(num);
	Enque(q);
	return p;
}

int main(){
	char choice = 'y';
	queInit();
	taoDanhSach();
	while (choice == 'y'){
	Node* p = themVaRut();
	printf("So bi rut ra la: %d\n",p->num);
	printf("Tiep tuc(y/n): ");scanf(" %c",&choice);
	}
	return 0;
}
