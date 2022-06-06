/*題目：
讀入一串字串，此字串會以00作結，如果沒有就報錯。
如果這個字串是奇數也要報錯。
這串字串是16進位的字串，其中要能接受大小寫。
此字串的轉換方式是反過來，所以四個四個讀
/
/想法：
例如吃到8這個字元：char a=8
我讓 a&1
這樣我就能得到最低位的位數
把這個位數記起來
然後a>>1 (除以10)

重複做8次
就能抓出新ㄉ位元順序
你覺得可行ㄇ
/
*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

int reverseBit(int old){
    int new = 0;
    int i = 8;
    while(i-->0){
        new = new*2 + (old&1);
        old>>=1;
    }
    return new;
}

/*    
    char table[10000]={0};
    char new_table[10000]={0};
    char ans[5000]={0};
    int32_t lenth=0;

    printf("Please enter thw hex string: ");
    fgets(table,9999,stdin);
    lenth=strlen(table);

    if(lenth%2==0){
        printf("The string's lenth is odd number.\n");
        return 0;
    }

    if(table[lenth-2]=='0' && table[lenth-3]=='0'){

    }
    else{
        printf("The end of string isn't '00'.\n");
        return 0;
    }

//現在先把位元換過來
//printf("---\n");
    for(size_t i=0 ; i<lenth-3 ; ++i){
        int temp = reverse(table[i]);
        new_table[i] = temp;
        printf("%d\n",temp);
    }

*/
/*for(size_t i=0 ; i<lenth ; i++){
printf("%c",new_table[i]);
}
printf("\n");
*/
//陣列中，1/2互換值，3/4互換值。
 /*   for(size_t i=0 ; i<lenth-3 ; i+=2){
        char tmp=new_table[i];
        new_table[i]=new_table[i+1];
        new_table[i+1]=tmp;
    }
    */
//把1/2代表ㄉ字元記下來，3/4代表ㄉ字元記下來......
    /*
    for( size_t i=0 ; i<lenth ; i+=2 ){
        int32_t tmp=new_table[i]*10;
        ans[i]= tmp+new_table[i+1];
    }
*/
//把陣列裡面的字元印出來
/*
    for(size_t i=0 ; i<lenth ; i+=2){
        printf("%c",ans[i]);
    }
*/

int getValue(char c){
    if(c>='0' && c<='9')return c-'0';
    else if(c>='A' && c<='F')return c-'A'+10;
    else if(c>='a' && c<='f')return c-'a'+10;
    else{
        return -1;
    }
}

int main(){
    char table[10000]={0};
    char new_table[10000]={0};
    int length = 0;
    
    printf("Please enter the hex string: ");
    fgets(table,9999,stdin);
    length=strlen(table);

    if (length%2==0){
        printf("The string's lenth is odd number.\n");
        return 0;
    }
    
    if (table[length-2]=='0' && table[length-3]=='0'){
        for ( int i=0 ; i<length-2 ; i+=2 ){
            int tmp =getValue(table[i])*16+getValue(table[i+1]);
            int tmp2=reverseBit(tmp);
            new_table[i/2]=(char)(tmp2);
        }
        printf("%s\n",new_table);
    }
    
    else{
        printf("The end of string isn't '00'.\n");
        return 0;
    }
}