//函數
#include <stdio.h>
#include <stdint.h>

void ones (int32_t number)
{
	int32_t number_ones =0;
	number_ones=number%10;
	
	
	if (number_ones==1)
	{
		printf("I");
	}
	else if (number_ones==2)
	{
		printf("II");
	}
	else if (number_ones==3)
	{
		printf("III");
	}
	else if (number_ones==4)
	{
		printf("IV");
	}
	else if (number_ones==5)
	{
		printf("V");
	}
	else if (number_ones==6)
	{
		printf("VI");
	}
	else if (number_ones==7)
	{
		printf("VII");
	}
	else if (number_ones==8)
	{
		printf("VIII");
	}
	else if (number_ones==9)
	{
		printf("IX");
	}
}


void tens (int32_t number)
{
	int32_t number_tens=0;
	number_tens=(number/10)%10;
	
	
	if (number_tens==1)
	{
		printf("X");
	}
	else if (number_tens==2)
	{
		printf("XX");
	}
	else if (number_tens==3)
	{
		printf("XXX");
	}
	else if (number_tens==4)
	{
		printf("XL");
	}
	else if (number_tens==5)
	{
		printf("L");
	}
	else if (number_tens==6)
	{
		printf("LX");
	}
	else if (number_tens==7)
	{
		printf("LXX");
	}
	else if (number_tens==8)
	{
		printf("LXXX");
	}
	else if (number_tens==9)
	{
		printf("XC");
	}
}

void hundreds (int32_t number)
{
	int32_t number_hundreds=0;
	number_hundreds=(number/100)%10;
	
	
	if(number_hundreds==1)
	{
		printf("C");
	}
	else if(number_hundreds==2)
	{
		printf("CC");
	}
	else if(number_hundreds==3)
	{
		printf("CCC");
	}
	else if(number_hundreds==4)
	{
		printf("CD");
	}
	else if(number_hundreds==5)
	{
		printf("D");
	}
	else if(number_hundreds==6)
	{
		printf("DC");
	}
	else if(number_hundreds==7)
	{
		printf("DCC");
	}
	else if(number_hundreds==8)
	{
		printf("DCCC");
	}
	else if(number_hundreds==9)
	{
		printf("CM");
	}
}

void thousands (int32_t number)
{

	if(number>2000)
	{
		printf("MM");
	}
	else if(number>1000)
	{
		printf("M");
	}

}






















