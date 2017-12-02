/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW10_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş.c                                                   */
/* ----------------------------------                                         */
/* Created on 02/05/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		141044029_Furkan_Aktaş.c contains codes for the homework X, which	  */
/*	 are used for reading information about a department in a university	  */
/*   such as students, lectures, and professors and outputs a file which 	  */
/*   includes some summary information.							  			  */	
/*																			  */	
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#define size 100

typedef struct{

	int amount;
	int id;
	char name[30],surname[30];
	
} students;		/* öğrenci bilgisi */

typedef struct{

	int amount,id;
	char degree[30];
	char name[30],surname[30];
	
} profs;	/* hoca bilgisi */

typedef struct{

	int amount;
	int code,idOfLect;		/*idOfLect: dersi veren hoca*/
	char name[30];
	
} lectures;	/* ders bilgisi */

typedef struct{

	int amount;
	char class[30],day[30];	
	int start,time,code;
		
} schedule;		/* takvim bilgisi */

typedef struct{

	int amount;
	int id,code;		/* öğrenci id, ders kodu */
	
} courseTake;		/* öğrenci tarafından alınan der bilgisi */

/*----------------------------------------------------------------------------*/
/*-------------------------- Function Prototypes -----------------------------*/
/*----------------------------------------------------------------------------*/
/* Function input		                                                      */
/* ------------------                                                         */
/* Bu fonksiyon dosyadan veri okuyup, belirlenmiş struct yapılarına atandı.	  */
/*----------------------------------------------------------------------------*/
void input(FILE *file, students student[size], profs prof[size],
	lectures lect[size], schedule schedul[size], courseTake take[size] );

/*----------------------------------------------------------------------------*/
/* Function output		                                                      */
/* ------------------                                                         */
/* 	Bu fonksiyon struct yapılardan aldığı verileri, txt dosyası olarak        */
/* çıktı verir.																  */
/*----------------------------------------------------------------------------*/
void output(FILE *file2,students student[size],profs prof[size],
	lectures lect[size],schedule schedul[size],	courseTake take[size] );


int main(){
	
	students student[size];
	profs prof[size];
	lectures lect[size];
	schedule schedul[size];
	courseTake take[size];
	
	FILE *file,*file2;
	
	file = fopen("input.dat","rb");
	
	if( file == NULL )
	{
		puts("dosya acilmiyor...");
	}
	else
	{
		input(file, student, prof, lect, schedul, take);
	}
	
	file2 = fopen("output.txt","w");
	
	if( file2 == NULL )
	{
		puts("dosya acilmiyor...");
	}
	else
	{
		output(file2, student, prof, lect, schedul, take);
	}

	fclose(file);
	fclose(file2);
	
	return 0;
}

