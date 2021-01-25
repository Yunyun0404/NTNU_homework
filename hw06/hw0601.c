#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
	int64_t num=0;
	uint8_t *num_ptr=NULL;
	double position=0;
	double new_value=0;
	
	printf("Please input an integer: ");
	if((scanf("%ld", &num))==1)
	{
		printf("The integer: %ld\n",num);	
		num_ptr=&num;
		for(int32_t i=0 ; i<8 ; i++)
		{
			printf("(%d) 0x%02X ",i+1,*(num_ptr+i));
		}
		printf("\n");
		while(1)
		{
			printf("Please enter the position ( 1~8, 0:End): ");
			if((scanf("%lf",&position))==1 && position==(int)position && position>=0 && position<=8)
			{
				if(position==0)
				{
					return 0;
				}
				else
				{
					printf("Please enter the new value (0~255): ");
					if((scanf("%lf",&new_value))==1 && new_value==(int64_t)new_value && new_value>=0 && new_value<=255)
					{
						*(num_ptr+(int8_t)position-1)=new_value;
						printf("The integer: %ld\n",num);						
						for(int32_t i=0 ; i<8 ; i++)
						{
							printf("(%d) 0x%02X ",i+1,*(num_ptr+i));
						}
						printf("\n");
					}
					else
					{
						printf("Error message!\n");
						return 0;
					}
				}
			}
			else
			{
				printf("Error message!\n");
				return 0;
			}
		}
	}
	else
	{
		printf("Error message!\n");
	}
	
	return 0;
}
