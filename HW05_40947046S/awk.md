#### awk 學習

1. awk可以以"欄"來處理文字，例如： ls -l 可以列出超長檔案資訊，有八個欄位。
   如    drwxr-xr-x  7  yunyun yunyun 4096 May 10 12:12 CP110-2
             $1     $2   $3      $4    $5    $6    $7     $8
2. 如果把ls -l的輸出經管線到 awk 寫成 ls -l | awk {} 對awk來說每一欄會自動儲存在其預設的欄位變數'$0'中。
3. 共有 **八** 個欄位，$1~$8，但要記得$0也有存東西喔，就是存$1~$8一整行的內容。
4. $0的內容有變更的話會自動更新其他欄位變數。
5. 如只單純寫成 ls -l | awk '{}' 是不會有任何的輸出的。因為沒輸出函數(function)和要輸出那一欄位。
   awk內建的輸出函數最常用的為〝print〞,例如：輸出 ls -l 檔案的大小欄(欄位=5)和檔名欄(欄位=8)可寫成
   ls -l | awk '{print $5 __,__ $8}'
   上面那個逗號代表 **輸出欄位間隔** ，預設是一個 **空白** 。