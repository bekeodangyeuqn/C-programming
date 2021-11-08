#include<stdio.h>

#define MAX_SIZE 1000 /* maximum size of	list plus one */
typedef struct {
int key;
/* other fields */
} element; 
element list[MAX_SIZE];

void inputList(element list[],int *k, int id){
	printf("Nhap list %d\n",id);
	int i;
	for(i=0;i<*k;i++){
		printf("Nhap phan tu %d: ",i);scanf("%d",&list[i].key);
	}
}

void sort(element list[],int k){
	int i,j;
	for (i = 0; i < k-1; i++){
		for (j = k-1; j > i; j--){
			if(list[j].key < list[j-1].key){
				element tmp;
				tmp = list[j];
				list[j] = list[j-1];
				list[j-1] = tmp;
			}
		}
	}
}


void verify(element list1[ ], element list2 [ ], int n, int m){
	int i, j; 
	sort(list1, n); 
	sort(list2, m); 
	i = j = 0;
	while (i < n && j < m){
	if (list1[i].key < list2[j].key) {
		printf ("%d is not in list 2 \n", list1[i].key); i++;
	}	else if (list1[i].key == list2[j].key) {
			i++; j++;
		}else {
			printf("%d is not in list 1\n", list2[j].key); j++;
		}
	}
	for(; i < n; i++) printf ("%d is not in list 2\n", list1[i].key); 
	for(; j < m; j++) printf("%d is not in list 1\n", list2[j].key);
}

int main(){
	int n,m;
	printf("n = ");scanf("%d",&n);
	printf("m = ");scanf("%d",&m);
	element list1[n];
	element list2[m];
	inputList(list1,&n,1);
	inputList(list2,&m,2);
	verify(list1,list2,n,m);
}



