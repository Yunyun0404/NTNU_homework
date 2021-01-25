#include <stdio.h>
#include <stdint.h>
#include "function2.h"

int main()
{
	
	int32_t rod_a=0,rod_b=0,rod_c=0;
	double n=0;
	printf("Please enter the disk number(2-20): \n");
	
	if((scanf("%lf", &n))==1 && n==(int)n && n>1 && n<=20)
	{
		recursive(1,2,3,n);
	}
	else
	{
			printf("Error message!\n");
	}
	
	return 0;
}
