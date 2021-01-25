#include <stdio.h>
#include <stdint.h>
#include <math.h>

void rotate(double *x_ptr,double *y_ptr,double theta)
{
	int32_t tmp=*x_ptr;
	*x_ptr=*x_ptr*cos(theta*3.14159265358979323846/180)+*y_ptr*sin(theta*3.14159265358979323846/180);
	*y_ptr=-tmp*sin(theta*3.14159265358979323846/180)+*y_ptr*cos(theta*3.14159265358979323846/180);
}
