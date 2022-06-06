#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <unistd.h>
#include <getopt.h>

void en(FILE *,FILE *,const char *);
void de(FILE *,FILE *,const char *);

struct option long_options[] = {  
     { "enc",  2 , NULL, 'e' },  
     { "dec", 2 , NULL, 'd' },  
     { "output", 1, NULL, 'o' },
    // { "duck", 0 ,&flag , 9999}; 
     {  0, 0, 0, 0},
};  

int main( int argc, char *argv[] ){
    const char table[65]={
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
        'O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
        'o','p','q','r','s','t','u','v','w','x','y','z',
        '0','1','2','3','4','5','6','7','8','9','+','/','\0'
    };

    int32_t c = 0;
    int32_t index = 0;
    char encode_name[32]={0};
    char decode_name[32]={0};
    char output_name[32]={0};

    int32_t encode_flag=0;
    int32_t decode_flag=0;

    FILE *encode=NULL;
    FILE *decode=NULL;
    FILE *output=NULL;

    while ( ( c = getopt_long( argc, argv, "e:d:o:", long_options, &index ) ) != -1 ){
        switch( c ){
            case 'e':
                encode_flag=1;
                strcpy(encode_name,optarg);
                break;
            case 'd':
                decode_flag=1;
                strcpy(decode_name,optarg);
                break;
            case 'o':
                strcpy(output_name,optarg);
                break;
            case '?':
                printf("There is no option.\n");
                return 0;
        }
    }
    output=fopen(output_name,"wb");
    
    if(encode_flag==1){

        if( ( encode=fopen(encode_name,"r") ) ==NULL ){
            printf("There isn't the file named: %s\n",encode_name);
            return 0;
        }
        en(encode,output,table);
    
    }else if(decode_flag==1){
        if( ( decode=fopen(decode_name,"r") ) ==NULL ){
            printf("There isn't the file named: %s\n",decode_name);
            return 0;
        }
        de(decode,output,table);
    }else{
        printf("error\n");
    }

    fclose(output);
    return 0;
}

void en(FILE *input,FILE *output,const char *table){
    //把二進位檔寫成txt
    while( !feof(input) ){
        int8_t cnt=0;
        uint8_t buffer[3]={0}; //edit
        cnt=fread(buffer,1,3,input);//edit
        char buf[4]={0};


        if(cnt==3){
            uint8_t one = (buffer[0] & 0b11111100)>>2;
            uint8_t two = ((buffer[0] & 0b00000011)<<4) | ((buffer[1] & 0b11110000)>>4);
            uint8_t three = ((buffer[1] & 0b00001111)<<2) | ((buffer[2] & 0b11000000)>>6);
            uint8_t four = buffer[2] & 0b00111111;
            buf[0]=table[one];
            buf[1]=table[two];
            buf[2]=table[three];
            buf[3]=table[four];

// printf("%hhu %hhu %hhu %hhu\n",one,two,three,four);
// printf("%hhu\n",buffer[0]<<6);
// printf("%hhu\n",(buffer[0]<<6)>>2);            
            
            fwrite(buf,1,4,output);
        }else if(cnt==1){
            uint8_t one = (buffer[0] & 0b11111100)>>2;
            uint8_t two = ((buffer[0] & 0b00000011)<<4) | ((buffer[1] & 0b11110000)>>4);
            
            buf[0]=table[one];
            buf[1]=table[two];
            buf[2]='=';
            buf[3]='=';
            
            fwrite(buf,1,4,output);
        }else if(cnt==2){
            uint8_t one = (buffer[0] & 0b11111100)>>2;
            uint8_t two = ((buffer[0] & 0b00000011)<<4) | ((buffer[1] & 0b11110000)>>4);
            uint8_t three = ((buffer[1] & 0b00001111)<<2) | ((buffer[2] & 0b11000000)>>6);
            
            buf[0]=table[one];
            buf[1]=table[two];
            buf[2]=table[three];
            buf[3]='=';
            
            fwrite(buf,1,4,output);
        }
    }
    fclose(input);
}

void de(FILE *input,FILE *output,const char *table){
    //把txt檔寫成二進位
    while( !feof(input) ){
        int8_t cnt=0;
        char buffer[4]={0}; //edit
        cnt=fread(buffer,1,4,input);//edit
        uint8_t buf[3]={0};
        uint8_t tmp[4]={0};
        int8_t count=0;

        if(cnt==0){
            continue;
        }else if( cnt!=4 ){
            printf("A: It's not base64.\n");
            exit(1);
        }

        for(int8_t i=0 ; i<4 ; ++i){
            if( strchr(table,buffer[i])==NULL && buffer[i]!='=' ){
                printf("B: It's not base64.\n");
                exit(1);
            }else if( buffer[i]!='=' ){
                tmp[i]=strchr(table,buffer[i])-table;
            }else{
                tmp[i]=0;
                count++;
            }
        }

        buf[0]= ((tmp[0] & 0b00111111)<<2) | (( tmp[1] & 0b00110000 )>>4);
        buf[1]= ((tmp[1] & 0b00001111)<<4) | ((tmp[2] & 0b00111100)>>2);
        buf[2]= ((tmp[2] & 0b00000011)<<6) | tmp[3];

        if(count==0){
            fwrite(buf,1,3,output);
        }else if(count==1){
            fwrite(buf,1,2,output);
        }else if(count==2){
            fwrite(buf,1,1,output);
        }else{
            
        }
    }
}
