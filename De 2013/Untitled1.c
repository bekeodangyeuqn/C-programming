#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char ma[10];
	int diem;
	struct node *left;
	struct node *right;
}node;

typedef node* tree;

void initTree(tree *t){
	*t == NULL;
}

int count = 0;

void addNodeToTree(tree *t, char ma[10]){
	if (*t == NULL){
		//count++;
		tree p = (node*)malloc(sizeof(node));
		strcpy(p->ma,ma);
		p->diem = 0;
		p->left = NULL;
		p->right = NULL;
		*t = p;
		//printf("Nut moi thu %d, dia chi: %p\n",count,&t);
	} else {
		if (strcmp((*t)->ma,ma) > 0)
			addNodeToTree(&(*t)->left,ma);
		else if (strcmp((*t)->ma,ma) < 0)
			addNodeToTree(&(*t)->right,ma);
	}
}

tree searchInTree(tree t, char ma[10]){
	if ( t == NULL || strcmp(t->ma,ma) == 0) return t;
	if (strcmp(t->ma,ma) >0)
		return searchInTree(t->left,ma);
	return searchInTree(t->right,ma);
}

int compareGoal(int goal1, int goal2){
	if (goal1 > goal2) return 1;
	else if (goal1 < goal2) return -1;
	else return 0;
}
tree readFile(FILE *fp){
	tree temp;
	initTree(&temp);
	fp = fopen("bongda.txt","r");
	if (fp == NULL){
		printf("Nhap file khong thanh cong");
	}
	while(!feof(fp)){
		char ma1[100];
		char ma2[100];
		int goal1;
		int goal2;
		fscanf(fp,"%s\t%s\t%d\t%d\n",ma1,ma2,&goal1,&goal2);
		printf("%s %s %d %d\n",ma1,ma2,goal1,goal2);
		int k = compareGoal(goal1,goal2);
		printf("%d",k);
		node *p = searchInTree(temp,ma1); 
	
		if (p == NULL){
			addNodeToTree(&temp,ma1);
			p = searchInTree(temp,ma1); 
		}
		node *q = searchInTree(temp,ma2);
		if (q == NULL){
			addNodeToTree(&temp,ma2);
			q = searchInTree(temp,ma2);
		}
			
		printf("%s %d %s %d",p->ma,p->diem,q->ma,q->diem);
		if (k == 1) p->diem = p->diem + 3;
		else if (k == -1) q->diem = q->diem + 3;
		else {
			q->diem = q->diem +1;
			p->diem = p->diem +1;
		}
		printf("%s %d\n%s %d",p->ma,p->diem,q->ma,q->diem);
	}
	fclose(fp);
	return temp;
}

void printTree(tree t){
	printTree(t->left);
	printf("%s\t%d",t->ma,t->diem);
	printTree(t->right);
}

tree mostLeftChild(tree t){
	tree temp = t;
	while (temp && temp->left != NULL)
		temp = temp->left;
	return temp;
}

tree deleteNode(tree t, char ma[10]){
	if (t == NULL) return t;
	else if (strcmp(t->ma,ma) < 0)
		t->right = deleteNode(t->right,ma);
	else if (strcmp(t->ma,ma) > 0)
		t->left = deleteNode(t->left,ma);
	else {
		if (t->left == NULL){
			tree temp = t->right;
			free(t);
			return temp;
		}
		else if (t->right == NULL){
			tree temp = t->left;
			free(t);
			return temp;
		}
		tree temp = mostLeftChild(t->right);
		strcpy(t->ma,temp->ma);
		t->diem = temp->diem;
		t->right =  deleteNode(t->right,temp->ma);
	}
	return t;
}

tree duyetXuongHang(tree t,int xh){
	if (t->diem <= xh) return t;
	duyetXuongHang(t->left,xh);
	duyetXuongHang(t->right,xh);
}

void writeFile(tree t,FILE *fp){
	if (t!=NULL){
		writeFile(t->left,fp);
		fprintf(fp,"%s\t%d\n",t->ma, t->diem);
		writeFile(t->right,fp);
	}
}

void menu(tree t){
	int luachon;
	while(1){
		printf("=========MENU==========\n1.Tao cay\n2.Hien thi ket qua\n3.Tim kiem\n4.Xuong hang\n5.Xuat file\n");
		printf("\nNhap lua chon: ");
		scanf("%d",&luachon);
		if (luachon < 0 || luachon > 5){
			printf("\nLua chon khong hop le. Xin kiem tra lai !\n");
			system("pause"); // dung màn hình
		} else if (luachon == 1){
				FILE *fin;
				readFile(fin);
				system("pause");
			}
			else if (luachon == 2){
				printTree(t);
				system("pause");
			} else if (luachon == 3){
				char ma[10];
				printf("Nhap ma doi: ");fflush(stdin);gets(ma);
				tree p = searchInTree(t,ma);
				if (p == NULL){
					printf("Khong co ma doi nay!\n");
				}
				printf("%s\t%d",p->ma,p->diem);
				system("pause");
			} else if (luachon == 4){
				int xh;
				printf("Nhap so diem xuong hang: ");scanf("%d",&xh);
				
			}else if (luachon == 5){
				FILE *fout;
				fout = fopen("ketqua.txt","w+");
				writeFile(t,fout);
				fclose(fout);
				break;
			}
		}
}

int main(){
	tree t;
	initTree(&t);
//	FILE *fin;
//	readFile(fin);
int luachon;
	while(1){
		printf("=========MENU==========\n1.Tao cay\n2.Hien thi ket qua\n3.Tim kiem\n4.Xuong hang\n5.Xuat file\n");
		printf("\nNhap lua chon: ");
		scanf("%d",&luachon);
		if (luachon < 0 || luachon > 5){
			printf("\nLua chon khong hop le. Xin kiem tra lai !\n");
			system("pause"); // dung màn hình
		} else if (luachon == 1){
//				tree t;
//				initTree(&t);
				FILE *fin;
				t = readFile(fin);
				system("pause");
			}
//			else if (luachon == 2){
//				printTree(t);
//				system("pause");
//			} else if (luachon == 3){
//				char ma[10];
//				printf("Nhap ma doi: ");fflush(stdin);gets(ma);
//				tree p = searchInTree(t,ma);
//				if (p == NULL){
//					printf("Khong co ma doi nay!\n");
//				}
//				printf("%s\t%d",p->ma,p->diem);
//				system("pause");
//			} else if (luachon == 4){
//				int xh;
//				printf("Nhap so diem xuong hang: ");scanf("%d",&xh);
//				
//			}else if (luachon == 5){
//				FILE *fout;
//				fout = fopen("ketqua.txt","w+");
//				writeFile(t,fout);
//				fclose(fout);
//				break;
//			}
		}
		return 0;
}
