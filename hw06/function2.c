#include <stdio.h>
#include <stdint.h>

int func()
{
	int32_t input[10]={0};
	double test=0;
	int32_t count=0;	
	int32_t buffer[10]={0};
	int32_t buffer_number=0;
	
	while(1)
	{
		printf("input: ");
		if(scanf("%lf",&test)==1 && test==(int)test && (test==-2 ||test==-1 || test>=0))
		{				
			if(test==0)
			{
				count--;
				break;
			}
			else if(test==-1)
			{
				buffer[buffer_number]=input[count-1];
				buffer_number+=1;
				count-=1;
			}
			else if(test==-2)
			{
				input[count]=buffer[buffer_number-1];
				buffer[buffer_number-1]=0;
				if(input[count]==0)
				{
				
				}
				else
				{
					count+=1;
				}
			}
			else
			{
				if(count==10)
				{
				for(int32_t x=0 ; x<9 ;x++)
				{	
					input[x]=input[x+1];
				}
				count--;
				}
				
				input[count]=(int)test;
				if(count<10)count++;
			}
			
			
		}
		else
		{
			printf("Error message!\n");
			return 0;
		}
	}
	
	printf("Result: ");
	for(int32_t i=0 ; i<=count ;i++)
	{
		printf("%d ",(int)input[i]);
	}
	printf("\n");
}


















