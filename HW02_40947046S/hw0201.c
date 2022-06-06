/*
?    只能，單一個，字元。
*    可以有，可以沒有，可以很多。
*/
#include "mymatch.h"

#define MAXSIZE 8192

int main() {
    char s[MAXSIZE], pat[MAXSIZE];
    printf("Please enter the string:\n");
    while (!fgets(s, MAXSIZE, stdin));
    printf("Please enter the pattern:\n");
    while (!fgets(pat, MAXSIZE, stdin));
    int n = strlen(s);
    
    
    /*
    char **res;
    mymatch(&res, s, pat);
    for(int i = 0; i < n; i++) {
        if(!res[i]) break;
        printf("%s\n", res[i]);
    }
    */
    return 0;
}