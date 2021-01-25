#include <stdio.h>
#include <stdint.h>

void print_plane(int32_t a,int32_t b,int32_t c,int32_t d)
{
	if(a==0 && b==0 && d==0)
	{
		printf("The plane is %dz=0\n",c);
	}
	else if(a==0 && c==0 && d==0)
	{
		printf("The plane is %dy=0\n",b);
	}
	else if(b==0 && c==0 && d==0)
	{
		printf("The plane is %dx=0\n",a);		
	}
	else if(a==0 && d==0)
	{
		printf("The plane is %dy+(%d)z=0\n",b,c);		
	}
	else if(a==0 && b==0)
	{
		printf("The plane is %dz+(%d)=0\n",c,d);		
	}
	else if(a==0 && c==0)
	{
		printf("The plane is %dy+(%d)=0\n",b,d);
	}
	else if(b==0 && c==0)
	{
		printf("The plane is %dx+(%d)=0\n",a,d);
	}
	else if(b==0 && d==0)
	{
		printf("The plane is %dx+(%d)z=0\n",a,c);
	}
	else if(c==0 && d==0)
	{
		printf("The plane is %dx+(%d)y=0\n",a,b);
	}
	else if(a==0)
	{
		printf("The plane is %dy+(%d)z+(%d)=0\n",b,c,d);
	}
	else if(b==0)
	{
		printf("The plane is %dx+(%d)z+(%d)=0\n",a,c,d);
	}
	else if(c==0)
	{
		printf("The plane is %dx+(%d)y+(%d)=0\n",a,b,d);
	}
	else if(d==0)
	{
		printf("The plane is %dx+(%d)y+(%d)z=0\n",a,b,c);
	}
	else
	{
		printf("The plane is %dx+(%d)y+(%d)z+%d=0\n",a,b,c,d);
	}
}



void project(double *x,double *y, double *z, int32_t a,int32_t b, int32_t c, int32_t d)
{
	double t=0;
	
	t=(-d-a*(*x)-b*(*y)-c*(*z))/(a*a+b*b+c*c);
	printf("The projection is (%lf,%lf,%lf)\n",*x+a*t,*y+b*t,*z+c*t);
}








