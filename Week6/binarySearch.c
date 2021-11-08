#include<stdio.h>

#define MAX 100
int count = 0,countR =0;
typedef int T;

void nhap(T M[],T *N){
	int i;
	for (i=0;i<*N;i++){
		M[i] = (i*3) - 1;
	}
}

int binarySearch(T M[],T X,int N){
	int Hi = N-1;
	int Lo = 0;
	int Mid;
	while (Hi >= Lo){
		Mid = (Hi + Lo)/2;
		if (M[Mid] == X){
			count ++;
			return Mid;
		} else if (M[Mid] > X){
			count ++;
			Hi = Mid -1;
		} else if (M[Mid] < X){
			count ++;
			Lo = Mid + 1;
		}
	}
	return -1;
}

int binarySearchR(T M[],T X,int Lo,int Hi){
	if (Lo > Hi) return -1; 
	countR ++;
	int Mid = ( Lo + Hi ) / 2;
    if	(M[Mid] < X ) return binarySearchR(M, X, Mid+1, Hi);
	else if ( M[Mid] > X ) return binarySearchR(M, X, Lo, Mid - 1);
	else{
		return Mid;	
	}
return -1;

}

int main(){
	int N,X;
	printf("Nhap so phan tu cua day: ");scanf("%d",&N);
	T M[N];
	printf("Nhap so can tim: ");scanf("%d",&X);
	nhap(M,&N);
	int k = binarySearch(M,X,N);
	int kR = binarySearchR(M,X,0,N-1);
	if (k == -1){
		printf("Khong tim thay!\n");
		printf("So lan so sanh bang tim kiem nhi phan: %d\n",count);
	} else{
		printf("Vi tri (tim kiem nhi phan): %d\n",k+1);
		printf("So lan so sanh bang tim kiem nhi phan: %d\n",count);
	}
	
	if (kR == -1) {
		printf("Khong tim thay!\n");
		printf("So lan goi ham bang tim kiem nhi phan de quy: %d\n",countR);
	} else{
		printf("Vi tri (tim kiem nhi phan de quy): %d\n",kR+1);
		printf("So lan goi ham bang tim kiem nhi phan de quy: %d\n",countR);
	}
	
	return 0;
}


