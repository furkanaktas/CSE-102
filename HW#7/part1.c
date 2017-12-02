/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW07_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş_Part1.c                                             */
/* ----------------------------------                                         */
/* Created on 14/04/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		141044029_Furkan_Aktaş_Part1.c contains codes for the first part of   */
/*	the homework VII, which checks whether the string is palindrome.		  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* Function isPalindrome                                                      */
/* ------------------                                                         */
/* Bu fonksiyon verilen string'in kontrolünü yapar,uzunluğunu bulur.          */
/*----------------------------------------------------------------------------*/

/* Function palindrome                                                        */
/* ------------------                                                         */
/* Bu fonksiyon verilen string'in palindrome olup olamdığına bakar.		      */
/*----------------------------------------------------------------------------*/

#include <stdio.h>

int isPalindrome(char * str);
int palindrome(char* str, int ilk, int son);

int main(){

	isPalindrome("X&x +%&CvcVC x!X");

	return 0;
}
int isPalindrome(char * str){

	int i,length;
	int ilk,son;
	
	if(str == NULL)
	{
		return 0;
	}
	
	length = 0;
	
	for(i=0;str[i]!='\0';i++)	/* string dizisinin uzunluğu */
		length++;
	
	ilk = 0;		/*	bakılacak ilk index */
	son = length-1;		/* liste sonundaki bakılacak ilk index */
	
	return palindrome(str, ilk, son);
}
int palindrome(char* str, int ilk, int son){

	if( !( ((int)'a' <= (int)str[ilk] && (int)'z' >= (int)str[ilk]) || 
		((int)'A' <= (int)str[ilk] && (int)'Z' >= (int)str[ilk]) )  )
		return palindrome(str, ++ilk, son);/* harften farklı karakter varsa*/
	
	else if( !( ( (int)'a' <= (int)str[son] && (int)'z' >= (int)str[son] ) || 
		( (int)'A' <= (int)str[son] && (int)'Z' >= (int)str[son] ) )  )
		return palindrome(str, ilk, --son);/* harften farklı karakter varsa*/
	
	if (str[ilk] != str[son])
	{
		if((int)str[ilk]-(int)'A' == (int)str[son]-(int)'a' ||
		(int)str[ilk]-(int)'a' == (int)str[son]-(int)'A')
		{
			return palindrome(str,++ilk, --son);
		}
		
		else if (ilk >= son) /* eşit olma durumu, (ana)string uzunluğu tek ise*/
			return 1;		/* büyük olma durumu,(ana)string uzunluğu çift ise*/
		
		else
			return 0;
	}	
	
	else if (ilk >= son)
		return 1;
		
	else
		return palindrome(str,++ilk, --son);	
		/*eşleşme varsa bir sonraki indexler için çağrıldı*/

	return 0;
}
