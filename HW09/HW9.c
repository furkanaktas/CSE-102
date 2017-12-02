/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW09_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş.c                                                   */
/* ----------------------------------                                         */
/* Created on 26/04/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		141044029_Furkan_Aktaş.c contains codes for the homework IX,		  */
/*	which are used for keeping information about world countries.			  */	
/*																			  */	
/*----------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#define size 100

typedef struct{
		
		char name[25];
		char neighbor[10][25];
		int population,area,army;
		
	} infoCountry;

int main(){

	int i,j,k,l,count,count2,count3,sonuc,large;
	char option,country[25],location[25],target[25];
	
	
	
	infoCountry info[size];
	
	
	for(i=0;i<size;i++)
	{
		
		for(k=0;k<25;k++)
		{
			info[i].name[k] = '\0';
		}
		for(j=0;j<10;j++)
		{
			for(k=0;k<25;k++)
			{
				info[i].neighbor[j][k] = '\0';
			}	
		}
	}
	

	j=0;			/* info dizisinin eleman değişkeni */
	i=0;			/* sonsuz döngü kontrolcüsü */
	while(i == 0)
	{
		printf("Make your choice:\n");	scanf(" %c",&option);
		switch(option)
		{
			case 'a':
			case 'A':
			{
				scanf("%s",(info[j].name));
				scanf("%d",&(info[j].population));
				scanf("%d",&(info[j].area));
				scanf("%d",&(info[j].army));
				
				count = 0;
				k=0;
				while(count == 0)
				{					
					scanf("%s",(info[j].neighbor[k]));
					
					if(strcmp( info[j].neighbor[k], "-1")==0)
					{
						info[j].neighbor[k][0] = '\0';
						count = -1;					
					}
					else if( k == 9 ) /* son komşu ülke */
					{
						count = -1;
					}
					else
					{
						count = 0;
					}
					k++;
				}
				j++;
				i=0;
				break;
			}
			case 'b':
			case 'B':
			{
				scanf("%s",country);
				
				count = 0;
				for(j=0;info[j].name[0] != '\0';j++)
				{
					if(strcmp(info[j].name,country) == 0)
					{
						count  = j;		/*eşleşmenin olduğu index*/
						count2 = j;
						count3 = j;
					}
				}
				
				if(strcmp( info[count].name, country) == 0)
				{
					large = info[count].army;
					sonuc = count;
					
					for(j=0;info[count].neighbor[j][0] != '\0';j++)
					{
				     /*j değişkenine bağlı olarak sırayla komşulara bakıldı*/			
						for(k=0;info[k].name[0] != '\0';k++)
						{
							if(strcmp(info[k].name,info[count].neighbor[j]) ==0)
							{
								count2 = k;		/*komşunun index'i*/
							}
						}
						
						if(large < info[count2].army)
						{
							large = info[count2].army ;
							sonuc = count2;
						}
						
						for(k=0;info[count2].neighbor[k][0] != '\0';k++)
						{
			/*k değişkenine bağlı olarak sırayla komşunun komşularına bakıldı*/				
							for(l=0;info[l].name[0] != '\0';l++)
							{
								if(strcmp(info[l].name,info[count2].neighbor[k])
									 == 0)
								{
									count3 = l;	/*komşunun komşusunun index'i*/
								}	
							}
			/*her komşunun(j'ye bağlı) tüm komşuları burada karşılaştırılıyor */		
							if(large < info[count3].army)
							{
								large = info[count3].army ;
								sonuc = count3;
							}
							
						}
					}
					printf("%s\n",info[sonuc].name);
				}	/*sonuc : enson bulunan (en büyük) verinin index'i */
				else
				{
					printf("Ülke kaydı yok ! \n");
				}
				i=0;
				break;
			}
			case 'c':
			case 'C':
			{
				scanf("%s",country);
				
				count = 0;
				for(j=0;info[j].name[0] != '\0';j++)
				{
					if(strcmp(info[j].name,country) == 0)
					{
						count  = j;		/*eşleşmenin olduğu index*/
						count2 = j;
						count3 = j;
					}
				}
				
				if(strcmp( info[count].name, country) == 0)
				{
					large = info[count].area; /*girilen ülkenin yüz ölçümü*/
					sonuc = count;
					
					for(j=0;info[count].neighbor[j][0] != '\0';j++)
					{
						for(k=0;info[k].name[0] != '\0';k++)
						{
				       /*j değişkenine bağlı olarak sırayla komşulara bakıldı*/		
							if(strcmp(info[k].name,info[count].neighbor[j]) ==0)
							{
								count2 = k;		/*komşunun index'i*/
							}
						}
						
						if(large < info[count2].area) /*komşu ülke yüz ölçümü*/
						{
							large = info[count2].area ;
							sonuc = count2;
						}
						
						for(k=0;info[count2].neighbor[k][0] != '\0';k++)
						{
			/*k değişkenine bağlı olarak sırayla komşunun komşularına bakıldı*/		
							for(l=0;info[l].name[0] != '\0';l++)
							{
								if(strcmp(info[l].name,info[count2].neighbor[k])
									 == 0)
								{
									count3 = l;	/*komşunun komşusunun index'i*/
								}	
							}
			/*her komşunun(j'ye bağlı) tüm komşuları burada karşılaştırılıyor */
							if(large < info[count3].area)
							{
								large = info[count3].area ;
								sonuc = count3;
							}
						}
					}
					printf("%s\n",info[sonuc].name);
				} 	/*sonuc : enson bulunan (en büyük) verinin index'i */
				else
				{
					printf("Ülke kaydı yok ! \n");
				}
				i=0;
				break;
			}
			case 'd':
			case 'D':
			{
				scanf("%s%s",location,target);
				for(j=0;info[j].name[0] != '\0';j++)
				{
					if(strcmp(info[j].name,location) == 0)
					{
						count  = j;		/*eşleşmenin olduğu index*/
					}
				}
				for(j=0;info[j].name[0] != '\0';j++)
				{
					if(strcmp(info[j].name,target) == 0)
					{
						count2  = j;		/*eşleşmenin olduğu index*/
					}
				}
				
				count3 = 0;
				for(j=0;info[count].neighbor[j][0] != '\0';j++)
				{ 								   /* ortak komşulara bakıldı */
					for(k=0;info[count2].neighbor[k][0] != '\0';k++)
					{
						if(strcmp(info[count].neighbor[j],
												info[count2].neighbor[k])==0)
						{
							count3 +=1;
						}
					}
				}
				if(info[count].neighbor[0][0] == '\0' || count3 == 0)
				{/*başlangıç konumun komşusu yoksa yada ortak komşu ülke yoksa*/
					printf("INACCESSIBLE\n");
				}
				i=0;
				break;
			}
			case 'e':
			case 'E':
			{
				printf("Good Bye\n");
				i=-1;
				break;
			}
			
		}
	}
	return 0;
}

