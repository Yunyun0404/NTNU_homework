#include "ip.h"
#include <stdlib.h>

#include <stdio.h>

IPH * iph_init( void ){
    IPH * tmp=NULL;
    tmp=malloc(216);
    return tmp;
}

void iph_free( IPH * t ){
    free(t);
}

int iph_encode( void * y, const IPH *t ){
    printf("It's too difficult to answer...");
    return 0;
}

int iph_decode( const void * t, IPH * y ){
    printf("It's too difficult to answer...");
    return 0;
}

