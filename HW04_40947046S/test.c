#include "test.h"
#include <stdlib.h>

#include <stdio.h>

Test * iph_init( void ){
    Test * tmp=NULL;
    tmp=malloc(216);
    return tmp;
}

void iph_free( Test * t ){
    free(t);
}

int iph_encode( void * y, const Test *t ){
    printf("It's too difficult to answer...");
    return 0;
}

int iph_decode( const void * t, Test * y ){
    printf("It's too difficult to answer...");
    return 0;
}

