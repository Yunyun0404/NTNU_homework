#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

//檢討：eof讀到之後還會再讀一次 by chen 神奇= =

typedef struct {
    char		bm[2];
    uint32_t	size;
    uint32_t	reserve;
    uint32_t	offset;
    uint32_t	header_size;
    uint32_t	width;
    uint32_t	height;
    uint16_t	planes;
    uint16_t	bpp;         //改16 色深
    uint32_t	compression; //改成3
    uint32_t	bitmap_size;
    uint32_t	hres;
    uint32_t	vres;
    uint32_t	used;
    uint32_t	important;
}__attribute__ ((packed)) sHeader;

typedef struct tagRGBQUAD {
    uint8_t Blue;
    uint8_t Green;
    uint8_t Red;
}__attribute__ ((packed)) BYTE;

typedef struct _plate{
    uint32_t    r;
    uint32_t    g;
    uint32_t    b;
    uint32_t    a;
}__attribute__ ((packed)) plate;

int main(){
    FILE* origin_bmp = NULL;
    FILE* output_bmp = NULL;
    char input_filename[32] = "";
    char output_filename[32] = "";
    const plate mask={.r=0b1111100000000000,.g=0b0000011111100000,.b=0b0000000000011111,.a=0b0000000000000000};
    int32_t x=0,y=0,r=0;

//Open the files
    printf("Please enter the input image name: ");
    fgets(input_filename,31,stdin);
    input_filename[ strlen(input_filename)-1 ] = 0;
    printf("Please enter the output image name: ");
    fgets(output_filename,31,stdin);
    output_filename[strlen(output_filename) - 1] = 0;

    if( strncmp( &input_filename[ strlen(input_filename)-4 ],".bmp",4) != 0 || strncmp( &output_filename[ strlen(output_filename)-4 ],".bmp",4) != 0 ){
        printf("Error: The file name extension is not \".bmp\"\n");
        return 0;
    }

    if( (origin_bmp = fopen(input_filename,"rb") ) == NULL){
        printf("open error\n");
        return 0;
    }
    
    if( (output_bmp = fopen(output_filename,"wb") ) == NULL){
        perror("Error");
        return 0;
    }

//input
    sHeader header;
    fread(&header,sizeof(sHeader),1,origin_bmp);
    if(header.bpp != 24){
        printf("Error: The bpp is not 24.\n");
        return 0;
    }
    header.bpp        = 16;
    header.compression= 3;
    header.offset     += sizeof(mask);
    header.bitmap_size= header.bitmap_size/24*16;
    header.size       = header.bitmap_size+header.offset;
    fwrite(&header,sizeof(sHeader),1,output_bmp);
    fwrite(&mask  ,sizeof(mask)   ,1,output_bmp);

    BYTE table[header.height][header.width];
    uint16_t array[header.height][header.width];

    int32_t count=0;
    count = fread(table,1,sizeof(table),origin_bmp);

    for(int32_t i=0 ; i<header.height ; ++i){
        for(int32_t u=0 ; u<header.width ; ++u){
            uint16_t new_r = table[i][u].Red;
            uint16_t new_g = table[i][u].Green;
            uint16_t new_b = table[i][u].Blue;

            new_r<<=8;
            new_g<<=3;
            new_b>>=3;
            array[i][u] = (new_r&mask.r) | (new_g&mask.g) | (new_b&mask.b);
        }
    }
    
    fwrite(array,1,count,output_bmp);
    printf("Done Done Done QwQ\n");
    return 0;
}

//maldives.bmp