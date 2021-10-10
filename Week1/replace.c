void replace(char str[], char replace_what,char replace_with){
int i;
for (i = 0; str[i] != '\0'; ++i){
if (str[i] == replace_what) str[i] = replace_with;
}
}

#define STRING_LEN 100

int main(void){
char str[STRING_LEN + 1];
char replace_what, replace_with, tmp;

printf("Please enter a string (no spaces)\n");
scanf("%100s", str);

printf("Letter to replace: ");
scanf(" %c", &replace_what);

printf("Letter to replace with: ");
scanf(" %c", &replace_with);

replace(str, replace_what, replace_with);
printf("The result: %s\n", str);
return 0;
}


