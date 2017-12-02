/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW07_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş_Part2.c                                             */
/* ----------------------------------                                         */
/* Created on 14/04/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		141044029_Furkan_Aktaş_Part2.c contains codes for the second part of  */
/*	the homework VII, which simulates hitting an air hockey disc and checks	  */
/* 	whether the disc will be in the goal or not.							  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* Function reflection                                                        */
/* ------------------                                                         */
/* Bu fonksiyon girilen atış açısına göre sekme açısını belirler.	          */
/*----------------------------------------------------------------------------*/

/* Function randNumber                                                        */
/* ------------------                                                         */
/* Bu fonksiyon girilen atış açısına göre rastgele bir sayı verir.(-5 ,+5)    */
/*----------------------------------------------------------------------------*/

/* Function kickDisc                                                          */
/* ------------------                                                         */
/* Bu fonksiyon hava hokeyi oyunun simülasyonunu uygular.					  */
/*----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

int reflection(int angle);

int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double
kickAngle, double ballRadius, double goalWidth);

int randNumber(int angle);

int main(){
	
	/*    geniş,yük,merkX,açı,R,kale*/  
	kickDisc(10, 26, 2, 41, 1, 2);
	
	return 0;
	
}

int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double
kickAngle, double ballRadius, double goalWidth){
	
	double dikeyMes,zafer1,zafer2,yatay,radyan,temp;
	temp = kickAngle; 
	/* temp:direk karşı duvara(sekmeden)atılan topun atış açısı,temp'e atandı*/
	/* dikeyMes:açıya göre dikeyde alınan mesafe.*/
	/* yatay:açıya göre yatayda  alınan mesafe.*/
	
	zafer1 = (wallWidth/2)-(goalWidth/2);	/* kalenin sol tarafının uzunluğu */ 
	zafer2 = (wallWidth/2)+(goalWidth/2);	/* kalenin sağ tarafının uzunluğu */
	
	if(kickAngle > 175 || kickAngle <5)
		return 0;
	
	else if(wallWidth < 2*ballRadius ) /*duvar genişliği en az çap kadar olur.*/ 
		return 0;
	
	else if(goalWidth > wallWidth || goalWidth <= 0) 
		return 0;	/*kale, duvar genişliğinden fazla olamaz*/
	
	else if (wallWidth <=0 || wallHeight <0)
		return 0;	/* yatay ve dikey duvar 0'dan küçük olamaz */
	
	else if( ballCenterX < ballRadius )
		return 0;	/* atış noktası en kısa yarı çap kadardır */
		
	else if( (ballCenterX==ballRadius || ballCenterX == wallWidth-ballRadius) &&
	 	kickAngle > 90)		return 0;	
	/* atış noktası sağ veya sol duvarın hemen dibindeyse atış açısı 90'dan 
	küçük olmalı */	
	else if(kickAngle < 90)
	{
		kickAngle = kickAngle;
		radyan = kickAngle*PI/180;	/* açı radyan cinsine çevrildi */
		dikeyMes = (wallWidth-ballCenterX-ballRadius)*tan(radyan);
		
	}	
	else if(kickAngle > 90 )
	{
		kickAngle = 180 - kickAngle;
		radyan = kickAngle*PI/180;	/* açı radyan cinsine çevrildi */
		dikeyMes = (ballCenterX-ballRadius)*tan(radyan);
	}	
	else 
	{
		yatay = ballCenterX;/*atış açısı=90 ,(yatay mesafe)=(atış noktasıdır)*/ 	
		if(yatay >= zafer1 && yatay <= zafer2)	
			return 1;	/* yatay mesafe kale sınırları içindeyse */
		else
			return 0;			
	}		
	/*	wallHeight <= dikeyMes+ballRadius : wallHeight her seferinde dikey 
mesafe kadar azalır.Dikey mesafe yatay mesafenin (wallWidth-2r) açıya bağlı 
tanjantı ile çarpılması sonucu bulunur.Eğer ölçülen dikey mesafe geriye kalan 
wallHeight'ten büyükse demekki duvar sonuna ulaşılmıştır.Bu durumda geriye kalan
 wallHeight'in açıya bağlı kotanjantı ile katettiği yatay mesafeyi buluruz.*/
	
	if(( ballCenterX == ballRadius ) && ( wallHeight <= dikeyMes+ballRadius ) )
	{	/* sekerek gelen top , üst sınıra ulaşırsa */
		yatay = (wallHeight-ballRadius)/tan(radyan)+ballRadius;
		dikeyMes = wallHeight-ballRadius;	/*gol durumu kontrolü için */
	}
	
	else if(( ballCenterX != ballRadius )&&( wallHeight <= dikeyMes+ballRadius))
	{	/* atış noktasından direk karşı duvara (sekmeden) giden atış */
	   if(temp < 90)
		yatay = (wallHeight-ballRadius)/tan(radyan) + ballCenterX;
		/* dikey mesafeden yatay konum bulundu. <90 olduğundan +ballCenterX */	
	   else
		yatay = ballCenterX - (wallHeight-ballRadius)/tan(radyan);
	   	/* >90 olduğundan ballCenterX -  () */ 
	   dikeyMes = wallHeight-ballRadius;	/*gol durumu kontrolü için */
	}
		
	wallHeight -= dikeyMes;	   /* dikey hareket, duvar yüklekliğinden düşüldü.*/
	
	if( (wallHeight-ballRadius == 0) && (yatay >= zafer1 && yatay <= zafer2) )
		return 1;	/* yatay konum kale sınırları içindeyse */

	else if(wallHeight-ballRadius != 0 && wallHeight-ballRadius > 0)
	{
		kickAngle = reflection(kickAngle);	/* sekme açısı bulundu */
		return kickDisc(wallWidth, wallHeight, ballRadius,kickAngle,ballRadius,
		goalWidth);/*yeni açı,atış merkezi(r) ve yükseklik ile tekrar çağrıldı*/
	}
	else
		return 0;
	
	return 0;
}

int reflection(int angle){
	
	int sapma;
	sapma = randNumber(angle)%9-4;
	angle += sapma;
	if(angle < 5)
		angle = 5;
	else if( angle > 175)
		angle = 175;	
	
	return angle;
}

int randNumber(int angle){
	srand(angle);
	return rand();
}
