void input(FILE *file,students student[size],profs prof[size],
	lectures lect[size],schedule schedul[size],courseTake take[size] ){
	
	int i,miktar;
	
/****************************  STUDENT(öğrenciler) ****************************/
		
	fread(&miktar,sizeof(int),1,file);
	
	for(i=0;i<miktar;i++)
	{
		student[i].amount = miktar;
		fread(&(student[i].id),sizeof(int),1,file);
		fread(student[i].name,sizeof(char),30,file);
		fread(student[i].surname,sizeof(char),30,file);
	}
		/* veriler sırayla dosyadan okundu*/		
	
/***************************	PROF(hocalar)	******************/		
		
	fread(&miktar,sizeof(int),1,file);
	
	for(i=0;i<miktar;i++)
	{
		prof[i].amount = miktar;
		fread(prof[i].degree,sizeof(char),30,file);
		fseek(file,(SEEK_CUR+1),SEEK_CUR);
		fread(&(prof[i].id),sizeof(int),1,file);
		fread(prof[i].name,sizeof(char),30,file);
		fread(prof[i].surname,sizeof(char),30,file);
	}
	/* veriler sırayla dosyadan okundu*/
	
/***************************	LECT(dersler)	******************/		
	
	fread(&miktar,sizeof(int),1,file);
	
	for(i=0;i<miktar;i++)
	{
		lect[i].amount = miktar;
		fread(&(lect[i].code),sizeof(int),1,file);
		fread(lect[i].name,sizeof(char),30,file);
		fseek(file,(SEEK_CUR+1),SEEK_CUR);
		fread(&(lect[i].idOfLect),sizeof(int),1,file);
	}
	/* veriler sırayla dosyadan okundu*/
	
/***************************	SCHEDUL(takvim)	******************/		
		
	fread(&miktar,sizeof(int),1,file);
	
	for(i=0;i<miktar;i++)
	{
		schedul[i].amount = miktar;
		fread(schedul[i].class,sizeof(char),30,file);
		fread(schedul[i].day,sizeof(char),30,file);
		fread(&(schedul[i].start),sizeof(int),1,file);
		fread(&(schedul[i].time),sizeof(int),1,file);
		fread(&(schedul[i].code),sizeof(int),1,file);
	}
		/* veriler sırayla dosyadan okundu*/

/*********************** TAKE(dersi alanlar) ********************************/

	fread(&miktar,sizeof(int),1,file);
	
	for(i=0;i<miktar;i++)
	{
		take[i].amount = miktar;
		fread(&(take[i].id),sizeof(int),1,file);
		fread(&(take[i].code),sizeof(int),1,file);
	}
		/* veriler sırayla dosyadan okundu*/
	
	return;
}
/******************************************************************************/
/******************************************************************************/
void output(FILE *file2,students student[size],profs prof[size],
	lectures lect[size],schedule schedul[size],courseTake take[size] ){
	
	int i,j,k,count,miktar,miktar2;
	
/*****************************	Lecture-Lecturer ****************************/	
	
	fprintf(file2,"Lecture-Lecturer\n");
		
	miktar = lect[0].amount;	/* toplam ders sayısı */
	miktar2 = prof[0].amount;	/* hocaların sayısı */
		
	for(i=0;i<miktar;i++)	/* ders sayısı kadar döngü */
	{
		fprintf(file2,"%s ",lect[i].name);	/*dersin ismi*/
		
		for(j=0;j<miktar2;j++)	/* hoca sayısı kadar döngü */
		{
			if( lect[i].idOfLect == prof[j].id) /* hoca id'leri eşleştiğinde */
			{
				fprintf(file2,"%s %s ",prof[j].name,prof[j].surname);
				
				count =0;
				for(k=0;k<take[0].amount;k++) /*alınan ders sayısı kadar döngü*/
				{
					if(lect[i].code == take[k].code) /*ders kodları eşleşt. */
					{
						count +=1;
					}
				}
				fprintf(file2,"%d\n",count);  /*satır sonu, yeni satır */
			}		
		}
	}
	fprintf(file2,"\n");  /* 2 özet arası boşluk */
/*****************************	Student-Lecture ****************************/
	
	fprintf(file2,"Student-Lecture\n");
			
	miktar = student[0].amount;
		
	for(i=0;i<miktar;i++)	/* öğrenci sayısı kadar döngü */
	{
		fprintf(file2,"%d ",student[i].id);
		fprintf(file2,"%s ",student[i].name);
		fprintf(file2,"%s ",student[i].surname);
			
		count=0;
		for(j=0;j<take[0].amount;j++)	/*alınan ders sayısı kadar döngü*/
		{
			if(student[i].id == take[j].id)
			{
				count +=1;		/* öğrencinin aldığı ders sayısı*/
			}
		}
		fprintf(file2,"%d \n",count);	/*satır sonunda, yeni satır*/
	}
	fprintf(file2,"\n");	 /* 2 özet arası boşluk*/

/*****************************	Student-Day  *****************************/	
		
	fprintf(file2,"Student-Day\n");
	
	miktar = student[0].amount;		/* toplam öğrenci sayısı */
	miktar2 = schedul[0].amount;		/* toplam takvim girdisi */
	
	for(i=0;i<miktar;i++)	/* öğrenci sayısı kadar döngü */
	{
		fprintf(file2,"%d ",student[i].id);
		fprintf(file2,"%s ",student[i].name);
		fprintf(file2,"%s ",student[i].surname);
		
		count = 0;
		for(j=0;j<take[0].amount;j++)	/*alınan ders sayısı kadar döngü*/
		{
			if(student[i].id == take[j].id)
			{
				count +=1;		/* öğrencinin aldığı ders sayısı */
			}
		}
		for(j=0;j<take[0].amount;j++)	/*alınan ders sayısı(take) kadar döngü*/
		{	
			if(student[i].id == take[j].id)	/*öğrenci take'teki id ile eşleş.*/
			{
				for(k=0;k<miktar2;k++)	/* toplam takvim girdisi kadar döngü */
				{
					if(take[j].code == schedul[k].code)	/*dersler eşleştiğin.*/
					{
						fprintf(file2,"%s",schedul[k].day);	/*ders günü*/
						
						count -=1;		
						if(count != 0)	
						{		/*son gün print edildiğinde virgül atılmayacak*/
							fprintf(file2,", ");
						}
					}
				}
			}
		}
		fprintf(file2,"\n"); 	/* satır sonunda yeni satır*/
	}
	fprintf(file2,"\n");	
	return;	
}
