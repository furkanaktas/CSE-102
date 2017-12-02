/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW04_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş_Part1.c                                             */
/* ----------------------------------                                         */
/* Created on 20/03/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		141044029_Furkan_Aktaş_Part1.c contains codes for the first part of   */
/*	the homework IV, which are used for calculating sine and cosine.          */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#define PI 3.14

double cosine(int degree, int n);
double sine(int degree, int n);
void getInputs(int* degree, int* n, int* exit);

int main(){
	
	int degree,n,exit;
	
	getInputs(&degree, &n, &exit);
	
	return 0;
	
	
}
/* Function cosine                                                            */
/* ------------------                                                         */
/* Bu fonksiyon kullanıcının girdiği sayı kosinüs değerini verir.             */
/*----------------------------------------------------------------------------*/

double cosine(int degree, int n){
	
	int j,deger,faktoriyel;
	double radyan,sonuc,temp,temp1;
	
	if(degree > 360 )
	{
		degree = degree % 360;
	}
	sonuc=0;
	for(n=(n-1);n>=0;n--)
	{
		radyan = ((double)degree/360)*(2*PI);
		temp1 = radyan;
		
		if(n%2 == 0)
		{
			deger = 1;
		}
		else
		{
			deger =-1;
		}
		
		faktoriyel = 1;
		for(j=(2*n);j>0;j--)
		{
			
			faktoriyel *= j;
				
		}
		
		for(j=(2*n);j>1;j--)
		{
			
			temp1 *= radyan;
				
		}
		if(n==0)
		{
			temp1 = 1;
			deger = 1;
		}
		
		temp = (deger*temp1)/faktoriyel;
		sonuc += temp;
	}
	printf("%.4f\n",sonuc);
	return sonuc;	

}
/* Function sine                                                              */
/* ------------------                                                         */
/* Bu fonksiyon kullanıcının girdiği sayı sinüs değerini verir.               */
/*----------------------------------------------------------------------------*/

double sine(int degree, int n){
	
	int j,deger,faktoriyel;
	double radyan,sonuc,temp,temp1;
	
	if(degree > 360 )
	{
		degree = degree % 360;
	}
	
	sonuc=0;
	for(n=(n-1);n>=0;n--)
	{
		radyan = ((double)degree/360)*(2*PI);
		temp1 = radyan;
		
		if(n%2 == 0)
		{
			deger = 1;
		}
		else
		{
			deger =-1;
		}
		
		
		faktoriyel = 1;
		for(j=((2*n)+1);j>0;j--)
		{
			faktoriyel *= j;
		}
		
		for(j=((2*n)+1);j>0;j--)
		{
			if( j == 1 )
			{
				temp1 *=1;
			}
			else
			{
				temp1 *= radyan;
			}	
			
		}
		
		temp = (deger*temp1)/faktoriyel;
		sonuc += temp;
	}
	printf("%.4f\n",sonuc);
	return sonuc;
	
}
void getInputs(int* degree, int* n, int* exit){
	
	int i;
	
	
	i = 1;
	while(i>0)
	{
		int a;
		char t;
		a = scanf("%d",&(*degree));	
		if( a == 0 )
		{
			
			
			scanf("%c",&t);
			if( t == 101 || t == 69)
			{
				*exit=1;
				i=0;
			}
			else
			{
				i=1;
			}
			
			
		}
		
		else
		{
			*exit=0;
			scanf("%d",&(*n));			
			sine((*degree), (*n));
			cosine((*degree), (*n));
			i=1;
		}
		
		
		
		
	}
	return;
}
