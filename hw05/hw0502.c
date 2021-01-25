#include <stdio.h>
#include <stdint.h>
#include "test2.h"
#include "function2.h"

	int32_t matrix_klop=0 , matrix_jlnp=0 , matrix_jkno=0 ;
	int32_t matrix_ilmp=0 , matrix_ikmo=0 , matrix_ijmn=0 ;
	int32_t determinant_a=0,determinant_b=0,determinant_c=0,determinant_d=0;

int main()
{

	
	matrix_2x2(matrix_klop,matrix_jlnp,matrix_jkno,matrix_ilmp,matrix_ikmo,matrix_ijmn,array);

	determinant(determinant_a,determinant_b,determinant_c,determinant_d,array,matrix_klop,matrix_jlnp,matrix_jkno,matrix_ilmp,matrix_ikmo,matrix_ijmn);
	
	printf("The matrix is\n");
	
	for(int32_t i=0 ; i<4 ; i++)
	{
		for(int32_t j=0 ; j<4 ; j++)
		{
			printf("%3d",array[i][j]);
		}
		printf("\n");
	}
	
	printf("The determinant is %d.\n",determinant_a-determinant_b+determinant_c-determinant_d);
	
return 0;
}
