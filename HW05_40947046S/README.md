#### hw05 

系級：資工113
學號：40947046S
姓名：劉佩昀

##### hw0501
一、介紹

在這題中，我使用了
```c
system("cat /proc/meminfo > data.txt");
```
去把我需要的記憶體用量紀錄下來，寫到data.txt檔案裡。

並把讀檔關檔寫成一個名為open()的function
並用sleep實作n秒印一次的功能

二、提醒
1. 請助教記得讀我的 **hw0501-bonus.pdf** 檔。
2. 假如同時輸入 --byte --mega --kilo，會用byte這個單位印出。
   假如同時輸入 --mega --kilo，會用mega這個單位印出。
   總之，在輸入不只一個單位option時，優先序為byte>mega>kilo。

#### hw0502
一、介紹
在此題中，我用mmap將檔案打開並修改值。
由於可能要處理很多個檔案，所以需要的東西的空間我一開始都在全域宣告10(助教您有說不會超過10個檔案)
這樣比較方便做事

讀檔案的structure長這樣：
```c
typedef struct _data{
    char tag[3];
    char title[30];
    char artist[30];
    char album[30];
    char year[4];
    char comment[28];
    uint8_t is_track;
    uint8_t track;
    uint8_t genre;
}data;
```
另外，像delete是需要把檔案的tag刪掉，所以還會用到ftruncate這個函式。

二、使用規定
1. 測試時，請一次只輸入一個option。
2. tag裡空的值，我一律不印。
3. genre會被初始化成255，記為undefined。
4. track會被初始化成0。

##### hw0503
在此題中，我直接把base64建成table。
```c
const char table[65]={
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
        'O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
        'o','p','q','r','s','t','u','v','w','x','y','z',
        '0','1','2','3','4','5','6','7','8','9','+','/','\0'
    };
```

en()是encode的function，把輸出丟到output。
```c
void en(FILE *input,FILE *output,const char *table);
```

de()是decode的function，把輸出丟到output。
```c
void de(FILE *input,FILE *output,const char *table);
```
