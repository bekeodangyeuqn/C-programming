#include<stdio.h>

void quickSort(int arr[],int left, int right){
	int i,j,pivot,temp;
	if (left < right){
		i = left ;
		j = right + 1;
		pivot = arr[left];
	do {
		do i++; while (arr[i] < pivot);
		do j--; while (arr[j] > pivot);
		if (i<j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	} while (i<j);
	temp = arr[left];
	arr[left] = arr[j];
	arr[j] = temp;
	quickSort(arr,left,j-1);
	quickSort(arr,j+1,right);
	}
}

int main(){
	int arr[10] = {10,50,7,8,40,35,70,25,12,48};
	quickSort(arr,0,9);
	int i = 0;
	for(;i<10;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
