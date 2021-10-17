#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
	char id[20];
	char name[50];
	int grade;
}Student;

typedef struct Node{
	Student data;
	struct Node *next;
}Node;

Node *makeNode(Student stu){
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = stu;
	p->next = NULL;
	return p;
}

typedef struct List{
	Node *root;
	Node *tail;
}List;

void khoiTao(List *l){
	l->root = NULL;
	l->tail = NULL;
}

void addStudentDescending(List *l, Node *newS){
	if (l->root == NULL){
		l->root = l->tail = newS;
	} else if (newS->data.grade > l->root->data.grade){
		newS->next = l->root;
		l->root = newS;
	} else {
		Node *k = l->root;
		Node *g; // Node o truoc phan tu them vao
		while (k != NULL && newS->data.grade < k->data.grade){
			g = k;
			k = k->next;
		}
		g->next = newS;
		newS->next = k;
	}
}

Student searchByID(List *l, char *id){
	if (l->root == NULL) return;
	Node *k ;
	for (k = l->root;k!=NULL;k = k->next){
		if (strcmp(k->data.id,id) == 0) return k->data;
		}
		// printf("Khong tim thay id cua hoc sinh!\n");
	return ;
	}

void deleteStudent(List *l, char *id){
	if (l->root == NULL) return; 
	if (strcmp(l->root->data.id,id) == 0){
		Node *p = l->root;
		l->root = l->root->next;
		free(p);
	} else {
		Node *k ;
		Node *g = (Node*)malloc(sizeof(Node)); // Node o truoc phan tu can xoa
		for (k = l->root;k!=NULL;k = k->next){
			if (strcmp(k->data.id,id) == 0){
				g->next = k->next;
				free(k);
				return;
			}
			g = k;
		}
	}
}



void doc1DC(Student *stu){
	printf("Name: ");fflush(stdin);gets(stu->name);
	printf("Id: ");fflush(stdin);gets(stu->id);
	printf("Grade(0-100,int): ");scanf("%d",&stu->grade);
}

void docThongTinHSKhiThem(List *l){
	int n;
	printf("Nhap so luong sinh vien muon nhap: ");scanf("%d",&n);
	int i;
	for (i=0;i<n;i++){
		Student stu;
		doc1DC(&stu);
		Node *newS = makeNode(stu);
		addStudentDescending(l,newS);
	}
}
	
void xuat(Student stu){
	printf("|%30s|%30s|%10d|\n",stu.id,stu.name,stu.grade);
}

void xuatDS(List l){
	Node *p;
	printf("|%30s|%30s|%10s|\n","Ma ID","Ho va ten","Diem so");
	for (p = l.root; p!=NULL;p = p->next){
		xuat(p->data);
	}
}

void changeGrade(List *l,int *grade, char *id){
	if (l->root == NULL) return;
	Node *p = (Node*)malloc(sizeof(Node));
	Node *k;
	for (k = l->root;k!=NULL;k = k->next){
		if (strcmp(k->data.id,id) == 0){
			strcpy(p->data.id,k->data.id);
		    strcpy(p->data.name,k->data.name);
		    p->data.grade = *grade;
		    deleteStudent(l,id);
		    addStudentDescending(l,p);
		    return;
		}
	}
}

void Menu(List l)
{
	int luachon;
	while (1)
	{
		printf("\n\n\t\t========== Menu ==========");
		printf("\n\t1. Them hoc sinh vao danh sach");
		printf("\n\t2. Xuat danh sach hoc sinh theo thu tu diem giam dan");
		printf("\n\t3. Tim kiem hoc sinh theo ID");
		printf("\n\t4. Xoa hoc sinh theo ID");
		printf("\n\t5. Thay doi diem cua sinh vien");
		printf("\n\t0. Thoat");
		printf("\n\n\t\t========== End ===========");

		printf("\nNhap lua chon: ");
		scanf("%d",&luachon);

		if (luachon < 0 || luachon > 5)
		{
			printf("\nLua chon khong hop le. Xin kiem tra lai !");
			system("pause"); // d?ng màn hình
		}
		else if (luachon == 1)
		{
			docThongTinHSKhiThem(&l);
		}
		else if (luachon == 2)
		{
			xuatDS(l);
			system("pause");
		}
		else if (luachon == 3)
		{   char id[100];
			printf("\nNhap gia tri id cua hoc sinh can tim kiem: ");fflush(stdin);gets(id);
			Student stu;
			stu = searchByID(&l,id);
            xuat(stu);
			system("pause");
		}
		else if (luachon == 4){
			char id2[100];
	        printf("\nNhap gia tri id cua hoc sinh can xoa: ");fflush(stdin);gets(id2);
			deleteStudent(&l,id2);
			xuatDS(l);
			system("pause");
		} else if (luachon == 5){
			char id3[100];
	        printf("\nNhap gia tri id cua hoc sinh can doi diem: ");fflush(stdin);gets(id3);
	        int grade;
	        printf("Nhap gia tri diem can doi: ");scanf("%d",&grade);
	        changeGrade(&l,&grade,id3);
	        xuatDS(l);
	        system("pause");
		} else
		{
			break; // thoát kh?i vòng l?p hi?n t?i
		}
	}
}

int main(){
    List l;
	khoiTao(&l);
	Menu(l);
	return 0;
}

