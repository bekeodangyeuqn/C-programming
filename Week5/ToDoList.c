#include <stdio.h>
#include <time.h>
#include<stdlib.h>

char *timeF(){
	time_t curtime;
    time(&curtime);
    return ctime(&curtime);
}

typedef struct ToDo{
	int id;
	char time[100];
	char place[100];
	char people[100];
	char des[100];
}ToDo;

typedef struct Node{
	ToDo Data;
	struct Node* next;
}Node;

Node *makeNode(ToDo TD){
	Node *p = (Node*)malloc(sizeof(Node));
	p->Data = TD;
	p->next = NULL;
}

Node *top;
Node *tail;

void queInit(){
	top = NULL;
	tail = NULL;
}

int queEmpty(){
	return top == NULL;
}

void Enque(Node *p){
	if (tail == NULL){
		top = p;
		tail = p;
	} else {
		tail->next = p;
		tail = tail->next;
	}
}

Node *Deque(){
	if (queEmpty()) return ;
	Node *p = top;
	top = top->next;
	if (top == NULL) tail == NULL;
	return p;
}

void nhapToDo(ToDo *TD, int *i){
	TD->id = *i;
	printf("Nhap dia diem: ");fflush(stdin);gets(TD->place);
	printf("Nhap nguoi: ");fflush(stdin);gets(TD->people);
	printf("Nhap dien ta: ");fflush(stdin);gets(TD->des);
    strcpy(TD->time,timeF()); 
}

void addToDo(ToDo TD,int *i){
	nhapToDo(&TD,i);
	Node *p = makeNode(TD);
	Enque(p);
}

void xuat(ToDo TD){
	printf("%5d|%20s|%20s|%20s|%20s|\n",TD.id,TD.place,TD.people,TD.des,TD.time);
}

void xuatDS(){
	Node *p;
	printf("%5s|%20s|%20s|%20s|%20s|\n","Ma ID","Dia diem","Nguoi","Dien ta","Thoi gian nhap");
	for (p = top; p!=NULL;p = p->next){
		xuat(p->Data);
	}
}

void deleteAToDo(int *id){
	//int id;
	//printf("Nhap id cong viec can xoa: ");scanf("%d",&id);
	if (top == NULL) return;
	if (top->Data.id == *id){
		Node *p = top;
		top = top->next;
		free(p);
		Node *k;
		for (k=top;k!=NULL;k = k->next){
			k->Data.id = k->Data.id - 1;
		}
	} else {
		Node *k; // Node can xoa
		Node *g = (Node*)malloc(sizeof(Node)); // Node truoc nut can xoa
		for (k=top;k!=NULL;k = k->next){
			if (k->Data.id == *id){
				g->next = k->next;
				free(k);
				//return;
			}
			g = k;
		}
		Node *c;
		for (c = g->next; c!=NULL; c = c->next){
			c->Data.id = (c->Data.id) -1;
	}
}
}

void modifyToDo(int *id){
	if (top == NULL) return;
	Node *p;
	for (p = top; p!=NULL; p = p->next){
		if (p->Data.id == *id){
			printf("%5s|%20s|%20s|%20s|%20s|\n","Id","Dia diem","Nguoi","Dien ta","Thoi gian nhap");
			printf("%5d|%20s|%20s|%20s|%20s|\n",p->Data.id,p->Data.place,p->Data.people,p->Data.des,p->Data.time);
			char time[100];
			char place[100];
			char people[100];
			char des[100];
			printf("Nhap dia diem can doi: ");fflush(stdin);gets(place);
			printf("Nhap nguoi can doi: ");fflush(stdin);gets(people);
			printf("Nhap dien ta can doi: ");fflush(stdin);gets(des);
			strcpy(p->Data.time,timeF()); 
			strcpy(p->Data.place,place); 
			strcpy(p->Data.people,people); 
			strcpy(p->Data.des,des); 
			printf("%5s|%20s|%20s|%20s|%20s|\n","Id","Dia diem","Nguoi","Dien ta","Thoi gian nhap");
			printf("%5d|%20s|%20s|%20s|%20s|\n",p->Data.id,p->Data.place,p->Data.people,p->Data.des,p->Data.time);
		}
	}
}

void Menu()
{
	int luachon;
	int count = 0;
	while (1)
	{
		printf("\n\n\t\t========== Menu ==========");
		printf("\n\t1. Them viec can lam vao danh sach");
		printf("\n\t2. Xuat danh sach viec can lam");
		printf("\n\t3. Xoa viec theo ID");
		printf("\n\t4. Thay doi mot viec theo ID");
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
		{   printf("count = %d\n",count);
			int n;
			printf("Nhap so luong muon nhap: ");scanf("%d",&n);
			int i;
			for (i =  1;i <= n;i++){
				int k = i + count;
				ToDo TD;
				addToDo(TD,&k);
			}
			count = count + n;
			system("pause");
		}
		else if (luachon == 2)
		{
			xuatDS();
			system("pause");
		}
		else if (luachon == 3)
		{   int id;
			printf("\nNhap gia tri id cua hoc sinh can xoa: ");scanf("%d",&id);
			deleteAToDo(&id);
			xuatDS();
			count = count -1;
			system("pause");
		}
		else if (luachon == 4){
			int id2;
	        printf("\nNhap gia tri id cua hoc sinh can thay doi: ");scanf("%d",&id2);
			modifyToDo(&id2);
			xuatDS();
			system("pause");
		} else
		{
			break; // thoát kh?i vòng l?p hi?n t?i
		}
	}
}

int main(){
	queInit();
	Menu();
	return 0;
}
