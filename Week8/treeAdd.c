#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Address{
	char name[50];
	char tel[11];
	char mail[100];
}Address;

typedef struct NodeTree{
	Address data;
	struct NodeTree *left;
	struct NodeTree *right;
}NodeTree;

typedef NodeTree* TreeType;

NodeTree *makeNode(Address data){
	NodeTree *newNode = (NodeTree*)malloc(sizeof(NodeTree));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void insertBST(Address *data,TreeType *root){
	if (*root == NULL){
		*root = (NodeTree*)malloc(sizeof(NodeTree));
		(*root)->data = *data;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if (strcmp((*data).mail,(*root)->data.mail)>0) insertBST(data,&(*root)->right);
	else if (strcmp((*data).mail,(*root)->data.mail)<0) insertBST(data,&(*root)->left);
}

void prettyprint(NodeTree *root,char *prefix){
	char *prefixend=prefix+strlen(prefix);
	if (root!=NULL){ 
		printf("%04s",root->data.mail);
		if (root->left!=NULL) if (root->right==NULL){ 
		printf("\304");strcat(prefix,"	");
 	}
	else {
	printf("\302");strcat(prefix,"\263	");
	}
 
	prettyprint(root->left,prefix);
	*prefixend='\0';
	if (root->right!=NULL) if (root->left!=NULL){
	printf("\n%s",prefix);printf("\300");
	} else printf("\304"); 
	strcat(prefix,"	"); 
	prettyprint(root->right,prefix);
}
}

void printTree(NodeTree *r){
	if (r == NULL) return;
	else {
		printf("%s: ",r->data.mail);
		if (r->left!=NULL && r->right == NULL){
			printf("%s ",r->left->data.mail);
		} 
		if (r->left==NULL && r->right != NULL){
			printf("  %s",r->right->data.mail);
		} 
		if (r->left!=NULL && r->right != NULL){
			printf("%s %s",r->left->data.mail,r->right->data.mail);
		}
		printf("\n");
		printTree(r->left);
		printTree(r->right);
	}
} 

NodeTree *Search(char* email,NodeTree *root){
	if (root == NULL) return NULL; // not found
	else if (strcmp((root->data).mail, email) == 0)
		return root;
	else if (strcmp((root->data).mail, email) < 0)
//continue searching in the right sub tree
		return Search(email,root->right);
	else {
// continue searching in the left sub tree
		return Search(email,root->left);
}
}


void chuanhoaxau(char *str){	
	int i;
	for(i = strlen(str)-1; i>=0; i--)
	{
		if(str[i]=='\n') str[i]='\0';
		if(str[i]=='\r') str[i]='\0';
	}	
		
}

void readFile(char *charname, Address add[],int count){
	FILE *fp;
	fp = fopen(charname,"r") ;
	if (fp == NULL){
		printf("Loi doc file");
	} else {
		int i=0;
		for (i=0;i<count;i++){
			fgets(add[i].name,51,fp);chuanhoaxau(add[i].name);
			fgets(add[i].tel,12,fp);chuanhoaxau(add[i].tel);
			fgets(add[i].mail,101,fp);chuanhoaxau(add[i].mail);
		}
	}
	fclose(fp);
}

/*void sort(Address add[], int count){
	int i,j;
	for (i=0;i<count;i++){
		for (j=count-1;j>i;j--){
			if (strcmp(add[j-1].name,add[j].name) > 0){
				Address tmp;
				tmp = add[j];
				add[j] = add[j-1];
				add[j-1] = tmp;
			}
		}
	}
}*/

int main(){
	//FILE *fp;
	Address add[100];
	TreeType root = NULL;
	int count,i;
	//int count,Hi,Lo;
	char filename[100], mail[100];
	printf("Nhap so luong: ");scanf("%d",&count);
	printf("Nhap ten file: ");fflush(stdin);gets(filename);
	printf("Nhap mail can tim: ");fflush(stdin);gets(mail);
	readFile(filename,add,count);
	//sort(add,count);
	//printAdd(add,count);
	for (i=0;i<count;i++){
		 insertBST(&add[i],&root);
	}
	/*for (i=0;i<count;i++){
		printf("%s\n%s\n%s\n",add[i].mail,add[i].name,add[i].tel);
	}*/
	//printf("%s\n%s\n%s\n",root->left->data.mail,root->left->data.name,root->left->data.tel);
	prettyprint(root,"-");
	//printTree(root);
	NodeTree *nt = Search(mail,root);
	//printf("Id = %d\n",id);
	if (nt==NULL) printf("Not found!\n");
	else {
		Address id = nt->data;
		printf("%s\n%s\n%s\n",id.mail,id.name,id.tel);
	}
	return 0;
}
