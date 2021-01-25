#include <stdio.h>
#include <stdint.h>
#include "function4.h"


int main()
{
	double resistance=0;
	double n = 0;

	printf("Please enter the resistance(1~100): ");
	if( scanf(" %lf", &resistance)==1)
	{
		if(resistance == (int)resistance && resistance>=1 && resistance<=100)
		{
			printf("Please enter n (1~100):");
			if(scanf(" %lf",&n)==1 && n>=1 && n <=100)
			{
				if(n==(int)n)
				{
					printf("Ans: %lf\n", eqivalent_resistance(resistance,n));
				}
				else
				{
					printf("Error message!\n");
				}
			}
			else	
			{
				printf("Error message!\n");
				return 0;
			}
		}
		else
		{
			printf("Error message!\n");
		}				
	}
	else
	{
		printf("Error message!\n");
		return 0;
	}
}
