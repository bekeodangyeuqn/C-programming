#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum login{
	FAIL,SUCCESS
};
typedef struct NODE
{
	char username[100];
	char password[100];
	float diem;
	struct NODE *left;
	struct NODE *right;
}NODE;

typedef NODE* TREE;

void initTree(TREE *t)
{
	*t == NULL;
}

void addNodeToTree(char username[100],char password[100], float diem, TREE *t)
{
	if (*t == NULL){
		TREE p = (NODE*)malloc(sizeof(NODE));
		strcpy(p->username,username);
		strcpy(p->password,password);
		p->diem = diem;
		p->left = NULL;
		p->right = NULL;
		*t = p;
	} else {
		if (strcmp((*t)->username,username) > 0)
			addNodeToTree(username,password,diem, &(*t)->left);
		else if (strcmp((*t)->username,username) < 0)
			addNodeToTree(username,password,diem, &(*t)->right);
	}
}

int havespace(char s[100]){
	int n = strlen(s);
	int boo = 0;
	int i;
	for (i=0;i<n;i++){
		if (s[i] == ' '){
			boo = 1;
			break;
		}
	}
	return boo;
}

TREE searchDataInTree(char username[100], TREE t){
	if (t == NULL || (strcmp(t->username,username) == 0)) return t;
	if (strcmp(t->username,username) >0)
		return searchDataInTree(username,t->left);
	return searchDataInTree(username,t->right);
}

void readFile(FILE *fp, TREE *t){
	fp = fopen("student.txt","r");
	if (fp == NULL){
		printf("Nhap file khong thanh cong");
	}
	while (!feof(fp)){
		char username[100];
		char password[100];
		float diem;
		fscanf(fp,"%s\t%s\t%f\n",username,password,&diem);
		NODE *p = searchDataInTree(username,*t);
		if (p == NULL)
			addNodeToTree(username,password,diem,t);
		//printf("%s ",word);
	}
	fclose(fp);
}

void writeFile(TREE t,FILE *fp){
	if (t!=NULL){
		writeFile(t->left,fp);
		fprintf(fp,"%s\t%s\t%f\n",t->username,t->password, t->diem);
		writeFile(t->right,fp);
	}
}

TREE mostLeftChild(TREE t){
	TREE temp = t;
	while (temp && temp->left != NULL)
		temp = temp->left;
	return temp;
}

TREE deleteNode(TREE t, char username[100]){
	if (t == NULL) return t;
	else if (strcmp(t->username,username) < 0)
		t->right = deleteNode(t->right,username);
	else if (strcmp(t->username,username) > 0)
		t->left = deleteNode(t->left,username);
	else {
		if (t->left == NULL){
			TREE temp = t->right;
			free(t);
			return temp;
		}
		else if (t->right == NULL){
			TREE temp = t->left;
			free(t);
			return temp;
		}
		TREE temp = mostLeftChild(t->right);
		strcpy(t->username,temp->username);
		strcpy(t->password,temp->password) ;
		t->diem = temp->diem;
		t->right =  deleteNode(t->right,temp->username);
	}
	return t;
}

void printData(TREE t){
	if (t!=NULL){
		printData(t->left);
		printf("%s\t%s\t%f\n",t->username,t->password, t->diem);
		printData(t->right);
	}
}

void loggedUserMenu(TREE t,TREE p){
	int luachon;
	while(1){
		printf("=========USER MENU==========\n1.Xem diem\n2.Thay doi mat khau\n3.Ghi thong tin");
		printf("\nNhap lua chon: ");
		scanf("%d",&luachon);
		if (luachon < 0 || luachon > 3){
			printf("\nLua chon khong hop le. Xin kiem tra lai !");
			system("pause"); // dung màn hình
		} else if (luachon == 1){
				printf("Diem cua ban: %.1f\n",p->diem);
				system("pause");
			}
			else if (luachon == 2){
				char password[100];
				printf("Nhap mat khau moi(> 6 ky tu va khong dau cach): ");fflush(stdin);gets(password);
				if (strlen(password) >= 6 && havespace(password) == 0){
					char password2[100];
					printf("Nhap lai mat khau moi: ");fflush(stdin);gets(password2);
					if (strcmp(password2,password) == 0){
						strcpy(p->password,password);
						printf("Thay doi mat khau thanh cong. Xin hay luu du lieu o lua chon 3.");
					} else {
						printf("Nhap mat khau lan 2 sai\n");
					}
				} else {
					printf("Mat khau khong hop le!\n");
				}
				system("pause");
			} else if (luachon == 3){
				FILE *fout;
				fout = fopen("student.txt","w+");
				writeFile(t,fout);
				fclose(fout);
				break;
			}
		}
}

