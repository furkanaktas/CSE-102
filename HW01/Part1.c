/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW01_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş_Part1.c                                             */
/* ----------------------------------                                         */
/* Created on 18/02/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*	 141044029_Furkan_Aktaş_Part1.c contains codes for the first part of      */
/*	the homework I, which are used for calculating the overall grade of       */
/*	the students.                                                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include <stdio.h>
int main(void){
	

    int yuzdeVize1,yuzdeVize2,yuzdeVize3;
	int yuzdeOdev1,yuzdeOdev2;
	int yuzdeFinal;

	float vize1,vize2,vize3;
	float odev1,odev2;
	float final;
	float sonuc;
	
	printf("Please enter the 1. midterm weight:" );	scanf("%d",&yuzdeVize1);
	printf("Please enter the 2. midterm weight:" );	scanf("%d",&yuzdeVize2);
	printf("Please enter the 3. midterm weight:" );	scanf("%d",&yuzdeVize3);

	printf("Please enter the 1. homework weight:");	scanf("%d",&yuzdeOdev1);
	printf("Please enter the 2. homework weight:");	scanf("%d",&yuzdeOdev2);

	printf("Please enter the final exam weight:" );	scanf("%d",&yuzdeFinal);	


	printf("Please enter the 1. midterm grade:"  );	scanf("%f",&vize1);   
	printf("Please enter the 2. midterm grade:"  );	scanf("%f",&vize2);
	printf("Please enter the 3. midterm grade:"  );	scanf("%f",&vize3);

	printf("Please enter the 1. homework grade:" );	scanf("%f",&odev1);
	printf("Please enter the 2. homework grade:" );	scanf("%f",&odev2);   

	printf("Please enter the final exam grade:"  );	scanf("%f",&final);   

	sonuc = (yuzdeVize1*vize1)/100 + (yuzdeVize2*vize2)/100 + 
	(yuzdeVize3*vize3)/100 + (yuzdeOdev1*odev1)/100 + (yuzdeOdev2*odev2)/100 +
	(yuzdeFinal*final)/100 ;
	/* her alınan değer kendi yüzdesiyle çarpılarak toplam sonuç bulundu. */
	
	printf("Your final grade is: %f\n",sonuc); 		
	

	return 0;	
}
