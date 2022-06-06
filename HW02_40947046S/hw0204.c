#include "mix.h"

/*
    要記著前面的op
    tmp=1;

    第二個op如果是+或-
    如：a-b+c
    那就算前面的運算
    也就是tmp=a-b
    然後存到sum裡面
    也就是sum=sum+tmp
    式子就會變成sum+c
    同時把op更新成這個+或-

    第二個op如果是*或/
    如a-b*c
    那就算後面的這個運算
    也就是tmp=b*c
    同時把op更新成*

*/
int main(){
    char buffer[4096]={0};
    char *ptr=buffer;
    sMixedNumber table[1024];
    int32_t cnt=0;
    char oper=0;
    
    fgets(buffer,4095,stdin);
    buffer[strlen(buffer)-1]=0;

    // \frac{}
    for(size_t i=0 ; i<4096 ; ++i){
        if( buffer[i]>='0' && buffer[i]<='9' && buffer[i+1]=='\\' ){
            table[cnt].a = buffer[i]-'0';
        }else if( buffer[i]=='\\' ){
            i+=4;
        }else if( buffer[i]=='{' || buffer[i]=='}' || buffer[i]==')' ){

        }else if( buffer[i]=='(' || buffer[i+1]=='-' ){
            //負帶分數的狀況 (-a\frac{b}frac{c})

        }else if( buffer[i]=='f' || buffer[i]=='r' || buffer[i]=='a' || buffer[i]=='c'){

        }else if( buffer[i-1]=='{' && buffer[i-2]=='}'){
            table[cnt].c = buffer[i]-'0';
            cnt++;
        }else if ( buffer[i-1]=='{' && buffer[i+1]=='}' ){
            table[cnt].b = buffer[i]-'0';
        }

    }
/*
        table[i].a = (int32_t)strtol(buffer,&ptr,10);
        sscanf (buffer,"\\frac{%d}{%d}",&table[i].b,&table[i].c);
        printf("a:%d,b:%d,c:%d\n",table[i].a,table[i].b,table[i].c);
*/

    return 0;
}

/*
int mixed_set( sMixedNumber *pNumber , int32_t a, int32_t b,int32_t c){
	if(c==0 && b!=0)return -1;
	if(c<b)return -1;
	if((a!=0) && (b<0))return -1;
	if(b==0 && c==0){
		pNumber->a=a;
		pNumber->b=0;
		pNumber->c=1;
	}
	else{
	pNumber->a=a;
	pNumber->b=b;
	pNumber->c=c;
	}
	
	return 0;
}
// return -1 if invalid; otherwise , return 0.
*/