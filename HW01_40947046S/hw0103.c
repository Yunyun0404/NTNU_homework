/*
strtol是啥:

形式  long int mystrtol(const char *nptr, char **endptr , int base);
    base    要用幾進制轉換 (0的話默許是10進位、遇到0x或0X的話則優先用16進位、碰到0前置字元則用8進位)
            (限制:2~36)
    nptr    函式會掃描nptr字串，跳過一開始的字元直到找到'數字'或'正負號'再開始做轉換，
            碰到非數字或\0停止，並把這個位置+1存到endptr。
    endptr  不為null的話，就會將nptr的中止字元傳到endptr，
*/

#include "mystring.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
   char str[30] = "2030300 This is test";
   char **ptr;
   long ret;

   ret = mystrtol(str, ptr, 10);
   printf("ret:%ld\n",mystrtol(str, ptr, 10));
   printf("The number(unsigned long integer) is %ld\n", ret);
   printf("String part is |%c|", *ptr);

   return(0);
}

/*
int main(){
    char a[]="1000000000 gr";
    char b[]="1000000000 hr";
    char c[]="ffff hr";
    char **ptr;
    printf("a=%d\n",mystrtol(a,ptr,10));
    printf("%s\n",*ptr);
    printf("b=%d\n",mystrtol(b,ptr,2));
    printf("c=%d\n",mystrtol(c,NULL,16));
    return 0;
}
*/