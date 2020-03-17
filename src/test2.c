/* fgetwc example */
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
    FILE *fin;
    FILE *fout;
    wint_t wc;
    fin = fopen("in.txt", "r");
    fout = fopen("out.txt", "w+");
    while ((wc = fgetwc(fin)) != WEOF)
    {
        fputwc(wc, fout);
    }
    fclose(fin);
    fclose(fout);
    printf("File has been created...\n");
    return 0;
}