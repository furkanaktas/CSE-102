/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW05_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş.c                                                   */
/* ----------------------------------                                         */
/* Created on 04/04/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		141044029_Furkan_Aktaş.c contains codes for the homework I, which are */
/*  used for performing basic operations of a chess simulator which will take */
/*	commands and arguments from the user, executes the commands and           */
/*	return the result.             											  */	
/*																			  */	
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* Function konum                                                             */
/* ------------------                                                         */
/* Bu fonksiyon girilen konumdaki elemanın kendisini ve index'ini return eder.*/
/*----------------------------------------------------------------------------*/

/* Function getPosition                                                       */
/* ------------------                                                         */
/* Bu fonksiyon kullanıcıdan konum verilerini alır.                           */
/*----------------------------------------------------------------------------*/

/* Function isValidCell                                                       */
/* ------------------                                                         */
/* Bu fonksiyon girilen konumun geçerli olup olmadığını kontrol eder.         */
/*----------------------------------------------------------------------------*/

/* Function printBoard                                                        */
/* ------------------                                                         */
/* Bu fonksiyon satranç tahtasını ekrana basar.                               */
/*----------------------------------------------------------------------------*/

/* Function konum                                                             */
/* ------------------                                                         */
/* Bu fonksiyon girilen konumdaki elemanın kendisini ve index'ini return eder.*/
/*----------------------------------------------------------------------------*/

/* Function isPieceMovable                                                    */
/* ------------------                                                         */
/*  Bu fonksiyon girilen konumdaki elemanın hareket edip edemediğini          */ 
/*(taş olup olmadığını) kontrol eder.                                         */
/*----------------------------------------------------------------------------*/

/* Geri kalan fonksiyonlar                                                    */
/* ------------------                                                         */
/* Diğer fonksiyonlar kendi isimlerindeki taşların hareklerini kontrol eder.  */
/*----------------------------------------------------------------------------*/
#include <stdio.h>

void getPosition(char *col, int *row);
int isValidCell(char col, int row);
void printBoard(char *board);
void initBoard(char* a);

void konum(char col, int row,char *board,char* source, int* index);
int isPieceMovable(char *board);
int isKnightMovable(char *board, char sourceCol, int sourceRow,
												 char targetCol, int targetRow);
int isRookMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow);
int isKingMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow);
int isQueenMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow);
int isBishopMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow);
int isPawnMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow);

