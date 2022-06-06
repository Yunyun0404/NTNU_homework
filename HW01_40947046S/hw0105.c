#include "mysplit.h"

int main(){
    char ***ppplist;
    int pCounter=0;
    const char pStr="123456789a21345a87921a56a3212342a";
    const char pSeparator='a';

    mystrsplit(**pppList ,&pCounter, pStr , &pSeparator );
    printf("pcounter:%d\n",pCounter);
    return 0;
}