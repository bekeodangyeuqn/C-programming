#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Address{
	char name[50];
	char tel[11];
	char mail[100];
}Address;

void chuanhoaxau(char *str){	
	int i;
	for(i = strlen(str)-1; i>=0; i--)
	{
		if(str[i]=='\n') str[i]='\0';
		if(str[i]=='\r') str[i]='\0';
	}	
		
}

void readFile(char *charname, Address add[],int count){
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
		printf("%s %20s %20s\n",add[i].name,add[i].tel,add[i].mail);
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
}

int main(){
	//FILE *fp;
	Address add[100];
	int count,Hi,Lo;
	char filename[100], name[50];
	printf("Nhap so luong: ");scanf("%d",&count);
	printf("Nhap ten file: ");fflush(stdin);gets(filename);
	printf("Nhap ten can tim: ");fflush(stdin);gets(name);
	readFile(filename,add,count);
	sort(add,count);
	printAdd(add,count);
	int id = binarySearch(name,count-1,0,add);
	printf("Id = %d\n",id);
	if (id == -1){
		printf("Not found");
		return 0;
	} else{
		printf("%s has tel: %s and email %s",add[id].name,add[id].tel,add[id].mail);
	}
	return 0;
}
