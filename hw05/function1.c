#include <stdio.h>
#include <stdint.h>

void odd(int32_t array01[10])
{
	for(int32_t i=0 ; i<10 ;i++)
	{
		printf("%2d",array01[i]);
	}
		
	for(int32_t i=0 ; i<10 ; i++)
	{
		for(int32_t k=i+1 ; k<10 ; k++) //跟後面的數比大小
		{
			if(abs(array01[i]%2)==1 && abs(array01[k]%2)==1) //odd
			{
				if(array01[k]<array01[i])
				{
					int32_t tmp=0;
					tmp=array01[i];
					array01[i]=array01[k];
					array01[k]=tmp;
				}		
			}
		}		
	}
	
	printf("\n");
}

void even(int32_t array02[10])
{
	for(int32_t i=0 ; i<10 ; i++)
	{
		if(abs(array02[i]%2)==1)
		{
			printf("%2d",array02[i]);
		}
	}
	
	for(int32_t i=0 ; i<10 ; i++)
	{
		for(int32_t k=i+1 ; k<10 ; k++) //跟後面的數比大小
		{
			if(abs(array02[i]%2)==0 && abs(array02[k]%2)==0) //even
			{
				if(array02[k]>array02[i])
				{
					int32_t tmp=0;
					tmp=array02[i];
					array02[i]=array02[k];
					array02[k]=tmp;
				}		
			}
		}		
	}
}

void print(int32_t array03[10])
{
	for(int32_t i=0 ; i<10 ; i++)
	{
		if(abs(array03[i]%2)==0)
		{
			printf("%2d",array03[i]);
		}
	}
	
	
	printf("\n");
}








