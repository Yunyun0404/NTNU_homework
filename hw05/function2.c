#include <stdint.h>
#include <stdio.h>


void matrix_2x2(int32_t matrix_klop,int32_t matrix_jlnp,int32_t matrix_jkno,int32_t matrix_ilmp,int32_t matrix_ikmo,int32_t matrix_ijmn,int32_t array01[4][4])
{
	matrix_klop=array01[2][2]*array01[3][3]-array01[2][3]*array01[3][2];
	matrix_jlnp=array01[2][1]*array01[3][3]-array01[2][3]*array01[3][1];	
	matrix_jkno=array01[2][1]*array01[3][2]-array01[2][2]*array01[3][1];
	matrix_ilmp=array01[0][2]*array01[3][3]-array01[2][3]*array01[0][3];
	matrix_ikmo=array01[0][2]*array01[3][2]-array01[2][2]*array01[0][3];
	matrix_ijmn=array01[0][2]*array01[3][1]-array01[2][1]*array01[0][3];
}

void determinant(int32_t determinant_a,int32_t determinant_b,int32_t determinant_c,int32_t determinant_d,int32_t array01[4][4],int32_t matrix_klop,int32_t matrix_jlnp,int32_t matrix_jkno,int32_t matrix_ilmp,int32_t matrix_ikmo,int32_t matrix_ijmn)
{
	determinant_a=array01[0][0]*(array01[1][1]*matrix_klop-array01[1][2]*matrix_jlnp+array01[1][3]*matrix_jkno);
	determinant_b=array01[0][1]*(array01[1][0]*matrix_klop-array01[1][2]*matrix_ilmp+array01[1][3]*matrix_ikmo);
	determinant_c=array01[0][2]*(array01[1][0]*matrix_jlnp-array01[1][1]*matrix_ilmp+array01[1][3]*matrix_ijmn);	
	determinant_d=array01[0][3]*(array01[1][0]*matrix_jkno-array01[1][1]*matrix_ikmo+array01[1][2]*matrix_ijmn);
}
