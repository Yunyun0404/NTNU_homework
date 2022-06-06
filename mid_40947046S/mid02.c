#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char *name;
    char *code;
    char *indicator_name;
    char *indicator_code;
    int32_t data[61];
} country;

int main(){
    FILE *record=NULL;
    char name[64]={0};
    int32_t start_time=0;
    int32_t end_time=0;
    int32_t choice=0;
    int32_t line=0;
    country table[300];
    
    printf("Please enter the data name: ");
    fgets(name,63,stdin);
    name[ strlen(name)-1 ]=0;
    printf("Please enter the analylis start name: ");
    scanf("%d",&start_time);
    printf("Please enter the analysis end name: ");
    scanf("%d",&end_time);

    if(strncmp(&name[strlen(name) - 4],".csv",4) != 0){
        printf("Error: The file name extension is not \".csv\"\n");
        return 0;
    }
    if((record = fopen(name,"r")) == NULL){
        perror("Error");
        return 0;
    }
    
/*
    while( !feof(record) ){
        char buffer[1024]={0};
        fgets(buffer,1023,record);
        buffer[ strlen(buffer)-1 ]=0;
        line++;
        int32_t cnt=0;
        char *token=NULL;


        if(line>5){
            table[line-6].indicator_name="Population, total";
            table[line-6].indicator_code="SP.POP.TOTL";
            token=strtok(buffer,",");
            table[line-6].name=token;

            while(token!=NULL){
                token = strtok(NULL,",");
                if(cnt==0){
                    table[line-6].code=token;
                }else if(cnt==1){
                    table[line-6].indicator_name=token;
                }else if(cnt==2){
                    table[line-6].indicator_code=token;
                }else break;
                cnt++;
            }
        }
    } 
*/
/*
for(size_t i=0 ; i<300 ; ++i){
    printf("%s   %s   %s   %s\n",table[i].name,table[i].code,table[i].indicator_name,table[i].indicator_code);
    /*for(size_t u=0 ; u<61 ; ++u){
        printf("%d ",table[i].data[u]);
    }
    printf("\n");
}
*/
    do{
        printf("-----Menu-----\n");
        printf("1) Which country has the largest population growth?\n");
        printf("2) Which country has the largest population growth rate?\n");
        printf("3) Which country has the smallest population growth , including negative growth?\n");
        printf("4) Which country has the smallest population growth rate, including negative growth?\n");
        printf("5) Which country has the largest population standard deviation?\n");
        printf("6) Which country has the smallest population standard deviation?\\n");
        printf("7) Given a country name (case -insensitive), please use linear least squares method to predict the country's population in 2021.\n");
        printf("8) Exit\n");
        printf("Choice (1-7, 8:exit): ");
        scanf("%d",&choice);

        if(choice != 8){

            switch(choice){
                case 1:
                    printf("hi\n");
                    break;
                case 2:
                    printf("yo\n");
                    break;
                case 3:
                    printf("hey\n");
                    break;
                case 4:
                    printf("yoho\n");
                    break;
                case 5:
                    printf("QAQ\n");
                    break;
                case 6:
                    printf("GG\n");
                    break;
                case 7:
                    printf("haha\n");
                    break;
            }
        }

    }while(choice != 8);

    printf("Bye!\n");
    return 0;
}


   
//API_SP.POP.TOTL_DS2_en_csv_v2_3731322.csv