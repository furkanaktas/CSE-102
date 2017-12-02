/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW08_141044029_Furkan_Aktaş                                                */
/*                                                                            */
/* 141044029_Furkan_Aktaş.c                                                   */
/* ----------------------------------                                         */
/* Created on 17/04/2016 by Furkan_Aktaş                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		141044029_Furkan_Aktaş.c contains codes for the homework VIII,		  */
/*	which are used for displaying chess simulator.							  */	
/*																			  */	
/*----------------------------------------------------------------------------*/

#include <stdio.h>
#define BOARD_SIZE 8
/*----------------------------------------------------------------------------*/
/*-------------------------- Function Prototypes -----------------------------*/
/*----------------------------------------------------------------------------*/
/* Function getPosition                                                       */
/* ------------------                                                         */
/* Bu fonksiyon kullanıcıdan konum verilerini alır.                           */
/*----------------------------------------------------------------------------*/
void getPosition(char *col, int *row);

/*----------------------------------------------------------------------------*/
/* Function isValidCell                                                       */
/* ------------------                                                         */
/* Bu fonksiyon girilen konumun geçerli olup olmadığını kontrol eder.         */
/*----------------------------------------------------------------------------*/
int isValidCell(char col, int row);

/*----------------------------------------------------------------------------*/
/* Function konum                                                             */
/* ------------------                                                         */
/* Bu fonksiyon girilen konumdaki elemanın kendisini ve index'ini return eder.*/
/*----------------------------------------------------------------------------*/
void konum(char col, int row,char *board,char* source, int* index);

/*----------------------------------------------------------------------------*/
/* Function printBoard                                                        */
/* ------------------                                                         */
/* Bu fonksiyon satranç tahtasını ekrana basar.                               */
/*----------------------------------------------------------------------------*/
void printBoard(char *board);

/*----------------------------------------------------------------------------*/
/* Function getPlayer                                                         */
/* ------------------                                                         */
/* Bu fonksiyon verilen stun ve satıra göre oradaki elemanı return eder.	  */
/*----------------------------------------------------------------------------*/
char getPlayer(char* board,char sc,int sr);

/*----------------------------------------------------------------------------*/
/* Function isWhite ,isBlack                                                  */
/* ------------------                                                         */
/* Bu fonksiyonlar oyanan taşın ne hangi renk olduğunu belirler.		 	  */
/*----------------------------------------------------------------------------*/
int isWhite(char currPlayer);
int isBlack(char currPlayer);

/*----------------------------------------------------------------------------*/
/* Function colRow			                                                  */
/* ------------------                                                         */
/* Bu fonksiyon verilen indexe göre stün ve satırı return eder.			 	  */
/*----------------------------------------------------------------------------*/
void colRow(int index, int* col, int*row);


/*----------------------------------------------------------------------------*/
/* Function kontrolSah		                                                  */
/* ------------------                                                         */
/*	 Bu fonksiyon şah'ın şah-mat durumunu kontrol eder ve isInCheck	  		  */
/*   fonksiyonuna kaynaklık eden 0,1,2 değerlerini	return eder.		  	  */
/*----------------------------------------------------------------------------*/
int kontrolSah(char* board, int index);

/*----------------------------------------------------------------------------*/
/* Function isInCheck                                                         */
/* ------------------                                                         */
/* 		Bu fonksiyon şah'ın indexini bulur ve kontrolSah fonksiyonundan 	  */
/* 	aldığı değerlere göre 0,1,2	 return eder.								  */
/*----------------------------------------------------------------------------*/
int isInCheck(char* board);

/*----------------------------------------------------------------------------*/
/* Function isPieceMovable                                                    */
/* ------------------                                                         */
/*  	Bu fonksiyon girilen konumdaki elemanın istenilen hareketi 			  */
/*	geçerliyse 1 değerini return eder, geçerli değilse return 0; 			  */
/*----------------------------------------------------------------------------*/
int isPieceMovable(char *board, char sc, int sr, char tc, int tr);

/*----------------------------------------------------------------------------*/
/* Function makeMove                                                          */
/* ------------------                                                         */
/* 	   Bu fonksiyon isPieceMovable fonk. 1 return ediyorken, taşı hareket	  */
/*	ettirir.Bu durumdayken isInCheck fonk. tarafından şahın, mat durumu		  */
/*	kontrol edilir.Eğer oynayan taşın şahı mat riskindeyse hareketi geri	  */
/*	alır 1 return eder.Eğer rakip taş mat riskindeyse 3 return eder.Mat riski */
/*	hiç yoksa 2 return eder.Eğer verilen konumda taş yoksa (hareket mümkün	  */
/*	değilse) 0 return eder.      											  */	
/*----------------------------------------------------------------------------*/	
int makeMove(char *board, char sc, int sr, char tc, int tr);

