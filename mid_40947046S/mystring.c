#include "mystring.h"
#include <string.h>

char *mystrtok_r(char *str, const char *delim , char **saveptr){
    char* ans=NULL;
    static char* remember=NULL;  //用static是關鍵!by chen
    char* separate_ptr=NULL;
    int32_t isEnd=1;
    int32_t cnt=0;
    
    if( remember==NULL ){
        if( str!=NULL )remember=str;
        else return NULL;
    }

    ans=remember;
    separate_ptr=strpbrk(remember,delim);

    if( separate_ptr==NULL ){
        remember=NULL;
        return ans;
    }else{
        isEnd=0;
        while(!isEnd){
            isEnd=1;
            *(separate_ptr)=0;
            separate_ptr++;
            while( delim[cnt]!=0 ){
                    if( *(separate_ptr)==delim[cnt] ){
                        isEnd=0;
                        break;
                    }
                    cnt++;
            }
            cnt=0;
        }

        *saveptr=remember;
        remember=separate_ptr;
        return ans;
    }
}