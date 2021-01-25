#include <stdio.h>
#include <stdint.h>
#include "function1.h" 

int main()
{
	double number=0;
	
	printf("Please enter an integer (0<value<3000):");
	
	if(scanf(" %lf", &number) == 1)
	{
		printf("%lf\n",number);
		
		if(number <=0 || number != (int)number || number>3000)
		{
			printf("Error message!!\n");
			return 0;
		}
		
			thousands((int)number);
			hundreds((int)number);
			tens((int)number);
			ones((int)number);
	
	}
	else 
	{
		printf("Error message!\n");
		return 0;
	}
	
printf(" \n");
return 0;
}
