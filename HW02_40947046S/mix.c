#include "mix.h"

//負號只在a那邊
//必為最簡分數
//沒有分數＝0/0 所以這個是合法的喔
//分母為0不合法 但記得寫進readme
int mixed_set( sMixedNumber *pNumber , int32_t a, int32_t b,int32_t c){
	if(c==0 && b!=0)return -1;
	if(c<b)return -1;
	if((a!=0) && (b<0))return -1;
	if(b==0 && c==0){
		pNumber->a=a;
		pNumber->b=0;
		pNumber->c=1;
	}
	else{
	pNumber->a=a;
	pNumber->b=b;
	pNumber->c=c;
	}
	
	return 0;
}
int least_common_multiple(int32_t x,int32_t y){
	for( int32_t i=1 ; i<=x*y ; ++i){
		if( (i%x==0) && (i%y==0) )return i;
	}
}


int mixed_print( const sMixedNumber number){
	printf("%d\\frac{%d}{%d}\n",number.a,number.b,number.c);
	return 0;
}
// in the form of (a,b,c)

void mixed_add( sMixedNumber *pNumber , const sMixedNumber r1,const sMixedNumber r2){
	int32_t tmp=least_common_multiple(r1.c,r2.c);
	int32_t r1_enlarge=tmp/r1.c;
	int32_t r2_enlarge=tmp/r2.c;
	sMixedNumber new_r1={0};
	sMixedNumber new_r2={0};	
	
	if(r1.a<0) new_r1.b=r1.a*tmp-r1.b*r1_enlarge;
	else new_r1.b=r1.a*tmp+r1.b*r1_enlarge;
	if(r2.a<0) new_r2.b=r2.a*tmp-r2.b*r2_enlarge;
	else new_r2.b=r2.a*tmp+r2.b*r2_enlarge;	
	
	pNumber->c=tmp;
	
	if((new_r1.b+new_r2.b)>0){
		pNumber->a=(int)(new_r1.b+new_r2.b)/tmp;
		pNumber->b=abs((new_r1.b+new_r2.b))%tmp;	
	}
	else{
		if((int)(abs(new_r1.b+new_r2.b)/tmp)==0){
			pNumber->a=-0;
			pNumber->b=0-abs((new_r1.b+new_r2.b))%tmp;	
		}
		else{
			pNumber->a=-(int)(abs(new_r1.b+new_r2.b)/tmp);
			pNumber->b=abs((new_r1.b+new_r2.b))%tmp;	
		}
	}
	
	for( int32_t i=abs(pNumber->b) ; i>1 ; --i ){
		if( (pNumber->b%i==0) && (pNumber->c%i==0) ){
			pNumber->b/=i;
			pNumber->c/=i;
			break;
		}
	}
	
	if(pNumber->b==0)pNumber->c=0;
}
// pNumber = r1 + r2

void mixed_sub( sMixedNumber *pNumber , const sMixedNumber r1,const sMixedNumber r2){
	int32_t tmp=least_common_multiple(r1.c,r2.c);
	int32_t r1_enlarge=tmp/r1.c;
	int32_t r2_enlarge=tmp/r2.c;	
	sMixedNumber new_r1={0};
	sMixedNumber new_r2={0};	
	
	if(r1.a<0) new_r1.b=r1.a*tmp-r1.b*r1_enlarge;
	else new_r1.b=r1.a*tmp+r1.b*r1_enlarge;
	if(r2.a<0) new_r2.b=r2.a*tmp-r2.b*r2_enlarge;
	else new_r2.b=r2.a*tmp+r2.b*r2_enlarge;
	
	pNumber->c=tmp;
	
	if((new_r1.b-new_r2.b)>0){
		pNumber->a=(int)(new_r1.b-new_r2.b)/tmp;
		pNumber->b=abs((new_r1.b-new_r2.b))%tmp;
	}
	else{
		if((int)(abs(new_r1.b-new_r2.b)/tmp)==0){
			pNumber->a=0;
			pNumber->b=0-(abs((new_r1.b-new_r2.b))%tmp);
		}
		else {
			pNumber->a=0-(int)(abs(new_r1.b-new_r2.b)/tmp);
			pNumber->b=abs((new_r1.b-new_r2.b))%tmp;	
		}
	}	
	
	for( int32_t i=abs(pNumber->b) ; i>1 ; --i ){
		if( (pNumber->b%i==0) && (pNumber->c%i==0) ){
			pNumber->b/=i;
			pNumber->c/=i;
			break;
		}		
	}
	if(pNumber->b==0)pNumber->c=0;
}
// pNumber = r1 - r2
/*finish*/


void mixed_mul( sMixedNumber *pNumber , const sMixedNumber r1,const sMixedNumber r2){
	if(r1.a<0 && r2.a<0)pNumber->b=(r1.a*r1.c-r1.b)*(r2.a*r2.c-r2.b);
	if(r1.a<0 && r2.a>=0)pNumber->b=(r1.a*r1.c-r1.b)*(r2.a*r2.c+r2.b);
	if(r1.a>=0 && r2.a>=0)pNumber->b=(r1.a*r1.c+r1.b)*(r2.a*r2.c+r2.b);
	if(r1.a>=0 && r2.a<0)pNumber->b=(r1.a*r1.c+r1.b)*(r2.a*r2.c-r2.b);
	
	pNumber->c=r1.c*r2.c;

	for( int32_t i=abs(pNumber->b) ; i>1 ; --i ){
		if( (pNumber->b%i==0) && (pNumber->c%i==0) ){
			pNumber->b/=i;
			pNumber->c/=i;
			break;
		}		
	}
	
	if(pNumber->b >0){
		pNumber->a=(int)(pNumber->b/pNumber->c);	
		pNumber->b=pNumber->b%pNumber->c;
	}
	else if(pNumber->b <0){
		pNumber->a=0-(int)(abs(pNumber->b)/pNumber->c);
		if(pNumber->a==0)pNumber->b=0-abs(pNumber->b)%pNumber->c;
		else pNumber->b=abs(pNumber->b)%pNumber->c;
	}
			
	if(pNumber->b==0)pNumber->c=0;
}
// pNumber = r1 * r2

void mixed_div( sMixedNumber *pNumber , const sMixedNumber r1,const sMixedNumber r2){
	if(r1.a<0)pNumber->b=(r1.a*r1.c-r1.b)*r2.c;
	else pNumber->b=(r1.a*r1.c+r1.b)*r2.c;
	
	if(r2.a<0)pNumber->c=(r2.a*r2.c-r2.b)*r1.c;
	else pNumber->c=(r2.a*r2.c+r2.b)*r1.c;
	
	if((pNumber->c <0) && (pNumber->b <0) ){
		pNumber->c=abs(pNumber->c);
		pNumber->b=abs(pNumber->b);
	}
	
	for( int32_t i=abs(pNumber->b) ; i>1 ; --i ){
		if( (pNumber->b%i==0) && (pNumber->c%i==0) ){
			pNumber->b/=i;
			pNumber->c/=i;
			break;
		}		
	}
	
	if(pNumber->b >0){
		pNumber->a=(int)(pNumber->b/pNumber->c);	
		pNumber->b=pNumber->b%pNumber->c;
	}
	else if(pNumber->b <0){
		pNumber->a=0-(int)(abs(pNumber->b)/pNumber->c);
		if(pNumber->a==0)pNumber->b=0-abs(pNumber->b)%pNumber->c;
		else pNumber->b=abs(pNumber->b)%pNumber->c;
	}
			
	if(pNumber->b==0)pNumber->c=0;
}
// pNumber = r1 / r2