/*----------------------------------------------------------------------------*/
/* Function initBoard                                                         */
/* ------------------                                                         */
/* Bu fonksiyon satranç tahtasını içeren, 64'lük tek boyutlu array içerir.    */
/*----------------------------------------------------------------------------*/
void initBoard(char* a);

/*----------------------------------------------------------------------------*/
/* Geri kalan fonksiyonlar                                                    */
/* ------------------                                                         */
/* Diğer fonksiyonlar kendi isimlerindeki taşların hareklerini kontrol eder.  */
/*----------------------------------------------------------------------------*/
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

int main() {
    char board [BOARD_SIZE*BOARD_SIZE], empty;
    int player = 1; /* 1 white, 0 black */
    char sc,tc; /* source/target cols */
    int sr,tr; /* source/target rows */
    int moveStatus = 0;
    int checkStatus = 0;
    char currPlayer;

    initBoard(board);

    do {
        printBoard(board);
        printf("%s player move > ", player ? "White" : "Black");
        getPosition(&sc,&sr);
        scanf("%c", &empty);
        getPosition(&tc,&tr);
        scanf("%c", &empty);
        currPlayer = getPlayer(board, sc,sr);
		
        if(!isValidCell(sc,sr)) {
            printf("Source position is invalid\n");
            continue;
        }
        if(!isValidCell(tc,tr)) {
            printf("Target position is invalid\n");
            continue;
        }
        if((isBlack(currPlayer) && player) ||
           (isWhite(currPlayer) && !player)) {
            printf("Illegal piece. \n");
            continue;
        }

        moveStatus = makeMove(board,sc,sr,tc,tr);
        switch(moveStatus) {
            case 0:
                printf("Invalid move!\n");
                break;
            case 1:
                printf("Your king is in check!\n");
                ++checkStatus;
                break;
            case 3:
                printf("Check!\n ");
            case 2:
                player = !player;
                checkStatus = 0;
                break;
        }
    } while(checkStatus < 2);
    printf("%s player WINS!\n", player ? "Black" : "White");
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
	else if(i==0 || i==8 || i==16 || i==24 || i==32 || i==40 || i==48 || i==56)
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
	char b[64]={'r','n','b','q',' ','b','n',' ',
		 	    ' ','p','p','p','p','p','p','p',
			    ' ',' ',' ',' ',' ',' ',' ',' ',
			    ' ',' ',' ',' ',' ',' ',' ',' ',
			    'p',' ',' ','K',' ','k',' ','P',
			    ' ',' ',' ',' ',' ',' ',' ',' ',
			    ' ','P','P','P','P','P','P',' ',
			    'R','N','B','Q',' ','B','N',' '};
	
	for(i=0;i<64;i++)
	{
		a[i]=b[i];		
	}		  
	return;
}
int isPieceMovable(char *board, char sc, int sr, char tc, int tr){
	
	int index1,index2;
	char sr2,tc2;
	
	konum(sc, sr, board,&sr2,&index1);  /* kaynak  (sr2)*/
	konum(tc, tr, board,&tc2,&index2);	/* hedef  (tc2)*/
	
	if((sr2=='P' || sr2=='R' || sr2=='N' || sr2=='B' || sr2=='Q' || sr2=='K') &&
		(tc2=='p' || tc2=='r' || tc2=='n' || tc2=='b' || tc2=='q' || tc2=='k'
		 || tc2==' '))
	{
		index1 = index1;
	}	
	else if( (sr2=='p' || sr2=='r' || sr2=='n' || sr2=='b' || sr2=='q' ||
		 sr2=='k') && (tc2=='P' || tc2=='R' || tc2=='N' || tc2=='B' || tc2=='Q'
		  || tc2=='K' || tc2==' ' ) )
	{
		index1 = index1;
	}						/* kaynağa göre hedef belirlendi */	
	else 
	{
		return 0;
	}
	
	if(sr2 == 'P' || sr2 == 'p')
	{
		return isPawnMovable(board, sc, sr, tc, tr);
	}
	else if(sr2 == 'R' || sr2 == 'r')
	{
		return isRookMovable(board, sc, sr, tc, tr);
	}									
	else if(sr2 == 'N' || sr2 == 'n')
	{
		return isKnightMovable(board, sc, sr, tc, tr);
	}	
	else if(sr2 == 'K' || sr2 == 'k')
	{
		return isKingMovable(board, sc, sr, tc, tr);
	}	
	else if(sr2 == 'Q' || sr2 == 'q')
	{
		return isQueenMovable(board, sc, sr, tc, tr);
	}	
	else if(sr2 == 'B' || sr2 == 'b') 
	{
		return isBishopMovable(board, sc, sr, tc, tr);
	}		/* kaynağa göre taşın fonk. çağrıldı */ 	
	else
	{
		return 0;	/* kaynak boş( ' ' ) ise return 0 */
	}	
	return 0;	
}
int isKnightMovable(char *board, char sourceCol, int sourceRow,
												 char targetCol, int targetRow){
	/* AT (N)*/
	char source,target;			/* kaynağın index'i , hedefin index'i */
	int indexS,indexT,sc,sr;	/* sc: stunun sayısal karşılığı , sr: satır */
		
	konum(sourceCol, sourceRow, board,&source,&indexS);
	konum(targetCol, targetRow, board,&target,&indexT);
	colRow(indexS,&sc,&sr);
	
	/* at kaynak konumundan +6, -6, +10, -10, -15, +15, -17, +17 'lik konumlara 
	hareket edebilir */
	
	if( ((indexT == indexS+6 ) && (sr-1 >= 1 && sc-2 >= 1 )) || 
		((indexT == indexS-6 ) && (sr+1 <= 8 && sc+2 <= 8 )) ||
		((indexT == indexS+10) && (sr-1 >= 1 && sc+2 <= 8 )) ||
		((indexT == indexS-10) && (sr+1 <= 8 && sc-2 >= 1 )) ||
		((indexT == indexS+15) && (sr-2 >= 1 && sc-1 >= 1 )) ||
		((indexT == indexS-15) && (sr+2 <= 8 && sc+1 <= 8 )) ||
		((indexT == indexS+17) && (sr-2 >= 1 && sc+1 <= 8 )) ||
		((indexT == indexS-17) && (sr+2 <= 8 && sc-1 >= 1 ))    )	
	{
		return 1;
	}	
	else
	{
		return 0;
	}	
	return 0;
}
int isRookMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow){
	/* KALE (R) */
	char source,target;
	int indexS,indexT;	/* kaynağın index'i , hedefin index'i */	
	int i,count;
	
	count=1;
	
	konum(sourceCol, sourceRow, board,&source,&indexS);
	konum(targetCol, targetRow, board,&target,&indexT);
	
	if(targetCol == sourceCol) /* aynı stün içinde hareket (yukarı aşağı) */
	{	
		if(sourceRow > targetRow) /* aşağı hareket */
		{
			i=indexS+8; 	/* +8 kaynak tan 1 ileriyi (aşağı) ifade eder.*/
			while(i != indexT)
			{					
				if(board[i] == ' ')
				{
					i +=8;
					count +=1;	 /* count'un başlangıç(ilk) değeri 1 dir. */
				}		/* kaynak ile hedef arası boş olduğu sürece count+=1; */
				else
				{
					i=indexT;
				}
			}
			if(count == (sourceRow-targetRow))	/* satırlar farkı */
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
			i=indexS-8; /* -8 kaynak tan 1 geriyi (yukarı) ifade eder.*/
			while(i != indexT)
			{					
				if(board[i] == ' ')
				{
					i -=8;	
					count +=1;	/* count'un başlangıç(ilk) değeri 1 dir. */
				}		/* kaynak ile hedef arası boş olduğu sürece count+=1; */
				else
				{
					i=indexT;
				}
			}
			if(count == (targetRow-sourceRow)) /* satırlar farkı */
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
		if((int)sourceCol > (int)targetCol) /* sola hareket */
		{
			i=indexS-1; /*kaynaktan 1 adım geri (sol)*/
			while(i != indexT)
			{					
				if(board[i] == ' ')
				{
					i -=1;		/* count'un başlangıç(ilk) değeri 1 dir. */
					count +=1;	
				}		/* kaynak ile hedef arası boş olduğu sürece count+=1; */
				else
				{
					i=indexT;
				}
			}
			if(count == ((int)sourceCol - (int)targetCol)) /* stunlar farkı */
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
			i=indexS+1;	/*kaynaktan 1 adım ileri (sağ)*/
			while(i != indexT)
			{					
				if(board[i] == ' ')
				{
					i +=1;	/* count'un başlangıç(ilk) değeri 1 dir. */
					count +=1;	
				}		/* kaynak ile hedef arası boş olduğu sürece count+=1; */
				else
				{
					i=indexT;				
				}
			}
			if(count == ((int)targetCol)-(int)sourceCol) /* stunlar farkı */
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
	return 0;
}
int isKingMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow){
	/* ŞAH (K) */
	char source,target;
	int indexS,indexT,sc,sr;	/* kaynağın index'i , hedefin index'i */
	
	konum(sourceCol, sourceRow, board,&source,&indexS);
	konum(targetCol, targetRow, board,&target,&indexT);
	colRow(indexS,&sc,&sr);
	
/* Şah için kaynaktan -1, +1, -7, +7, -8, +8, -9, +9 'lik hareketler geçerli */ 
	
	if( ((indexT == indexS-1) && (      sc-1 >= 1		)) ||
		((indexT == indexS+1) && (      sc+1 <= 8		)) ||
		((indexT == indexS-8) && (      sr+1 <= 8		)) || 
		((indexT == indexS+8) && (      sr-1 >= 1		)) ||
		((indexT == indexS-7) && (sr+1 <= 8 && sc+1 <= 8)) ||
		((indexT == indexS+7) && (sr-1 >= 1 && sc-1 >= 1)) ||
		((indexT == indexS-9) && (sr+1 <= 8 && sc-1 >= 1)) ||
		((indexT == indexS+9) && (sr-1 >= 1 && sc+1 <= 8))    )
	{
		return 1;
	}	
	else
	{
		return 0;
	}
	
	return 0;
}
int isQueenMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow){
	/* VEZİR (Q) */
	int sR,tR,indexS,indexT;
	char sC,tC,source,target;
	sR=sourceRow;	tR=targetRow;	sC=(int)sourceCol;	tC=(int)targetCol;
	
	konum(sourceCol, sourceRow, board,&source,&indexS);	
	konum(targetCol, targetRow, board,&target,&indexT);
	
	/* aynı satır veya stun içinde hareket varsa KALE fonk. return edildi */
	if(sourceRow == targetRow || sourceCol == targetCol)
	{
		return isRookMovable(board, sourceCol, sourceRow, targetCol, targetRow);
	}
	/* çapraz hareket varsa FİL fonk return edildi */
	else if((tR>sR || tR<sR) && (sC<tC || sC>tC))						
	{
	   return isBishopMovable(board, sourceCol, sourceRow, targetCol,targetRow);	
	}
	return 0;
}
int isBishopMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow){
	/* FİL (B) */
	char source,target;
	int indexS, indexT;	/* kaynağın index'i , hedefin index'i */
	int i,count;
	
	konum(sourceCol, sourceRow, board,&source,&indexS); /* kaynak */
	konum(targetCol, targetRow, board,&target,&indexT);	/* hedef */
	
	if(sourceRow < targetRow && sourceCol > targetCol)
	{							/* sol üst çapraz hareket */
		i=indexS-9;
		count=9;
		while(i != indexT)
		{					
			if(board[i] == ' ')
			{
				i -=9;	 /* count'unn başlangıç(ilk) değeri 9 dir. */
				count +=9;	
			}		    /* kaynak ile hedef arası boş olduğu sürece count+=9; */	
			else
			{
				i=indexT;
			}
		}
		if(count == (indexS-indexT))	/* indexler farkı */
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
		i=indexS-7;
		count=7;
		while(i != indexT)
		{					
			if(board[i] == ' ')
			{
				i -=7;	
				count +=7;	/* count'un başlangıç(ilk) değeri 7 dir. */
			}			/* kaynak ile hedef arası boş olduğu sürece count+=7; */
			else
			{
				i=indexT;
			}
		}
		if(count == (indexS-indexT)) /* indexler farkı */
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
		i=indexS+9;
		count=9; 
		while(i != indexT)
		{					
			if(board[i] == ' ')
			{
				i +=9;	/* count'un başlangıç(ilk) değeri 9 dir. */
				count +=9;	
			}		    /* kaynak ile hedef arası boş olduğu sürece count+=9; */	
			else
			{
				i=indexT;
			}
		}
		if(count == (indexT-indexS)) 	/* indexler farkı */
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
		i=indexS+7;
		count=7; 
		while(i != indexT)
		{					
			if(board[i] == ' ')
			{
				i +=7;	
				count +=7;	/* count'un başlangıç(ilk) değeri 7 dir. */
			}			/* kaynak ile hedef arası boş olduğu sürece count+=7; */
			else
			{
				i=indexT;			
			}
		}
		if(count == (indexT-indexS)) /* indexler farkı */
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
		return 0;	/* FİL için hareket çapraz olmak zorunda */
	}
	return 0;
}
int isPawnMovable(char *board , char sourceCol, int sourceRow,
												 char targetCol, int targetRow){
	/* PİYON (P) */
	char source,target;
	int indexS,indexT,sr,sc;	/* kaynağın index'i , hedefin index'i */
	
	konum(sourceCol, sourceRow, board,&source,&indexS);
	konum(targetCol, targetRow, board,&target,&indexT);
	colRow(indexS,&sc,&sr);	
	
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
			else if ( indexT == (indexS-16) )  /*2 adım ileri (yukarı) */
			{
				if(target == ' ' && board[indexS-8] == ' ')
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}  
			else if( ((indexT == indexS-7) && (sr+1 <= 8 && sc+1 <= 8)) ||
					 ((indexT == indexS-9) && (sr+1 <= 8 && sc-1 >= 1))   )
			{									 /* çapraz */
				if(target != ' ')
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
			if( (indexT == indexS-8) && (sr+1 <= 8) )/* ileri hareket (yukarı)*/
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
			else if( ((indexT == indexS-7) && (sr+1 <= 8 && sc+1 <= 8)) ||
					 ((indexT == indexS-9) && (sr+1 <= 8 && sc-1 >= 1))   ) 
			{								/* çapraz */
				if(target != ' ')
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
		if(sourceRow == 7 )  /* piyon başlangıç pozisyonunda */
		{
			if(indexT == indexS+8) /* 1 adım ileri (aşağı)*/
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
			else if ( indexT == (indexS+16) ) /* 2 adım ileri (aşağı) */
			{
				if(target == ' ' && board[indexS+8] == ' ')
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else if( ((indexT == indexS+7) && (sr-1 >= 1 && sc-1 >= 1)) ||
					 ((indexT == indexS+9) && (sr-1 >= 1 && sc+1 <= 8))   ) 
			{								/* çapraz */
				if(target != ' ')
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
			if( (indexT == indexS+8) && (sr-1 >= 1) ) /* 1 adım ileri (aşağı) */
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
			else if( ((indexT == indexS+7) && (sr-1 >= 1 && sc-1 >= 1)) ||
					 ((indexT == indexS+9) && (sr-1 >= 1 && sc+1 <= 8))   )  
			{										/* çapraz */
				if(target != ' ')
				{
					return 1;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	return 0;
}
void konum(char col, int row, char* board,char* source, int* index){
	/* col ve row'a göre oradaki index değeri ve elemanı bulunuyor.*/
	
	int j,col2,k;
	
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
int makeMove(char *board, char sc, int sr, char tc, int tr){
	
	char temp,tas,worb,source,target;			/* worb: white or black*/
	int indexS,indexT;
	
	if(isPieceMovable(board, sc, sr, tc, tr) == 1 )
	{
		konum(sc, sr, board, &source, &indexS);   /* kaynağın index'i (indexS)*/
		konum(tc, tr, board, &target, &indexT);	   /* hedefin index'i (indexT)*/
		
		worb = board[indexS];
		tas  = board[indexS];
	
		if(worb == 'P' || worb == 'R' || worb == 'N' || worb == 'B' || 
		   worb == 'Q' || worb == 'K')		/* taşın rengi belirlendi */
		{
			worb = 'W';
		}	
		else
		{
			worb = 'B';
		}
	
		temp = board[indexT] ;
		board[indexT] = board[indexS];	/* taş hareket ettrildi */
		board[indexS] = ' ';

		if(isInCheck(board)==0)	
		{					 /* hareket sonucuna göre şah-mat durumuna bakıldı*/
			return 2;
		}
		else if(isInCheck(board)==1 || isInCheck(board)==2)
		{
			if( isInCheck(board)==1 && tas == 'k')
			{						 /* siyah şah, beyaz şah'ın önüne oynarsa */			
				board[indexS] = board[indexT];	
				board[indexT] = temp;
				return 1;
			}
			else if( (isInCheck(board)==1 && worb == 'W') || 
					 (isInCheck(board)==2 && worb == 'B')    )
			{									/*eğer oynanan taşın şah'ı mat*/
				board[indexS] = board[indexT];  /*tehlikesinde ise oynanan 	  */
				board[indexT] = temp;		    /* hareket geri alındı.       */
				return 1;				  /* return 1 (your king is in check) */
			}		
			else if( (isInCheck(board)==2 && worb == 'W')|| 
					 (isInCheck(board)==1 && worb == 'B')    )
			{
				return 3;
			}	
		}	
		/* eğer oynanan taş beyaz ve şah-mat durumu gerçekleşen taş siyah ise */
		/* yada tam tersi return 3 (check)*/
	}
	else
	{
		return 0;
	}		
	return 0;		
}
char getPlayer(char* board, char sc, int sr){

	char source;
	int index;
	konum(sc, sr, board, &source, &index);
	return source;
}
int isWhite(char currPlayer){
	
	if( currPlayer=='P'|| currPlayer=='R'|| currPlayer=='N'|| currPlayer=='B'||
	 currPlayer=='Q'|| currPlayer=='K'|| currPlayer==' ')
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
}
int isBlack(char currPlayer){
	
	if( currPlayer=='p'|| currPlayer=='r'|| currPlayer=='n'|| currPlayer=='b'||
	 currPlayer=='q'|| currPlayer=='k'|| currPlayer==' ')
	{
		return 1;
	}		
	else
	{
		return 0;
	}	
	return 0;
}
int isInCheck(char* board){
	
	int i,index,index1;
	
	index =0;
	for(i=0;board[i] != 'K';i++)	/* beyaz şah'ın index'i bulundu */
	{
		index = i;
	}
	index +=1;
	
	if(i==0)
	{
		index=0;	
	}
	
	index1 =0;
	for(i=0;board[i] != 'k';i++)	/* siyah şah'ın index'i bulundu */
	{
		index1 = i;	
	}
	index1 +=1;
	
	if(i==0)
	{
		index1=0;
	}
	kontrolSah(board, index);	/* beyaz şah, şah-mat durumu */
	kontrolSah(board, index1);	/* siyah şah, şah-mat durumu */
	
	if( kontrolSah(board, index) == 0 && kontrolSah(board, index1) == 0)
	{
		return kontrolSah(board, index);	/*şah-mat yoksa */
	}	
	else if( kontrolSah(board, index) == 1 )	/* beyaz şah-mat durumunda */
	{
		return kontrolSah(board, index);
	}
	else if( kontrolSah(board, index1) == 2) 	/* siyah şah-mat durumunda */	
	{
		return kontrolSah(board, index1);	
	}
	return 0;
}
void colRow(int index, int* col, int*row){

	if((index+1)%8 == 0)
	{
		*row = (index+1)/8;
	}
	else
	{
		*row = (index+1)/8 + 1;	
	}
	*row = 9-(*row) ;
	
	if(index==0)
	{
		*col=1;
	}	
	else if((index+1)%8 == 0) 
	{
		*col= index%8 + 1;
	}
	else	
	{
		*col=(index+1)%8;
	}	
	return;
}

int kontrolSah(char* board, int index){
							/* sr : tahtada bakılacak satır, tr: şah'ın satırı*/
	int i,sr,test,tr,col,sonuc;
	char sc,tc;	/* sc : tahtada bakılacak stun, tc: şah'ın  sütunu*/
	
	test = board[index];	/* beyaz şah yada siyah şah ( K yada k ) */
	
	colRow(index, &col, &tr);
			 /* gelen index'e (şah index'i) göre satır(tr), sütun(tc) bulundu */
	
	tc = (char)((int)'a'+col-1); /* şah'ın hangi stunda (a-h) oldugunu bulduk*/
	
	sonuc = 0;
	for(sr=1;sr<=8;sr++)
	{
		for(i=0;i<=7;i++)
		{
			sc = (char)((int)'a'+i);  /* a-h arası sc'ye verildi */
			if( isPieceMovable(board, sc, sr, tc, tr) == 1 )
			{
				sonuc = 1;
			}
		}
	}
	
/* döngü ile tahtadaki tüm taşların sırayla şahı mat etme ihtimaline bakıldı*/
/* şah'ı mat eden herhangi bir taş varsa sonuc=1 oluyor. (ilk sonuc degeri=0)*/ 
	
	if((test == 'k') && ( sonuc == 1))	/* şah siyahsa */
	{
		return 2;
	}
	else if((test == 'K') && ( sonuc == 1))	/* şah beyazsa */
	{
		return 1;
	}
	else
	{
		return 0;
	}
}