void emptyBuffer()
{
	while ( getchar() != '\n' );
}
int main()
{
	char board [64];
	int initComplete = 0;
	char empty;

	int command;
	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: initBoard(board); 
				initComplete = 1; 
				printf("OK\n");
				break;
			case 2: 
				/*Read space character after command number*/
				scanf("%c", &empty);
				if (initComplete)
				{
					if(isPieceMovable(board))
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
				{  
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3: 
				if (initComplete)
					printBoard(board);
				else  
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: printf("Invalid command!\n"); emptyBuffer(); break;

		}	
		
		scanf("%d", &command);
	
	}
	return 0;
}
void getPosition(char *col, int *row){
	
	scanf(" %c",&(*col));
	scanf("%d",&(*row));
	
	return;	
}
int isValidCell(char col, int row){
	
	int a=(int)col;
	
	if((97<=a && a<=104) && (1<=row && row<=8))
	{
		return 1;
	}
	else
	{	
		return 0;
	}
}
void printBoard(char *board){
	
	int i,a,s;
	s=8;
	
	printf("\n  a b c d e f g h \n");
	printf("  - - - - - - - - \n");
	for(i=0;i<64;i++)
	{
		a = board[i];
		if(i==7 || i==15 || i==23 || i==31 || i==39 || i==47 || i==55 || i==63)
		{
			printf("%c",a);
			printf("|\n");
		}
	else if(i==0 || i==8 || i==16 || i==24 || i==32 || i==40 || i==48 || i==56 )
		{
			printf("%d|%c ",s,a);
			s -=1;
		}
		else
		{			
			printf("%c ",a);
		}
		
	
	}
	printf("  - - - - - - - - \n");
	return;
}
void initBoard(char a[]){

	int i;
	char b[64]={'r','n','b','q','k','b','n','r',
		 	    'p','p','p','p','p','p','p','p',
			    ' ',' ',' ',' ',' ',' ',' ',' ',
			    ' ',' ',' ',' ',' ',' ',' ',' ',
			    ' ',' ',' ',' ',' ',' ',' ',' ',
			    ' ',' ',' ',' ',' ',' ',' ',' ',
			    'P','P','P','P','P','P','P','P',
			    'R','N','B','Q','K','B','N','R'};
	
	for(i=0;i<64;i++)
	{
		a[i]=b[i];		
	}		  
	return;
}
int isPieceMovable(char *board){
	
	char col,colTar;
	int row,rowTar;
	int index;
	char source;
	
	getPosition(&col, &row);     /* taşın konumu */
	getPosition(&colTar, &rowTar);   /* taşın hareket edeceği konum */
	
	if(isValidCell(col, row) == 0 || isValidCell(colTar, rowTar) ==0 )
			return 0;    /* kaynağın geçerlilik kontrolü */
						/* hedefin geçerlilik kontrolü */
	
	
	konum(col, row, board,&source,&index); /* kaynak'ta taş olup olmadığı */
	
	if(source =='P' || source =='p')
	{ 
		return isPawnMovable(board, col, row, colTar, rowTar);
	}
	else if(source =='R' || source =='r')
	{ 
		return isRookMovable(board, col, row, colTar, rowTar);
		
	}
	else if(source =='N' || source =='n')
	{ 
		return isKnightMovable(board, col, row, colTar, rowTar);
		
	}
	else if(source =='K' || source =='k')
	{ 
		return isKingMovable(board, col, row, colTar, rowTar);
		
	}
	else if(source =='Q' || source =='q')
	{ 
		return isQueenMovable(board, col, row, colTar, rowTar);
		
	}
	else if(source =='B' || source =='b')
	{ 
		return isBishopMovable(board, col, row, colTar, rowTar);
		
	}
	else
	{ 
	 	return 0;
	}	
}
int isKnightMovable(char *board, char sourceCol, int sourceRow,
												 char targetCol, int targetRow){
	/* AT (N)*/
	char source;
	char target;
	int indexS; /* kaynağın index'i */
	int indexT; /* hedefin index'i */
	
	konum(sourceCol, sourceRow, board,&source,&indexS);
	konum(targetCol, targetRow, board,&target,&indexT);
	
	/* at kaynak konumundan +6, -6, +10, -10, -15, +15, -17, +17 'lik konumlara 
	hareket edebilir */
	
	if(source == 'N')
	{
		if(indexT == (indexS+6) || indexT ==(indexS+15) || indexT ==(indexS+17))
		{
			if(target == 'k' || target == 'q' || target == 'n' || target == 'b')
			{
				return 1;
			}
			else if(target == 'r' || target == 'p' || target == ' ')
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	   else if(indexT==(indexS-6) || indexT==(indexS-15) || indexT==(indexS-17))
		{
			if(target == 'k' || target == 'q' || target == 'n' || target == 'b')
			{
				return 1;
			}
			else if(target == 'r' || target == 'p' || target == ' ')
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if(indexT == (indexS+10) || indexT==(indexS-10))
		{
			if(target == 'k' || target == 'q' || target == 'n' || target == 'b')
			{
				return 1;
			}
			else if(target == 'r' || target == 'p' || target == ' ')
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else if(source == 'n')
	{
		if(indexT == (indexS+6) || indexT ==(indexS+15) || indexT ==(indexS+17))
		{
			if(target == 'K' || target == 'Q' || target == 'N' || target == 'B')
			{
				return 1;
			}
			else if(target == 'R' || target == 'P' || target == ' ')
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	   else if(indexT==(indexS-6) || indexT==(indexS-15) || indexT==(indexS-17))
		{
			if(target == 'K' || target == 'Q' || target == 'N' || target == 'B')
			{
				return 1;
			}
			else if(target == 'R' || target == 'P' || target == ' ')
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if(indexT == (indexS+10) || indexT==(indexS-10))
		{
			if(target == 'K' || target == 'Q' || target == 'N' || target == 'B')
			{
				return 1;
			}
			else if(target == 'R' || target == 'P' || target == ' ')
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
}
int isRookMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow){
	/* KALE (R) */
	char source;
	char target;
	int indexS;	/* kaynağın index'i */
	int indexT;	/* hedefin index'i */
	int i,a;
	a=1;
	
	konum(sourceCol, sourceRow, board,&source,&indexS);
	konum(targetCol, targetRow, board,&target,&indexT);
	
	
	if(targetCol == sourceCol) /* aynı stün içinde hareket (yukarı aşağı) */
	{
		if(source == 'R' || source == 'Q')
		{
			if(target == 'k' || target == 'q' || target == 'b' || target == ' ')
			{
				if(sourceRow > targetRow)
				{
					i=indexS+8; /* +8 kaynak tan 1 ileriyi (aşağı) ifade eder.*/
				}
				else
				{
					i=indexS-8; /* -8 kaynak tan 1 geriyi (yukarı) ifade eder.*/
				}	
			}
			else if(target == 'n' || target == 'r' || target == 'p')
			{
				if(sourceRow > targetRow)
				{
					i=indexS+8;
				}
				else
				{
					i=indexS-8;
				}
			}
			else
			{
				i=indexT;
				a=-100;	
			}
		}
		else if(source == 'r' || source == 'q')
		{
			if(target == 'K' || target == 'Q' || target == 'B' || target == ' ')
			{
				if(sourceRow > targetRow)
				{
					i=indexS+8;
				}
				else
				{
					i=indexS-8;
				}	
			}
			else if(target == 'N' || target == 'R' || target == 'P')
			{
				if(sourceRow > targetRow)
				{
					i=indexS+8;
				}
				else
				{
					i=indexS-8;
				}
			}
			else
			{
				i=indexT;
				a=-100;	
			}
		}
		if(sourceRow > targetRow) /* aşağı hareket */
		{
			while(i != indexT)
			{					
				if(board[i] == ' ')
				{
					i +=8;
					a +=1;	 /* a'nın başlangıç(ilk) değeri 1 dir. */
				}			/* kaynak ile hedef arası boş olduğu sürece a+=1; */
				else
				{
					i=indexT;
				}			
			}
			if(a == (sourceRow-targetRow))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if(sourceRow < targetRow) /* yukarı hareket */
		{
			while(i != indexT)
			{					
				if(board[i] == ' ')
				{
					i -=8;	
					a +=1;	/* a'nın başlangıç(ilk) değeri 1 dir. */
				}			/* kaynak ile hedef arası boş olduğu sürece a+=1; */
				else
				{
					i=indexT;
				}			
			}
			if(a == (targetRow-sourceRow)) /* satırlar farkı */
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if(targetRow == sourceRow)
		{	
			return 0;
		}
	}
	else if(targetRow == sourceRow) /* aynı satır içinde hareket (sağa sola)*/
	{
		if(source == 'R' || source == 'Q')
		{
			if(target == 'k' || target == 'q' || target == 'b' || target == ' ')
			{
				if((int)sourceCol > (int)targetCol)
				{
					i=indexS-1;
				}
				else
				{
					i=indexS+1;
				}	
			}
			else if(target == 'n' || target == 'r' || target == 'p')
			{
				if((int)sourceCol > (int)targetCol)
				{
					i=indexS-1;
				}
				else
				{
					i=indexS+1;
				}
			}
			else
			{
				i=indexT;
				a=-100;	
			}
		}
		else if(source == 'r' || source == 'q')
		{
			if(target == 'K' || target == 'Q' || target == 'B' || target == ' ')
			{
				if((int)sourceCol > (int)targetCol)
				{
					i=indexS-1; /*kaynaktan 1 adım geri (sol)*/
				}
				else
				{
					i=indexS+1;	/*kaynaktan 1 adım ileri (sağ)*/
				}	
			}
			else if(target == 'N' || target == 'R' || target == 'P')
			{
				if((int)sourceCol > (int)targetCol)
				{
					i=indexS-1;	/*kaynaktan 1 adım geri (sol)*/
				}
				else
				{
					i=indexS+1;	/*kaynaktan 1 adım ileri (sağ)*/
				}
			}
			else
			{
				i=indexT;
				a=-100;	
			}
		}
		if((int)sourceCol > (int)targetCol) /* sola hareket */
		{
			while(i != indexT)
			{					
				if(board[i] == ' ')
				{
					i -=1;
					a +=1;	/* a'nın başlangıç(ilk) değeri 1 dir. */
				}			/* kaynak ile hedef arası boş olduğu sürece a+=1; */
				else
				{
					i=indexT;
				}			
			}
			if(a == ((int)sourceCol - (int)targetCol)) /* stunlar farkı */
			{
				return 1;
			}
			else
			{
					return 0;
			}
		}
		else if((int)sourceCol < (int)targetCol) /* sağa hareket */
		{
			while(i != indexT)
			{					
				if(board[i] == ' ')
				{
					i +=1;
					a +=1;	/* a'nın başlangıç(ilk) değeri 1 dir. */
				}			/* kaynak ile hedef arası boş olduğu sürece a+=1; */
				else
				{
					i=indexT;
				}			
			}
			if(a == ((int)targetCol)-(int)sourceCol) /* stunlar farkı */
			{
				return 1;
			}
			else
			{
					return 0;
			}
		}
		else if((int)targetCol == (int)sourceCol)
		{	
			return 0;
		}
	}
	else /*kale için, sadece aynı satır veya aynı sütun içinde hareket geçerli*/
	{
		return 0;
	}
	
	
}
int isKingMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow){
	/* ŞAH (K) */
	char source;
	char target;
	int indexS;	/* kaynağın index'i */
	int indexT;	/* hedefin index'i */
	
	konum(sourceCol, sourceRow, board,&source,&indexS);
	konum(targetCol, targetRow, board,&target,&indexT);
	
/* Şah için kaynaktan -1, +1, -7, +7, -8, +8, -9, +9 'lik hareketler geçerli */ 
	
	if(source == 'K')
	{
		if(indexT == (indexS-8) || indexT == (indexS+8) || indexT == (indexS+1))
		{
		   if( target == ' ' || target == 'k' || target == 'q' || target == 'n')
		   {
		   		return 1;
		   }
		   else if(target == 'b' || target == 'r' || target == 'p')
		   {
		   		return 1;
		   }
		   else
		   {
		   		return 0;
		   }
		}
		else if(indexT==(indexS-1) || indexT==(indexS+7) || indexT==(indexS+9))
		{
		   if( target == ' ' || target == 'k' || target == 'q' || target == 'n')
		   {
		   		return 1;
		   }
		   else if(target == 'b' || target == 'r' || target == 'p')
		   {
		   		return 1;
		   }
		   else
		   {
		   		return 0;
		   }
		}
		else if(indexT == (indexS-7) || indexT == (indexS-9))
		{
		   if( target == ' ' || target == 'k' || target == 'q' || target == 'n')
		   {
		   		return 1;
		   }
		   else if(target == 'b' || target == 'r' || target == 'p')
		   {
		   		return 1;
		   }
		   else
		   {
		   		return 0;
		   }
		}
		else
		{
			return 0;
		}
	}
	else if(source == 'k')
	{
		if(indexT == (indexS-8) || indexT == (indexS+8) || indexT == (indexS+1))
		{
		   if( target == ' ' || target == 'K' || target == 'Q' || target == 'N')
		   {
		   		return 1;
		   }
		   else if(target == 'B' || target == 'R' || target == 'P')
		   {
		   		return 1;
		   }
		   else
		   {
		   		return 0;
		   }
		}
		else if(indexT==(indexS-1) || indexT==(indexS+7) || indexT==(indexS+9))
		{
		   if( target == ' ' || target == 'K' || target == 'Q' || target == 'N')
		   {
		   		return 1;
		   }
		   else if(target == 'B' || target == 'R' || target == 'P')
		   {
		   		return 1;
		   }
		   else
		   {
		   		return 0;
		   }
		}
		else if(indexT == (indexS-7) || indexT == (indexS-9))
		{
		   if( target == ' ' || target == 'K' || target == 'Q' || target == 'N')
		   {
		   		return 1;
		   }
		   else if(target == 'B' || target == 'R' || target == 'P')
		   {
		   		return 1;
		   }
		   else
		   {
		   		return 0;
		   }
		}
		else
		{
			return 0;
		}
	}
	
}
int isQueenMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow){
	/* VEZİR (Q) */
	int sR,tR;
	char sC,tC;
	sR=sourceRow;	tR=targetRow;	sC=(int)sourceCol;	tC=(int)targetCol;
	if(sourceRow == targetRow || sourceCol == targetCol)
	{
		if(isRookMovable(board, sourceCol, sourceRow, targetCol, targetRow)==1)
			return 1;
		else
			return 0;
	}
	else if((tR>sR || tR<sR) && (sC<tC || sC>tC))
	{	
		if(isBishopMovable(board, sourceCol, sourceRow, targetCol, targetRow)==1)
			return 1;
		else
			return 0;	
	}
	
}
int isBishopMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow){
	/* FİL (B) */
	char source;
	char target;
	int indexS;	/* kaynağın index'i */
	int indexT;	/* hedefin index'i */
	int i,a;
	
	konum(sourceCol, sourceRow, board,&source,&indexS);
	konum(targetCol, targetRow, board,&target,&indexT);
	
	if(source == 'B' || source == 'Q')
	{
		if(target == 'k' || target == 'q' || target == 'b' || target == ' ')
		{
			if(sourceRow < targetRow && sourceCol > targetCol)
			{					/*sol üst çapraz*/
				i=indexS-9;
				a=9;
			}
			else if(sourceRow < targetRow && sourceCol < targetCol)
			{					/*sağ üst çapraz*/
				i=indexS-7;
				a=7; 
			}
			else if(sourceRow > targetRow && sourceCol < targetCol)
			{					/*sağ alt çapraz*/
				i=indexS+9;
				a=9; 
			}
			else if(sourceRow > targetRow && sourceCol > targetCol)
			{						/*sol alt çapraz*/
				i=indexS+7;
				a=7; 
			}	
		}
		else if(target == 'n' || target == 'r' || target == 'p')
		{
			if(sourceRow < targetRow && sourceCol > targetCol)
			{						/*sol üst çapraz*/
				i=indexS-9;
				a=9;
			}
			else if(sourceRow < targetRow && sourceCol < targetCol)
			{						/*sağ üst çapraz*/
				i=indexS-7;
				a=7; 
			}
			else if(sourceRow > targetRow && sourceCol < targetCol)
			{						/*sağ alt çapraz*/
				i=indexS+9;
				a=9; 
			}
			else if(sourceRow > targetRow && sourceCol > targetCol)
			{						/*sol alt çapraz*/
				i=indexS+7;
				a=7; 
			}
		}
		else
		{
			i=indexT;
			a=-100;	
		}
	}
	else if(source == 'b' || source == 'q')
	{
		if(target == 'K' || target == 'Q' || target == 'B' || target == ' ')
		{
			if(sourceRow < targetRow && sourceCol > targetCol)
			{						/*sol üst çapraz*/
				i=indexS-9;
				a=9;
			}
			else if(sourceRow < targetRow && sourceCol < targetCol)
			{						/*sağ üst çapraz*/
				i=indexS-7;
				a=7; 
			}
			else if(sourceRow > targetRow && sourceCol < targetCol)
			{							/*sağ alt çapraz*/
				i=indexS+9;
				a=9; 
			}
			else if(sourceRow > targetRow && sourceCol > targetCol)
			{							/*sol alt çapraz*/
				i=indexS+7;
				a=7; 
			}	
		}
		else if(target == 'N' || target == 'R' || target == 'P')
		{
			if(sourceRow < targetRow && sourceCol > targetCol)
			{						/*sol üst çapraz*/
				i=indexS-9;
				a=9;
			}
			else if(sourceRow < targetRow && sourceCol < targetCol)
			{						/*sağ üst çapraz*/
				i=indexS-7;
				a=7; 
			}
			else if(sourceRow > targetRow && sourceCol < targetCol)
			{						/*sağ alt çapraz*/
				i=indexS+9;
				a=9; 
			}
			else if(sourceRow > targetRow && sourceCol > targetCol)
			{							/*sol alt çapraz*/
				i=indexS+7;
				a=7; 
			}
		}
		else
		{
			i=indexT;
			a=-100;	
		}
	}
	if(sourceRow < targetRow && sourceCol > targetCol)
	{							/* sol üst çapraz hareket */
		while(i != indexT)
		{					
			if(board[i] == ' ')
			{
				i -=9;
				a +=9;	 /* a'nın başlangıç(ilk) değeri 1 dir. */
			}			/* kaynak ile hedef arası boş olduğu sürece a+=9; */
			else
			{
				i=indexT;
			}			
		}
		if(a == (indexS-indexT))	/* indexler farkı */
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(sourceRow < targetRow && sourceCol < targetCol) /* yukarı hareket */
	{								/* sağ üst çapraz hareket */
		while(i != indexT)
		{					
			if(board[i] == ' ')
			{
				i -=7;	
				a +=7;	/* a'nın başlangıç(ilk) değeri 1 dir. */
			}			/* kaynak ile hedef arası boş olduğu sürece a+=7; */
			else
			{
				i=indexT;
			}			
		}
		if(a == (indexS-indexT)) /* indexler farkı */
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(sourceRow > targetRow && sourceCol < targetCol) 
	{							/* sağ alt çapraz hareket */
		while(i != indexT)
		{					
			if(board[i] == ' ')
			{
				i +=9;	
				a +=9;	/* a'nın başlangıç(ilk) değeri 1 dir. */
			}			/* kaynak ile hedef arası boş olduğu sürece a+=9; */
			else
			{
				i=indexT;
			}			
		}
		if(a == (indexT-indexS)) /* indexler farkı */
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(sourceRow > targetRow && sourceCol > targetCol) 
	{							/* sol alt çapraz hareket */
		while(i != indexT)
		{					
			if(board[i] == ' ')
			{
				i +=7;	
				a +=7;	/* a'nın başlangıç(ilk) değeri 1 dir. */
			}			/* kaynak ile hedef arası boş olduğu sürece a+=7; */
			else
			{
				i=indexT;
			}			
		}
		if(a == (indexT-indexS)) /* indexler farkı */
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(targetRow == sourceRow || targetCol==sourceCol)
	{	
		return 0;
	}
}
int isPawnMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow){
	/* PİYON (P) */
	char source;
	char target;
	int indexS;	/* kaynağın index'i */
	int indexT;	/* hedefin index'i */
	
	konum(sourceCol, sourceRow, board,&source,&indexS);
	konum(targetCol, targetRow, board,&target,&indexT);
	
	if(source == 'P')
	{
		if(sourceRow == 2)  /* piyon başlangıç konumunda */
		{
			if(indexT == (indexS-8) ) /* 1 adım ileri (yukarı) */
			{
				if( target == ' ')
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
	/*		else if ( indexT == (indexS-16) )  2 adım ileri (yukarı) 
			{
				if(target == ' ' && board[indexS-8] == ' ')
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}  */
			else if(indexT == (indexS-7) || indexT == (indexS-9)) /* çapraz */
			{
				if(target =='p' || target =='q'|| target =='n')
				{
					return 1;
				}
				else if(target =='k' || target =='b'|| target =='r')
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
		else  /* piyon herhangi bir konumda */
		{
			if(indexT == (indexS-8) )  /* ileri hareket (yukarı)*/
			{
				if(target == ' ')
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else if(indexT == (indexS-7) || indexT == (indexS-9)) /* çapraz */
			{
				if(target =='p' || target =='q'|| target =='n')
				{
					return 1;
				}
				else if(target =='k' || target =='b'|| target =='r')
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	else if(source == 'p')
	{
		if(sourceRow == 7)  /* piyon başlangıç pozisyonunda */
		{
			if(indexT == (indexS+8) )	/* 1 adım ileri (aşağı)*/
			{
				if(target == ' ')
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
	/*		else if ( indexT == (indexS+16) )  2 adım ileri (aşağı) 
			{
				if(target == ' ' && board[indexS+8] == ' ')
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}*/
			else if(indexT == (indexS+7) || indexT == (indexS+9)) /* çapraz */
			{
				if(target =='P' || target =='Q'|| target =='N')
				{
					return 1;
				}
				else if(target =='K' || target =='B'|| target =='R')
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
		else  	/* piyon herhangi bir konumda */
		{
			if(indexT == (indexS+8) ) /* 1 adım ileri (aşağı) */
			{
				if(target == ' ')
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else if(indexT == (indexS+7) || indexT == (indexS+9)) /* çapraz */
			{
				if(target =='P' || target =='Q'|| target =='N')
				{
					return 1;
				}
				else if(target =='K' || target =='B'|| target =='R')
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
	}
}
void konum(char col, int row, char* board,char* source, int* index){
	/* col ve row'a göre oradaki index değeri ve elemanı bulunuyor.*/
	
	int i,j,col2,k;
	
	col2 = (int)col -96; /* örnek: sütun a ise (int)a = 97 -96 =1 */ 
	
	k=-1;
	
	for(j=0;j<(col2 +(8*(8-row)));j++) 
	{					/* (8*(8-row)) satır sayısına göre işlem sağlar */
		k +=1;		/* örnek : b7 = 2+8 =10; 0'dan 9'a kadar indexlenir */	
	}
	
	*index = k;
	*source = board[k];
	
	return;	
}
