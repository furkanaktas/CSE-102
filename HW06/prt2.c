/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW06_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş_Part2.c                                             */
/* ----------------------------------                                         */
/* Created on 06/04/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*	    141044029_Furkan_Aktaş_Part2.c contains codes for the second 		  */	
/*	part of the homework VI, which are used for for finding substring(s)      */
/*  in a given string.														  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* Function matcher                                                        	  */
/* ------------------                                                         */
/* Bu fonksiyon verilen string dizisinde istenilen string dizisini bulur.     */
/*----------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

char* matcher(char* haystack, char* needle);

int main(){

	char* ptr = matcher("lorem ipsum dolor asdasd sit amet.",NULL);
	
	return 0;

}

char* matcher(char* haystack, char* needle){

	int a,b,t,i,j,k,l,size,size2;
	char arr[1000];  			 /* haystack için boş alt array */
	char* sonuc;
	
	if(needle == NULL)
	{
		return '\0';
	}
	
	size = strlen(haystack);		/* kaynak kelime uzunluğu */
	size2 = strlen(needle);			/* hedef kelime uzunluğu */
	
	if(size2%2 == 0)
	{
		b = size2/2;	/* b: hedef kelimede beklenen eşleşme sayısı*/
	}
	else
	{
		b = (size2+1)/2;
	}
	
	for(i=0;i<size;i++)
	{
		for(k=0;k<(size+1);k++)
		{
			arr[k]='\0';		/* her seferinde alt array boşatıldı */
		}
		
		k=i;
		for(j=0;j<(size-i);j++)		
		{
			arr[j]=haystack[k]; /* Array her döngüde 1 sonraki indexten başlar*/
			k++;
		}
				
		a=0;
		t=0;					/* t: hedef kelime indexi */
		j=0;					/* j: alt array (arr[]) indexi */
		while(j < size)
		{
			if( j%2==0 && t%2==0)
			{
				if(arr[j] == needle[t])
				{
					a+=1;	/* eşleşme sayısı */
				}
			}
		
			if(t == (size2-1))	/* t  hedef kelimenin son elemanı iken */
			{
				if(a == b)		/* eşleşme sayısı (a), beklenene eşitse (b)*/
				{	
					a=0;				
					k=0;
					while(arr[k] !='\0')
					{
						a+=1;	/* alt array'in son halinin uzunluğunu bulur */
						k++;
					}
					
					l = size-a+j-size2+1; 	
					i=size;					
					j=size;
					printf("%c  \n",haystack[l]);
					sonuc = &haystack[l];
					return sonuc;
					
				}	
 /* (size-a) : alt arrayin başlangıç indexi, +j : son eşleşenin olduğu index*/
 /* -size2 : hedef kelime uzunluğunu çıkarttık, +1: 1. index'ine geldik */						
				else
				{
					a=0;	/* kelime bulunmadıysa eşleşme sayısını 0'ladık. */
					t=0;	/* hedef kelime indexini 0'ladık. */
				}	
			}			
			else
			{
				t++;
			}	
			j++;
			
		}
		if(i==(size-1) && a!=b)
		{
			printf(" lolololo");
			return '\0';
		}
	}

	return '\0';
}
