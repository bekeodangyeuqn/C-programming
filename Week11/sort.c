#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GETFILE "address2.txt"
#define M 10

typedef struct Address{
	char name[50];
	char tel[11];
	char mail[100];
}Address;

void chuanhoaxau(char *str)
{   int i;
	for(i = strlen(str)-1; i>=0; i--)
	{
		if(str[i]=='\n') str[i]='\0';
		if(str[i]=='\r') str[i]='\0';
	}	
		
}

void readFilebyArray(Address addressList[],int n){
	FILE *fp;
	fp = fopen(GETFILE,"r") ;
	if (fp == NULL){
		printf("Loi doc file");
	} else {
		int i=0;
		for (i=0;i<n;i++){
			fgets(addressList[i].name,51,fp);chuanhoaxau(addressList[i].name);
			fgets(addressList[i].tel,12,fp);chuanhoaxau(addressList[i].tel);
			fgets(addressList[i].mail,101,fp);chuanhoaxau(addressList[i].mail);
		}
	}
	fclose(fp);
}

void insertSort(Address addressList[], int n){
	int i,j;
	Address k;
	for (i=1; i<n;i++){
		k = addressList[i];
		j = i-1;
		while (j >=0 && (strcmp(k.name,addressList[j].name) < 0)){
			addressList[j+1] = addressList[j];
			j--;
		}
		addressList[j+1] = k;
	}
}

void quickSort(Address addressList[], int l, int r){
	Address pivot,tmp;
	int i,j;
	if (l < r){
		i = l; j = r+1;
		pivot = addressList[l];
		do {
		do i++; while (strcmp(pivot.name,addressList[i].name) > 0);
		do j--; while (strcmp(pivot.name,addressList[j].name) < 0);
		if (i < j){
			tmp = addressList[i];
			addressList[i] = addressList[j];
			addressList[j] = tmp;
		} 
	}while (i < j);
	tmp = addressList[j];
	addressList[j] = addressList[l];
	addressList[l] = tmp;
	quickSort(addressList,l,j-1);
	quickSort(addressList,j+1,r);
	}
}

void merge(Address addressList[], int l,int m, int r){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	Address A1[n1],A2[n2];
	for (i=0;i<n1;i++){
		A1[i] = addressList[l+i];
	}
	for (i=0;i<n2;i++){
		A2[i] = addressList[i+m+1]; 
	}
	i = 0;
	j = 0;
	k = l;
	while (i<n1 && j < n2){
		if (strcmp(A1[i].name,A2[j].name) <= 0){
			addressList[k] = A1[i];
			i++;
		} else {
			addressList[k] = A2[j];
			j++;
		}
		k++;
	}
	while (i < n1){
		addressList[k] = A1[i];
		i++;
		k++;
	}
	while (j < n2){
		addressList[k] = A2[j];
		j++;
		k++;
	}
}

void mergeSort(Address addressList[], int l, int r){
	if (l < r){
		int m = (l+r)/2;
		mergeSort(addressList,l,m);
		mergeSort(addressList,m+1,r);
		merge(addressList,l,m,r);
	}
}

void heapify(Address addressList[], int n, int i){
	int max = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if (l < n && strcmp(addressList[l].name,addressList[max].name) > 0)
		max = l;
	if (r < n && strcmp(addressList[r].name,addressList[max].name) > 0)
		max = r;
	if (max != i){
		Address tmp;
		tmp = addressList[i];
		addressList[i] = addressList[max];
		addressList[max] = tmp;
		heapify(addressList,n,max); // max luc nay la chi so cua phan tu goc ban dau da bi doi vi tri voi phan tu lon nhat
	}
}

void heapSort(Address addressList[], int n){
	int i;
	// dung Heap cho array
	for (i = n/2 - 1; i >= 0; i--){
		heapify(addressList,n,i);
	}
	
	for (i = n -1; i > 0; i--){
		Address tmp = addressList[i];
		addressList[i] = addressList[0];
		addressList[0] = tmp;
		heapify(addressList,i,0);
	}
}

void outputFile(Address addressList[], int n,FILE *fout){
	int i;
    for (i = 0; i < n; i++)
        fprintf(fout,"%s %s %s\n", addressList[i].name,addressList[i].tel,addressList[i].mail);
}

void printArray(Address addressList[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%s %s %s\n", addressList[i].name,addressList[i].tel,addressList[i].mail);
    printf("\n");
}

void menu(Address addressList[])
{
	int luachon;
	while (1){
		printf("\n\n\t\t========== Menu ==========");
		printf("\n\t1. Sap xep theo Insert Sort");
		printf("\n\t2. Sap xep theo Quick Sort");
		printf("\n\t3. Sap xep theo Merge Sort");
		printf("\n\t4. Sap xep theo Heap Sort");
		printf("\n\t0. Thoat");
		printf("\n\n\t\t========== End ===========");
		
		printf("\nNhap lua chon: ");
		scanf("%d",&luachon);

		if (luachon < 0 || luachon > 4){
			printf("\nLua chon khong hop le. Xin kiem tra lai !");
			system("pause"); // dung màn hình
		}
		else if (luachon == 1){
			printf("Sap xep bang Insert Sort\n\n");
			insertSort(addressList,M);
			printArray(addressList,M);
			system("pause");
		}
		else if (luachon == 2){	
			printf("Sap xep bang Quick Sort\n\n");
			quickSort(addressList,0,M-1);
			printArray(addressList,M);
			system("pause");
	}
		else if (luachon == 3){   
			printf("Sap xep bang Merge Sort\n\n");
			mergeSort(addressList,0,M-1);
			printArray(addressList,M);
			system("pause");
	}
		else if (luachon == 4){
			printf("Sap xep bang Heap Sort\n\n");
			heapSort(addressList,M);
			printArray(addressList,M);
			system("pause");
		}
	 else
		{
			break; // thoat khoi vòng lap hien tai
	}
	}
}

int main(){
	Address addressList[100];
	readFilebyArray(addressList,M);
	menu(addressList);
	return 0;
}