void loggedAdminMenu(TREE t){
	int luachon;
	while(1){
		printf("=========ADMIN MENU==========\n1.Them sinh vien\n2.In danh sach sinh vien\n3.Xoa sinh vien\n4.Ghi thong tin\n");
		printf("\nNhap lua chon: ");
		scanf("%d",&luachon);
		if (luachon < 0 || luachon > 4){
			printf("\nLua chon khong hop le. Xin kiem tra lai !\n");
			system("pause"); // dung màn hình
		} else if (luachon == 1){
				char username[100];
				printf("Nhap username moi: ");fflush(stdin);gets(username);
				if (havespace(username) == 0 && searchDataInTree(username,t) == NULL){
					char password[100];
					printf("Nhap password cho user moi: ");fflush(stdin);gets(password);
					if (strlen(password) >= 6 && havespace(password) == 0){
						float diem;
						printf("Nhap diem cho user moi: ");scanf("%f",&diem);
						addNodeToTree(username,password,diem,&t);
					} else printf("Password khong hop le!\n");
				} else printf("Username khong hop le hoac da ton tai!\n");
				printf("Them thanh cong. Xin hay ghi file o 4.\n");
				system("pause");
			}
			else if (luachon == 2){
				printData(t->left);
				printData(t->right);
				system("pause");
			} else if (luachon == 3){
				char username[100];
				printf("Nhap username can xoa: ");fflush(stdin);gets(username);
				TREE p = searchDataInTree(username,t);
				if (p == NULL){
					printf("Username khong ton tai trong du lieu\n");
				}
				printf("%s\t%s\t%s\n","Username","Password","Diem");
				printf("%s\t%s\t%.1f\n",p->username,p->password,p->diem);
				t = deleteNode(t,username);
				printf("Xoa thanh cong. Xin hay ghi file o 4.\n");
				system("pause");
			} else if (luachon == 4){
				FILE *fout;
				fout = fopen("student.txt","w+");
				writeFile(t,fout);
				fclose(fout);
				break;
			}
		}
}

void loginMenu(TREE t){
	int luachon;
	while(1){
		TREE logged;
		printf("=========MENU==========\n1.Dang nhap\n2.Thoat\n");
		printf("Nhap lua chon:");scanf("%d",&luachon);
		if (luachon < 0 || luachon > 2){
			printf("\nLua chon khong hop le. Xin kiem tra lai !");
			system("pause"); // dung màn hình
		} else
		if (luachon == 1){
			int countLogIn = 0;
			while(countLogIn < 3){
				char username[100];
				char password[100];
				printf("Username:"); fflush(stdin);gets(username);
				printf("Password:"); fflush(stdin);gets(password);
				TREE temp = searchDataInTree(username,t);
				if (temp == NULL){
					countLogIn++;
					printf("Dang nhap sai. Ban con %d lan dang nhap\n",3-countLogIn);
				} 
				else if (strcmp(temp->password,password) != 0){
					countLogIn++;
					printf("Dang nhap sai. Ban con %d lan dang nhap\n",3-countLogIn);
				}
					else{
						logged = temp;
						break;
					} 
			}
			if (countLogIn >= 3) exit(-1);
			if (strcmp(logged->username,"Admin") == 0){
				printf("Dang nhap admin thanh cong!\n");
				loggedAdminMenu(t);
			}
			else {
				printf("Dang nhap user thanh cong!\n");
				loggedUserMenu(t,logged);
				//printf("Dang nhap user thanh cong!\n");
			}
		}
		else if (luachon == 2){
			exit(-1);
		}
	}
}

int main(){
	TREE t;
	initTree(&t);
	FILE *fin;
	readFile(fin,&t);
	printData(t);
	loginMenu(t);
}
