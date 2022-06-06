#include "key.h"

// 前面不能是英文字母、底線、#、@、.、

struct option long_options[] = {  
     { "linenum" , 0, NULL, 'n' },  
     { "color"   , 0, NULL, 'c' },  
     { "language", 1, NULL, 'l' },
     {  0        , 0,  0  ,  0  },               //規定：最後一定要有這行，表示結束，這是man的規定。
};  

int main( int argc, char *argv[] ){    
    puts( "---" );
    
    // getopt_long
    
    int32_t c=0;
    int32_t index=0;
    int32_t flag_n=0; //上行數
    int32_t flag_c=0; //上色
    char type[32]="c";

    while ( ( c = getopt_long( argc, argv, "ncl:", long_options, &index ) ) != -1 ){
        switch( c ){
            case 'n':
                flag_n=1;
                break;
            case 'c':
                flag_c=1;
                break;
            case 'l':
                strcpy(type,optarg);
                break;
            case '?':
                printf( "option: ?\n" );
                printf("There isn't the option\n");
                return 0;
        }
    }
    FILE * input=NULL;
    input=fopen(argv[argc-1],"r");
    
    if( flag_c==0 && flag_n==0 ){
        //把整個code印出來
        print(input);
    }else if( flag_c==1 && flag_n==1 ){
        //上顏色 && 上行數
        //檢查看哪種語言
        color_line(input,type);
    }else if( flag_c==1 && flag_n==0 ){
        //上顏色
        //檢查看哪種語言
        color(input,type);
    }else if( flag_c==0 && flag_n==1 ){
        line(input);
    }
    return 0;
}