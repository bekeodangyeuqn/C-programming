# include <string.h>
# include <stdio.h>
 
# define NO_OF_CHARS 256 // 256 la so ky tu co the co theo ma ASCII

int count = 0;
 
int max (int a, int b) { return (a > b)? a: b; }
 
/* Ham tien xu ly su dung Boyle Moore bang
 bad character heuristic */
void badCharHeuristic( char *str, int size,
                        int badchar[NO_OF_CHARS])
{
    int i;
 
    // Khoi tao vi tri xuat hien cuoi cung trong pattern cua tat ca ky tu la -1
    for (i = 0; i < NO_OF_CHARS; i++)
         badchar[i] = -1;
 
    // Tim vi tri xuat hien cuoi cung cua ky tu trong pattern
    // Vi du: Ta co pattern "ABCABC" thi vi tri xuat hien cuoi cung cua 'C' la: badchar[14] = 5
    for (i = 0; i < size; i++)
         badchar[(int) str[i]] = i;
}
 
/* Ham tim kiem mau su dung thuat toan Boyer Moore Algorithm
   bang Bad Character Heuristic  */
void search( char *txt,  char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);
 
    int badchar[NO_OF_CHARS];
 
    /* Dien cac vi tri xuat hien cuoi cung cua cac ky tu 
	trong pattern vao trong mang badchar qua ham tien
	xu ly da tao  */
    badCharHeuristic(pat, m, badchar);
 
    int s = 0;  // s bieu dien su dich chuyen cua pattern so voi text
    while(s <= (n - m))
    {
        int j = m-1; // j luc nay la chi so cho ky tu cuoi cung cua pattern
 
        /* Giam chi so j khi ma ky tu tai chi so j cua pattern trung
		voi ky tu tai chi so s+j cua text */
        while(j >= 0 && pat[j] == txt[s+j]){
        	count++;
        	j--;
		}
            
 			
        /* Sau vong lap while o tren, neu j = -1
		thi tuc la tat ca cac ky tu trong pattern deu trung
		khop voi cac ky tu o text tuong ung, ta se dua ra ket
		qua la s */
        if (j < 0)
        {
            printf("\nPattern xuat hien bat dau tai vi tri: %d", s);
 
            /* Sau do ta lai tiep tuc dich pattern sao cho ky
			tu tiep theo cua text trung voi vi tri xuat hien cuoi
			cung cua ky tu do trong pattern
			Dieu kien s+m < n de kiem tra xem pattern co bi
			dich den cuoi text hay khong */
            s += (s+m < n)? m-badchar[txt[s+m]] : 1;
 
        }
 
        else
            /* Neu j >= 0, tuc la xuat hien vi tri khong
			trung khop, ta dich pattern sao cho ky tu khong
			trung khop o text phai trung voi vi tri
			xuat hien cuoi cung cua ky tu do trong pattern.
			Ham max la de chac chan rang pattern duoc dich theo
			thuan, boi neu vi tri xuat hien cuoi cung trong
			pattern cua ky tu nam ben phai ky tu khong trung khop 
			o tren text thi pattren se bi dich theo chieu nguoc lai */
            s += max(1, j - badchar[txt[s+j]]);
    }
}
 
int main()
{
    char txt[] = "abcadacaeeeffaadbfacddedaadbfdfbeccae";
    char pat[] = "aadbf";
    search(txt, pat);
    printf("\nCount: %d",count);
    return 0;
}

