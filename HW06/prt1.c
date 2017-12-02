#include <stdio.h>
#include  <string.h>

void freq(char* str, int* fr);

int main(){
	
	int fr[37];
	freq("abCd Ef ghIj kLM nopr stuv yzwxq 19  23 4 5 6 7 890 0 ?? |",fr);

	return 0;
}

void freq(char* str, int* fr){

	int i,j,len;
	
	len = strlen(str);
	
	for(i=0;i<37;i++)
	{
		fr[i]=0;
	}
	
	for(i=0;i<len;i++)
	{
		if(  ( (int)str[i]>=(int)'a' && (int)str[i]<=(int)'z' ) || 
		( (int)str[i]>=(int)'A' && (int)str[i]<=(int)'Z' ) || 
		( (int)str[i]>=(int)'0' && (int)str[i]<=(int)'9' )  )
		{	
			for(j=(int)'a';j<=(int)'z';j++)
			{
				if((int)str[i] == j)
				{
					fr[j-(int)'a'] +=1; 
				}		
			}
			for(j=(int)'A';j<=(int)'Z';j++)
			{
				if((int)str[i] == j)
				{
					fr[j-(int)'A'] +=1; 
				}		
			}
			for(j=(int)'0';j<=(int)'9';j++)
			{
				if((int)str[i] == j)
				{
					fr[26+j-(int)'0'] +=1; 
				}		
			}
		}
		else
		{
			fr[36] +=1;
		}	
	}
	for(i=0;i<37;i++)
	{
		printf("%d ",fr[i]);
	}
	printf("\n");
	return;
}
