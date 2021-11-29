#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char c;
    struct Node *left;
    struct Node *right;
}Node;

Node *makeNode(char c){
    Node *p = (Node*)malloc(sizeof(Node));
    if (p == NULL){
    	printf ("Cap phat bo nho that bai!");
    	return NULL;
	} else{
		p->c = c;
    	p->left = NULL;
    	p->right = NULL;
    	return p;
	}
}

Node *find(Node *r,char c){
	if (r == NULL) return NULL;
	if (r->c == c) return r;
	Node *le = find(r->left,c);
	Node *ri = find(r->right,c);
	if (le!=NULL) return le;
	if (ri!=NULL) return ri;
	return NULL;
}

void addChildLeft(Node *r, int p, char c){
	if (r == NULL) return;
	if (find(r,c) != NULL) return;
	Node *q = find(r,p);
	if (q!= NULL && q->left == NULL){
		Node *newNode = makeNode(c);
		if (newNode == NULL){
			printf("Cap phat bo nho that bai!");
			return;
		}
		q->left = newNode;
	}
}

void addChildRight(Node *r, int p, char c){
	if (r == NULL) return;
	if (find(r,c) != NULL) return;
	Node *q = find(r,p);
	if (q!= NULL && q->right == NULL){
		Node *newNode = makeNode(c);
		if (newNode == NULL){
			printf("Cap phat bo nho that bai!");
			return;
		}
		q->right = newNode;
	}
}

void printTree(Node *r){
	if (r == NULL) return;
	else {
		printf("%c: ",r->c);
		if (r->left!=NULL && r->right == NULL){
			printf("%c ",r->left->c);
		} 
		if (r->left==NULL && r->right != NULL){
			printf("  %c",r->right->c);
		} 
		if (r->left!=NULL && r->right != NULL){
			printf("%c %c",r->left->c,r->right->c);
		}
		printf("\n");
		printTree(r->left);
		printTree(r->right);
	}
} 

int main(){
	Node *root = makeNode('+');
	addChildLeft(root,'+','!');
	addChildRight(root,'+','/');
	addChildLeft(root,'!','a');
	addChildLeft(root,'/','-');
	addChildRight(root,'/','d');
	addChildLeft(root,'-','b');
	addChildRight(root,'-','c');
	printTree(root);
	return 0;
}
