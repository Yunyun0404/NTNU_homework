#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

typedef struct {
    char		bm[2];
    uint32_t	size;
    uint32_t	reserve;
    uint32_t	offset;
    uint32_t	header_size;
    uint32_t	width;
    uint32_t	height;
    uint16_t	planes;
    uint16_t	bpp;
    uint32_t	compression;
    uint32_t	bitmap_size;
    int32_t	    hres;
    int32_t	    vres;
    uint32_t	used;
    uint32_t	important;
}__attribute__ ((packed)) sHeader;

typedef struct tagRGBQUAD {
    uint8_t Blue;
    uint8_t Green;
    uint8_t Red;
}__attribute__ ((packed)) pixel;

pixel top_left;
pixel top_right;
pixel bot_left;
pixel bot_right;
int32_t height=768,width=1024;

pixel linear( double y , double x ){
    pixel R1,R2,tmp;
    R1.Red  = ( (width-1-x) / (width-1) ) * bot_left.Red   + ( x / (width-1) ) * bot_right.Red;
    R1.Green= ( (width-1-x) / (width-1) ) * bot_left.Green + ( x / (width-1) ) * bot_right.Green;
    R1.Blue = ( (width-1-x) / (width-1) ) * bot_left.Blue  + ( x / (width-1) ) * bot_right.Blue;

    R2.Red  = ( (width-1-x) / (width-1) ) * top_left.Red   + ( x / (width-1) ) * top_right.Red;
    R2.Green= ( (width-1-x) / (width-1) ) * top_left.Green + ( x / (width-1) ) * top_right.Green;
    R2.Blue = ( (width-1-x) / (width-1) ) * top_left.Blue  + ( x / (width-1) ) * top_right.Blue;

    tmp.Red  =( (height-1-y) / (height-1) )*R1.Red   + ( ( y / (height-1) )*R2.Red );
    tmp.Green=( (height-1-y) / (height-1) )*R1.Green + ( ( y / (height-1) )*R2.Green );
    tmp.Blue =( (height-1-y) / (height-1) )*R1.Blue  + ( ( y / (height-1) )*R2.Blue );
    return tmp;
}

int32_t help=0;

struct option long_options[]={  
     { "", 2 , NULL, 'w' },  
     { "", 2 , NULL, 'h' },  
     { "", 1 , NULL, 'o' },
     { "help" , 0 , &help , 1 },
     {  0, 0, 0, 0},               //規定：最後一定要有這行，表示結束，這是man的規定。
};  

int main( int argc, char *argv[] ){
    char file_name[32]={0};
    FILE *output=NULL;
    
    int32_t c = 0;
    int32_t index = 0;

    strcpy(file_name,"output.bmp");
    while ( ( c = getopt_long( argc, argv, "w:h:o:", long_options, &index ) ) != -1 ){
        switch( c ){
            case 'w':
                width=atoi(optarg);
                break;
            case 'h':
                height=atoi(optarg);
                break;
            case 'o':
                strcpy( file_name , optarg);
                break;
            case '?':
                printf("unknown opt\n");
                return 0;
        }
    }

    pixel table[height][width];

    if(help){
        printf("  Usage:\n");
        printf("     ./fin01 [options]\n");
        printf("        -w: the width of the output figure. (Default: 1024)\n");
        printf("        -h: the height of the output figure. (Default: 768)\n");
        printf("        -o: the output file name. (Default:output.bmp)\n");
        printf("        --help: this message.\n");
        return 0;
    }

    if( (output=fopen(file_name,"wb"))==NULL ){
        printf("open error\n");
        return 0;
    }

//height=768,width=1024
    printf("Please enter (R,G,B) in the top left pixel: ");
    scanf("%hhu%hhu%hhu" ,&table[height-1][0].Red   , &table[height-1][0].Green   , &table[height-1][0].Blue);
    getchar();
    printf("Please enter (R,G,B) in the top right pixel: ");
    scanf("%hhu%hhu%hhu" ,&table[height-1][width-1].Red , &table[height-1][width-1].Green , &table[height-1][width-1].Blue);
    getchar();
    printf("Please enter (R,G,B) in the bottom left pixel: ");
    scanf("%hhu%hhu%hhu" ,&table[0][0].Red      , &table[0][0].Green      , &table[0][0].Blue);
    getchar();
    printf("Please enter (R,G,B) in the bottom right pixel: ");
    scanf("%hhu%hhu%hhu" ,&table[0][width-1].Red    , &table[0][width-1].Green    , &table[0][width-1].Blue);
    getchar();
    
    top_left  = table[height-1][0];
    top_right = table[height-1][width-1];
    bot_left  = table[0][0];
    bot_right = table[0][width-1];
// printf("1023 0   :%hhu %hhu %hhu\n",table[1023][0].Red   , table[1023][0].Green  , table[1023][0].Blue);
// printf("1023 767 :%hhu %hhu %hhu\n",table[1023][767].Red , table[1023][767].Green, table[1023][767].Blue);
// printf("0 0      :%hhu %hhu %hhu\n",table[0][0].Red      , table[0][0].Green     , table[0][0].Blue);
// printf("0 767    :%hhu %hhu %hhu\n",table[0][767].Red    , table[0][767].Green   , table[0][767].Blue);

    sHeader header;
    header.bm[0]='B';
    header.bm[1]='M';
    header.size=54+height*width*3;
    header.reserve=0;
    header.offset=54;
    header.header_size=40;
    header.width=width;
    header.height=height;
    header.planes=1;
    header.bpp=24;
    header.compression=0;
    header.bitmap_size=width*height*3;
    header.hres=5000;
    header.vres=5000;
    header.used=0;
    header.important=0;
    fwrite(&header,sizeof(sHeader),1,output);

    for(int32_t i=0 ; i<height ; ++i){
        for(int32_t j=0 ; j<width ; ++j){
            table[i][j]=linear(i,j);
        }
    }

    fwrite(table,3,width*height,output);

    fclose(output);
    printf("Done\n");

    return 0;
}
