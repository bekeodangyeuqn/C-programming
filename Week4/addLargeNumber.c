#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
	int c;
	struct Node *Next;
}Node;


Node *makeNode(char x){
	Node *p = (Node*)malloc(sizeof(Node));
	p->c = x; p->Next = NULL;
	return p;
}

Node *top1;
Node *top2;
Node *topResult;

void initStack1(){
	top1 = NULL;
}

void initStack2(){
	top2 = NULL;
}

void initStackResult(){
	topResult = NULL;
}

int stackEmpty1(){
	return top1 == NULL;
}

int stackEmpty2(){
	return top2 == NULL;
}

int stackEmptyResult(){
	return topResult == NULL;
}



void push1(int x){
	Node *p = makeNode(x);
	p->Next = top1;
	top1 = p;
}

int pop1(){
	if (stackEmpty1()) return 0;
	Node *p;
	int x;
	x = top1->c;
	p = top1;
	top1 = top1->Next;
	free(p);
	return x;
}

void push2(int x){
	Node *p = makeNode(x);
	p->Next = top2;
	top2 = p;
}

int pop2(){
	if (stackEmpty2()) return 0;
	Node *p;
	int x;
	x = top2->c;
	p = top2;
	top2 = top2->Next;
	free(p);
	return x;
}

void pushResult(int x){
	Node *p = makeNode(x);
	p->Next = topResult;
	topResult = p;
}

int popResult(){
	if (stackEmptyResult()) return 0;
	Node *p;
	int x;
	x = topResult->c;
	p = topResult;
	topResult = topResult->Next;
	free(p);
	return x;
}

main(int argc, char *argv[]){
	char *s1 = argv[1], *s2 = argv[2];
	int i, N1 = strlen(s1), N2 = strlen(s2);
	for (i=0;i<N1;i++){
		push1(s1[i] - '0');
	}
	
	for (i=0;i<N2;i++){
		push2(s2[i] - '0');
	}
	int carryOn = 0;
	
	while(!stackEmpty1() || !stackEmpty2()){
		
			int a = pop1();
			int b = pop2();
			int t = a+b+ carryOn;
			if (t>=10){
				t = t-10;
				pushResult(t);
				carryOn = 1;
		} 	else {
				pushResult(t);
				carryOn = 0;
		}
	
}

    if (carryOn == 1){
    		pushResult(1);
		}

	while (!stackEmptyResult()){
		printf("%d",popResult());
	}
	return 0;
}
