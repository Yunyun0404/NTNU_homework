#include <stdio.h>
#include <stdint.h>

void recursive(int32_t rod_a,int32_t rod_b,int32_t rod_c,double n)
{
	if(n==1)
	{
		printf("Move the disk %d to rod %d\n",(int)n,rod_b);
	}
	else
	{
		if(n>1)
		{
			recursive(rod_a,rod_c,rod_b,n-1);
			printf("Move the disk %d to rod %d\n",(int)n,rod_b);
			recursive(rod_c,rod_b,rod_a,n-1);
		}
	}
}
