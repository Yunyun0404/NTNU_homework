#include <stdio.h>
#include <stdint.h>

#define red "\033[0;32;31m"
#define none "\033[m"

typedef union{
	double num;
	int64_t integer;
}doubletype;

int main()
{
	doubletype input;
	char fraction[53]={0};
	char exponent[12]={0};
	char sign=0;
	double copy=0;
	int32_t none_fraction=0;
	int num_exp=0;
	int index=0;
	
	printf("Please enter a floating-point number (");
	printf(red"double"none);
	printf(" precision): ");
	
	if(scanf("%lf",&input.num)==0){
		printf("Error input!\n");
		return 0;
	}
	
	copy=input.num;
	
	for(int32_t i=51 ; i>=0 ; --i){
		fraction[i]=(input.integer & 1)+'0';
		input.integer=input.integer>>1;
	}
	
	for(int32_t i=10 ; i>=0 ; --i){
		exponent[i]=(input.integer & 1)+'0';
		input.integer=input.integer>>1;
	}
	
	sign=(input.integer & 1)+'0';
	
	printf("Sign: %c\n",sign);
	printf("Exponent: %s\n",exponent);
	printf("Fraction: %s\n",fraction);
	
	printf("%lf = ",copy);
	printf("(-1)^%c * ",sign);
	
	for(int32_t y=0 ; y<52 ; ++y){
		if(fraction[y]==0)none_fraction++;
	}
	
	if(none_fraction!=52){
		printf("(1 ");
		for(int32_t i=0 ; i<52 ; ++i){
			if(fraction[i]=='1')printf("+ 2^-%d ",i+1);
		}
		printf(") * ");
	}
	
	index=1;
	for(int32_t i=10 ; i>=0 ; --i){
		if(exponent[i]=='1')num_exp+=index;
		index*=2;
	}
	printf("2^(%d-1023)\n",num_exp);
	
	return 0;
}
