#include<stdio.h>

void replace_char(char *str, char c1, char c2){
if (str == NULL) return;
while (*str != '\0'){
if (*str == c1)
*str = c2;
++str;
}
}

int main(){
	char c1;
	char c2;
	char s[100];
	printf("Type a string: ");scanf("%s",s);
	printf("Char to replace: ");scanf(" %c",&c1);
	printf("Char to replace with: ");scanf(" %c",&c2);
	replace_char(s,c1,c2);
	printf("New string: %s",s);
	return 0;
}

