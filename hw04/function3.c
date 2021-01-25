#include <stdio.h>
#include <stdint.h>

double factorial(int32_t k)
{
	double multiplication=1.0;

	for(int32_t i=1; i<=k ; i++)
	{		
		multiplication=i*multiplication ;
	}
	
return multiplication;
}

