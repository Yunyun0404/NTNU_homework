/*
cd /proc/
會出現一堆東西

其中有一個東西叫做 meminfo

cat meminfo
可以印出很多東西
其中有一欄：MemAvailable就是我要的東西

例如我可以每一秒打開一次這個檔案
這樣就能時時監測我要的東西了
但她的單位是kb 要注意

grep MemTotal /proc/meminfo | awk '{print $2}'就能拿到
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#define blue "\033[34m"
#define none "\033[0m"

void print();
void print_unit(int32_t,int32_t);
void open();

int32_t second_flag=0;
int32_t count_flag=0;
int32_t byte_flag=0;
int32_t kilo_flag=1;
int32_t mega_flag=0;
int32_t seconds_cnt=0;
int32_t counts_cnt=1;
int32_t help=0;
char total[128]={0};
char tmp[128]={0};
char avai[128]={0};
FILE *mem=NULL;
uint64_t total_num=0;
uint64_t avai_num=0;
char *tot=NULL;
char *ava=NULL;
double percent=0;

struct option long_options[]={  
     { "bytes" , 0 , NULL , 'b' },
     { "seconds" , 1 , NULL , 's' },
     { "count", 1 , NULL , 'c' },      //0:no argument ; 1:required arguments ; 2:optional arguments
     { "kilo" , 0 , &kilo_flag , 1 },
     { "mega" , 0 , &mega_flag , 1 },
     { "help" , 0 , &help , 1 },        //這就是要做到只有長選項，沒有短選項的做法：透過檢查flag的值去判斷。
     {  0 , 0 , 0 , 0 },               //規定：最後一定要有這行，表示結束，這是man的規定。
};  

int main( int argc, char *argv[] ){
    // getopt_long
    int32_t c = 0;
    int32_t index = 0;

    while ( ( c = getopt_long( argc, argv, "bs:c:", long_options, &index ) ) != -1 ){
        switch( c ){
            case 'b':
                byte_flag=1;
                break;
            case 's':
                second_flag=1;
                seconds_cnt=atoi(optarg);
                if(seconds_cnt<=0){
                    printf("error input\n");
                    return 0;
                }
                break;
            case 'c':
                count_flag=1;
                counts_cnt=atoi(optarg);
                if(counts_cnt<=0){
                    printf("error input\n");
                    return 0;
                }
                break;
            case '?':
                printf( "option: ?\n" );
                return 0;
        }
    }
   
    if(help)print();
 /*
        有分很多狀況，
        1. 沒有second_flag也沒有count_flag，需考慮單位。
        2. 有second_flag，沒count_flag，需考慮單位。
        3. 沒second_flag。有count_flag，需考慮單位。
        4. 有second_flag，有count_flag，需考慮單位。
*/
    if( second_flag==0 && count_flag==0 ){
        //case 1
        open();
        printf("Available: %lu ",avai_num);
        print_unit(byte_flag,mega_flag);
        printf(" (%.4lf\%%)\n",percent);
    }else if( second_flag==1 && count_flag==0 ){
        //case 2
        while(1){
            open();
            printf("Available: %lu ",avai_num);
            print_unit(byte_flag,mega_flag);
            printf(" (%.4lf\%%)\n",percent*100);
            sleep(seconds_cnt);
        }
    }else if( second_flag==0 && count_flag==1 ){
        //case 3
        while(counts_cnt--){
            open();
            printf("Available: %lu ",avai_num);
            print_unit(byte_flag,mega_flag);
            printf(" (%.4lf\%%)\n",percent*100);
            sleep(seconds_cnt);
        }
    }else if( second_flag==1 && count_flag==1 ){
        //case 4
        while(1){
            for(int32_t i=0 ; i<counts_cnt ; ++i){
                open();
                printf("Available: %lu ",avai_num);
                print_unit(byte_flag,mega_flag);
                printf(" (%.4lf \%%)\n",percent*100);
            }
            sleep(seconds_cnt);
        }
    }

    return 0;
}

void print(){
    printf("-Usage:\n");
    printf("\thw0501 [options]\n");
    printf("-Options:\n");
    printf("\t-b, --bytes          show output in bytes\n");
    printf("\t    --kilo           show output in kilobytes ("blue"default"none")\n");
    printf("\t    --mega           show output in megabytes\n");
    printf("\t-s N, --seconds N    repeat printing every N seconds\n");
    printf("\t-c N, --count N      repeat printing N times, then exit\n");
    printf("\t    --help           display this help and exit\n");
    exit(1);
}

void print_unit(int32_t B,int32_t MB){
    if(B)printf(" Bytes ");
    else if(MB)printf(" MB ");
    else printf(" KB ");
}

void open(){
//    system("cat /proc/meminfo > data.txt")  多此一舉並非好方法

    if( ( mem=fopen("/proc/meminfo","r") )== NULL ){
        printf("Open error\n");
        exit(1);
    }

    for(size_t i=0 ; i<3 ; ++i){
        if(i==0){
            fgets(total,127,mem);
        }else if(i==1){
            fgets(tmp,127,mem);
        }else if(i==2){
            fgets(avai,127,mem);
        }
    }
    // printf("here\n");
    // printf("%s\n",total);
    // printf("%s\n",tmp);
    // printf("%s\n",avai);

    tot=strchr(total,' ');
    ava=strchr(avai,' ');
    total_num=atoi(tot);
    avai_num=atoi(ava);
    percent=(double)avai_num/(double)total_num;    
    fclose(mem);
    
    if(byte_flag){
        avai_num*=1024;
    }else if(mega_flag){
        avai_num/=1024;
    }else if(kilo_flag){

    }
}
/*
1 Byte = 8 Bits
1 Kilobyte (KB) = 1024 Bytes
1 Megabyte (MB) = 1024 KB
*/