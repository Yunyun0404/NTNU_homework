#include <stdio.h>
#include <stdint.h>
#include "function3.h"

int main()
{
	int32_t k=0;

	double answer=1.0;
		
	printf("k-th order Taylor polynomail for e\n");
	printf("Please enter k:");
	if (scanf(" %d", &k)==1 && k>=0)
	{
		for(double i=1.0;i<=k;i++)
		{
			answer=answer+(1/factorial(i));
		}

		printf("%.20f\n", answer);
		return 0;
	}
	else
	{
		printf("Error message!\n");
		return 0;
	}
}
