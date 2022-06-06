#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

//檢討：eof讀到之後還會再讀一次 by chen 神奇= =
int check(sHeader Header);

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
}__attribute__ ((packed)) pixel;

int main(){
    FILE* image_file = NULL;
    FILE* text_file = NULL;
    char image_filename[32] = "";
    char text_filename[32] = "";
    int32_t m=0,n=0,image_cnt=0;

//Open the image file
    printf("Please enter the input image name: ");
    fgets(image_filename,31,stdin);
    *( strchr(image_filename,'\n') )=0;
    
    if( strncmp( &image_filename[ strlen(image_filename)-4 ],".bmp",4) != 0 ){
        printf("Error: The file name extension is not \".bmp\"\n");
        return 0;
    }

    if( (image_file = fopen(image_filename,"rb") ) == NULL){
        printf("open error\n");
        return 0;
    }
//read header
    sHeader header;
    fread(&header,sizeof(sHeader),1,image_file);
    if( check(header) )return 0;

//Open the text file
    printf("Please enter the text file name: ");
    fgets(text_filename,31,stdin);
    *( strchr(text_filename,'\n') )=0;

    if( (text_file = fopen(text_filename,"rb") ) == NULL){
        printf("open error\n");
        return 0;
    }

    if ( fscanf(text_file,"%d %d",n,m)==2 ){

    }else{
        printf("input error\n");
        return 0;
    }
    if( fscanf(text_file,"%d",image_cnt)==1 ){
        if(image_cnt==0){
            printf("0 is error input.\n");
            return 0;
        }
    }else{
        printf("open error\n");
        return 0;
    }

    int32_t *array=malloc( m*n*sizeof(int32_t) );
//
    printf("Please enter the (m,n): ");
    fscanf
    
//    
    
//input
    



    return 0;
}

int check(sHeader header){
    if(header.bpp != 24){
        printf("Error: The bpp is not 24.\n");
        return 1;
    }
    if(header.bm[0]=='B' && header.bm[1]=='M'){

    }else{
        printf("OH...it's not BMP image.\n");
        return 1;
    }
    return 0;
}