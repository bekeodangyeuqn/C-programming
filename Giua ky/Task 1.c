#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 11
#define LENGTH 5

typedef struct Address{
	char name[50];
	char tel[11];
	char mail[100];
}Address;

typedef struct Node{
	Address data;
	struct Node *next;
}Node;

Node *makeNode(Address data){
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	return p;
}

void chuanhoaxau(char *str){	
	int i;
	for(i = strlen(str)-1; i>=0; i--)
	{
		if(str[i]=='\n') str[i]='\0';
		if(str[i]=='\r') str[i]='\0';
	}	
		
}

// Thuc hien voi mang cho phan 1

void readFilebyArray(char *charname, Address add[],int count){
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

void sort(Address add[], int count){
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
}

void printAdd(Address add[], int count){
	int i;
	for (i=0;i<count;i++){
		printf("%s %s %s\n",add[i].name,add[i].tel,add[i].mail);
	}
}

int binarySearch(char Name[], int Hi,int Lo, Address add[]){
	if (Lo > Hi) {
		return -1;
	}
	int Mid = (Lo+Hi)/2;
	if (strcmp(Name,add[Mid].name) == 0){
		return Mid;
	} else if(strcmp(Name,add[Mid].name) > 0){
		return binarySearch(Name,Hi,Mid+1,add);
	} else {
		return binarySearch(Name,Mid-1,Lo,add);
	}
	return -1;
};

Node *top;
Node *tail;

// Dinh nghia bang link list cho phan 2

Node *insertLast(Address data, Node *top){
	Node *c = makeNode(data);
	if (top == NULL){
		top = c;
	} else{
		Node *p = top;
		while (p->next!=NULL){
			p = p->next;
	}
		p->next = c;
	}
	return top;
}

void doc1DCList(FILE *fin, Address *addr){
	fgets(addr->name,50,fin);chuanhoaxau(addr->name);
	fgets(addr->tel,50,fin);chuanhoaxau(addr->tel);
	fgets(addr->mail,50,fin);chuanhoaxau(addr->mail);
}

Node *docThongTinDCList(FILE *fin, Node *top){
	int n;
	printf("Nhap so luong muon nhap(10): ");scanf("%d",&n);
	int i;
	for (i=0;i<n;i++){
		Address addr;
		doc1DCList(fin,&addr);
		top = insertLast(addr,top);
	}
	return top;
}

void xuatDS(Node *top){
	Node *p;
	printf("Danh sach:\n");
	for (p = top; p!=NULL;p = p->next){
		printf("Thong tin: %s %s %s\n",p->data.name,p->data.tel,p->data.mail);
	}
}

Node *searchMoveToTop(char *name, Node *top){
	if (top == NULL) return ;
	Node *p, *q = NULL;
	if (strcmp(name,top->data.name) == 0){
		printf("Found! Thong tin tim duoc da nam o vi tri dau tien\n");
	} else {
		for (p = top;p->next!=NULL;p= p->next){
		if (strcmp(name,p->next->data.name) == 0){
			q = p->next;
			p->next = p->next->next;
			break;
		}
	}
	if (q == NULL){
		printf("Not found!\n");
	} else {
		printf("Found! Thong tin tim duoc da nam o vi tri dau tien\n");
		Node *tmp = top;
		q->next = tmp;
		top = q;
	}
	}
	return top;
}

// Dinh nghia bang queue cho phan 3,4

void initQue(){
	top = NULL;
	tail = NULL;
}

int queEmpty(){
	return top == NULL;
}

void Enque(Address addr){
	Node *p = makeNode(addr);
	if (tail == NULL){
		top = p;
		tail = p;
	} else {
		tail->next = p;
		tail = tail->next;
	}
}

Address Deque(){
	if (queEmpty()) return ;
	Node *p;
	Address addr;
	addr = top->data;
	p = top;
	top = top->next;
	free(p);
	if (top == NULL) tail == NULL;
	return addr;
}

void doc1DC(FILE *fin, Address *addr){
	fgets(addr->name,50,fin);
	fgets(addr->tel,50,fin);
	fgets(addr->mail,50,fin);
}

void docThongTinDC(FILE *fin){
	int n;
	printf("Nhap so luong muon nhap(10): ");scanf("%d",&n);
	int i;
	for (i=0;i<n;i++){
		Address addr;
		doc1DC(fin,&addr);
		Enque(addr);
	}
}

void xuat(FILE *fout){
	while (!queEmpty()){
		Address addr = Deque();
		fprintf(fout,"%s %s %s\n",addr.name,addr.tel,addr.mail);
		printf("%s %s %s\n",addr.name,addr.tel,addr.mail);
	}
}

// cho phan 4

void doc1DCtuBanPhim(Address *addr){
	printf("Name: ");fflush(stdin);gets(addr->name);
	printf("Tel: ");fflush(stdin);gets(addr->tel);
	printf("Mail: ");gets(addr->mail);
}

Node *DequeNode(){
	if (queEmpty()) return ;
	Node *p = top;
	top = top->next;
	if (top == NULL) tail == NULL;
	return p;
}

void taoDanhSach(){
	int i;
	printf("Nhap 5 dia chi\n");
	for (i=0;i<LENGTH;i++){
		Address addr;
		printf("Nhap gia tri Node can them:\n");
		doc1DCtuBanPhim(&addr);
		Enque(addr);
	}
	printf("Da nhap xong!\n");
}

Node *themVaRut(){
	Address addr;
	printf("Nhap gia tri Node can them vao(day phan tu dau ra):\n");
	doc1DCtuBanPhim(&addr);
	Node *p = DequeNode();
	Enque(addr);
	return p;
}

void Menu()
{
	int luachon;
	while (1){
		printf("\n\n\t\t========== Menu ==========");
		printf("\n\t1. Dinh nghia bang Array");
		printf("\n\t2. Dinh nghia bang link list");
		printf("\n\t3. Dinh nghia bang queue");
		printf("\n\t4. Doc va them vao hang doi");
		printf("\n\t0. Thoat");
		printf("\n\n\t\t========== End ===========");
		
		printf("\nNhap lua chon: ");
		scanf("%d",&luachon);

		if (luachon < 0 || luachon > 4){
			printf("\nLua chon khong hop le. Xin kiem tra lai !");
			system("pause"); // dung màn hình
		}
		else if (luachon == 1){
			Address add[100];
			int count,Hi,Lo;
			char filename[100], name[50], fileout[100];
			printf("Nhap so luong(10): ");scanf("%d",&count);
			printf("Nhap ten file dau vao(address2.txt): ");fflush(stdin);gets(filename);
			printf("Nhap ten file dau ra: ");fflush(stdin);gets(fileout);
			printf("Nhap ten can tim: ");fflush(stdin);gets(name);
			FILE *fout = fopen(fileout,"w+");
			readFilebyArray(filename,add,count);
			sort(add,count);
			printAdd(add,count);
			int id = binarySearch(name,count-1,0,add);
			printf("Id = %d\n",id);
			if (id == -1){
				printf("Not found");
		} else{
			printf("Seach thanh cong!\n");
			printf("%s has tel: %s and email %s\n",add[id].name,add[id].tel,add[id].mail);
			fprintf(fout,"%s %s %s\n",add[id].name,add[id].tel,add[id].mail);
			fclose(fout);
			system("pause");
		}
	}
		else if (luachon == 2){	
			Node *topL = NULL;
			char filename[100],name[50];
			FILE *fin;
			printf("Nhap ten file(address2.txt): ");fflush(stdin);gets(filename);
			printf("Nhap ten can tim: ");fflush(stdin);gets(name);
			fin = fopen(filename,"r");
			topL = docThongTinDCList(fin,topL);
			topL = searchMoveToTop(name,topL);
			xuatDS(topL);
			system("pause");
	}
		else if (luachon == 3){   
			FILE *fin;
			FILE *fout;
			initQue();
			char fileNameIn[100];
			char fileNameOut[100];
			printf("Nhap ten file de doc du lieu(address2.txt): "); scanf("%s",fileNameIn);
			printf("Nhap ten file de xuat du lieu: "); scanf("%s",fileNameOut);
			fin = fopen(fileNameIn,"r");
			fout = fopen(fileNameOut,"w+");
			docThongTinDC(fin);
			xuat(fout);
			fclose(fin);
			fclose(fout);
			system("pause");
	}
		else if (luachon == 4){
			char choice = 'y';
			initQue();
			taoDanhSach();
			while (choice == 'y'){
			Node* p = themVaRut();
			printf("Thong tin nut bi rut ra la: %s %s %s\n",p->data.name,p->data.tel,p->data.mail);
			printf("Tiep tuc(y/n): ");scanf(" %c",&choice);
			system("pause");
		}
	} else
		{
			break; // thoat khoi vòng lap hien tai
	}
	}
}

int main(){
	Menu();
	return 0;
}
