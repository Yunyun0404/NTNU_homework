#include "myvector.h"
#include <math.h>
/*
反省：
    不能無視const
    要注意->跟.的用法
*/

sVector * myvector_init(){
     sVector *ptr = calloc(1,sizeof(sVector));
     return ptr; 
}

// If error , return -1; otherwise , return 0;
/*
pVector 是 pointer: 拿 member 要用 ->
data 不是 pointer : 拿 member 要用 .

typedef struct _sVector{
    uint8_t type; // 1: Cartesian coordinates; 2: polar coordinates
    union Component{
        struct _sCartesian{
            double x;
            double y;
        } c;
        struct _sPolar{
            double distance;
            double angle;
        } p;
    } data;
}sVector;
*/
void change_to_c(sVector *pVector){
    //極座標轉直角
    double dis  = pVector->data.p.distance;
    double angle= pVector->data.p.angle;
    pVector->type = 1;
    pVector->data.c.x = dis*cos(angle);
    pVector->data.c.y = dis*sin(angle);
}

void change_to_p(sVector *pVector){
    //直角作標轉極座標
    double x = pVector->data.c.x;
    double y = pVector->data.c.y;
    pVector->type = 2;
    pVector->data.p.distance = sqrt( pow(x,2)+pow(y,2) );
    pVector->data.p.angle    = atan2(y,x);
}

int myvector_set( sVector *pVector , uint8_t type, double a, double b ){
    //double atan2  (double y,double x); return 弧度 
    if(type==1){
        pVector->type=1;
        pVector->data.c.x = a;
        pVector->data.c.y = b;
        return 0;
    }else if(type==2){
        pVector->type=2;
        pVector->data.p.distance = a;
        pVector->data.p.angle    = b;
        return 0;
    }else return -1;
}

/* 
Print the given vector according to the given type.
If Cartesian , print (x,y).
If polar , print (distance , theta -pi). EX: distance=2 and angle=90 degree ,print (2,0.5-pi).
Theta must be between 0 and 2.
If error , return -1; otherwise , return 0;
*/
int myvector_print( const sVector *pVector , uint8_t type ){
    sVector B = *pVector;
    if(type==1){
        if(B.type==1){
            printf("(%lf,%lf)\n",B.data.c.x,B.data.c.y);
            return 0;
        }else if(B.type==2){
            change_to_c(&B);
            printf("(%lf,%lf)\n",B.data.c.x,B.data.c.y);
            return 0;
        }else return -1;
    }else if(type==2){
        if(B.type==1){
            change_to_p(&B);
            printf("(%lf , %lf *pi)\n",B.data.p.distance,B.data.p.angle/M_PI);            
            return 0;
        }else if(B.type==2){
            printf("(%lf , %lf *pi)\n",B.data.p.distance,B.data.p.angle/M_PI);
            return 0;
        }else return -1;
    }
}

/* 
A = B + C
A's type is set to B's type.
If error , return -1; otherwise , return 0;
*/
int myvector_add( sVector *pA, const sVector *pB, const sVector *pC ){
    sVector B = *pB, C = *pC;
    if( (B.type==1 ||B.type==2) && (C.type==1 || C.type==2) ){

    }else return -1;

    int32_t type=B.type;
    if(B.type==2)change_to_c(&B);
    if(C.type==2)change_to_c(&C);
    pA->data.c.x=B.data.c.x+C.data.c.x;
    pA->data.c.y=B.data.c.y+C.data.c.y;
    pA->type=1;
    if(type==2)change_to_p(pA);
    return 0;
}

// A = B dot C
// If error , return -1; otherwise , return 0;
int myvector_inner_product( double *pA, const sVector *pB, const sVector *pC ){
    sVector B = *pB, C = *pC;
    if( (B.type==1 ||B.type==2) && (C.type==1 || C.type==2) ){

    }else return -1;

    if(B.type==2)change_to_c(&B);
    if(C.type==2)change_to_c(&C);
    *pA=B.data.c.x*C.data.c.x+B.data.c.y*C.data.c.y;
    return 0;
}

// Get the area of the parallelogram spanned by two vectors.
// If error , return -1; otherwise , return 0;
int myvector_area( double *pArea , const sVector *pB, const sVector *pC ){
    sVector B = *pB, C = *pC;
    if( (B.type==1 ||B.type==2) && (C.type==1 || C.type==2) ){

    }else return -1;

    double inner=0;
    myvector_inner_product( &inner, pB, pC );
    double c=0;
    c=inner/( sqrt( pow(B.data.c.x,2)+pow(B.data.c.y,2) )*sqrt( pow(C.data.c.x,2)+pow(C.data.c.y,2) ) );
    double theta=0;
    theta=acos(c);

    *pArea=( sqrt( pow(B.data.c.x,2)+pow(B.data.c.y,2) )*sqrt( pow(C.data.c.x,2)+pow(C.data.c.y,2) ) )*sin(theta);
    return 0;
}

int myvector_cvp( double *pX, double *pY, const double *pTx, const double *pTy, const sVector *pA, const sVector *pB ){
    *pX=0;
    *pY=0;
    printf("I haven't done.\n");
    return 0;
}