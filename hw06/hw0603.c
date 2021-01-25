#include <stdio.h>
#include <stdint.h>
#include <math.h>            //記得-lm啦
#include "function3.h"

int main()
{
	double x=0,y=0;
	double *x_ptr=NULL;
	double *y_ptr=NULL;
	double theta=0;
	
	printf("Please enter a point: ");
	if(scanf("%lf %lf",&x,&y)==2)
	{
		printf("Please enter the theta (0~360): ");
		if(scanf("%lf",&theta)==1 && theta>=0 && theta <=360)
		{
			x_ptr=&x;
			y_ptr=&y;
			rotate(x_ptr,y_ptr,theta);
			printf("%lf %lf\n",x,y);
		}
		else
		{
			printf("Error message!\n");
		}
	}
	else
	{
		printf("Error message!\n");
	}
	
	return 0;
}
