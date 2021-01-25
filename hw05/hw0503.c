#include <stdio.h>
#include <stdint.h>
#include "function3.h"

int main()
{
	double p1_degree=0;
	double p2_degree=0;
//input	
	printf("Please enter p1 degree: ");
	if((scanf(" %lf", &p1_degree))==1 && p1_degree==(int)p1_degree && p1_degree>=0)
	{
	
		double p1[(int)p1_degree+1];
		
		printf("Please enter p1 coefficients: ");
		for(int32_t one=p1_degree ; one>=0 ; one--)
		{
			if((scanf(" %lf",&p1[one])!=1))
			{
				printf("Error message!\n");	
				return 0;	
			}		
		}
		
		printf("Please enter p2 degree: ");
		
		if((scanf(" %lf",&p2_degree))==1 && p2_degree==(int)p2_degree && p2_degree>=0)
		{
		
			double p2[(int)p2_degree+1];
			
			printf("Please enter p2 coefficients: ");
			for(int32_t two=p2_degree ; two>=0 ; two--)
			{
				if((scanf(" %lf",&p2[two])!=1))
				{
					printf("Error message!\n");	
					return 0;	
				}					
			}
			printf("\n");
			
			print_p1p2(p1,p2,p1_degree,p2_degree);
		
			//加法
			if(p1_degree>=p2_degree)
			{
				double plus_p1p2[(int)p1_degree+1];
				plus(p1_degree,p2_degree,p1,p2,plus_p1p2);					
			}
			else
			{
				double plus_p1p2[(int)p2_degree+1];
				plus(p1_degree,p2_degree,p1,p2,plus_p1p2);
			}	
			//加法
			
			//減法
			if(p1_degree>=p2_degree)
			{
				double minus_p1p2[(int)p1_degree+1];
				minus(p1_degree,p2_degree,p1,p2,minus_p1p2);					
			}
			else
			{
				double minus_p1p2[(int)p2_degree+1];
				minus(p1_degree,p2_degree,p1,p2,minus_p1p2);
			}			
			//減法	
			
			//乘法	
			double power_p1p2[(int)(p1_degree+p2_degree+2)];
			multiplication(p1_degree,p2_degree,power_p1p2,p1,p2);
			//乘法
			
	
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
		return 0;	
	}	
//input over

	
return 0;	
}
