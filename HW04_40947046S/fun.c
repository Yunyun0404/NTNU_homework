#include "fun.h"

void money_modify(uint32_t *money){
    printf("-----------------------------------------------------\n");
    uint32_t tmp=0;
    printf("Please input the value "yellow"(0~4294967295)"none"\n");
    if( scanf("%u",&tmp)==1 && (tmp<=4294967295U) ){
        *money=tmp;
    }
}

void attr_modify(Attribute *att){
    int32_t flag=0;
    uint16_t value=0;
    printf("---------------------------------------------------------------------\n");
    printf("1. Would you want to modify the "yellow"stamina ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->stamina=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("2. Would you want to modify the "yellow"wrist strength ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->strnth=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("3. Would you want to modify the "yellow"intelligence ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->intell=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("4. Would you want to modify the "yellow"elegance ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->elegance=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("5. Would you want to modify the "yellow"glamour ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->glamour=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("6. Would you want to modify the "yellow"morality ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->morality=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("7. Would you want to modify the "yellow"faith ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->faith=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("8. Would you want to modify the "yellow"karma ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->karma=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("9. Would you want to modify the "yellow"sensitive ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->senstv=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("10. Would you want to modify the "yellow"stress ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->stress=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("11. Would you want to modify the "yellow"war evaluation ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->war_rep=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("12. Would you want to modify the "yellow"magic evaluation ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->magic_rep=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("13. Would you want to modify the "yellow"social evaluation ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->social_rep=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("14. Would you want to modify the "yellow"housework evaluation ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->housework_rep=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("15. Would you want to modify the "yellow"war skill ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->war_skill=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("16. Would you want to modify the "yellow"attack ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->attack=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("17. Would you want to modify the "yellow"defense ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->def=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("18. Would you want to modify the "yellow"magic skill ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->mag_skill=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("19. Would you want to modify the "yellow"magic attack ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->mag_atk=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("20. Would you want to modify the "yellow"magic defense ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->mag_def=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("21. Would you want to modify the "yellow"manner ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->manner=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("22. Would you want to modify the "yellow"art ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->art=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("23. Would you want to modify the "yellow"speech ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->speech=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("24. Would you want to modify the "yellow"cooking ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->cooking=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("25. Would you want to modify the "yellow"housework ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->housework=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
    printf("26. Would you want to modify the "yellow"personal ( 1:yes ; 0:no )"none" ?\n");
    if( scanf("%d",&flag)==1 && flag==1 ){
        printf("value: ");
        if( scanf("%hu",&value)==1 ){
            att->personal=value;
        }else{
            printf("error input,keep original value.\n");
        }
    }else if(flag==0){
    
    }else{
        printf("error input\n");
    }
}

void health_modify(uint16_t *health){
    printf("-----------------------------------------------------\n");
    uint16_t tmp=0;
    printf("Please input the value "yellow"(0~100)"none"\n");
    if( scanf("%hu",&tmp)==1 && tmp<=100 ){
        *health=tmp;
    }
}

void print_att_0(Attribute *att){
    printf("%hu\n",att->stamina);
    printf("%hu\n",att->strnth);
    printf("%hu\n",att->intell);
    printf("%hu\n",att->elegance);
    printf("%hu\n",att->glamour);
    printf("%hu\n",att->morality);
    printf("%hu\n",att->faith);
    printf("%hu\n",att->karma);
    printf("%hu\n",att->senstv);
    printf("%hu\n",att->stress);
    
    printf("%hu\n",att->war_rep);
    printf("%hu\n",att->magic_rep);
    printf("%hu\n",att->social_rep);
    printf("%hu\n",att->housework_rep);
    
    printf("%hu\n",att->war_skill);
    printf("%hu\n",att->attack);
    printf("%hu\n",att->def);
    printf("%hu\n",att->mag_skill);
    printf("%hu\n",att->mag_atk);
    printf("%hu\n",att->mag_def);

    printf("%hu\n",att->manner);
    printf("%hu\n",att->art);
    printf("%hu\n",att->speech);
    printf("%hu\n",att->cooking);
    printf("%hu\n",att->housework);
    printf("%hu\n",att->personal);
}