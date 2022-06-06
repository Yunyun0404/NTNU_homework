#include "mystring.h"

int main(){
    char str[]="asdsasdsa";
    const char key='s';
    char *token=NULL;
    char * list[20];
    token = mystrtok_r(str,&key,list);
    while( token != NULL ) {
        printf( "%s\n", token );
        token = mystrtok_r(NULL,&key,list);
   }

}