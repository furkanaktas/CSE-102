/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW01_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş_Part2.c                                             */
/* ----------------------------------                                         */
/* Created on 18/02/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*	 141044029_Furkan_Aktaş_Part2.c contains codes for the second part of     */
/*	the homework I, which are used for calculating how many days the user     */
/*	has lived and calculating how old the user would be if he were lived      */
/*  in planet which is different from the earth.                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include <stdio.h>
int main(void){
	
	int gun,ay,yil;
	int dogumGun,dogumAy,dogumYil;
	int saat,baskaAy,baskaGun;     
	int sonuc1,sonuc2,sonuc3,sonuc4;
	
	printf("Please enter the current date.\n");		
	
	printf("Year:" );			scanf("%d",&yil);
	printf("Month:");			scanf("%d",&ay );
	printf("Day:"   );			scanf("%d",&gun);

	printf("Please enter your birthday.\n");		
   
	printf("Year:");			scanf("%d",&dogumYil);	
	printf("Month:");			scanf("%d",&dogumAy );
	printf("Day:" );			scanf("%d",&dogumGun);

	sonuc1 = (30-dogumGun +5) + (12-dogumAy)*30 + ((yil-dogumYil)-1)*365 + 
	(ay-1)*30 + gun ; 

	/*ilk 2 parantez ile doğum tarihi girilen yılı tam yıla tamamladık 
	(ilk parantezde bir yılı 365 güne tamamlamak için +5 eklendi). 
	3. parantez ile günümüz tarihine   kadar olan tam yılları hesapladık,
	son kısım ile de günümüz tarihindeki ay ve günü ekledik.*/
	
	printf("You have lived %d days.\n",sonuc1);

	
	printf("Please enter about the time of another planet\n");
	
	printf("How many hours is a day?"  );			scanf("%d",&saat    );
	printf("How many days is a month?" );			scanf("%d",&baskaGun);
	printf("How many months is a year?");			scanf("%d",&baskaAy );

	sonuc2 = ((sonuc1*24)/saat) % baskaGun;	
	/* gun (toplam gunun bir aydaki gun sayısına bolumunden kalan)*/
	
	sonuc3 = ((sonuc1*24)/(saat * baskaGun)) % baskaAy;
	/* ay (toplam ay'ın bir yıldaki ay sayısına bolumunden kalan) */
	
	sonuc4 = (sonuc1*24)/(saat * baskaGun * baskaAy);	
	/* yıl (1 yılın saat cinsinden integer bölümleri.) */

	printf("If you lived in a planet where a day is %d hours, ",saat      );
	printf("a month is %d days and a year is %d months: ",baskaGun,baskaAy);
	printf("you were %d years, %d months and ",sonuc4,sonuc3              );
	printf("%d days old\n",sonuc2                                          );
	
	return 0;
	
}
