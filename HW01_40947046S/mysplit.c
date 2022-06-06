#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*
pppList      分割完的東西存這
pCounter     分割完剩下幾個東c
pStr         欲分割字串
pSeparator   欲分割字元
*/

int mystrsplit(char ***pppList , int *pCounter , const char *pStr, const char *pSeparator){
    int32_t cnt=0;
    char* token = strtok(pStr, pSeparator); 
 
    while (token != NULL) {
        cnt++; 
        token=strtok(NULL, pSeparator); 
    } 
    pCounter=cnt;
    printf("cnt:%d\n",cnt);

    if(pStr=='0')return -1;

    return 0;
}