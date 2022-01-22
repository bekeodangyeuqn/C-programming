#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GETFILEIN "address2.txt"
#define GETFILEOUT "addressOut.txt"
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
	fp = fopen(GETFILEIN,"r") ;
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

void printArray(Address addressList[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%s %s %s\n", addressList[i].name,addressList[i].tel,addressList[i].mail);
    printf("\n");
}

void outputFile(Address addressList[], int n){
	FILE *fout;
	fout = fopen(GETFILEOUT,"w+");
	int i;
    for (i = 0; i < n; i++)
        fprintf(fout,"%s %s %s\n", addressList[i].name,addressList[i].tel,addressList[i].mail);
    fclose(fout);
}

int main(){
	Address addressList[100];
	readFilebyArray(addressList,M);
	printf("Truoc khi sap xep: \n\n");
	printArray(addressList,M);
	printf("Sap xep bang Quick Sort:\n\n");
	quickSort(addressList,0,M-1);
	printArray(addressList,M);
	outputFile(addressList,M);
}
