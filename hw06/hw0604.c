#include <stdio.h>
#include <stdint.h>
#include "function4.h"

int main()
{
	int32_t a=0,b=0,c=0,d=0;
	double point_x=0,point_y=0,point_z=0;
	
	double *x=NULL;
	double *y=NULL;
	double *z=NULL;	
	
	printf("Please enter the plane: ");
	if(scanf("%d %d %d %d",&a,&b,&c,&d)==4)
	{
		//function4.c
		print_plane(a,b,c,d);
		
		printf("Please enter the point: ");
		
		if(scanf("%lf %lf %lf", &point_x, &point_y, &point_z)==3)
		{
			x=&point_x;
			y=&point_y;
			z=&point_z;
			
		//寫function4.c囉
			project(x,y,z,a,b,c,d);
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
			
	return 0;
}
