#include "mystring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
   const char str1[] = "abcde2fghi3jk4l";
   const char str2[] = "34";
   char *ret;

   ret = mystrpbrk(str1, str2);
   if(ret) 
   {
      printf("First matching character: %c", *ret);
   }
   else 
   {
      printf("Character not found");
   }
   
   return(0);
}