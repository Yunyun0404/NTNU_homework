#include "fun.h"

char stream_name[10][32]={0};
int32_t file_cnt=0;
char *pfile[10]={NULL};
data * Data[10]={NULL};
int32_t fd[10]={0};
struct stat file_stat[10];
off_t size[10]={0};

struct option long_options[] = {  
     { "" , 0 , NULL , 'h' },  //help  
     { "" , 1 , NULL , 't' },  //title tag
     { "" , 1 , NULL , 'T' },  //track tag
     { "" , 1 , NULL , 'a' },  //artist tag
     { "" , 1 , NULL , 'A' },  //album tag
     { "" , 1 , NULL , 'y' },  //year tag
     { "" , 1 , NULL , 'c' },  //comment tag
     { "" , 1 , NULL , 'g' },  //genre tag
     { "" , 0 , NULL , 'l' },  //list an ID3 tag
     { "" , 0 , NULL , 'd' },  //Deletes an ID3 tag
     {  0 , 0 ,   0  ,  0  },  //規定：最後一定要有這行，表示結束，這是man的規定。
};  

int main( int argc, char *argv[] ){
    int32_t c = 0;
    int32_t index = 0;
    
    int8_t flag_help=0;
    int8_t flag_title=0; //125開始30byte
    int8_t flag_track=0;
    int8_t flag_artist=0;//接在title後面30byte
    int8_t flag_album=0;//接在artist後面30byte
    int8_t flag_year=0;//接在album後面4byte
    int8_t flag_comment=0;//接在year的後面30byte，第29byte為1代表第30byte會有track的數字
    int8_t flag_genre=0;//最後一個byte
    int8_t flag_list=0;
    int8_t flag_deletes=0;
    uint8_t int_genre=0;
    uint8_t int_track=0;

    char edit[32]={0};

    while ( ( c = getopt_long( argc, argv, "ht:T:a:A:y:c:g:ld", long_options, &index ) ) != -1 ){
        switch( c ){
            case 'h':
                flag_help=1;
                break;
            case 't':
                flag_title=1;
                strcpy(edit,optarg);
                break;
            case 'T':
                flag_track=1;
                int_track=atoi(optarg);
                break;
            case 'a':
                flag_artist=1;
                strncpy(edit,optarg,strlen(optarg));
                break;
            case 'A':
                flag_album=1;
                strncpy(edit,optarg,strlen(optarg));
                break;
            case 'y':
                flag_year=1;
                strncpy(edit,optarg,strlen(optarg));
                break;
            case 'c':
                flag_comment=1;
                strncpy(edit,optarg,strlen(optarg));
                break;
            case 'g':
                flag_genre=1;
                int_genre=atoi(optarg);
                break;
            case 'l':
                flag_list=1;
                break;
            case 'd':
                flag_deletes=1;
                break;    
            case '?':
                printf( "option: ?\n" );
                break;
        }
    }

    if(flag_help){
        help();
        return 0;
    }

    if( flag_list==0 && flag_deletes==0 ){
        for( int32_t i = 3 ; i < argc ; ++i ){
            file_cnt++;
            strcpy( stream_name[i-3],argv[i] );
        }
    }else{
        for(int32_t i=2 ; i<argc ; ++i){
            file_cnt++;
            strcpy( stream_name[i-2],argv[i] );
        }
    }

    //open
    for(int32_t i=0 ; i<file_cnt ; ++i){
        fd[i]=open( stream_name[i],O_RDWR );

        if(fd[i]==-1){
            printf("104:open file:%s error\n",stream_name[i]);
            return 0;
        }

        fstat( fd[i], &file_stat[i] );
        size[i]=file_stat[i].st_size;
        pfile[i]=mmap( 0 , size[i] , PROT_READ | PROT_WRITE,MAP_SHARED , fd[i] , 0 );
        Data[i]=(data *)(pfile[i]+size[i]-128);
    }

    //end
    for(int32_t i=0 ; i<file_cnt ; ++i){
        //檢查每個檔案是否都具備tag，有的話在名為tag的array填1，沒有則填0。
        if( strncmp(Data[i]->tag,"TAG",3)==0 ){

        }else{
            //int ftruncate(int fd, off_t length);
            /*函数说明：ftruncate()会将参数fd指定的文件大小改为参数length指定的大小。
              参数fd 为已打开的文件描述词，而且必须是以写入模式打开的文件。
              如果原来的文件大小比参数length 大，则超过的部分会被删去。
            */
           munmap(pfile[i],size[i]);
           ftruncate(fd[i],size[i]+128);
           
           if( fd[i]==-1 ){
               printf("open file: %s error\n",stream_name[i]);
               return 0;
           }

           fstat( fd[i],&file_stat[i] );
           size[i]=file_stat[i].st_size;
           pfile[i]=mmap( 0 , size[i] , PROT_READ | PROT_WRITE,MAP_SHARED , fd[i] , 0 );
           Data[i]=(data *)(pfile[i]+size[i]-128);
           memcpy(Data[i]->tag,"TAG",3);
           
           Data[i]->genre=255;
        }
    }

    if(flag_list){
        list();
        return 0;
    }else if(flag_deletes){//刪除所有tag
        delete();
        return 0;
    }

    if(flag_track){
        for(int32_t i=0 ; i<file_cnt ; ++i){
            Data[i]->track=int_track;
        }
    }else if(flag_title){
        for(int32_t i=0 ; i<file_cnt ; ++i){
            for(int32_t u=0 ; u<30 ; ++u) Data[i]->title[u]=0;
            strncpy( Data[i]->title , edit , 30 );
        }
    }else if(flag_artist){
        for(int32_t i=0 ; i<file_cnt ; ++i){
            for(int32_t u=0 ; u<30 ; ++u) Data[i]->artist[u]=0;
            strncpy( Data[i]->artist , edit , 30 );
        }
    }else if(flag_album){
        for(int32_t i=0 ; i<file_cnt ; ++i){
            for(int32_t u=0 ; u<30 ; ++u) Data[i]->album[u]=0;
            strncpy( Data[i]->album , edit , 30 );
        }
    }else if(flag_year){
        for(int32_t i=0 ; i<file_cnt ; ++i){
            for(int32_t u=0 ; u<4 ; ++u) Data[i]->year[u]=0;
            strncpy( Data[i]->year , edit , 4 );
        }
    }else if(flag_comment){
        for(int32_t i=0 ; i<file_cnt ; ++i){
            for(int32_t u=0 ; u<28 ; ++u) Data[i]->comment[u]=0;
            strncpy( Data[i]->comment , edit , 30 );
        }
    }else if(flag_genre){
        for(int32_t i=0 ; i<file_cnt ; ++i){
            Data[i]->genre=int_genre;
        }
    }

    for(int32_t i=0 ; i<file_cnt ; ++i){
        munmap(pfile[i],size[i]);
    }

    return 0;
}


