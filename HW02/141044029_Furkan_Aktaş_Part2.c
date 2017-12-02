/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW02_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş_Part2.c                                             */
/* ----------------------------------                                         */
/* Created on 27/02/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*	 141044029_Furkan_Aktaş_Part2.c contains codes for the second part of     */
/*	the homework II, which are used for calculating area and perimeter of     */
/*  the rectangle, square and circle.                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include <stdio.h>
#define PI 3.14

int areaOfRectangle(int width, int height);
int perimeterOfRectangle(int width, int height);

int areaOfSquare(int width);
int perimeterOfSquare(int width);

double perimeterOfCircle(int radius);
double areaOfCircle(int radius);

int main(){
	
	int width,height,radius;
	int areaRectangle,areaSquare;
	int periRectangle,periSquare;
	double periCircle,areaCircle;

	printf("Please enter the width of the rectangle:");		scanf("%d",&width);
	printf("Please enter the height of the rectangle:");	scanf("%d",&height);

	areaRectangle = areaOfRectangle(width,height);
	periRectangle = perimeterOfRectangle(width,height);

	printf("The area of the rectangle is: %d\n",areaRectangle);
	printf("The perimeter of the rectangle is: %d\n",periRectangle);
	

	printf("Please enter the width of the square:");		scanf("%d",&width);

	areaSquare = areaOfSquare(width);
	periSquare = perimeterOfSquare(width);
	
	printf("The area of the square is: %d\n",areaSquare);
	printf("The perimeter of the square is: %d\n",periSquare);


	printf("Please enter the radius of the circle:");		scanf("%d",&radius);

	areaCircle = areaOfCircle(radius);
	periCircle = perimeterOfCircle(radius);	

	printf("The area of the circle is: %.2f\n",areaCircle);
	printf("The perimeter of the circle is: %.2f\n",periCircle);
	

}

/*...............................Rectangle....................................*/
int areaOfRectangle(int width, int height)
{
	int area;
	area = width*height;
	return area;
}

int perimeterOfRectangle(int width, int height)
{
	int perimeter;
	perimeter = (width+height)*2;
	return perimeter;
}

/*................................Square......................................*/

int areaOfSquare(int width)
{
	int area;
	area = width*width;
	return area;
}
int perimeterOfSquare(int width)
{
	int perimeter;
	perimeter = width*4;
	return perimeter;
}

/*................................Circle......................................*/

double areaOfCircle(int radius)
{
	double area;
	area = PI*(radius*radius);
	return area;
}
double perimeterOfCircle(int radius)
{
	double perimeter;
	perimeter = 2*PI*radius;
	return perimeter;
}

