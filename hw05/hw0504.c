#include <stdint.h>
#include <stdio.h>
#include "function4.h"
#include <math.h>

	double point_number=0;//點的數量
	double average_x=0,average_y=0; //平均數
	double five=0,six=0,seven=0; //七行表中的五六七
	double slope=0; //斜率
	double abc=0; //相關係數
		
int main()
{

	printf("Please enter the point number: ");
	if(scanf("%lf",&point_number)==1 && point_number==(int)point_number)
	{
		double point_x[(int)point_number];
		double point_y[(int)point_number];		
		double difference_x[(int)point_number];
		double difference_y[(int)point_number];		
		double three[(int)point_number];	
		double four[(int)point_number];	
		double three_four[(int)point_number];		
			
		for(size_t i=0 ; i<point_number ; i++)
		{
			printf("Please enter Point %lu: ",i+1);
			if(scanf("%lf %lf",&point_x[i],&point_y[i])!=2)
			{
				printf("Error message!\n");
				return 0;
			}
		}
		Average_x(point_number,average_x,point_x);
		average_x=Average_x(point_number,average_x,point_x);

		Average_y(point_number,average_y,point_y);
		average_y=Average_y(point_number,average_y,point_y);

		
		correlation_coefficient(point_number,average_x,average_y,point_x,point_y,three,four,three_four,five,six,seven,abc,slope);		
	}
	else
	{
		printf("Error message!\n");	
	}

return 0;
}
