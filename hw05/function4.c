#include <math.h>
#include <stdint.h>
#include <stdio.h>


double Average_x(double point_number,double average_x,double point_x[])
{
	for(size_t i=0 ; i<point_number ; i++) //計算x的平均值
	{
			average_x=average_x+point_x[i];
	}
	average_x=average_x/point_number;
	return average_x;
}
double Average_y(double point_number,double average_y,double point_y[])
{
	for(size_t i=0 ; i<point_number ; i++) //計算y的平均值
	{
		average_y=average_y+point_y[i];
	}
	average_y=average_y/point_number;
	return average_y;
}
void correlation_coefficient(double point_number,double average_x,double average_y,double point_x[],double point_y[],double three[],double four[],double three_four[],double five,double six,double seven,double abc,double slope)
{
	for(size_t i=0 ; i<point_number ; i++) //計算七行表中三的平方
	{
		three[i]=(average_x-point_x[i])*(average_x-point_x[i]);
	}

	for(size_t i=0 ; i<point_number ; i++) //計算七行表中4的平方
	{
		four[i]=(average_y-point_y[i])*(average_y-point_y[i]);
	}

	for(size_t i=0 ; i<point_number ; i++) //計算七行表中3x4
	{
		three_four[i]=(average_x-point_x[i])*(average_y-point_y[i]);

	}

	for(size_t i=0 ; i<point_number ; i++) //計算七行表中5
	{
		five=five+three[i];	
	}

	for(size_t i=0 ; i<point_number ; i++) //計算七行表中6
	{
		six=six+four[i];
	}

	for(size_t i=0 ; i<point_number ; i++) //計算七行表中7
	{
		seven=seven+three_four[i];
	}



	abc=seven/sqrt(five*six);
	slope=abc*sqrt(six/point_number)/sqrt(five/point_number);
		
	printf("y = %f x + %f\n",slope,average_y-average_x*slope);
	
}
