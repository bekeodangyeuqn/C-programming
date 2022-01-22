#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	char data[10];
	int count;
	struct node *left;
	struct node *right;
}NODE;

typedef NODE* TREE;

void initTree(TREE *t){
	t = NULL;
}

void addNodetoTree(TREE *t, char data[10]){
	if (*t == NULL){
		NODE *p = (NODE*)malloc(sizeof(NODE));
		strcpy(p->data,data);
		//p->data = data;
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
		*t = p;
	}
	else{
		if (strcmp((*t)->data,data) >0){
			addNodetoTree(&(*t)->left,data);
		} else if (strcmp((*t)->data,data) < 0){
			addNodetoTree(&(*t)->right,data);
		}
	}
}

NODE *searchDataInTree(TREE t,char data[10]){
	if (t == NULL || (strcmp(t->data,data) == 0)) return t;
	if (strcmp(t->data,data) >0)
		return searchDataInTree(t->left,data);
	return searchDataInTree(t->right,data);
}

void readFile(FILE *fp, TREE *t){
	fp = fopen("word.txt","r");
	if (fp == NULL){
		printf("Nhap file khong thanh cong");
	}
	while (!feof(fp)){
		char word[10];
		fscanf(fp,"%s ",word);
		NODE *p = searchDataInTree(*t,word);
		if (p == NULL)
			addNodetoTree(t,word);
		else {
			p = searchDataInTree(*t,word);
			p->count++;
		}
		//printf("%s ",word);
	}
	fclose(fp);
}

void printData(TREE t){
	if (t!=NULL){
		printData(t->left);
		printf("%s %d\n",t->data,t->count);
		printData(t->right);
	}
}

void searchWord(TREE t){
	char word[10];
	printf("Nhap tu can tim: "); fflush(stdin); gets(word);
	NODE *p = searchDataInTree(t,word);
	if (p==NULL){
		printf("Khong tim thay tu %s\n",word);
		//exit(-1);
	}
	else {
		p = searchDataInTree(t,word);
		printf("Tu: %s\nSo luong: %d\n",p->data,p->count);
	}
}

int main(){
	TREE t;
	initTree(&t);
	FILE *fin;
	readFile(fin,&t);
	searchWord(t);
	printf("\n====WORD LIST====\n");
	printData(t);
	
	
	return 0;
}

