#include <stdio.h>
#include <string.h>

int count = 0;

void search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 	int i;
    
    for (i = 0; i <= N - M; i++) {
        int j;
 
    
        for (j = 0; j < M; j++){
        	count++;
        	if (txt[i + j] != pat[j])
                break;
		}
            
 
        if (j == M) 
            printf("Tim thay Pattern tai vi tri: %d \n", i);
    }
}
 

int main()
{
    char txt[] = "abcadacaeeeffaadbfacddedaadbfdfbeccae";
    char pat[] = "aadbf";
    search(pat, txt);
    printf("\nCount: %d",count);
    return 0;
}
