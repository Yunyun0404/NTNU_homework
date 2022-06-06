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
    uint16_t	bpp;
    uint32_t	compression;
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

int main(){
    FILE* origin_bmp = NULL;
    FILE* output_bmp = NULL;
    char input_filename[32] = "";
    char output_filename[32] = "";
    
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
    printf("please enter the center: ");
    if( scanf("(%d,%d)",&x,&y)!=2 ){
        printf("Your input is a little weird.\n");
        return 0;
    }
    printf("please enter the radius: ");
    if( scanf("%d",&r)!=1 ){
        printf("Your input is a little weird.\n");
        return 0;
    }
    
    if(r<0){
        printf("r needs to be positive integer.\n");
        return 0;
    }

    sHeader header;
    fread(&header,sizeof(sHeader),1,origin_bmp);
    if(header.bpp != 24){
        printf("Error: The bpp is not 24.\n");
        return 0;
    }
    if( header.bm[0]=='B' && header.bm[1]=='M' ){

    }else{
        printf("Oh...it's not bmp.\n");
        return 0;
    }

    fwrite(&header,sizeof(sHeader),1,output_bmp);

    BYTE table[header.height][header.width];
    int32_t count=0;

    count = fread(table,1,sizeof(table),origin_bmp);
    y=header.height-1-y;

    for(int32_t i=0 ; i<header.height ; ++i){
        for(int32_t u=0 ; u<header.width ; ++u){
            if( (i-y)*(i-y)+(u-x)*(u-x)> r*r ){
                table[i][u].Blue=255;
                table[i][u].Green=255;
                table[i][u].Red=255;
            }
        }
    }

    fwrite(table,1,count,output_bmp);

    return 0;
}

//maldives.bmp