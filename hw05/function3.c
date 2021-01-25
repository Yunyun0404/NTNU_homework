#include <stdint.h>
#include <stdio.h>



void print_p1p2(double p1[],double p2[],double p1_degree,double p2_degree)
{
	printf("p1: ");
	for(int32_t i=p1_degree ; i>=0 ; i--)
	{
		if(i!=0 && p1[i]!=0)
		{
			if(p1[i]>0)
			{
				printf("%f x^%d+",p1[i],i);
			}
			else if(p1[i]<0)
			{
				printf("(%f) x^%d+",p1[i],i);
			}
		}
		else if(i==0)
		{
			if(p1[i]>0)
			{
				printf("%f",p1[i]);
			}
			else if(p1[i]<0)
			{
				printf("(%f)",p1[i]);
			}
		}		
	}
	
	printf("\n");
	printf("p2: ");
	
	for(int32_t i=p2_degree ; i>=0 ; i--)
	{
		if(i!=0 && p2[i]!=0)
		{
			if(p2[i]>0)
			{
				printf("%f x^%d+",p2[i],i);
			}
			else if(p2[i]<0)
			{
				printf("(%f) x^%d+",p2[i],i);
			}
		}
		else if(i==0 && p2[i]!=0)
		{
			printf("%f",p2[i]);
		}		
	}
	printf("\n");
}

void plus(double p1_degree,double p2_degree,double p1[],double p2[],double plus_p1p2[])
{
	printf("p1 + p2: ");
	
	if(p1_degree>=p2_degree)
	{
		for(int32_t i=0 ; i<=p2_degree ; i++)
		{
			plus_p1p2[i]=p1[i]+p2[i];
		}
		for(int32_t i=p1_degree ; i>p2_degree ; i--)
		{
			if(p1[i]!=0)
			{
				if(p1[i]>0)
				{
					printf("%lf x^%d+",p1[i],i);
				}
				else if(p1[i]<0)
				{
					printf("(%lf) x^%d+",p1[i],i);
				}
			}
		}
		for(int32_t i=p2_degree ; i>=0 ; i--)
		{
			if(plus_p1p2[i]!=0 && i>0)
			{
				if(plus_p1p2[i]>0)
				{
					printf("%lf x^%d+",plus_p1p2[i],i);
				}
				else if(plus_p1p2[i]<0)
				{
					printf("(%lf) x^%d+",plus_p1p2[i],i);
				}
			}
			else if(i==0)
			{
				if(plus_p1p2[i]>0)
				{
					printf("%lf",plus_p1p2[i]);
				}
				else if(plus_p1p2[i]<0)
				{
					printf("(%lf)",plus_p1p2[i]);
				}
				else if(plus_p1p2[i]==0)
				{
					printf("\b");
				}
			}
		}
	}
	else
	{
		for(int32_t i=0 ; i<=p1_degree ; i++)
		{
			plus_p1p2[i]=p1[i]+p2[i];
		}
		for(int32_t i=p2_degree ; i>p1_degree ; i--)
		{
			if(p2[i]!=0)
			{
				if(p2[i]>0)
				{
					printf("%lf x^%d+",p2[i],i);
				}
				else if(p2[i]<0)
				{
					printf("(%lf) x^%d+",p2[i],i);
				}
			}
		}
		for(int32_t i=p1_degree ; i>=0 ; i--)
		{
			if(plus_p1p2[i]!=0 && i>0)
			{
				if(plus_p1p2[i]>0)
				{
					printf("%lf x^%d+",plus_p1p2[i],i);
				}
				else if(plus_p1p2[i]<0)
				{
					printf("(%lf) x^%d+",plus_p1p2[i],i);
				}
			}
			else if(i==0)
			{
				if(plus_p1p2[i]>0)
				{
					printf("%lf",plus_p1p2[i]);
				}
				else if(plus_p1p2[i]<0)
				{
					printf("(%lf)",plus_p1p2[i]);
				}
				else if(plus_p1p2[i]==0)
				{
					printf("0");
				}
			}
		}		
	}
	printf("\n");
}

