/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW03_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş.c                                                   */
/* ----------------------------------                                         */
/* Created on 05/03/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*	141044029_Furkan_Aktaş.c contains codes for the homework III,which asks   */
/* users for an integer and checks if the number is an odd, a factorial or    */
/* a narcissistic number, depending on the user choice.                       */
/*	                                                                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

int oddNumber(int number);
int factorialNumber(int number);
int narcissisticNumber(int number);

int main(){


	printf("******************************************************\n");
	printf("*                    WELCOME!                        *\n");
	printf("*   This program check whether the given number      *\n");
	printf("*  is an odd, a factorial or a narcissistic number   *\n");
	printf("*                                                    *\n");
	printf("******************************************************\n"); 


	int i,j,k;
	char cevap1;	
	int cevap2,number;		
	
	
	j=1;
	while (j>0)
	{
		
		
		printf("\nPlease enter a positive integer : ");	scanf("%d",&number);		
		
		if (number<=0)
		{
			printf("The entered number is not positive.\n");
	
			i=1;
			while (i>0)    /* y,n  dışındaki girdiler engellemek için */
			{
				printf("Do you want to continue (y/n)? ");
				scanf("%s",&cevap1);
				if (cevap1=='y' || cevap1=='Y')
				{
					j=1;
					i=0;
				}
				else if (cevap1=='n' || cevap1=='N')
				{
					printf("Good bye !\n");					
					j=0;
					i=0;				
				}
				else
				{
					i=1;	/* y,n  dışındaki girdiler engellemek için */
				
				}
			}			
		}        /* ana if kapatma */
		
		else
		{
			printf("Which property would you like to check?\n");
			printf("1)Odd number\n");
			printf("2)Factorial number\n");
			printf("3)Narcissistic number\n");
			
			k=1;			
			while (k>0) /* 1/2/3  dışındaki girdileri engellemek için */
			{						
				printf("Please enter(1/2/3): ");	scanf("%d",&cevap2);
				if(cevap2==1)
				{
					oddNumber(number);
			
					i=1;
					while (i>0)	/* y,n  dışındaki girdiler engellemek için */
					{
						printf("Do you want to continue (y/n)? ");
						scanf("%s",&cevap1);
						if (cevap1=='y' || cevap1=='Y')
						{
							j=1;
							i=0;
							k=0;								
						}
						else if (cevap1=='n' || cevap1=='N')
						{
							printf("Good bye !\n");							
							j=0;
							i=0;
							k=0;
						}
						else
						{						
							i=1;  /* y,n  dışındaki girdiler engellemek için */
							k=0;
						}				
					}			
				}
				else if (cevap2==2)
				{
					factorialNumber(number);
			
					i=1;
					while (i>0)  /* y,n  dışındaki girdiler engellemek için */
					{
						printf("Do you want to continue (y/n)? ");
						scanf("%s",&cevap1);
						if (cevap1=='y' || cevap1=='Y')
						{
							j=1;
							i=0;
							k=0;								
						}
						else if (cevap1=='n' || cevap1=='N')
						{
							printf("Good bye !\n");							
							j=0;
							i=0;
							k=0;
						}
						else
						{						
							i=1;  /* y,n  dışındaki girdiler engellemek için */
							k=0;
						}				
					}						
				}
				else if (cevap2==3)
				{
					narcissisticNumber(number);
				
					i=1;
					while (i>0)  /* y,n  dışındaki girdiler engellemek için */
					{
						printf("Do you want to continue (y/n)? ");
						scanf("%s",&cevap1);
						if (cevap1=='y' || cevap1=='Y')
						{
							j=1;
							i=0;
							k=0;								
						}
						else if (cevap1=='n' || cevap1=='N')
						{
							printf("Good bye !\n");							
							j=0;
							i=0;
							k=0;
						}
						else
						{						
							i=1;  /* y,n  dışındaki girdiler engellemek için */
							k=0;
						}				
					}						
				}
				else
				{
					k=1;	/* 1/2/3  dışındaki girdileri engellemek için */
				}			
			}	
			
		}    /* ana else kapatma */
		
		

	}   /* ana döngü kapatma */
			
	return 0;
}       /* main */


/*******************************FONKSİYONLAR***********************************/

/* Function oddNumber                                                         */
/* ------------------                                                         */
/* Bu fonksiyon verilen sayının tek sayı olup olmadığını kontrol eder.        */
/*----------------------------------------------------------------------------*/

int oddNumber(int number){

	if(number%2==1)
	{
		printf("%d is an odd number !\n",number);
	}
	else
	{
		printf("%d is not an odd number !\n",number);
	}
	
	return 0;
}
/*----------------------------------------------------------------------------*/
/* Function factorialNumber                                                   */
/* ------------------                                                         */
/* Bu fonksiyon verilen sayının faktoriyal sayı olup olmadığını kontrol eder. */
/*----------------------------------------------------------------------------*/

int factorialNumber(int number){

	int i,j,digit;
	
	digit = 1;

	j=1;	
	i=1;
	while(i>0)
	{
		digit *= j;		/* factorial işlemi */
		
		if(number > digit) 
		{
			i=1;	/* girilen sayı digitten büyükse döngüye devam */
		}
		
		else if(number == digit)
		{
			printf("%d is a factorial number !\n",number);			
			i=0;
		}
		else if(number < digit)
		{
			printf("%d is not a factorial number !\n",number);
			i=0;
		}
		j++;		
	}


	return 0;
}
/*----------------------------------------------------------------------------*/
/* Function narcissisticNumber                                                */
/* ------------------                                                         */
/* Bu fonksiyon verilen sayının narsistik sayı olup olmadığını kontrol eder.  */
/*----------------------------------------------------------------------------*/

int narcissisticNumber(int number){

	int digit,kalan,toplam;
	int temp1 = number;
	int temp2 = number;

	digit=0;
	while (temp1>0)		/* basamak sayısını bulup  digit'e  atama */
	{
		temp1 /= 10;
		digit++;
	}
	
	kalan=0;	
	toplam=0;
	while (temp2>0)		
	{
		kalan = temp2 % 10;		/* basamaklarda olan rakamları bulma */
		toplam += pow(kalan,digit);	 /* narcissistic sayı işlemi */
		temp2 /= 10;
		
	}
	if (toplam == number)
	{
		printf("%d is a narcissistic number !\n",number);
	}
	else
	{
		printf("%d is not a narcissistic number !\n",number);
	}


	return 0;

}




