#include <stdio.h>
#include <stdint.h>

void print_card(const uint8_t player[13])
{
	for(int32_t i=0 ; i<=12 ;i++)
	{
		printf("%u ",player[i]);
	}
	printf("\n");
}

int32_t sort_card(uint8_t player[13],int32_t (*compare)(int32_t ,int32_t ))
{
	for(int32_t i=0 ; i<=12 ; i++)
	{
		for(int32_t j=i+1 ; j<=12 ; j++)
		{
			if(compare(player[i],player[j]))
			{
				int32_t tmp=player[i];
				player[i]=player[j];
				player[j]=tmp;
			}
		}
	}
}

int32_t func01(int32_t a,int32_t b)
{
	if(a%13==1)
	{
		return 0;
	}
	else if(b%13==1)
	{
		return 1;
	}
	else
	{
		return ((a-1)%13)<((b-1)%13);
	}
}


int32_t func02(int32_t a,int32_t b)
{
	if(a%13==2)
	{
		return 0;
	}
	else if(b%13==2)
	{
		return 1;
	}
	else
	{
		return func01(a,b);
	}


}

int32_t func03(int32_t a,int32_t b)
{	
	int32_t a_color=(a-1)/13;
	int32_t b_color=(b-1)/13;
	
	if(a_color<b_color)
	{
		return 0;
	}
	else if(a_color>b_color)
	{
		return 1;
	}
	else
	{
		return func01(a,b);
	}
}

