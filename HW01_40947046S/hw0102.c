#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#define blue "\033[0;32;34m"
#define red "\033[0;32;31m"
#define end "\033[m"


int main()
{
	char text[1025]={0};
	char ans[1025]={0};
	char key[130]={0};
	char change[130]={0};
	int32_t length=0;
	char *needle=ans;
	char *pointer=NULL;
	
	printf("Please enter the original text:\n");
	fgets(text,1025,stdin);
	text[strlen(text)-1]='\0';
	strncpy(ans,text,1024);
		
	printf("Keyword:\n");
	printf(blue);
	fgets(key,129,stdin);
	printf(end);
	key[strlen(key)-1]='\0';
	int32_t strlen_key=strlen(key);
	
	printf("New word:\n");
	printf(red);
	fgets(change,129,stdin);
	printf(end);
	change[strlen(change)-1]='\0';
	int32_t strlen_change=strlen(change);
	
	length=strlen_change-strlen_key;
	pointer=strstr(needle,key);
	

	while(pointer!=NULL)
	{
	//移動位置(<：大家都往前n格  >：大家都往後n格)
		if(length<0)
		{
			for(int32_t i=pointer-needle+strlen(change) ; i<strlen(ans)+length ; ++i)
			{
				ans[i]=ans[i-strlen(change)+strlen(key)];
			}
		}
		else if(length>0)
		{
			for(int32_t i=strlen(ans)-1 ; i>=pointer-needle ; --i)
			{
				ans[i+length]=ans[i];
			}
		}
	//移動位置end
	
		strncpy(pointer,change,strlen_change);
		needle=pointer+strlen_change;
		pointer=strstr(needle,key);
	}
	
	printf("\nBefore:\n");
//printf("%s\n",text);
	for(int32_t i=0 ; i<strlen(text) ; ++i)
	{
		if(strncmp(text+i,key,strlen_key)==0)
		{
			printf(blue"%s"end,key);
			i=i+strlen_key-1;
		}
		else printf("%c",text[i]);
	}

	printf("\nAfter:\n");
	for(int32_t i=0 ; i<strlen(ans) ; ++i)
	{
		if(strncmp(ans+i,change,strlen_change)==0)
		{
			printf(red"%s"end,change);
			i=i+strlen_change-1;
		}
		else printf("%c",ans[i]);
	}
	printf("\n");
	
	return 0;
}
