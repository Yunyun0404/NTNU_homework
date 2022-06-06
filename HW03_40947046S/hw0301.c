#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#define red  "\033[31m"
#define none "\033[m"

struct _line{
    int32_t chap;
    int32_t verse;
    char text[512];
    char book_id[10];
}__attribute__ ((__packed__));//這行很重要

typedef struct _line line;

void print(uint32_t *cnt,line record[]);

//{"chapter":1,"verse":1,"text":"In the beginning God created the heavens and the earth.","translation_id":"ASV","book_id":"Gen","book_name":"Genesis"}
//來自戀雪的知識：fgets可以讀一行阿，他會讀到\n後再塞一個\0

int main(){
    char target[1024]={0};
    char buffer[1024]={0};
    uint32_t cnt=0;
    line *record=malloc(32768*sizeof(line));
    FILE *pFile = NULL;
    
    if( ( pFile = fopen( "bible.txt", "rb" ) ) == NULL ){
        printf( red"File could not be opened!\n"none );
        return 0;
    }
    printf("Please enter the search target: ");
    fgets(target,1023,stdin);
    target[ strlen(target)-1 ]=0;
    
    while(!feof(pFile)){
        char *s=NULL;
        char *pointer=NULL;
        fgets(buffer,1023,pFile);
        buffer[strlen(buffer)-1]=0;
        s=strcasestr(buffer,target);
        if(s!=NULL){
            if(buffer[12]>='0' && buffer[12]<='9'){
                record[cnt].chap=(buffer[11]-'0')*10+buffer[12];
                if(buffer[23]>='0' && buffer[23]<='9'){
                    record[cnt].verse=(buffer[22]-'0')*10+buffer[23];
                }else record[cnt].verse=buffer[22]-'0';
            }else{
                record[cnt].chap=buffer[11]-'0';
                if(buffer[22]>='0' && buffer[22]<='9'){
                    record[cnt].verse=(buffer[21]-'0')*10+buffer[22];
                }else record[cnt].verse=buffer[21]-'0';
            }
            
            s=strcasestr(buffer,"text");
            s=s+7;
            for(int32_t i=0 ; i<256 ; ++i){
                if( *(s+i) != '\"' ){
                    record[cnt].text[i] = *(s+i);
                }else{
                    record[cnt].text[i] = '\0';
                    break;
                }
            }
            s=strcasestr(buffer,"book_id");
            s=s+10;
            for(int32_t i=0 ; i<256 ; i++){
                if( *(s+i) != '\"'){
                    record[cnt].book_id[i] = *(s+i);
                }else{
                    record[cnt].book_id[i] = '\0';
                    break;
                }
            }
            cnt++;
        }
    }

    print(&cnt,record);
    free(record);
    fclose(pFile);
    return 0;
}

void print(uint32_t *cnt,line record[]){
    printf("Found %d time(s)\n",*cnt);
    for(int32_t i=0 ; i<*cnt ; ++i){
        printf("%u. %s %d:%d %s\n",i+1,record[i].book_id,record[i].chap,record[i].verse,record[i].text);
    }
}