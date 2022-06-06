#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <unistd.h>
#include <getopt.h>
#include <ctype.h>

void allocate_memory(FILE *,char *,int32_t);
void free_memory(FILE *);
void encode(FILE *);
void decode(FILE *);

int main( int argc, char *argv[] ){
    int32_t c = 0;
    char input[32]={0};
    char struc_name[32]="Test";
    char output[32]="test";
    FILE *pfile=NULL;
    FILE *pfile2=NULL;
    FILE *pfile3=NULL;
    
    while ( ( c = getopt( argc, argv, "i:n:p:" ) ) != -1 ){
        switch( c ){
            case 'i':
                strcpy(input,optarg);
                break;
            case 'n':
                strcpy(struc_name,optarg);
                break;
            case 'p':
                strcpy(output,optarg);
                break;
            case '?':
                printf( "option: ?\n" );
                return 0;
        }
    }
    
    if( (pfile=fopen(input,"r"))==NULL ){
        printf("There isn't the file named: %s\n",input);
        return 0;
    }
 
    char *h_name=calloc( 4100 , sizeof(char) );    
    strncpy(h_name,output,strlen(output) );
    h_name=strcat(h_name,".h");
    char *c_name=calloc( 4100 , sizeof(char) ) ;
    strncpy(c_name,output,strlen(output) );
    c_name=strcat(c_name,".c");

    if( (pfile2 = fopen(h_name,"w") ) == NULL){
        perror("Error");
        return 0;
    }
    if( (pfile3 = fopen(c_name,"w") ) == NULL){
        perror("Error");
        return 0;
    }
    
    int32_t bits[50]={0};
    int32_t new_bit[50]={0};
    char item_name[50][30]={0};
    int32_t cnt=0;
    int32_t len=0;
    int32_t alpha=0;
    int32_t total_mem=0;

    while( !feof(pfile) ){
        char buffer[1025]={0};
        fgets(buffer,1024,pfile);
        if(buffer[0]!='|')continue;
        for(size_t i=1 ; i<strlen(buffer) ; ++i){
            if(buffer[i]=='|'){
                bits[len]=cnt;
                cnt=0;
                alpha=0;
                len++;
            }else{
                if( buffer[i]>='a' && buffer[i]<='z' ){
                    item_name[len][alpha]=buffer[i];
                    alpha++;
                }else if( buffer[i]>='A' && buffer[i]<='Z' ){
                    item_name[len][alpha]=tolower(buffer[i]);
                    alpha++;
                }
                cnt++;
            }
        }
    }

    for(int32_t i=0 ; i<len ; ++i){
        new_bit[i]=bits[i]/2;
        if(new_bit[i]<=8)new_bit[i]=8;
        else if(new_bit[i]<=16)new_bit[i]=16;
        else if(new_bit[i]<=32)new_bit[i]=32;
        else if(new_bit[i]<=64)new_bit[i]=64;
        total_mem+=new_bit[i];
    }

    fprintf(pfile2,"#pragma once\n\n");
    fprintf(pfile2,"#include <stdint.h>\n\n");
    fprintf(pfile2,"typedef struct _s%s\n{\n",struc_name);
    for( int32_t i=0 ; i<len ; ++i ){
        fprintf(pfile2,"    uint%d_t %s;\n",new_bit[i],item_name[i]);
    }
    fprintf(pfile2,"}%s;\n\n",struc_name);
    fprintf(pfile2,"%s * iph_init( void );\n",struc_name);
    fprintf(pfile2,"void iph_free( %s * );\n",struc_name);
    fprintf(pfile2,"int iph_encode( void *, const %s * );\n",struc_name);
    fprintf(pfile2,"int iph_decode( const void *, %s * );\n",struc_name);
    fclose(pfile2);
    fclose(pfile);

    fprintf(pfile3,"#include \"%s\"\n",h_name);
    fprintf(pfile3,"#include <stdlib.h>\n\n");
    fprintf(pfile3,"#include <stdio.h>\n\n");
    
    fprintf(pfile3,"%s * iph_init( void ){\n",struc_name);
    allocate_memory(pfile3,struc_name,total_mem);
    fprintf(pfile3,"}\n\n");

    fprintf(pfile3,"void iph_free( %s * t ){\n",struc_name);
    free_memory(pfile3);
    fprintf(pfile3,"}\n\n");
    
    fprintf(pfile3,"int iph_encode( void * y, const %s *t ){\n",struc_name);
    encode(pfile3);
    fprintf(pfile3,"}\n\n");

    fprintf(pfile3,"int iph_decode( const void * t, %s * y ){\n",struc_name);
    decode(pfile3);
    fprintf(pfile3,"}\n\n");
    
    fclose(pfile3);
    free(h_name);
    free(c_name);
    return 0;
}

void allocate_memory(FILE * stream,char *type,int32_t total_mem){
    fprintf(stream,"    %s * tmp=NULL;\n",type);
    fprintf(stream,"    tmp=malloc(%d);\n",total_mem);
    fprintf(stream,"    return tmp;\n");
}

void free_memory(FILE * stream){
    fprintf(stream,"    free(t);\n");
}

void encode(FILE * stream){
    fprintf(stream,"    printf(\"It's too difficult to answer...\");\n");
    fprintf(stream,"    return 0;\n");
}

void decode(FILE * stream){
    fprintf(stream,"    printf(\"It's too difficult to answer...\");\n");
    fprintf(stream,"    return 0;\n");
}