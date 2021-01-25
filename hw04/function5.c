#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

#define YELLOW "\033[1;33m"

void game (int32_t answerA,int32_t answerB,int32_t answerC,int32_t answerD);
void AB (int32_t answerA,int32_t answerB,int32_t answerC,int32_t answerD,int32_t A,int32_t B,int32_t guess_answer);

void make_answer (int32_t answerA,int32_t answerB,int32_t answerC,int32_t answerD)
{
//以下為利用亂數製造答案
	
	srand(time(0));
	answerA= rand()%10;
	answerB= rand()%10;	
	answerC= rand()%10;
	answerD= rand()%10;	
	
	while(answerA==answerB)
	{
		answerB= rand()%10;
	}
	
	while(answerA==answerC || answerB==answerC)
	{
		answerC= rand()%10;
	}
	
	while(answerA==answerD || answerB==answerD || answerC==answerD)
	{
		answerD= rand()%10;	
	}
	
	game (answerA,answerB,answerC,answerD);
//以上製造好亂數的答案了
}



void game (int32_t answerA,int32_t answerB,int32_t answerC,int32_t answerD)
{
	int32_t guess_answer=0;
	int32_t A=0,B=0;
	
	for(int32_t round=1 ; guess_answer!=(1000*answerA+100*answerB+10*answerC+answerD) ; round++ )
	{	
		printf("Round %d >>>\n",round);
		printf("    Your guess: ");
		if(scanf("%d", &guess_answer)==1)
		{
			if(guess_answer<100 || guess_answer>9999)
			{
				printf("Invalid guess!\n");
			}
			else
			{
				AB (answerA,answerB,answerC,answerD,A,B,guess_answer);
			}
		}
		else
		{
			printf("Invalid guess!!\n");
			break;
		}
		
			

	}

}

void AB (int32_t answerA,int32_t answerB,int32_t answerC,int32_t answerD,int32_t A,int32_t B,int32_t guess_answer)
{
		int32_t guess_answerA=0,guess_answerB=0,guess_answerC=0,guess_answerD=0;
		A=0;
		B=0;
		
		//把猜的數字分離開來
		guess_answerA=(guess_answer/1000)%10;
		guess_answerB=(guess_answer/100)%10;
		guess_answerC=(guess_answer/10)%10;
		guess_answerD=guess_answer%10;
		//以上分離完畢
		
		//數字不能重複
		if(guess_answerA==guess_answerB)
		{
			printf("Invalid guess!\n");
		}
		else if(guess_answerA==guess_answerC)
		{
			printf("Invalid guess!\n");
		}
		else if(guess_answerA==guess_answerD)
		{
			printf("Invalid guess!\n");
		}
		else if(guess_answerB==guess_answerC)
		{
			printf("Invalid guess!\n");
		}
		else if(guess_answerB==guess_answerD)
		{
			printf("Invalid guess!\n");
		}
		else if(guess_answerC==guess_answerD)
		{
			printf("Invalid guess!\n");	
		}
		else
		{
			//判斷幾A幾B
			if(guess_answerA==answerA)
			{
				A+=1;
			}
			else if(guess_answerA==answerB || guess_answerA==answerC || guess_answerA==answerD)
			{
				B+=1;
			}
				
			if(guess_answerB==answerB)
			{
				A+=1;
			}
			else if(guess_answerB==answerA || guess_answerB==answerC || guess_answerB==answerD)
			{
				B+=1;
			}			
		
			if(guess_answerC==answerC)
			{
				A+=1;
			}
			else if(guess_answerC==answerA || guess_answerC==answerB || guess_answerC==answerD)
			{
				B+=1;
			}			
		
			if(guess_answerD==answerD)
			{
				A+=1;
			}
			else if(guess_answerD==answerA || guess_answerD==answerB || guess_answerD==answerC)
			{
				B+=1;
			}			
			
			printf(YELLOW"Response: %d A %d B\n\033[1;0m",A,B);	
		
			if(A==4)
			{
				printf(YELLOW"Response: Bingo!! Congratulations.\n\033[1;0m");
			}
		}
}





