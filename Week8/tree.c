#include<stdio.h>
#include<stdlib.h>

int countLeaf = 0;

typedef struct Node{
    int id;
    struct Node *left;
    struct Node *right;
}Node;

Node *makeNode(int id){
    Node *p = (Node*)malloc(sizeof(Node));
    if (p == NULL){
    	printf ("Cap phat bo nho that bai!");
    	return NULL;
	} else{
		p->id = id;
    	p->left = NULL;
    	p->right = NULL;
    	return p;
	}
}

Node *find(Node *r,int id){
	if (r == NULL) return NULL;
	if (r->id == id) return r;
	Node *le = find(r->left,id);
	Node *ri = find(r->right,id);
	if (le!=NULL) return le;
	if (ri!=NULL) return ri;
	return NULL;
}

void addChildLeft(Node *r, int p, int id){
	if (r == NULL) return;
	if (find(r,id) != NULL) return;
	Node *q = find(r,p);
	if (q!= NULL && q->left == NULL){
		Node *newNode = makeNode(id);
		if (newNode == NULL){
			printf("Cap phat bo nho that bai!");
			return;
		}
		q->left = newNode;
	}
}

void addChildRight(Node *r, int p, int id){
	if (r == NULL) return;
	if (find(r,id) != NULL) return;
	Node *q = find(r,p);
	if (q!= NULL && q->right == NULL){
		Node *newNode = makeNode(id);
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
		printf("%d: ",r->id);
		if (r->left!=NULL && r->right == NULL){
			printf("%d ",r->left->id);
		} 
		if (r->left==NULL && r->right != NULL){
			printf("  %d",r->right->id);
		} 
		if (r->left!=NULL && r->right != NULL){
			printf("%d %d",r->left->id,r->right->id);
		}
		printf("\n");
		printTree(r->left);
		printTree(r->right);
	}
} 

int nb_nodes(Node *r){ 
	if(r == NULL) return 0;
	else return 1+nb_nodes(r->left)+ nb_nodes(r->right);
}

int isLeaf(Node *q){
	if (q == NULL) return 0;
	return q->left == NULL && q->right == NULL;
}

void nb_leaf(Node *r){
	if (r == NULL) return;
	if (isLeaf(r)) countLeaf++;
	else{
		nb_leaf(r->left);
		nb_leaf(r->right);
	}
}

int height(Node *r){
	if (r == NULL) return 0;
	int hmax = 0;
	int hle = height(r->left);
	int hri = height(r->right);
	if (hle >= hri) hmax = hle;
	else hmax = hri;
	return hmax + 1;
}


int main(){
	Node *root = makeNode(1);
	addChildLeft(root,1,2);
	addChildRight(root,1,3);
	addChildLeft(root,2,4);
	addChildRight(root,2,5);
	addChildLeft(root,3,6);
	addChildRight(root,3,10);
	addChildRight(root,10,12);
	addChildLeft(root,10,11);
	addChildLeft(root,11,13);
	addChildLeft(root,4,7);
	addChildRight(root,4,8);
	addChildRight(root,5,9);
	nb_leaf(root);
	printTree(root);
	printf("So Node: %d\n",nb_nodes(root));
	printf("So la: %d\n",countLeaf);
	printf("Do cao: %d\n",height(root));
	printf("So nut trong: %d",nb_nodes(root)-countLeaf);
	return 0;
}