void help(){
    printf("usage: hw0502 -[tTaAycg] "yellow"\"value\""none" file1 [file2...]\n");
    printf("       hw0502 -d file1 [file2...]\n");
    printf("       hw0502 -l file1 [file2...]\n");
    printf("       hw0502 -h\n");
    printf("  -t   Modifies a Title tag\n");
    printf("  -T   Modifies a Track tag\n");
    printf("  -a   Modifies an Artist tag\n");
    printf("  -A   Modifies an Album tag\n");
    printf("  -y   Modifies a Year tag\n");
    printf("  -c   Modifies a Title tag\n");
    printf("  -g   Modifies a Genre tag\n");
    printf("  -l   Lists an ID3 tag\n");//打勾
    printf("  -d   Deletes an ID3 tag\n");
    printf("  -h   Displays this help info\n");//打勾
}

void list(){
    for(int32_t i=0 ; i<file_cnt ; ++i){
        printf(yellow"========== %s ==========\n"none,stream_name[i]);
        char tmp_tag[5]={0};
        char tmp_title[35]={0};
        char tmp_artist[35]={0};
        char tmp_album[35]={0};
        char tmp_year[5]={0};
        char tmp_comment[35]={0};
        
        memcpy(tmp_tag,Data[i]->tag,3);
        memcpy(tmp_title,Data[i]->title,30);
        memcpy(tmp_artist,Data[i]->artist,30);
        memcpy(tmp_album,Data[i]->album,30);
        memcpy(tmp_year,Data[i]->year,4);
        memcpy(tmp_comment,Data[i]->comment,30);

        // printf("tag:%3s\n",tmp_tag);
        printf("Title:%s\n",tmp_title);
        printf("Artist:%s\n",tmp_artist);
        printf("Album:%s\n",tmp_album);
        printf("Year:%s\n",tmp_year);
        if(Data[i]->genre>192){
            printf("Genre: Undefined (%d)\n",Data[i]->genre);
        }else printf("Genre:%s (%d)\n",table[Data[i]->genre],Data[i]->genre);
        printf("Comment:%s\n",tmp_comment);
        printf("Track:%d\n",Data[i]->track);
    }
}
void delete(){
    for(int32_t i=0 ; i<file_cnt ; ++i){
        ftruncate(fd[i],size[i]-128);
        size[i]-=128;
    }
}
/*
typedef struct _data{
    char tag[3];
    char title[30];
    char artist[30];
    char album[30];
    char year[4];
    char comment[28];
    int8_t is_track;
    int8_t track;
    char genre;
}data;
*/