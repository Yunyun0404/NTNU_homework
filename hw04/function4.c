#include <stdio.h>
#include <stdint.h>

double eqivalent_resistance (double resistance,int32_t n)
{
	double tmp=0.0;

	for(int32_t i=1 ; i<=n ; i++)
	{
		if(i==1)
		{
			tmp=resistance*2;
		}		
		else
		{
			tmp= ((tmp*resistance)/(tmp+resistance))+resistance;
		}	
	}
	return tmp;
}
