/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW02_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş_Part1.c                                             */
/* ----------------------------------                                         */
/* Created on 27/02/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*	 141044029_Furkan_Aktaş_Part1.c contains codes for the first part of      */
/*	the homework II, which are used for calculating the overall grade of      */
/*	the 3 students.                                                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include <stdio.h>

void calculateLastGrade();

int main(){

	calculateLastGrade();
	calculateLastGrade();
	calculateLastGrade();	

}

void calculateLastGrade()
{
	int midterm,homework,final;
	int midWeight,homWeight,finWeight;
	float grade;

	printf("Please enter the 1. midterm weight:");	scanf("%d",&midWeight);
	printf("Please enter the 1. homework weight:");	scanf("%d",&homWeight);
	printf("Please enter the final exam weight:");	scanf("%d",&finWeight);

	printf("Please enter the 1. midterm grade:");	scanf("%d",&midterm);
	printf("Please enter the 1. homework grade:");	scanf("%d",&homework);
	printf("Please enter the final exam grade:");	scanf("%d",&final);

	grade = (final*finWeight + homework*homWeight + midterm*midWeight)/100;

	printf("Your final grade is:%f\n",grade);	
	
}
