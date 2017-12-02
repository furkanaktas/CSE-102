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
/* Function kontrol			                                                  */
/* ------------------                                                         */
/*	 Bu fonksiyon verilen kaynak ve hedef indexe göre ,taşın hareketinin	  */
/* geçerliliğini kontrol eder ve isPieceMovable fonksiyonuna kaynaklık eden   */
/* 0,1,2,3 değerlerini isInCheck fonksiyonun sonucuna göre return eder.		  */
/*----------------------------------------------------------------------------*/
int kontrol(char* board, int indexS, int indexT);

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
/*  	Bu fonksiyon girilen konumdaki elemanın hareketi geçerliyse kontrol   */
/*	kontrol fonksiyonunu return eder, geçerli değilse return 0;				  */
/*----------------------------------------------------------------------------*/
int isPieceMovable(char *board, char sc, int sr, char tc, int tr);

/*----------------------------------------------------------------------------*/
/* Function makeMove                                                          */
/* ------------------                                                         */
/* Bu fonksiyon isPieceMovable fonksiyonunu return eder. 					  */
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
	char source,target;
	int indexS,indexT;	/* kaynağın index'i , hedefin index'i */
	
	konum(sourceCol, sourceRow, board,&source,&indexS);
	konum(targetCol, targetRow, board,&target,&indexT);
	
	/* at kaynak konumundan +6, -6, +10, -10, -15, +15, -17, +17 'lik konumlara 
	hareket edebilir */
	
	if(indexT == (indexS+6) || indexT ==(indexS+15) || indexT ==(indexS+17))
	{
		return kontrol(board, indexS, indexT);
	}	
	else if(indexT==(indexS-6) || indexT==(indexS-15) || indexT==(indexS-17))
	{
		return kontrol(board, indexS, indexT);
	}	
	else if(indexT == (indexS+10) || indexT==(indexS-10))
	{
		return kontrol(board, indexS, indexT);
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
	int i,a;
	
	a=1;
	
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
					a +=1;	 /* a'nın başlangıç(ilk) değeri 1 dir. */
				}			/* kaynak ile hedef arası boş olduğu sürece a+=1; */
				else
				{
					i=indexT;
				}
			}
			if(a == (sourceRow-targetRow))	/* satırlar farkı */
			{
				return kontrol(board, indexS, indexT);
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
					a +=1;	/* a'nın başlangıç(ilk) değeri 1 dir. */
				}			/* kaynak ile hedef arası boş olduğu sürece a+=1; */
				else
				{
					i=indexT;
				}
			}
			if(a == (targetRow-sourceRow)) /* satırlar farkı */
			{
				return kontrol(board, indexS, indexT);
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
					i -=1;		/* a'nın başlangıç(ilk) değeri 1 dir. */
					a +=1;	/* kaynak ile hedef arası boş olduğu sürece a+=1; */
				}
				else
				{
					i=indexT;
				}
			}
			if(a == ((int)sourceCol - (int)targetCol)) /* stunlar farkı */
			{
				return kontrol(board, indexS, indexT);
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
					i +=1;	/* a'nın başlangıç(ilk) değeri 1 dir. */
					a +=1;	/* kaynak ile hedef arası boş olduğu sürece a+=1; */
				}			
				else
				{
					i=indexT;				
				}
			}
			if(a == ((int)targetCol)-(int)sourceCol) /* stunlar farkı */
			{
				return kontrol(board, indexS, indexT);
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
	char source;
	char target;
	int indexS;	/* kaynağın index'i */
	int indexT;	/* hedefin index'i */
	
	konum(sourceCol, sourceRow, board,&source,&indexS);
	konum(targetCol, targetRow, board,&target,&indexT);
	
/* Şah için kaynaktan -1, +1, -7, +7, -8, +8, -9, +9 'lik hareketler geçerli */ 
	
	if(indexT == (indexS-8) || indexT == (indexS+8) || indexT == (indexS+1))
	{
		return kontrol(board, indexS, indexT);
	}	
	else if(indexT==(indexS-1) || indexT==(indexS+7) || indexT==(indexS+9))
	{
		return kontrol(board, indexS, indexT);
	}	
	else if(indexT == (indexS-7) || indexT == (indexS-9))
	{
		return kontrol(board, indexS, indexT);
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
	int i,a;
	
	konum(sourceCol, sourceRow, board,&source,&indexS); /* kaynak */
	konum(targetCol, targetRow, board,&target,&indexT);	/* hedef */
	
	if(sourceRow < targetRow && sourceCol > targetCol)
	{							/* sol üst çapraz hareket */
		i=indexS-9;
		a=9;
		while(i != indexT)
		{					
			if(board[i] == ' ')
			{
				i -=9;	 /* a'nın başlangıç(ilk) değeri 9 dir. */
				a +=9;	 /* kaynak ile hedef arası boş olduğu sürece a+=9; */
			}			
			else
			{
				i=indexT;
			}
		}
		if(a == (indexS-indexT))	/* indexler farkı */
		{
			return kontrol(board, indexS, indexT);
		}
		else
		{
			return 0;
		}
	}
	else if(sourceRow < targetRow && sourceCol < targetCol) /* yukarı hareket */
	{								/* sağ üst çapraz hareket */
		i=indexS-7;
		a=7;
		while(i != indexT)
		{					
			if(board[i] == ' ')
			{
				i -=7;	
				a +=7;	/* a'nın başlangıç(ilk) değeri 7 dir. */
			}			/* kaynak ile hedef arası boş olduğu sürece a+=7; */
			else
			{
				i=indexT;
			}
		}
		if(a == (indexS-indexT)) /* indexler farkı */
		{
			return kontrol(board, indexS, indexT);
		}
		else
		{
			return 0;
		}
	}
	else if(sourceRow > targetRow && sourceCol < targetCol) 
	{							/* sağ alt çapraz hareket */
		i=indexS+9;
		a=9; 
		while(i != indexT)
		{					
			if(board[i] == ' ')
			{
				i +=9;	/* a'nın başlangıç(ilk) değeri 9 dir. */
				a +=9;	/* kaynak ile hedef arası boş olduğu sürece a+=9; */
			}			
			else
			{
				i=indexT;
			}
		}
		if(a == (indexT-indexS)) 	/* indexler farkı */
		{
			return kontrol(board, indexS, indexT);
		}
		else
		{
			return 0;
		}
	}
	else if(sourceRow > targetRow && sourceCol > targetCol) 
	{							/* sol alt çapraz hareket */
		i=indexS+7;
		a=7; 
		while(i != indexT)
		{					
			if(board[i] == ' ')
			{
				i +=7;	
				a +=7;	/* a'nın başlangıç(ilk) değeri 7 dir. */
			}			/* kaynak ile hedef arası boş olduğu sürece a+=7; */
			else
			{
				i=indexT;			
			}
		}
		if(a == (indexT-indexS)) /* indexler farkı */
		{
			return kontrol(board, indexS, indexT);
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
	int indexS,indexT;	/* kaynağın index'i , hedefin index'i */
	
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
					return kontrol(board, indexS, indexT);
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
					return kontrol(board, indexS, indexT);
				}
				else
				{
					return 0;
				}
			}  
			else if(indexT == (indexS-7) || indexT == (indexS-9)) /* çapraz */
			{
				if(target != ' ')
				{
					return kontrol(board, indexS, indexT);
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
					return kontrol(board, indexS, indexT);
				}
				else
				{
					return 0;
				}
			}
			else if(indexT == (indexS-7) || indexT == (indexS-9)) /* çapraz */
			{
				if(target != ' ')
				{
					return kontrol(board, indexS, indexT);
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
			if(indexT == (indexS+8) )	/* 1 adım ileri (aşağı)*/
			{
				if(target == ' ')
				{
					return kontrol(board, indexS, indexT);
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
					return kontrol(board, indexS, indexT);
				}
				else
				{
					return 0;
				}
			}
			else if(indexT == (indexS+7) || indexT == (indexS+9)) /* çapraz */
			{
				if(target != ' ')
				{
					return kontrol(board, indexS, indexT);
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
					return kontrol(board, indexS, indexT);
				}
				else
				{
					return 0;
				}
			}
			else if(indexT == (indexS+7) || indexT == (indexS+9)) /* çapraz */
			{
				if(target != ' ')
				{
					return kontrol(board, indexS, indexT);
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
	
	return isPieceMovable(board, sc, sr, tc, tr);		
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
int kontrol(char* board, int indexS, int indexT){

	char temp,worb;			/* worb: white or black*/
	
	worb =board[indexS];
	
	if(worb == 'P' || worb == 'R' || worb == 'N' || worb == 'B' || worb == 'Q'
	 	|| worb == 'K')		/* taşın rengi belirlendi */
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

				
	if(isInCheck(board)==0)	 /* hareket sonucuna göre şah-mat durumuna bakıldı*/
	{
		return 2;
	}
	else if(isInCheck(board)==1 || isInCheck(board)==2)
	{
		if( (isInCheck(board)==1 && worb == 'W') || 
			(isInCheck(board)==2 && worb == 'B') )
		{									    /*eğer oynanan taşın şah'ı mat*/
			board[indexS] = board[indexT];		/*tehlikesinde ise oynanan 	  */
			board[indexT] = temp;				/* hareket geri alındı.       */
			return 1;
		}		
		else if( (isInCheck(board)==2 && worb == 'W' )|| 
				 (isInCheck(board)==1 && worb == 'B') )
		{
			return 3;
		}	
	}	/* eğer oynanan taş beyaz ve şah-mat durumu gerçekleşen taş siyah ise */
		/* yada tam tersi return 3 */
	return 0;
}
int kontrolSah(char* board, int index){
				/*bu fonksiyon, her zaman ŞAH taşının indexi ile çağırılıyor */
	int a,b,c,d,e;	/*bu yüzden mat riski, ŞAH taşı merkez alınarak bulunuyor*/
				/*diğer taşların ŞAH'a uzaklığına bakarak return değeri belir.*/
	int i,temp,temp1,sc,sr;
	char test,tar,tar1,tar2,tar3,tar4,tar5;
	
	a=0;	b=0;	c=0;	d=0;	e=0;
	
	colRow(index, &sc, &sr);	/* sc: sütun(column)   , sr: satır(row) */ 
	test = board[index];
	
	temp = sc;	
	temp1 = sr;	
	
	if(test == 'k' )
	{
		tar  = 'Q'; 	/* a , b */	
		tar1 = 'B';		/* a */
		tar2 = 'R';		/* b */
		tar3 = 'P';		/* c */
		tar4 = 'N';		/* d */
		tar5 = 'K';		/* e */
	}	
	else if(test == 'K')
	{
		tar  = 'q';		/* a , b */	
		tar1 = 'b';		/* a */
		tar2 = 'r';		/* b */
		tar3 = 'p';		/* c */
		tar4 = 'n';		/* d */
		tar5 = 'k';		/* e */
	}
/************ ÇAPRAZDAN GERÇEKLEŞEN MAT GİRİŞİMİ (FİL VE VEZİR İÇİN) **********/
	i=index-9;
	sr +=1;				/* sol üst çapraz kontrolü */
	sc -=1;
	while(sr <= 8 && sc >= 1)	/* tablo dışına çıkılmadıkça */
	{					
		if(board[i] == ' ')		/* boşlukları atla */
		{
			i -=9;
			sr +=1;
			sc -=1;
		}
		else if(board[i] == tar || board[i] == tar1) /* tar: Q,q  ,tar1: B,b*/
		{
			a =1;
			sr = 9;		/* boşluktan başka, taş fil veya vezir olduğu zaman */
		}
		else			/* a=1;     a'nın ilk değeri 0'dı.					*/
		{
			sr = 9;			
		}
	}

	sc  =temp;			/* sc, sr değiştiği için tekrar ilk değeri verildi */
	sr  =temp1;
	
	i=index+9;			/* sağ alt çapraz kontrolü */
	sr -=1;
	sc +=1;
	while(sr >= 1 && sc <= 8)
	{					
		if(board[i] == ' ')
		{
			i +=9;
			sr -=1;
			sc +=1;
		}
		else if(board[i] == tar || board[i] == tar1) /* Q,q  , B,b*/
		{
			a =1;
			sr = 0;
		}
		else
		{
			sr = 0;			
		}
	}

	sc  =temp;			/* sc, sr değiştiği için tekrar ilk değeri verildi */
	sr  =temp1;
	
	i=index+7;				/* sol alt çapraz kontrolü */
	sr -=1;
	sc -=1;
	while(sr >= 1 && sc >= 1)
	{					
		if(board[i] == ' ')
		{
			i +=7;
			sr -=1;
			sc -=1;
		}
		else if(board[i] == tar || board[i] == tar1) /* Q,q  , B,b*/
		{
			a =1;
			sr = 0;
		}
		else
		{
			sr = 0;			
		}
	}
	
	sc  =temp;			/* sc, sr değiştiği için tekrar ilk değeri verildi */
	sr  =temp1;
	
	i=index-7;						/* sağ üst çapraz kontrolü */
	sr +=1;
	sc +=1;
	while(sr <= 8 && sc <= 8)
	{					
		if(board[i] == ' ')
		{
			i -=7;
			sr +=1;
			sc +=1;
		}
		else if(board[i] == tar || board[i] == tar1) /* Q,q  , B,b*/
		{
			a =1;
			sr = 9;
		}
		else
		{
			sr = 9;			
		}
	}	
/**********DİKEY VEYA YATAYDAN GELEN MAT GİRİŞİMİ (KALE VE VEZİR İÇİN)*********/

	sc  =temp;			/* sc, sr değiştiği için tekrar ilk değeri verildi */
	sr  =temp1;

	i=index-1; 				/* sol taraf kontrolü */
	sc -=1;
	while( sc >= 1 )		/* tablo dışına çıkılamadıkça */
	{					
		if(board[i] == ' ')
		{
			i -=1;
			sc -=1;	
		}
		else if(board[i] == tar || board[i] == tar2) /* tar: Q,q  ,tar2:  R,r */
		{
			b =1;
			sc = 0;
		}
		else
		{
			sc = 0;
		}
	}

	sc  =temp;		/* sc, sr değiştiği için tekrar ilk değeri verildi */
	sr  =temp1;

	i=index+1; 				/* sağ taraf kontrolü */
	sc +=1;
	while( sc <= 8 )
	{					
		if(board[i] == ' ')
		{
			i +=1;
			sc +=1;	
		}
		else if(board[i] == tar || board[i] == tar2) /* Q,q  , R,r*/
		{
			b =1;
			sc = 9;
		}
		else
		{
			sc = 9;
		}
	}
	
	sc  =temp;			/* sc, sr değiştiği için tekrar ilk değeri verildi */
	sr  =temp1;
	
	i=index+8; 				/* aşağı taraf kontrolü */
	sr -=1;
	while( sr >= 1 )
	{					
		if(board[i] == ' ')
		{
			i +=8;
			sr -=1;	
		}
		else if(board[i] == tar || board[i] == tar2) /* Q,q  , R,r*/
		{
			b =1;
			sr = 0;
		}
		else
		{
			sr = 0;
		}
	}
	
	sc  =temp;		/* sc, sr değiştiği için tekrar ilk değeri verildi */
	sr  =temp1;

	i=index-8; 					/* üst taraf kontrolü */
	sr +=1;
	while( sr <= 8 )
	{					
		if(board[i] == ' ')
		{
			i -=8;
			sr +=1;	
		}
		else if(board[i] == tar || board[i] == tar2) /* Q,q  , R,r*/
		{
			b =1;
			sr = 9;
		}
		else
		{
			sr = 9;
		}
	}
/*************** ÇAPRAZDAN GELEN MAT GİRİŞİMİ (PİYON İÇİN) ********************/
	
	sc  =temp;			/* sc, sr değiştiği için tekrar ilk değeri verildi */
	sr  =temp1;
	
	if( test == 'K')	/* şah K (beyaz), piyon p (siyah piyon)*/
	{
		if(sc == 8 && sr <7 ) /* 8.stunda sadece sol üst taraftan şah-mat olur*/
		{
			i=index-9;
			if(board[i] == tar3 )	/* tar3: piyon*/
			{
				c=1;
			}
		}
		else if(sc == 1 && sr < 7 )
		{					/* 1.stunda sadece sağ üst taraftan şah-mat olur*/
			i=index-7;
			if(board[i] == tar3 ) /* tar3: piyon*/
			{
				c=1;
			}
		}
		else if( sr < 7 ) /* siyah piyon en az 6. satırdaki elemanı yer */
		{
			i=index-7;
			if(board[i] == tar3)
			{
				c=1;
			}
			i=index-9;
			if(board[i] == tar3)
			{
				c=1;
			}
		}
	}
	else		/* şah k (siyah)  ,piyon P (beyaz piyon) */
	{
		if(sc == 8 && sr > 2 ) /*8.stunda sadece sol alt taraftan şah-mat olur*/
		{
			i=index+7;
			if(board[i] == tar3 )
			{
				c=1;
			}
		}
		else if(sc == 1 && sr > 2 )
		{					   /*1.stunda sadece sağ alt taraftan şah-mat olur*/
			i=index+9;
			if(board[i] == tar3 )
			{
				c=1;
			}
		}
		else if( sr > 2 )	/* beyaz piyon en az 3. satırdaki elemanı yer */
		{
			i=index+7;
			if(board[i] == tar3 )
			{
				c=1;
			}
			i=index+9;
			if(board[i] == tar3 )
			{
				c=1;
			}
		}	
	}
/************************* AT İLE GELEN MAT GİRİŞİMİ **************************/	
	
	sc =temp;
	sr  =temp1;	/*AT +6 -6 ,+10 -10 ,+15 -15 ,+17 -17 lik indexlere gidebilir*/
				/*bu yüzden şah'ın index'ine olan mesafeler bu kadar olacak*/
	i = index -17;
	if(board[i]==tar4 && (sr+2 <=8 && sc-1 >=1 ))	/* tar4 : rakip AT */
	{
		d=1;
	}
	i = index -15;
	if(board[i]==tar4 && (sr+2 <=8 && sc+1 <=8 ))
	{
		d=1;
	}
	i = index -10;
	if(board[i]==tar4 && (sr+1 <=8 && sc-2 >=1 ))
	{
		d=1;
	}
	i = index -6;
	if(board[i]==tar4 && (sr+1 <=8 && sc+2 <=8 ))
	{
		d=1;
	}	
	i = index +15;
	if(board[i]==tar4 && (sr-2 >=1 && sc-1 >=1 ))
	{
		d=1;
	}
	i = index +17;
	if(board[i]==tar4 && (sr-2 >=1 && sc+1 <=8 ))
	{
		d=1;
	}	
	i = index +10;
	if(board[i]==tar4 && (sr-1 >=1 && sc+2 <=8 ))
	{
		d=1;
	}
	i = index +6;
	if(board[i]==tar4 && (sr-1 >=1 && sc-2 >=1 ))
	{
		d=1;
	}		
/********************** ŞAH İLE GELEN MAT GİRİŞİMİ ****************************/
	
	sc =temp;	 	/*ŞAH +1 -1 ,+7 -7 ,+8 -8 ,+9 -9 lik indexlere gidebilir*/
	sr  =temp1;	  /*bu yüzden şah'ın index'ine olan mesafeler bu kadar olacak*/
	
	i = index -1;
	if(board[i]==tar5 && (sc-1 >=1 ))		/* tar5: rakip şah */
	{
		e=1;			
	}
	i = index -7;
	if(board[i]==tar5 && (sr+1 <=8 && sc+1 <=8 ))
	{
		e=1;			
	}
	i = index -8;
	if(board[i]==tar5 && (sr+1 <=8 ))
	{
		e=1;			
	}
	i = index -9;
	if(board[i]==tar5 && (sr+1 <=8 && sc-1 >=1 ))
	{
		e=1;			
	}	
	i = index +1;
	if(board[i]==tar5 && ( sc+1 <=8 ))
	{
		e=1;			
	}
	i = index +7;
	if(board[i]==tar5 && (sr-1 >=1 && sc-1 >=1 ))
	{
		e=1;			
	}	
	i = index +8;
	if(board[i]==tar5 && (sr-1 >= 1))
	{
		e=1;			
	}
	i = index +9;
	if(board[i]==tar5 && (sr-1 >=1 && sc+1 <=8 ))
	{
		e=1;			
	}		
	
   /* herhangi bir şekilde şahı mat edecek durum varsa (a=1,b=1,c=1,d=1,e=1)*/
   /* taş beyazsa return 1, siyahsa return 0, mat durumu yoksa return 0 */	
	if((test == 'K') && ( a==1 || b==1 || c==1 || d==1 || e==1))
	{
		return 1;
	}
	else if((test == 'k') && ( a==1 || b==1 || c==1 || d==1 || e==1))
	{
		return 2;
	}
	else
	{
		return 0;
	}
	return 0;
}

