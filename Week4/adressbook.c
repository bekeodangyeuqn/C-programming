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

void initStack(){
	top = NULL;
}

int stackEmpty(){
	return top == NULL;
}

void push(Address addr){
	Node *p = makeNode(addr);
	p->next = top;
	top = p;
}

Address pop(){
	if (stackEmpty()) return ;
	Node *p;
	Address addr;
	addr = top->addr;
	p = top;
	top = top->next;
	free(p);
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
		push(addr);
	}
}

void xuat(FILE *fout){
	while (!stackEmpty()){
		Address addr = pop();
		fprintf(fout,"%s%s%s\n",addr.name,addr.tel,addr.mail);
	}
}



int main(){
	FILE *fin;
	FILE *fout;
	//Address addr;
	initStack();
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
