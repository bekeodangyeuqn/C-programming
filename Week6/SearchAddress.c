#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Address{
	char name[50];
	char tel[30];
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

int main(){
	FILE *fp;
	int i;
	int n;
	Address ad[100];
	char name[50];
	fp = fopen("address2.txt","r");
	printf("Nhap so phan tu n: ");scanf("%d",&n);
	printf("Nhap ten can tim: ");fflush(stdin);gets(name);
	if (fp == NULL){
		printf("Loi doc file!");
		exit(-1);
	}
	for (i=0;i<n;i++){
		fgets(ad[i].name,50,fp); chuanhoaxau(ad[i].name);
		fgets(ad[i].tel,30,fp);  chuanhoaxau(ad[i].tel);
		fgets(ad[i].mail,100,fp); chuanhoaxau(ad[i].mail);
		if (feof(fp)){
			break;
		}
	}
	for(i=0;i<n;i++){
		if (strcmp(name,ad[i].name) == 0){
			printf("Ho ten: %s\n",ad[i].name);
			printf("SDT: %s\n",ad[i].tel);
			printf("Mail: %s\n",ad[i].mail);
			break;
		}
		printf("Khong tim thay!\n");
	}
	return 0;
}
