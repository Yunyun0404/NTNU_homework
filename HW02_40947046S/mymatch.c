#include "mymatch.h"
/*
    反省：
    把i跟j搞混
    明明知道要return num卻寫成return 0
    \n跟\0
    處理字串的時候再三思考是否\0
*/
 /*
   const char *tmp = "This string literal is arbitrary";
    int main(int argc, char *argv[]){
    char *ret;
    ret=strstr(tmp, "literal");
    if(ret){
        printf("found substring at address %p\n", ret);
    }
    else{
        printf("no substring found!\n");
    }
    exit(EXIT_SUCCESS);
}
*/
int recursive(char *s,char *p,int i,int j){
    //設定好終點
    if( s[i]=='\0' && p[j]=='\0' )return 1;
    else if( s[i]=='\0' || p[j]=='\0' )return 0;

    //設定遇到?  *  其他
    if( p[j]=='?'){
        return recursive(s,p,i+1,j+1);//遇到?直接跳到下一個
    }else if( p[j]=='*' ){
        for(size_t k=0 ; i+k <= strlen(s) ; ++k){ //請注意反斜線0
            if( recursive(s,p,i+k,j+1) )return 1;
        }
        return 0;
    }

    return (s[i]==p[j]) && recursive(s,p,i+1,j+1);
}

int mymatch(char ***pppList , const char *pStr, const char *pPattern){
    char **pplist = malloc( sizeof(char*)*128 );

    if( pppList==NULL || pStr==NULL || pPattern==NULL ){
        printf("Error input.\n");
        return -1;
    }
    if( strlen(pPattern)==0 ){
        printf("Error input.\n");
        return -1;
    }
    
    uint32_t cnt=0;
    uint32_t num=0;
    char* token = strtok( (char *)pStr , " " );
    char **table= malloc(sizeof(char*)*128);
    while (token != NULL) { 
        table[cnt]=token;
        cnt++;
        token = strtok(NULL, " "); 
    }


    for( size_t i=0 ; i<cnt ; ++i){
        char *s=table[i];
        char *p=(char *)pPattern;
        if( recursive(s,p,0,0) ){
            pplist[num]=table[i];
            num++;
        }
    }

    *pppList=pplist;

    return num;
}
/*
    for(int32_t i=0 ; i<cnt ; ++i){
        //看table[i]
        for( int32_t u=0 ; u>=0 ; ++u ){
            if( pPattern[u]=='*' ){

            }else if( pPattern[u]=='?' ){

            }else{

            }
        }
    }
*/

/*
    因為會有agr***e??a這種測資
    感覺可以一個一個判
    如果是 * ?以外的就直接檢查
    一檢查出不符合就跳到下一個
    如果是 * ?的話就按照規定來
*//*
    char **pplist = malloc( sizeof(char*)*128 )
    char s[3] = '123' 
    pplist[0]  = s                          
*/