#### Bonus

Alice一開始寫的方法將 char str[10000000] 宣告在函式裡，記憶體區段中就會存在 **區域變數** 中的stack，這個區域不能存那麼大的東西，大概10^6就會爆炸了。

Bob的解法是將其宣告成static char str[10000000]，如此將會使str存在data(bss)裡，這個地方可以存那麼大的東西，所以給過。

Catherine的解法是將str宣告成全域變數。同Bob的做法，str將會存在data段。