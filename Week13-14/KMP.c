# include <string.h>
# include <stdio.h>

int count = 0;

	// Timh tien to - hau to dai nhat
void computeLPSArray(char* pat, int M, int* lps)
{
    //  k la do dai cua tien to hau to truoc do
    int k = 0;
  
    lps[0] = 0; // lps[0] luon bang 0
  
    // vong lap de tinh lps voi 
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[k]) {
            k++;
            lps[i] = k;
            i++;
        }
        else 
        {
            
            if (k != 0) {
                k = lps[k - 1];
  
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
  
    int lps[M];
  
    
    computeLPSArray(pat, M, lps);
  
    int i = 0; // chi so cho txt
    int j = 0; // chi so cho pat
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
            count++;
        }
  
        if (j == M) {
            printf("Tim thay Pattern tai vi tri: %d\n", i - j);
            j = lps[j - 1];
        }
  
        // Neu khong trung o vi tri j cua pattern
        else if (i < N && pat[j] != txt[i]) {
            
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main()
{
    char txt[] = "abcadacaeeeffaadbfacddedaadbfdfbeccae";
    char pat[] = "aadbf";
    KMPSearch(pat, txt);
    printf("\nCount: %d",count);
    return 0;
}
