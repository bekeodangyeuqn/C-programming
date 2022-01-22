#include<stdio.h>
#include<stdlib.h>

#define N 6

void insertSort(int A[], int n){
	int i,j,k;
	for (i=1;i<n;i++){
		k = A[i];
		j = i-1;
		while (j >=0 && A[j] > k){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = k;
	}
}

void printSort(int A[], int n){
	int i;
	for (i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
}

int main(){
	int A[N] = {4,2,6,1,8,0};
	printSort(A,N);
	insertSort(A,N);
	printSort(A,N);
	return 0;
}
