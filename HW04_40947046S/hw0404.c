#include "fun.h"

/*為啥不從第10個存檔改啊?
    因為裡面可能有裝備
    這樣的話資料就不夠乾淨
    我們傾向從乾淨的資料著手
*/
uint64_t util_getFdSize( int fd ){
    struct stat statbuf;  
    if( fstat( fd, &statbuf ) < 0 ){
        close( fd );
        return -1;
    }
    return statbuf.st_size;
}

size_t offset_date_year = 0x0032; // ~0033
size_t offset_date_month = 0x0034; // ~0035
size_t offset_date_dayofweek = 0x0036; // ~0037
size_t offset_date_day = 0x0038; // ~0039

size_t offset_attr_0 = 0x003e;  // ~0051 存了左上的欄位 
size_t offset_attr_1 = 0x0054;  // ~005B 存了右上的欄位
size_t offset_attr_2 = 0x005c;  // ~0067 存了左下的欄位
size_t offset_attr_3 = 0x0068;  // ~0073 存了右下的欄位

size_t offset_money = 0x00b0; // ~ 00b3
size_t offset_age = 0x00ba;  // ~ 00bb
size_t offset_birth_day = 0x00be;  // ~ 00bf
size_t offset_birth_month = 0x00c2;  // ~ 00c5
size_t offset_birth_year = 0x00c6;  // ~ 00c7
size_t offset_body = 0x00d2;  // ~ 00db
size_t offset_healthy = 0x00ea;  //  ~00eb
size_t offset_bad = 0x00ec;  //  ~00ed
size_t offset_personal = 0x00ee;  //  ~00ef
// personal detail: f0 ff
size_t offset_le = 0x0118; // 
size_t offset_relation = 0x025c; //
size_t offset_equipment = 0x043a;  // 
size_t offset_head = 0x043c; //道具欄的頭
size_t offset_storage = 0x0580;  // +5504

int main(){
    int32_t fd = 0;
    char	fileName[256] = {0};
    int32_t attr_flag=0;
    int32_t healthy_flag=0;
    int32_t money_flag=0;

    printf( "Please enter the file name: " );
    if( fgets( fileName, sizeof( fileName ), stdin ) == NULL ){
        printf( "Error!\n" );
        return 0;
    }
    
    // Since fgets will include '\n', we need to remove this character.
    if( fileName[strlen( fileName )-1] == '\n' ){
        fileName[ strlen( fileName ) - 1 ] = 0;
    }
    
    fd = open( fileName, O_RDWR );
    
    // Open file descriptor
    if( fd == -1 ){
        printf( "Open file error!\n" );
        return -1;
    }

    char    *_pFile = NULL;
    uint64_t fileSize = util_getFdSize( fd );
    
    _pFile = mmap( 0, fileSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0 );
    
    Attribute *attribute = (Attribute *)( _pFile + offset_attr_0  );
    uint16_t *health    = (uint16_t *)( _pFile + offset_healthy );
    uint32_t *money     = (uint32_t *)( _pFile + offset_money   );
    
    printf("================================Hello================================\n");
    printf("Welcome to "yellow"Princess Maker2"none"Version:cheat\n");
    printf("    I'm Yunyun:)))     \n");
    printf("=====================================================================\n");
    printf("Would you want to modify the "yellow"money"none" ? ( yes:1 ; no:0 )\n");
    if( scanf("%d",&money_flag)==1 && ( money_flag==1 || money_flag==0 ) ){

    }else{
        printf("input error\n");
        return 0;
    }
    if(money_flag==1){
        money_modify(money);
    }
    printf("Great done\n");
    printf("=====================================================================\n");
    printf("Would you want to modify the "yellow"healthy condition"none" ? ( yes:1 ; no:0 )\n");
    if( scanf("%d",&healthy_flag)==1 && ( healthy_flag==1 || healthy_flag==0 ) ){

    }else{
        printf("input error\n");
        return 0;
    }
    if(healthy_flag==1){
        health_modify(health);
    }
    printf("Great done\n");
    printf("=====================================================================\n");
    printf("Would you want to modify the"yellow" attribute"none" ? ( yes:1 ; no:0 )\n");
    if( scanf("%d",&attr_flag)==1 && ( attr_flag==1 || attr_flag==0 ) ){

    }else{
        printf("input error\n");
        return 0;
    }
    if(attr_flag==1){
        attr_modify(attribute);        
    }
    printf("Great done\n");

    munmap( _pFile, fileSize );
    close( fd );
    
    return 0;
}

/*使用iconv
int in_s, out_s;
char in_buf[LEN], out_buf[LEN], *in_ptr = in_buf, *out_ptr = out_buf;
if((cd = iconv_open("UTF8", "BIG-5")) == (iconv_t)-1) {
    fprintf(stderr, "error: opening iconv\n");
    exit(1);
}
if(iconv(cd, &in_ptr, &in_s, &out_ptr, &out_s) == (size_t)-1) {
    fprintf(stderr, "errno: %s\n", strerror(errno));
}
*/

/*
測試檔INPUT(記得資料儲存是little endian)
stamina  體力 586  024A 存成 4A 02
以下只寫原值比較懂：
左上
strnth   腕力 336  0150     50 01
intell   智力 445  01BD     BD 01
elegance 氣質 534  0216     16 02
glamour  魅力 539  021B     1B 02
morality 道德 319  013F     3F 01
faith    信仰 201  00C9     C9 00
karma    罪孽 26   001A     1A 00
senstv   感受 168  00A8     A8 00
stress   疲勞 2    0002     02 00
reserve

右上
war_rep       戰士評價 234 00EA  EA 00
mag_rep       魔法評價 275 0113  13 01
social_rep    社交評價 340 0154  54 01
housework_rep 家事評價 329 0149  49 01

左下
戰鬥技術 103 0067  67 00
攻擊能力 113 0071  71 00
防禦能力 10  000A  0A 00
魔法技術 122 007A  7A 00
魔法能力 104 0068  68 00
抗魔能力 24  0018  18 00

右下
禮儀 103 0067  67 00
藝術 154 009A  9A 00
談話 13  000D  0D 00
烹飪 135 0087  87 00
掃除 99  0063  63 00
待人 95  005F  5F 00

年   1218 04C2  C2 04
月   3    0003  03 00
日   31   001F  1F 00
星期 6    0006  06 00
錢錢 55087
*/