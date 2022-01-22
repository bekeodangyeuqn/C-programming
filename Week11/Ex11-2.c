#include <stdio.h>
#include <stdlib.h>


void nhapArray(int A[], int n){
	int i;
	for (i=0; i<n;i++){
		A[i] = rand();
	}
}

void insertSort(int A[], int n){
	int i,j;
	int k;
	for (i=1; i<n;i++){
		k = A[i];
		j = i-1;
		while (j >=0 && k < A[j]){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = k;
	}
}

void printArray(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ",A[i]);
    printf("\n");
}

void quickSort(int A[], int l, int r){
	int pivot,tmp;
	int i,j;
	if (l < r){
		i = l; j = r+1;
		pivot = A[l];
		do {
		do i++; while (pivot > A[i]);
		do j--; while (pivot < A[j]);
		if (i < j){
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		} 
	}while (i < j);
	tmp = A[j];
	A[j] = A[l];
	A[l] = tmp;
	quickSort(A,l,j-1);
	quickSort(A,j+1,r);
	}
}

int main(){
	int A[10000];
	int n;
	int luachon;
	printf("Nhap so luong n: ");scanf("%d",&n);
	nhapArray(A,n);
	printf("Truoc khi sap xep: \n");
	printArray(A,n);
	printf("1.Insert Sort\n2.Quick Sort\nNhap lua chon:");scanf("%d",&luachon);
	if (luachon == 1) {
		insertSort(A,n);
		printArray(A,n);
	} else if (luachon == 2){
		quickSort(A,0,n-1);
		printArray(A,n);
	}
	return 0;
}

// Ca hai cach sap xep deu rat nhanh nen em khong biet cai nao hon a
