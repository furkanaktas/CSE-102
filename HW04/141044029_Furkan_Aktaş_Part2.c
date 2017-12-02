/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW04_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş_Part2.c                                             */
/* ----------------------------------                                         */
/* Created on 20/03/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		141044029_Furkan_Aktaş_Part2.c contains codes for the second part of  */
/*	the homework IV, which are used for printing out user's entered number.   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include <stdio.h>

int printNumber(int num ,int borderWidth, char borderChar);
void getInputs(int* num, int* borderWidth, char* borderChar);

int main(){
	
	int num,borderWidth;
	char borderChar; 
	
	getInputs(&num, &borderWidth, &borderChar);
	
	/*printf("%d%d%c",num,borderWidth,borderChar);*/
	
	
	
	return 0;
	
}

/* Function printNumber                                                       */
/* ------------------                                                         */
/* Bu fonksiyon kullanıcının girdiği sayıyı ekrana basar                      */
/*----------------------------------------------------------------------------*/

int printNumber(int num, int borderWidth , char borderChar){
	
	int i,j,l;
	int x1,x2,x3,x4,x5,x6;
	
	int sayi;
	int basamak,start;
	int r,t,y,u,o,p; 	/* basamaktaki sayılar */
	
	x1=x2=x3=x4=x5=x6=borderWidth;
	sayi = num;
	
	if(num > 99999)
	{
		return 0;
	}
	else if(num < 0)
	{
		return 0;
	}
	else
	{
		if( num == 0)
		{
			basamak = 1;
			start = 7;
			t = 0;	
		}
		else
		{
			basamak=0;
			while(num > 0)
			{
				num = num/10;	 /* girilen sayının basamak sayını bulma */
				basamak++;
			}
			if(basamak == 1)
			{
				start = 7;	
			}
			else if(basamak == 2)
			{
				start = 14;	
			}
			else if(basamak == 3)   /* basamak sayısına göre başlangıç değeri */
			{
				start = 21;			/* yatay uzunluğu belirlemek için */
			}
			else if(basamak == 4)
			{
				start = 28;	
			}
			else if(basamak == 5)
			{
				start = 35;	
			}
		
			l=0;
			while(sayi > 0)
			{
				r = sayi % 10;	/* basamaktaki sayıyı bulma */
			
				if(l==0)
				{
					t = r;	
				}
				else if(l==1)
				{
					y = r;	 /* her bir değeri farklı değişkene atadık */
				}
				else if(l==2)
				{
					u = r;	
				}
				else if(l==3)
				{
					o = r;		
				}
				else if(l==4)
				{
					p = r;		
				}
				sayi /= 10;
				l +=1;
			}
		}
	
	i=(7+(2*borderWidth));	 /* çerçeve  dahil satır sayısı */
	while(i>0)				/* Ana döngü */
	{
		
		if(i>((7+(2*x3))-x3))  /*  7x7'lik bölgenin üst tarafını yazar */
		{
		
			while(borderWidth > 0)
			{
			
				for(j=0;j<(start+(2*x1));j++) 
				{
					printf("%c",borderChar);
				}
				printf("\n");
				borderWidth--;
				i--;
			}
		}
		else if(i == (1+x3) || i == ((7+(2*x3))-x3))  
		{
			x1=x5;					/*sayının alt ve üst boşlukları */
			x2=x5;
			while(x1>0)
			{
				printf("%c",borderChar);
				x1--;
			}
			for(j=0;j<start;j++)
			{
				printf(" ");
			} 
			while(x2>0)
			{
				printf("%c",borderChar);
				x2--;
			}
			printf("\n");
			i--;	
			
		}
		else if((1+x3) <= i && i <= ((6+(2*x3))-x3)) 
		{
			x1=x5;				/* sayının yazılcağı aralık*/
			x2=x5;
			while(x1>0)
			{
				printf("%c",borderChar);
				x1--;
			}
			if(basamak==1) /* tek basamaklı sayılar */
			{				
				if(t==0)	/* 0 ın yazımı */
				{
					if(i==(2+x3) || i==((6+(2*x3))-x3))	
					{
						printf("  ");
						for(j=0;j<3;j++)
						{
							printf("%c",borderChar);
						}
						printf("  ");
					}		
					else
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
							
				}
				
				else if(t==1)	/* 1 in yazımı */
				{
			if(i==((6+(2*x3))-x3) || i==((4+(2*x3))-x3) || i==((3+(2*x3))-x3))
					{
						printf("   %c   ",borderChar);
					}
					else if(i==((5+(2*x3))-x3))
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
				}
				else if(t==2)	/* 2 nin yazımı */
				{
			if(i==((2+(2*x3))-x3) || i==((4+(2*x3))-x3) || i==((6+(2*x3))-x3))	
					{
						printf("  ");
						for(j=0;j<3;j++)
						{
							printf("%c",borderChar);
						}
						printf("  ");
					}		
					else if ( i==((5+(2*x3))-x3) )
					{
						printf("    %c  ",borderChar);
					}
					else
					{
						printf("  %c    ",borderChar);
					}
							
				}
				else if(t==3)  /* 3 ün yazımı */
				{
			if(i==((2+(2*x3))-x3) || i==((6+(2*x3))-x3))	
					{
						printf("  ");
						for(j=0;j<3;j++)
						{
							printf("%c",borderChar);
						}
						printf("  ");
					}
					else if(i==((3+(2*x3))-x3) || i==((5+(2*x3))-x3))
					{
						printf("    %c  ",borderChar);
					}		
					else
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
							
				}
				else if(t==4)	/*4 un yazımım */
				{
					if( i==((3+(2*x3))-x3) || i==((2+(2*x3))-x3) )	
					{
						printf("    %c  ",borderChar);
					}		
					else if ( i==((6+(2*x3))-x3 )  || i==((5+(2*x3))-x3)  )
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
							
				}
				else if(t==5)	/* 5 in yazımı */
				{
			if(i==((2+(2*x3))-x3) || i==((4+(2*x3))-x3) || i==((6+(2*x3))-x3))	
					{
						printf("  ");
						for(j=0;j<3;j++)
						{
							printf("%c",borderChar);
						}
						printf("  ");
					}		
					else if ( i==((5+(2*x3))-x3) )
					{
						printf("  %c    ",borderChar);
					}
					else
					{
						printf("    %c  ",borderChar);
					}
							
				}
				else if(t==6)	/* 6 nın  yazımı */
				{
			if(i==((2+(2*x3))-x3) || i==((4+(2*x3))-x3) || i==((6+(2*x3))-x3))	
					{
						printf("  ");
						for(j=0;j<3;j++)
						{
							printf("%c",borderChar);
						}
						printf("  ");
					}		
					else if ( i==((5+(2*x3))-x3) )
					{
						printf("  %c    ",borderChar);
					}
					else
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
							
				}
				else if(t==7)	/* 7 nin yazımı */
				{
					if(i==((6+(2*x3))-x3))
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}		
					else
					{
						printf("    %c  ",borderChar);
					}
							
				}
				else if(t==8)	/* 8 in yazımı */
				{
			if(i==((2+(2*x3))-x3) || i==((4+(2*x3))-x3) || i==((6+(2*x3))-x3))	
					{
						printf("  ");
						for(j=0;j<3;j++)
						{
							printf("%c",borderChar);
						}
						printf("  ");
					}		
					else
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
							
				}
				else if(t==9)	/* 9 un  yazımı */
				{
			if(i==((2+(2*x3))-x3) || i==((4+(2*x3))-x3) || i==((6+(2*x3))-x3))	
					{
						printf("  ");
						for(j=0;j<3;j++)
						{
							printf("%c",borderChar);
						}
						printf("  ");
					}		
					else if (i==((3+(2*x3))-x3))
					{
						printf("    %c  ",borderChar);
					}
					else
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
							
				}
			}  		/* tek basamaklıların sonu */
			
			if (basamak == 2)
			{
				if(i==((6+(2*x3))-x3)) /* 6. basamak (sayı bölgesinde) */
				{
					if(y==1)
					{
						printf("   %c   ",borderChar);
					}
				else if(y==2 || y==3 || y==5 || y==6 || y==7 || y==8 || y==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(y==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					if(t==1)
					{
						printf("   %c   ",borderChar);
					}
		else if(t==0 || t==2 || t==3 || t==5 || t==6 || t==7 || t==8 || t==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(t==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
				}
				else if(i==((5+(2*x3))-x3))	/*  5. basamak (sayı bölgesinde)*/
				{
					if(y==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(y==2 || y==3 || y==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(y==4 || y==8 || y== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(y==5 || y==6)
					{
						printf("  %c    ",borderChar);
					}
					
					if(t==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(t==2 || t==3 || t==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(t==0 || t==4 || t==8 || t== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(t==5 || t==6)
					{
						printf("  %c    ",borderChar);
					}
					
				}
				else if(i==((4+(2*x3))-x3))	  /* 4. basamak (sayı bölgesinde)*/
				{
					if(y==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(y==2 || y==4 || y==5 || y==6 || y==8 || y==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if (y==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(y==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(t==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(t==2 || t==4 || t==5 || t==6 || t==8 || t==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if(t==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(t==0)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(t==7)
					{
						printf("    %c  ",borderChar);
					}
				}
				
				else if(i==((3+(2*x3))-x3))  /* 3. basamak (sayı bölgesinde) */
				{
					if(y==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(y==3 || y==4 || y==5 || y==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(y==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(y==6 || y==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(y==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(t==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(t==3 || t==4 || t==5 || t==7 || t==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(t==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(t==0 || t==6 || t==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
					
				}
			
				else if(i==((2+(2*x3))-x3))   /* 2. basamak (sayı bölgesinde) */
				{
					
				    if(y==1 || y==2 || y==3 || y==5 || y==6 || y==8 || y==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					
					else if(y==4 || y==7)
					{
						printf("    %c  ",borderChar);
					}
					
				if(t==0 || t==1 || t==2 || t==3 || t==5 || t==6 || t==8 || t==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					
					else if(t==4 || t==7)
					{
						printf("    %c  ",borderChar);
					}
				}
			}  /* 2 basamaklıların sonu */
			
			if (basamak == 3)
			{
				if(i==((6+(2*x3))-x3)) /* 6. basamak (sayı bölgesinde) */
				{
					if(u==1)
					{
						printf("   %c   ",borderChar);
					}
				else if(u==2 || u==3 || u==5 || u==6 || u==7 || u==8 || u==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(u==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
				
					if(y==1)
					{
						printf("   %c   ",borderChar);
					}
		 else if(y==0 || y==2 || y==3 || y==5 || y==6 || y==7 || y==8 || y==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(y==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
					if(t==1)
					{
						printf("   %c   ",borderChar);
					}
		else if(t==0 || t==2 || t==3 || t==5 || t==6 || t==7 || t==8 || t==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(t==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
				}
				else if(i==((5+(2*x3))-x3))	/*  5. basamak (sayı bölgesinde) */
				{
					if(u==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(u==2 || u==3 || u==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(u==4 || u==8 || u== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(u==5 || u==6)
					{
						printf("  %c    ",borderChar);
					}
					
					if(y==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(y==2 || y==3 || y==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(y==0 || y==4 || y==8 || y== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(y==5 || y==6)
					{
						printf("  %c    ",borderChar);
					}
					
					if(t==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(t==2 || t==3 || t==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(t==0 || t==4 || t==8 || t== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(t==5 || t==6)
					{
						printf("  %c    ",borderChar);
					}
					
				}
				else if(i==((4+(2*x3))-x3))	   /* 4. basamak (sayı bölgesinde)*/
				{
					if(u==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(u==2 || u==4 || u==5 || u==6 || u==8 || u==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if (u==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(u==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(y==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(y==2 || y==4 || y==5 || y==6 || y==8 || y==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if (y==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(y==0)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(y==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(t==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(t==2 || t==4 || t==5 || t==6 || t==8 || t==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if(t==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(t==0)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(t==7)
					{
						printf("    %c  ",borderChar);
					}
				}
				
				else if(i==((3+(2*x3))-x3))  /* 3. basamak (sayı bölgesinde) */
				{
					if(u==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(u==3 || u==4 || u==5 || u==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(u==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(u==6 || u==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(u==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(y==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(y==3 || y==4 || y==5 || y==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(y==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(y==0 || y==6 || y==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(y==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(t==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(t==3 || t==4 || t==5 || t==7 || t==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(t==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(t==0 || t==6 || t==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
					
				}
			
				else if(i==((2+(2*x3))-x3))   /* 2. basamak (sayı bölgesinde) */
				{
					if(u==1 || u==2 || u==3 || u==5 || u==6 || u==8 || u==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					
					else if(u==4 || u==7)
					{
						printf("    %c  ",borderChar);
					}
				        
				if(y==0 || y==1 || y==2 || y==3 || y==5 || y==6 || y==8 || y==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					
					else if(y==4 || y==7)
					{
						printf("    %c  ",borderChar);
					}
					
				if(t==0 || t==1 || t==2 || t==3 || t==5 || t==6 || t==8 || t==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					
					else if(t==4 || t==7)
					{
						printf("    %c  ",borderChar);
					}
				}
			}		/* 3 basamaklıların sonu */
			
			if (basamak == 4)
			{
				if(i==((6+(2*x3))-x3)) /* 6. basamak (sayı bölgesinde)) */
				{
					if(o==1)
					{
						printf("   %c   ",borderChar);
					}
				else if(o==2 || o==3 || o==5 || o==6 || o==7 || o==8 || o==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(o==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
					
		  			if(u==1)
					{
						printf("   %c   ",borderChar);
					}
		  else if(u==0 || u==2 || u==3 || u==5 || u==6 || u==7 || u==8 || u==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(u==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
				
					if(y==1)
					{
						printf("   %c   ",borderChar);
					}
		 else if(y==0 || y==2 || y==3 || y==5 || y==6 || y==7 || y==8 || y==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(y==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
					if(t==1)
					{
						printf("   %c   ",borderChar);
					}
		else if(t==0 || t==2 || t==3 || t==5 || t==6 || t==7 || t==8 || t==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(t==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
				}
				else if(i==((5+(2*x3))-x3))	/*  5. basamak (sayı bölgesinde) */
				{
					if(o==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(o==2 || o==3 || o==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(o==4 || o==8 || o== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(o==5 || o==6)
					{
						printf("  %c    ",borderChar);
					}
					
					if(u==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(u==2 || u==3 || u==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(u==0 || u==4 || u==8 || u== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(u==5 || u==6)
					{
						printf("  %c    ",borderChar);
					}
					
					if(y==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(y==2 || y==3 || y==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(y==0 || y==4 || y==8 || y== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(y==5 || y==6)
					{
						printf("  %c    ",borderChar);
					}
					
					if(t==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(t==2 || t==3 || t==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(t==0 || t==4 || t==8 || t== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(t==5 || t==6)
					{
						printf("  %c    ",borderChar);
					}
					
				}
				else if(i==((4+(2*x3))-x3))	  /* 4. basamak (sayı bölgesinde) */
				{
					if(o==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(o==2 || o==4 || o==5 || o==6 || o==8 || o==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if (o==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(o==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(u==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(u==2 || u==4 || u==5 || u==6 || u==8 || u==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if (u==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(u==0)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(u==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(y==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(y==2 || y==4 || y==5 || y==6 || y==8 || y==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if (y==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(y==0)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(y==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(t==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(t==2 || t==4 || t==5 || t==6 || t==8 || t==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if(t==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(t==0)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(t==7)
					{
						printf("    %c  ",borderChar);
					}
				}
				
				else if(i==((3+(2*x3))-x3))  /* 3. basamak (sayı bölgesinde) */
				{
					if(o==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(o==3 || o==4 || o==5 || o==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(o==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(o==6 || o==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(o==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(u==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(u==3 || u==4 || u==5 || u==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(u==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(u==0 || u==6 || u==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(u==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(y==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(y==3 || y==4 || y==5 || y==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(y==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(y==0 || y==6 || y==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(y==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(t==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(t==3 || t==4 || t==5 || t==7 || t==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(t==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(t==0 || t==6 || t==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
					
				}
			
				else if(i==((2+(2*x3))-x3))   /* 2. basamak (sayı bölgesinde) */
				{
					if(o==1 || o==2 || o==3 || o==5 || o==6 || o==8 || o==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if(o==4 || o==7)
					{
						printf("    %c  ",borderChar);
					}
					
				if(u==0 || u==1 || u==2 || u==3 || u==5 || u==6 || u==8 || u==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if(u==4 || u==7)
					{
						printf("    %c  ",borderChar);
					}
				        
				if(y==0 || y==1 || y==2 || y==3 || y==5 || y==6 || y==8 || y==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if(y==4 || y==7)
					{
						printf("    %c  ",borderChar);
					}
					
				if(t==0 || t==1 || t==2 || t==3 || t==5 || t==6 || t==8 || t==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if(t==4 || t==7)
					{
						printf("    %c  ",borderChar);
					}
				}
			} /* 4 basamaklıların sonu */
			if (basamak == 5)
			{
				if(i==((6+(2*x3))-x3)) /* 6. basamak (sayı bölgesinde) */
				{
					if(p==1)
					{
						printf("   %c   ",borderChar);
					}
				else if(p==2 || p==3 || p==5 || p==6 || p==7 || p==8 || p==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(p==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
					if(o==1)
					{
						printf("   %c   ",borderChar);
					}
		  else if(o==0 || o==2 || o==3 || o==5 || o==6 || o==7 || o==8 || o==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(o==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
					if(u==1)
					{
						printf("   %c   ",borderChar);
					}
		  else if(u==0 || u==2 || u==3 || u==5 || u==6 || u==7 || u==8 || u==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(u==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
				
					if(y==1)
					{
						printf("   %c   ",borderChar);
					}
		 else if(y==0 || y==2 || y==3 || y==5 || y==6 || y==7 || y==8 || y==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(y==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
					if(t==1)
					{
						printf("   %c   ",borderChar);
					}
		else if(t==0 || t==2 || t==3 || t==5 || t==6 || t==7 || t==8 || t==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					else if(t==4)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
				}
				else if(i==((5+(2*x3))-x3))	/*  5. basamak (sayı bölgesinde) */
				{
					if(p==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(p==2 || p==3 || p==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(p==4 || p==8 || p== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(p==5 || p==6)
					{
						printf("  %c    ",borderChar);
					}
					
					if(o==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(o==2 || o==3 || o==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(o==0 || o==4 || o==8 || o== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(o==5 || o==6)
					{
						printf("  %c    ",borderChar);
					}
					
					if(u==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(u==2 || u==3 || u==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(u==0 || u==4 || u==8 || u== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(u==5 || u==6)
					{
						printf("  %c    ",borderChar);
					}
					
					if(y==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(y==2 || y==3 || y==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(y==0 || y==4 || y==8 || y== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(y==5 || y==6)
					{
						printf("  %c    ",borderChar);
					}
					
					if(t==1)
					{
						printf("  %c%c   ",borderChar,borderChar);
					}
					else if(t==2 || t==3 || t==7 )
					{
						printf("    %c  ",borderChar);
					}
					else if(t==0 || t==4 || t==8 || t== 9)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(t==5 || t==6)
					{
						printf("  %c    ",borderChar);
					}
					
				}
				else if(i==((4+(2*x3))-x3))	   /* 4. basamak (sayı bölgesinde)*/
				{
					if(p==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(p==2 || p==4 || p==5 || p==6 || p==8 || p==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if (p==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(p==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(o==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(o==2 || o==4 || o==5 || o==6 || o==8 || o==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if (o==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(o==0)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(o==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(u==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(u==2 || u==4 || u==5 || u==6 || u==8 || u==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if (u==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(u==0)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(u==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(y==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(y==2 || y==4 || y==5 || y==6 || y==8 || y==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if (y==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(y==0)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(y==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(t==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(t==2 || t==4 || t==5 || t==6 || t==8 || t==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if(t==3)
					{
						printf("   %c%c  ",borderChar,borderChar);
					}
					else if(t==0)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(t==7)
					{
						printf("    %c  ",borderChar);
					}
				}
				
				else if(i==((3+(2*x3))-x3))  /* 3. basamak (sayı bölgesinde) */
				{
					if(p==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(p==3 || p==4 || p==5 || p==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(p==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(p==6 || p==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(p==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(o==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(o==3 || o==4 || o==5 || o==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(o==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(o==0 || o==6 || o==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(o==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(u==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(u==3 || u==4 || u==5 || u==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(u==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(u==0 || u==6 || u==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(u==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(y==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(y==3 || y==4 || y==5 || y==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(y==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(y==0 || y==6 || y==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					else if(y==7)
					{
						printf("    %c  ",borderChar);
					}
					
					if(t==1)
					{
						printf("   %c   ",borderChar);
					}
					else if(t==3 || t==4 || t==5 || t==7 || t==9)
					{
						printf("    %c  ",borderChar);
					}
					else if(t==2)
					{
						printf("  %c    ",borderChar);
					}
					else if(t==0 || t==6 || t==8)
					{
						printf("  %c %c  ",borderChar,borderChar);
					}
					
					
				}
			
				else if(i==((2+(2*x3))-x3))   /* 2. basamak (sayı bölgesinde)*/
				{
					if(p==1 || p==2 || p==3 || p==5 || p==6 || p==8 || p==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if(p==4 || p==7)
					{
						printf("    %c  ",borderChar);
					}
					
				if(o==0 || o==1 || o==2 || o==3 || o==5 || o==6 || o==8 || o==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if(o==4 || o==7)
					{
						printf("    %c  ",borderChar);
					}
					
				if(u==0 || u==1 || u==2 || u==3 || u==5 || u==6 || u==8 || u==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					else if(u==4 || u==7)
					{
						printf("    %c  ",borderChar);
					}
				        
				if(y==0 || y==1 || y==2 || y==3 || y==5 || y==6 || y==8 || y==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					
					else if(y==4 || y==7)
					{
						printf("    %c  ",borderChar);
					}
					
				if(t==0 || t==1 || t==2 || t==3 || t==5 || t==6 || t==8 || t==9)
					{
						printf("  %c%c%c  ",borderChar,borderChar,borderChar);
					}
					
					
					else if(t==4 || t==7)
					{
						printf("    %c  ",borderChar);
					}
				}
			} 		    /* 5 basamaklıların sonu */
			while(x2>0)
			{
				printf("%c",borderChar);
				x2--;
			}
			printf("\n");
			i--;
		}	
			
		
		else
		{
			while(x4>0)	 /*  7x7'lik bölgenin alt tarafını yazar */
			{
				/* basamak ve cerceveye gore karakter uzunluğu -----*/
				for(j=0;j<(start+(2*x6));j++)                
				{
					printf("%c",borderChar);
				}
				printf("\n");
				x4--;
				i--;
			}
		}
		
		
	}
	return 1;
	}
	
/* tek basamaklı sayılar hariç diğer sayılar , satırdaki karşılığına göre 
ekrana bastırıldı. örnek: 23    1. satır     ***   ***
		        				2. satır       *     * 	 
                                3. satır      **   ***
                                4. satır       *   *  
                                5. satır     ***   *
*/

}	/* printInput  fonksiyonunun sonu */


/* Function getInputs                                                         */
/* ------------------                                                         */
/* Bu fonksiyon kullanıcıdan girdi alır.                                      */
/*----------------------------------------------------------------------------*/

void getInputs(int* num, int* borderWidth, char* borderChar){

	
		while((*num) >= 0)
		{
			scanf("%d",&(*num));
			scanf("%d",&(*borderWidth));
			scanf(" %c",&(*borderChar));	
			printNumber(*num , *borderWidth, *borderChar);
		}
		return;
}


