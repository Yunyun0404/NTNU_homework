#### hw0501 bonus

Q: Why MemFree is not equal to MemAvailable?
   What is different between these two values?

A: MemFree表示系統內尚未使用的空間。
   MemAvailable除了MemFree以外的空間，還要加上其他雖然已經被應用程式使用，但可以回收的空間，例如：cache、buffer、slab都有一部份可以回收。
   所以真正能用的空間是MemAvailable。