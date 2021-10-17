#include<stdio.h>
#include<stdlib.h>

typedef struct Address{
	char name[50];
	char tel[30];
	char mail[100];
}Address;

typedef struct Node{
	int id;
	Address addr;
	struct Node *next;
}Node;

typedef struct List{
	Node *root;
	Node *tail;
}List; 

void khoiTao(List *l){
	l->root = NULL;
	l->tail = NULL;
}


Node *makeNode(Address addr, int id){
	Node *p = (Node*)malloc(sizeof(Node));
	p->id = id;
	p->addr = addr;
	p->next = NULL;
	return p;
}

void themNode(List *l,Node *newA){
    if ( l->tail == NULL ) {
      l->root = l->tail = newA;
      // cur = root;
} else {  //newA->next = cur->next; 
          l->tail->next = newA;
          l->tail = newA;
    }
}

void ThemNode_p_VaoSauNode_q(List *l, int *n, Address addr)
{
	if (*n == 0){
		Node *p = makeNode(addr,1);
		if (l->root == NULL){
		l->root = l->tail = p;
	}
	else{
		p->next = l->root; // dùng con tro cua node p liên ket voi l.root
		l->root = p; // cap nhat lai l.root là p
	}
	Node *j;
	for (j = l->root->next;j!=NULL;j = j->next){
		j->id = j->id + 1;
	}
	} else{
		Node *k;
		for (k = l->root; k != NULL; k = k->next)
		{
			if (*n == k->id)
			{
				Node *h = makeNode(addr,*n+1); // khoi tao node h moi de thêm vào sau node q 
				Node *g = k->next; // cho node g tro den node nam sau node q
				h->next = g; //  Tao moi liên ket tu node h den node g <=> cung chính là tao moi liên ket tu node h den node nam sau node q
				k->next = h; // Tao moi liên ket tu node q den node h <=> chính là node k den node h
				Node *j;
				for (j = g;j!=NULL;j = j->next){
					j->id = j->id + 1;
				}
			}
		}
	}
}

void doc1DC(Address *adrr){
	printf("Name: ");fflush(stdin);gets(adrr->name);
	printf("Tel: ");fflush(stdin);gets(adrr->tel);
	printf("Mail: ");fflush(stdin);gets(adrr->mail);
}

void docThongTinDCKhiThem(List *l){
	int n;
	printf("Nhap so luong muon nhap: ");scanf("%d",&n);
	int i;
	for (i=0;i<n;i++){
		Address adrr;
		doc1DC(&adrr);
		Node *newA = makeNode(adrr,i+1);
		themNode(l,newA);
	}
}
	
void xuat(int *i, Address adrr){
	printf("|%5d|%30s|%30s|%30s|\n",*i,adrr.name,adrr.tel,adrr.mail);
}

void xuatDS(List l){
	Node *p;
	printf("|%5s|%30s|%30s|%30s|\n","Ma ID","Ho va ten","So dien thoai","Email");
	for (p = l.root; p!=NULL;p = p->next){
		xuat(&p->id,p->addr);
	}
}

void xoaNodeBatKy(List *l, int *n){
	if (l->root == NULL){
		return;
	}
	if (*n == 1){
	Node *p = l->root; // node p là node se xóa
	l->root = l->root->next;// cap nhat lai l.root là phan tu ke tiep
	free(p);
	Node *k;
	for (k = l->root;k!=NULL;k = k->next){
		k->id = k->id -1;
	} 
	} else{
		Node *g = (Node*)malloc(sizeof(Node));
		Node *k;
		for (k = l->root;k!=NULL;k=k->next){
			if (k->id == *n){
				g->next = k->next;
				free(k);
				return;
			}
			g = k;
		}
		Node *j;
		for (j = g->next;j!=NULL;j = j->next){
			j->id = (j->id) -1;
		}
	}
}


void Menu(List l)
{
	int luachon;
	while (1)
	{
		printf("\n\n\t\t========== Menu ==========");
		printf("\n\t1. Them dia chi vao danh sach");
		printf("\n\t2. Xuat danh sach lien ket don");
		printf("\n\t3. Them dia chi moi vao sau mot dia chi trong danh sach");
		printf("\n\t4. Xoa dia chi bat ky");
		printf("\n\t0. Thoat");
		printf("\n\n\t\t========== End ===========");

		printf("\nNhap lua chon: ");
		scanf("%d",&luachon);

		if (luachon < 0 || luachon > 4)
		{
			printf("\nLua chon khong hop le. Xin kiem tra lai !");
			system("pause"); // dung màn hình
		}
		else if (luachon == 1)
		{
			docThongTinDCKhiThem(&l);
		}
		else if (luachon == 2)
		{
			xuatDS(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			printf("\nNhap gia tri id cua dia chi can them vao sau: ");
			scanf("%d",&x);
			Address addr;
		    doc1DC(&addr);
			ThemNode_p_VaoSauNode_q(&l,&x,addr); // thêm node p vào sau node q trong danh sách l
			system("pause");
		}
		else if (luachon == 4){
			int n;
			printf("Nhap id nut can xoa: ");
			scanf("%d",&n);
			xoaNodeBatKy(&l,&n);
		} else
		{
			break; // thoát khoi vòng lap hien tai
		}
	}
}

int main(){
    List l;
	khoiTao(&l);
	Menu(l);
	return 0;
}
