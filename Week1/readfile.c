#include<stdio.h>

int main(){
	FILE *fin;
	char *filename = "samplefile.txt";
	if (fin = fopen(filename,"r") == NULL){
		printf("Can't open the file!");
	}
	char *buff[2];
	int i;
	for (i=0;i<2;i++){
		fgets(buff[i],100,fin);
		printf("%s\n",buff[i]);
	}
	return 0;
}
