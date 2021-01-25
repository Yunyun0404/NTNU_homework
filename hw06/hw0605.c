#include <stdio.h>
#include <stdint.h>
#include "function5.h"
#include "test.h"

int main()
{
	for(int32_t i=0 ; i<=12 ; i++)
	{
		for(int32_t u=0 ; u<=12 ; u++)
		{
			if(player1[i]==player2[u])
			{
				printf("Error message!\n");
				return 0;
			}
		}
	}	
	for(int32_t i=0 ; i<=1 ; i++)
	{
		for(int32_t u=0 ; u<=12 ; u++)
		{
			if(player1[i]==player3[u])
			{
				printf("Error message!\n");
				return 0;
			}
		}
	}
	for(int32_t i=0 ; i<=12 ; i++)
	{
		for(int32_t u=0 ; u<=12 ; u++)
		{
			if(player1[i]==player4[u])
			{
				printf("Error message!\n");
				return 0;
			}
		}
	}
	for(int32_t i=0 ; i<=12 ; i++)
	{
		for(int32_t u=0 ; u<=12 ; u++)
		{
			if(player2[i]==player3[u])
			{
				printf("Error message!\n");
				return 0;
			}
		}
	}
	for(int32_t i=0 ; i<=12 ; i++)
	{
		for(int32_t u=0 ; u<=12 ; u++)
		{
			if(player2[i]==player4[u])
			{
				printf("Error message!\n");
				return 0;
			}
		}
	}
	for(int32_t i=0 ; i<=12 ; i++)
	{
		for(int32_t u=0 ; u<=12 ; u++)
		{
			if(player3[i]==player4[u])
			{
				printf("Error message!\n");
				return 0;
			}
		}
	}	
	for(int32_t i=0 ; i<=12 ; i++)
	{
		for(int32_t u=i+1 ; u<=12 ; u++)
		{
			if(player1[i]==player1[u])
			{
				printf("Error message!\n");
				return 0;
			}
		}
	}
	for(int32_t i=0 ; i<=12 ; i++)
	{
		for(int32_t u=i+1 ; u<=12 ; u++)
		{
			if(player2[i]==player2[u])
			{
				printf("Error message!\n");
				return 0;
			}
		}
	}
	for(int32_t i=0 ; i<=12 ; i++)
	{
		for(int32_t u=i+1 ; u<=12 ; u++)
		{
			if(player3[i]==player3[u])
			{
				printf("Error message!\n");
				return 0;
			}
		}
	}
	for(int32_t i=0 ; i<=12 ; i++)
	{
		for(int32_t u=i+1 ; u<=12 ; u++)
		{
			if(player4[i]==player4[u])
			{
				printf("Error message!\n");
				return 0;
			}
		}
	}

					
	printf("Before:\n");
	print_card( player1 );
	print_card( player2 );
	print_card( player3 );
	print_card( player4 );
	printf("Type 01:\n");
	sort_card( player1,func01 );
	sort_card( player2,func01 );
	sort_card( player3,func01 );
	sort_card( player4,func01 );
	print_card( player1 );
	print_card( player2 );
	print_card( player3 );
	print_card( player4 );
	printf("Type 02:\n");
	sort_card( player1,func02 );
	sort_card( player2,func02 );
	sort_card( player3,func02 );
	sort_card( player4,func02 );
	print_card( player1 );
	print_card( player2 );
	print_card( player3 );
	print_card( player4 );
	printf("Type 03:\n");
	sort_card( player1,func03 );
	sort_card( player2,func03 );
	sort_card( player3,func03 );
	sort_card( player4,func03 );
	print_card( player1 );
	print_card( player2 );
	print_card( player3 );
	print_card( player4 );
	return 0;
}
