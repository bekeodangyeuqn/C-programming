#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Address{
	char name[50];
	char tel[30];
	char mail[100];
}Address;

typedef struct Node{
	Address addr;
	struct Node *next;
}Node;

Node *makeNode(Address addr){
	Node *p = (Node*)malloc(sizeof(Node));
	p->addr = addr;
	p->next = NULL;
	return p;
}

Node *top;
Node *tail;

void initQue(){
	top = NULL;
	tail = NULL;
}

int queEmpty(){
	return top == NULL;
}

void Enque(Address addr){
	Node *p = makeNode(addr);
	if (tail == NULL){
		top = p;
		tail = p;
	} else {
		tail->next = p;
		tail = tail->next;
	}
}

Address Deque(){
	if (queEmpty()) return ;
	Node *p;
	Address addr;
	addr = top->addr;
	p = top;
	top = top->next;
	free(p);
	if (top == NULL) tail == NULL;
	return addr;
}

void doc1DC(FILE *fin, Address *addr){
	fgets(addr->name,50,fin);
	fgets(addr->tel,50,fin);
	fgets(addr->mail,50,fin);
}

void docThongTinDC(FILE *fin){
	while(!feof(fin)){
		Address addr;
		doc1DC(fin,&addr);
		Enque(addr);
	}
}

void xuat(FILE *fout){
	while (!queEmpty()){
		Address addr = Deque();
		fprintf(fout,"%s%s%s\n",addr.name,addr.tel,addr.mail);
	}
}



int main(){
	FILE *fin;
	FILE *fout;
	//Address addr;
	initQue();
	char fileNameIn[100];
	char fileNameOut[100];
	printf("Nhap ten file de doc du lieu: "); scanf("%s",fileNameIn);
	printf("Nhap ten file de xuat du lieu: "); scanf("%s",fileNameOut);
	fin = fopen(fileNameIn,"r");
	fout = fopen(fileNameOut,"w+");
	docThongTinDC(fin);
	xuat(fout);
	fclose(fin);
	fclose(fout);
	return 0;
}
