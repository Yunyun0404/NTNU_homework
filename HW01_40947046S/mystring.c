#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include "mystring.h"

//finish：strchr 找第一個字元
char* mystrchr(const char* s, int c){
    size_t len=0;
    for(len=0 ; s[len]!=0 ; ++len);
    len++;

    for(size_t i=0 ; i<len ; ++i){
        if(s[i] == c) return (char*)s+i;
    }

    return NULL;
}
//finish：strrchr 找最後一個字元
char* mystrrchr(const char* s, int c){
    size_t len=0;
    for(len=0 ; s[len]!=0 ; ++len);
    len++;

    while(len != -1){
        if(s[len] == c) return (char*)s+len;
        else len--; 
    }

    return NULL;
}
//finish：strspn 找看看連續幾個字符都屬於accept
size_t mystrspn(const char* s, const char* accept){
    size_t ans=0;
    size_t cnt=0;
    size_t len=0;
    for(len=0 ; s[len]!=0 ; ++len);
    len++;
    size_t accept_len=0;
    for(accept_len=0 ; accept[accept_len]!=0 ; ++accept_len);
    accept_len++;

    for(int32_t i=0 ; i<len-1 ; ++i){
        for(int32_t j=0 ; j<accept_len-1 ; ++j){
            if (s[i]==accept[j]) {
                cnt++;
                ans++;
                break;
            }
        }
        if(cnt==0)return ans;
    }
    return ans;
}
//finish：strcspn 找看看第幾個字符在reject
size_t mystrcspn(const char* s, const char* reject){
    size_t ans = 0;
    size_t len=0;
    for(len=0 ; s[len]!=0 ; ++len);
    len++;
    size_t reject_len=0;
    for(reject_len=0 ; reject[reject_len]!=0 ; ++reject_len);
    reject_len++;    
    
    for(int32_t i=0 ; i<len-1 ; ++i){
        for(int32_t j=0 ; j<reject_len-1 ; ++j){
            if(s[i]==reject[j])return i;
        }
    }
    return -1;//打在readme
}
//finish：strpbrk 找看看哪個地方是第一次出現accept的值的位置
char* mystrpbrk(const char* s, const char* accept){
    size_t ans = 0;
    size_t len=0;
    for(len=0 ; s[len]!=0 ; ++len);
    len++;
    size_t accept_len=0;
    for(accept_len=0 ; accept[accept_len]!=0 ; ++accept_len);
    accept_len++;    
    
    for(int32_t i=0 ; i<len-1 ; ++i){
        for(int32_t j=0 ; j<accept_len-1 ; ++j){
            if(s[i]==accept[j])return (char*)s+i;
        }
    }

    return NULL;
}
//finish：strstr 返回找到第一個needle的位置
char* mystrstr(const char* haystack, const char* needle){
    int32_t cnt = 0;
    int32_t needle_len = 0;
    int32_t judge = 0;

    for(needle_len=0 ; haystack[needle_len]!=0 ; ++needle_len);
    needle_len++;


/*    for( cnt=0 ; haystack[cnt+needle_len-1!=0 ; cnt++){

    }
*/
    while(haystack[cnt+needle_len-1]!=0){
        for( int32_t i = 0 ; i<needle_len ; i++ ){
            if( needle[i]!=haystack[cnt+i] ){
                judge=1;
                break;
            }
        }
        if(judge){
            cnt++;
            judge=0;
        }
        else return (char*)&haystack[cnt]; 

    }
    return NULL;
}
//阿...有bug ：strtok 把str這個字串按delim分段，用static。
char* mystrtok(char* str, const char* delim){
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
    separate_ptr=mystrpbrk(remember,delim);

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

        remember=separate_ptr;
        return ans;
    }
}

/*
strtol是啥:

形式  long int mystrtol(const char *nptr, char **endptr , int base);
    base    要用幾進制轉換 (0的話默許是10進位、遇到0x或0X的話則優先用16進位、碰到0前置字元則用8進位)
            (限制:2~36)
    nptr    函式會掃描nptr字串，跳過一開始的字元直到找到'數字'或'正負號'再開始做轉換，
            碰到非數字或\0停止，並把這個位置+1存到endptr。
    endptr  不為null的話，就會將nptr的中止字元傳到endptr，
*/
/*
isupper() 測大寫否
islower() 測小寫否
*/
long int mystrtol(const char *nptr, char **endptr , int base){
    const char *s=NULL;
    char c=0;
    int32_t neg=0;
    int32_t i=1 ;
    long int ans=0;

    s=nptr;
    c=*s;

    while(i){
        if( char_num(c) ){
            break;
        }
        else if ( base>10 && char_eng(c) ){
            break;
        }
        else if( c=='-'){
            neg=1;
            i=0;
        }
        s=s+1;
        c=*s;   
    }

    if( (base==0 || base == 16) && c=='0' && ( *s=='x' || *s=='X' ) && ( ( s[1]>='0' && s[1]<='9' ) || ( s[1]>='A' && s[1]<='F' ) || ( s[1]>='a' && s[1]<='f' ) ) ){
        c=s[1]; 
        s+=2; 
        base=16; 
    }
    if( base==0 )base=10;


    while(1){
        if( char_num(c) ){
            ans*=base;
            ans+=(c-'0');
        }else if( islower(c) && (c-'a'+10)<base ){
            ans*=base;
            ans+=(c-'a'+10);
        }else if( isupper(c) && (c-'A'+10)<base ){
            ans*=base;
            ans+=(c-'A'+10);
        }else{
            break;
        }
        s=s+1;
        c=*s;
    }

    if(neg==1)ans*=-1;
    
    if(endptr!=NULL){
        s=s+1;
        endptr=&s;
    }

    return ans;
}

int char_num(char c){
    if(c>='0' && c<='9')return 1;
    else return 0;
}
int char_eng(char c){
    if( c>='A' && c<='Z' )return 1;
    else if( c>='a' && c<='z' )return 1;
    else return 0;
}
