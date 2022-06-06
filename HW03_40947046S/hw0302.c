#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
lapor說：buffer用完要memset
*/

int main(){
    FILE* srt = NULL;
    char filename[64]={0};
    double preTime=0;
    double nowTime=0;
    char buffer[128]={0};
    char lrc[128]={0};
    double waitTime=0;
    double speed=0;
    int flag=1;
    printf("Open a SRT file: ");
    fgets(filename,64,stdin);
    filename[strlen(filename) - 1]=0;

    if( strncmp(&filename[strlen(filename) - 4],".srt",4) != 0){
        printf("Error: The file name extension is not \".srt\"\n");
        return 0;
    }

    if((srt = fopen(filename,"r")) == NULL){
        perror("Error");
        return 0;
    }
    printf("Speed (0.5~2): ");
    
    if( scanf("%lf",&speed)==1 && speed<=2 && speed>=0.5){

    }else{
        printf("error input\n");
        return 0;
    }
/*
00:00:14,760 --> 00:00:18,023
in the next 18 minutes when I do our chat,
*/
    system("clear");
    
    while(!feof(srt)){
        fgets(buffer,127,srt);
        buffer[strlen(buffer)-1]=0;
        preTime=0;
        nowTime=0;
        if( strlen(buffer)==1 ){
            
        }else if( buffer[2] == ':' ){
            preTime += (buffer[0] -'0') * 60000;
            preTime += (buffer[1] -'0') * 6000;
            preTime += (buffer[3] -'0') * 1000;
            preTime += (buffer[4] -'0') * 100;
            preTime += (buffer[6] -'0') * 10;
            preTime +=  buffer[7] -'0'      ;
            preTime += (buffer[9] -'0')  *0.1;
            preTime += (buffer[10]-'0')  *0.01;
            preTime += (buffer[11]-'0')  *0.001;
            if(flag){
                flag=0;
                usleep(preTime*1000000/speed);
            }
            nowTime += (buffer[17] -'0') * 60000;
            nowTime += (buffer[18] -'0') * 6000;
            nowTime += (buffer[20] -'0') * 1000;
            nowTime += (buffer[21] -'0') * 100;
            nowTime += (buffer[23] -'0') * 10;
            nowTime +=  buffer[24] -'0'      ;
            nowTime += (buffer[26] -'0')  *0.1;
            nowTime += (buffer[27] -'0')  *0.01;
            nowTime += (buffer[28] -'0')  *0.001;

            waitTime = (nowTime - preTime) * 1000000/speed;

            fgets(lrc,127,srt);
            lrc[strlen(lrc)-1] = 0;
            printf("%s\n",lrc);
            usleep(waitTime);
            system("clear");  
            memset(buffer,0,128);
            memset(lrc,0,128);
        }
        else continue;
    }

    fclose(srt);
    
    return 0;
}
//JamieOliver_2010-480p.eng.srt