#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
// #include <curl/curl.h> 
// #include <assert.h>

int32_t help=0;

struct option long_options[]={  
     { "country", 1 , NULL, 'c' },
     { "start"  , 1 , NULL, 's' },
     { "end"    , 1 , NULL, 'e' },
     { "output" , 1 , NULL, 'o' },
     { "help"   , 0 , &help , 1 },
     { 0 , 0 , 0 , 0 },               //規定：最後一定要有這行，表示結束，這是man的規定。
};  

int main( int argc, char *argv[] ){
    char country[64]={0};
    char start[32]={0};
    char end[32]={0};
    char output[32]={0};

    int32_t c = 0;
    int32_t index = 0;

    strcpy(country,"Taiwan");
    strcpy(start,"01-02-2020");
    strcpy(end,"12-31-2021");
    strcpy(output,"output.csv");

    while ( ( c=getopt_long( argc, argv, "c:s:e:o:", long_options, &index ) ) != -1 ){
        switch( c ){
            case 'c':
                strcpy(country,optarg);
                break;
            case 's':
                strcpy(start,optarg);
                break;
            case 'e':
                strcpy(end,optarg);
                break;
            case 'o':
                strcpy(output,optarg);
                break;
            case '?':
                printf("unknown opt\n");
                return 0;
        }
    }

    if(help){
        printf("\n  fin02:\n");
        printf("     -c, --country: the country name.           default: Taiwan\n");
        printf("     -s, --start:   MM-DD-YYYY: the start date. default: 01-02-2020\n");
        printf("     -e, --end:     MM-DD-YYYY: the end date.   default:12-31-2021\n");
        printf("     -o, --output:  output file name.           default:output.csv\n\n");
    }
/*
    //抓資料囉
    CURL *curl;
    CURLcode res;
    char address[256]={0};
    curl = curl_easy_init();
  
    strcpy(address,"https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_daily_reports/");
    strcat(address,start);
    strcat(address,".csv");

    if(curl){
        curl_easy_setopt( curl, CURLOPT_URL, "" );
        
        FILE *pFile = fopen( "start.txt", "w" );
        assert( pFile );//確定一下file有沒有成功吃到
        curl_easy_setopt( curl, CURLOPT_WRITEDATA, pFile );
        
        Perform the request, res will get the return code 
        res = curl_easy_perform(curl);
         Check for errors 
        if( res != CURLE_OK ){
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
         
         always cleanup  
        curl_easy_cleanup(curl);
        fclose( pFile );
    }
*/
    return 0;
}