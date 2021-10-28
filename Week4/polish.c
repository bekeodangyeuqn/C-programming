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

Node *top;

void initStack(){
	top = NULL;
}

int stackEmpty(){
	return top == NULL;
}

void push(int x){
	Node *p = makeNode(x);
	p->Next = top;
	top = p;
}

float pop(){
	if (stackEmpty()) return 0;
	Node *p;
	float x;
	x = top->c;
	p = top;
	top = top->Next;
	free(p);
	return x;
}

main(int argc, char *argv[]){ 
	char *s = argv[1]; int i, N = strlen(s);
	initStack();
	for (i = 0; i < N; i++){
	if (s[i] == '+'){
		float a = pop();
		float b = pop();
		push(b+a);
	} 
	if (s[i] == '*'){
		float a = pop();
		float b = pop();
		push(b*a);
	}
	if (s[i] == '-'){
		float a = pop();
		float b = pop();
		push(b-a);
	}  
	if (s[i] == '/'){
		float a = pop();
		float b = pop();
		push(b/a);
	} 
	//if ((s[i] >= '0') && (s[i] <= '9')) push('0');
	//if((s[i] >= '0') && (s[i] <= '9'))
	    //push(10*pop() + (s[i++]-'0'));
	if((s[i] >= '0') && (s[i] <= '9')){
		int y = s[i] - '0';
		push((y));
	}
	    //push(10*pop() + (s[i++]-'0'));
}
	printf("%.2f \n", pop());
	return 0;
}

