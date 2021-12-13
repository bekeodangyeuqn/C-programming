#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Node1{
	char c;
	struct Node1 *Next;
}Node1;

typedef struct Node2{
	float x;
	struct Node2 *Next;
}Node2;

Node1 *makeNode1(char x){
	Node1 *p = (Node1*)malloc(sizeof(Node1));
	p->c = x; p->Next = NULL;
	return p;
}

Node2 *makeNode2(float x){
	Node2 *p = (Node2*)malloc(sizeof(Node2));
	p->x = x; p->Next = NULL;
	return p;
}

Node1 *top1;
Node2 *top2;

void initStack1(){
	top1 = NULL;
}

void initStack2(){
	top2 = NULL;
}

int stackEmpty1(){
	return top1 == NULL;
}

int stackEmpty2(){
	return top2 == NULL;
}

void push1(char x){
	Node1 *p = makeNode1(x);
	p->Next = top1;
	top1 = p;
}

char pop1(){
	if (stackEmpty1()) return '\0';
	char x;
	x = top1->c;
	Node1 *tmp = top1;
	top1 = tmp->Next;
	free(tmp);
	return x;
}

void push2(float x){
	Node2 *p = makeNode2(x);
	p->Next = top2;
	top2 = p;
}

float pop2(){
	if (stackEmpty2()) return 0;
	Node2 *p;
	float x;
	x = top2->x;
	p = top2;
	top2 = top2->Next;
	free(p);
	return x;
}

int priority(char x){
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}


main(){
	initStack1();
	char a[100], b[100]; 
	printf("Enter the expression: ");scanf("%s",a);
	int i,j=0, N = strlen(a);
	for (i = 0; i < N; i++){
		if (isalnum(a[i])){
			b[j] = a[i];
			printf("%c ",b[j]);
			j++;
		} else 
			if (top1 == NULL) push1(a[i]);
			else {
				while(priority(top1->c) >= priority(a[i])){
					b[j] = pop1();
					printf("%c ",b[j]);
					j++;
					if (top1 == NULL) break;
				}
                push1(a[i]);
			}
	}
		while(top1 != NULL){
			b[j] = pop1();
        	printf("%c ",b[j]);
        	j++;
    	}
	initStack2();
	int M = strlen(b);
	for (i = 0; i < M; i++){
		if (b[i] == '+'){
			float c = pop2();
			float d = pop2();
			push2(d+c);
		} else
		if (b[i] == '*'){
			float c = pop2();
			float d = pop2();
			push2(d*c);
		} else
		if (b[i] == '-'){
			float c = pop2();
			float d = pop2();
			push2(d-c);
		}  else
		if (b[i] == '/'){
			float c = pop2();
			float d = pop2();
			push2(d/c);
		} else
		if((b[i] >= '0') && (b[i] <= '9')){
			int y = b[i] - '0';
			push2((y));
		}
	}
	printf("\nKet qua: \n%.2f \n", pop2());
	return 0;
}

