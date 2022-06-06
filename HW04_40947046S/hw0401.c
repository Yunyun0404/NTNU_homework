#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
char test[3]={"int"};
//灰階Gray = 0.299 * Red + 0.587 * Green + 0.114 * Blue
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
}__attribute__ ((packed)) pixel;

void black_1(pixel* a,pixel* b,pixel* c,pixel*d);
void black_2(pixel* a,pixel* b,pixel* c,pixel*d);
void white(pixel* a,pixel* b,pixel* c,pixel*d);
void gray(pixel* a,pixel* b,pixel* c,pixel* d,uint8_t color);


int main( int argc, char *argv[] ){
    FILE* origin_bmp = NULL;
    FILE* layer1_bmp = NULL;
    FILE* layer2_bmp = NULL;
    FILE* overlap_bmp = NULL;
    char input_filename[32]="t";
    char layer1_name[64]="";
    char layer2_name[64]="";
    char overlap_name[64]="";
    char buffer[32]="";

//Open the files
    strcpy(input_filename,argv[1]);

    if( strncmp( &input_filename[ strlen(input_filename)-4 ],".bmp",4) != 0  ){
        printf("Error: The file name extension is not \".bmp\"\n");
        return 0;
    }

    sscanf(input_filename,"%s.bmp",buffer);
    snprintf(layer1_name,sizeof(layer1_name),"%s_layer1.bmp",buffer);
    snprintf(layer2_name,sizeof(layer2_name),"%s_layer2.bmp",buffer);
    snprintf(overlap_name,sizeof(overlap_name),"%s_overlap.bmp",buffer);

    if( (origin_bmp = fopen(input_filename,"rb") ) == NULL){
        printf("open error\n");
        return 0;
    }
    
    if( (layer1_bmp = fopen(layer1_name,"wb") ) == NULL){
        perror("Error");
        return 0;
    }
    if( (layer2_bmp = fopen(layer2_name,"wb") ) == NULL){
        perror("Error");
        return 0;
    }
    if( (overlap_bmp = fopen(overlap_name,"wb") ) == NULL){
        perror("Error");
        return 0;
    }

    sHeader header;
    fread(&header,sizeof(sHeader),1,origin_bmp);
    if(header.bpp != 24){
        printf("Error: The bpp is not 24.\n");
        return 0;
    }
    if(header.bm[0]=='B' && header.bm[1]=='M'){

    }else{
        printf("It's not bmp.\n");
        return 0;
    }
    
    uint32_t h=header.height;
    uint32_t w=header.width;

    int32_t count=0;
    pixel origin_table[h][w];
    count = fread(origin_table,1,sizeof(origin_table),origin_bmp);
    header.height*=2;
    header.width*=2;
    header.bitmap_size*=4;
    header.size=header.bitmap_size+header.offset;
    fwrite(&header,sizeof(sHeader),1,layer1_bmp);
    fwrite(&header,sizeof(sHeader),1,layer2_bmp);
    fwrite(&header,sizeof(sHeader),1,overlap_bmp);

    pixel (*layer1_table)[2*w] = (pixel(*)[2*w])malloc(4*h*w*sizeof(pixel));
    pixel (*layer2_table)[2*w] = (pixel(*)[2*w])malloc(4*h*w*sizeof(pixel));
    pixel (*overlap_table)[2*w] = (pixel(*)[2*w])malloc(4*h*w*sizeof(pixel));
   
    for(uint32_t i=0 ; i<h ; ++i){
        for(uint32_t u=0 ; u<w; ++u){
            uint8_t color=origin_table[i][u].Blue*0.114+origin_table[i][u].Red*0.299+origin_table[i][u].Green*0.587;
            gray(&overlap_table[i*2][u*2],&overlap_table[i*2][u*2+1],&overlap_table[i*2+1][u*2],&overlap_table[i*2+1][u*2+1],color);        
            if(color>127){
                white(&layer1_table[i*2][u*2],&layer1_table[i*2][u*2+1],&layer1_table[i*2+1][u*2],&layer1_table[i*2+1][u*2+1]);
                white(&layer2_table[i*2][u*2],&layer2_table[i*2][u*2+1],&layer2_table[i*2+1][u*2],&layer2_table[i*2+1][u*2+1]);
            }else{
                black_1(&layer1_table[i*2][u*2],&layer1_table[i*2][u*2+1],&layer1_table[i*2+1][u*2],&layer1_table[i*2+1][u*2+1]);
                black_2(&layer2_table[i*2][u*2],&layer2_table[i*2][u*2+1],&layer2_table[i*2+1][u*2],&layer2_table[i*2+1][u*2+1]);
            }
        }
    }

    
    fwrite(overlap_table,1,count*4,overlap_bmp);
    fwrite(layer1_table,1,count*4,layer1_bmp);
    fwrite(layer2_table,1,count*4,layer2_bmp);
    free(layer1_table);
    free(layer2_table);
    free(overlap_table);
    return 0;
}

void black_1(pixel* a,pixel* b,pixel* c,pixel*d){
    a->Blue=255;
    a->Green=255;
    a->Red=255;
    b->Blue=0;
    b->Green=0;
    b->Red=0;
    c->Blue=0;
    c->Green=0;
    c->Red=0;
    d->Blue=255;
    d->Green=255;
    d->Red=255;
}

void black_2(pixel* a,pixel* b,pixel* c,pixel*d){
    a->Blue=0;
    a->Green=0;
    a->Red=0;
    b->Blue=255;
    b->Green=255;
    b->Red=255;
    c->Blue=255;
    c->Green=255;
    c->Red=255;
    d->Blue=0;
    d->Green=0;
    d->Red=0;
}

void white(pixel* a,pixel* b,pixel* c,pixel*d){
    a->Blue=255;
    a->Green=255;
    a->Red=255;
    b->Blue=0;
    b->Green=0;
    b->Red=0;
    c->Blue=0;
    c->Green=0;
    c->Red=0;
    d->Blue=255;
    d->Green=255;
    d->Red=255;
}

void gray(pixel* a,pixel* b,pixel* c,pixel* d,uint8_t color){
    if(color>127){
        a->Blue=255;
        a->Green=255;
        a->Red=255;
        b->Blue=255;
        b->Green=255;
        b->Red=255;
        c->Blue=255;
        c->Green=255;
        c->Red=255;
        d->Blue=255;
        d->Green=255;
        d->Red=255;
    }else{
        a->Blue=0;
        a->Green=0;
        a->Red=0;
        b->Blue=0;
        b->Green=0;
        b->Red=0;
        c->Blue=0;
        c->Green=0;
        c->Red=0;
        d->Blue=0;
        d->Green=0;
        d->Red=0;
    }
}

//maldives.bmp