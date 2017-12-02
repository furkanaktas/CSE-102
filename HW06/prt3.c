/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW06_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş_Part3.c                                             */
/* ----------------------------------                                         */
/* Created on 06/04/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*	    141044029_Furkan_Aktaş_Part3.c contains codes for the third 		  */	
/*	part of the homework VI, which are used  for counting the occurrences     */
/*  of a substring in the a given string.						              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* Function count                                                        	  */
/* ------------------                                                         */
/* 	    Bu fonksiyon, verilen string dizisinde istenilen string dizisinin	  */	
/*  eşleşme sayısını verir.												      */
/*----------------------------------------------------------------------------*/

/* Function matcher                                                        	  */
/* ------------------                                                         */
/* 	    Bu fonksiyon, verilen string dizisinde istenilen string dizisini	  */	
/*   bulur.												      				  */
/*----------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

char* matcher(char* haystack, char* needle);
int count(char* str, char* substr);

int main(){

	count("elececele",NULL);
	
	return 0;

}
int count(char* str, char* substr){
	
	int i,j,k,size,count;
	char list[1000];
	char a;
	
	if(substr == NULL)
	{
		return '\0';
	}
	
	size = strlen(str);
		
	count =0;
	for(i=0;i<size;i++)
	{
		for(k=0;k<(size+1);k++)
		{
			list[k]='\0';		/* her seferinde alt array boşatıldı */
		}
		
		
		k=i;
		for(j=0;j<(size-i);j++)		
		{
			list[j]=str[k]; /* Array her döngüde 1 sonraki indexten başlar*/
		
			k++;
		}
		
		if( matcher(list, substr) != '\0')
		{
			count +=1;
		}
			
		
	}	
	printf("%d\n",count);
	return count;
	
}

char* matcher(char* haystack, char* needle){

	int a,b,t,j,k,l,size,size2;
	char arr[1000];  			 /* haystack için boş alt array */
	char* sonuc;
	
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
	
	k=0;
	for(j=0;j<(size);j++)		
	{
		arr[j]=haystack[k];   /*alt array'e haystack elemanları dolduruldu*/
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
				j=size;
				sonuc = &haystack[l];
				return sonuc;
					
			}	
 /* (size-a) : alt arrayin başlangıç indexi, +j : son eşleşmenin olduğu index*/
 /* -size2 : hedef kelime uzunluğunu çıkarttık, +1: 1. index'ine geldik */						
			else
			{
				return '\0'; /* ilk seferde eşleşme olmazsa */
			}	
		}			
		else
		{
			t++;
		}
			
		j++;
	}		
	return '\0';
}
