#include<stdio.h>

#define MAX 11

typedef int T;

void nhap(T M[]){
	int i;
	for (i=0;i<MAX-1;i++){
		printf("Nhap phan tu thu %d:",i+1); scanf("%d",&M[i]);
	}
	printf("Nhap phan tu can tim: ");scanf("%d",&M[MAX]);
}
int LinearSentinelSearch (T M[], T X){
	int k = 0; M[MAX]=X;
	while (M[k] != X) k++;
	if (k == MAX) return 0; else
	return k;
}

int main(){
	T M[MAX];
	nhap(M);
	int k = LinearSentinelSearch(M,M[MAX]);
	if (k==0) printf("Khong ton tai so can tim");
    else printf("Vi tri: %d",k+1);
    return 0;
}