void minus(double p1_degree,double p2_degree,double p1[],double p2[],double minus_p1p2[])
{
	printf("p1 - p2: ");
	
	if(p1_degree>=p2_degree)
	{
		for(int32_t i=0 ; i<=p2_degree ; i++)
		{
			minus_p1p2[i]=p1[i]-p2[i];
		}
		for(int32_t i=p1_degree ; i>p2_degree ; i--)
		{
			if(p1[i]!=0)
			{
				if(p1[i]>0)
				{
					printf("%lf x^%d+",p1[i],i);
				}
				else if(p1[i]<0)
				{
					printf("(%lf) x^%d+",p1[i],i);
				}
			}
		}
		for(int32_t i=p2_degree ; i>=0 ; i--)
		{
			if(minus_p1p2[i]!=0 && i>0)
			{
				if(minus_p1p2[i]>0)
				{
					printf("%lf x^%d+",minus_p1p2[i],i);
				}
				else if(minus_p1p2[i]<0)
				{
					printf("(%lf) x^%d+",minus_p1p2[i],i);
				}
			}
			else if(i==0)
			{
				if(minus_p1p2[i]>0)
				{
					printf("%lf",minus_p1p2[i]);
				}
				else if(minus_p1p2[i]<0)
				{
					printf("(%lf)",minus_p1p2[i]);
				}
				else if(minus_p1p2[i]==0)
				{
					printf("0");
				}
			}
		}
	}
	else
	{
		for(int32_t i=0 ; i<=p1_degree ; i++)
		{
			minus_p1p2[i]=p1[i]+p2[i];
		}
		for(int32_t i=p2_degree ; i>p1_degree ; i--)
		{
			if(p2[i]!=0)
			{
				if(p2[i]>0)
				{
					printf("%lf x^%d+",p2[i],i);
				}
				else if(p2[i]<0)
				{
					printf("(%lf) x^%d+",p2[i],i);
				}
			}
		}
		for(int32_t i=p1_degree ; i>=0 ; i--)
		{
			if(minus_p1p2[i]!=0 && i>0)
			{
				if(minus_p1p2[i]>0)
				{
					printf("%lf x^%d+",minus_p1p2[i],i);
				}
				else if(minus_p1p2[i]<0)
				{
					printf("(%lf) x^%d+",minus_p1p2[i],i);
				}
			}
			else if(i==0)
			{
				if(minus_p1p2[i]>0)
				{
					printf("%lf",minus_p1p2[i]);
				}
				else if(minus_p1p2[i]<0)
				{
					printf("(%lf)",minus_p1p2[i]);
				}
				else if(minus_p1p2[i]==0)
				{
					printf("0");
				}
			}
		}		
	}
	printf("\n");
}


void multiplication(double p1_degree,double p2_degree,double power_p1p2[],double p1[(int)p1_degree+1],double p2[(int)p2_degree+1])
{
	printf("p1 * p2: ");
	
	if(p1_degree<p2_degree)
	{	
	
		double tmp[(int)(p1_degree+p2_degree+2)];
			
		for(int32_t p1_power=0 ; p1_power<=p1_degree ; p1_power++)
		{
			for(int32_t p2_power=0 ; p2_power<=p2_degree ; p2_power++)
			{
				
				power_p1p2[p1_power+p2_power]=tmp[p1_power+p2_power]+p1[p1_power]*p2[p2_power];					
				
				tmp[p1_power+p2_power]=power_p1p2[p1_power+p2_power];	
			}
			
		}
		
		for(int32_t h=0 ; h<=p2_degree ; h++)
		{
			power_p1p2[h]=tmp[h];
		}
					
	}
	else if(p1_degree>=p2_degree)
	{		
		double tmp[(int)(p1_degree+p2_degree+2)];
			
		for(int32_t p2_power=0 ; p2_power<=p2_degree ; p2_power++)
		{
			for(int32_t p1_power=0 ; p1_power<=p1_degree ; p1_power++)
			{		
				power_p1p2[p1_power+p2_power]=tmp[p1_power+p2_power]+p1[p1_power]*p2[p2_power];					
	
				tmp[p1_power+p2_power]=power_p1p2[p1_power+p2_power]	;	
			}
			
		}
		
		for(int32_t h=0 ; h<=p1_degree ; h++)
		{
			power_p1p2[h]=tmp[h];
		}	
	
	
	}
		
	for(int32_t i=p1_degree+p2_degree ; i>=0 ; i--)
	{
		if(i==0)
		{
			if(power_p1p2[i]>0)
			{
				printf("%lf",power_p1p2[i]);
			}
			else if(power_p1p2[i]<0)
			{
				printf("(%lf)",power_p1p2[i]);
			}
			else if(power_p1p2[i]==0)
			{
				printf("0");
			}
		
		}
		else if(power_p1p2[i]!=0 && i!=0)
		{
			if(power_p1p2[i]>0)
			{
				printf("%lf x^%d+",power_p1p2[i],i);
			}
			else if(power_p1p2[i]<0)
			{
				printf("(%lf) x^%d+",power_p1p2[i],i);
			}
		}		
	}
printf("\n");
}



















