#include <iostream>
#include"ConnectFourAbstract.h"
#include"ConnectFourDiagonal.h"
#include"Cell.h"
using namespace std;

namespace mehmet
{
	
	ConnectFourDiagonal::ConnectFourDiagonal(){
		game_play();
	}
	int ConnectFourDiagonal::control(char sign){		 //SADECE capraz kontrol eden check fonksiyonu						
	
		int i,j;
		int win=0;
		
					for(i=row-1; i>=0; i--){									
					  for(j=column-1; j>=0; j--){

			
					if(gameboard[i][j].signn==sign && gameboard[i-1][j-1].signn==sign && gameboard[i-2][j-2].signn==sign && gameboard[i-3][j-3].signn==sign)
						{win=1;}   //satir ve sutunu 1 er azaltarak sol carazi kontrol ediyo
		
					if(gameboard[i][j].signn==sign && gameboard[i-1][j+1].signn==sign && gameboard[i-2][j+2].signn==sign && gameboard[i-3][j+3].signn==sign)
						{win=1;}         //satiri 1 azaltip sutunu 1 er art�rarak sag carazi kontrol ediyo
		}	
	
	}
	
	return win;               //win i returb ediyo
}
void ConnectFourDiagonal::displayBoard(){
    
	int a,i,j;
    char harf[]={'A','B','C','D','E','F','G','H','I','j','K','L','M','N','O','P','Q','R','S','T','U','V','W','X'};
     
     for(a=0; a<column; a++){
   	cout<<harf[a]<<" ";                         //dizini basina size kadar harfleri s�ra ile koyuyor.
   }
   cout<<endl;
	for(i=0; i<row; i++){

		for(j=0; j<column; j++){

			if(gameboard[i][j].empty==true){                                  //nokta ile doldurmanin kosulu
			gameboard[i][j].signn='.';                                       //belirtilen yer bos ise nokta koy  
			}                                        
			cout<<gameboard[i][j].signn<<" ";                                    //nokta arlarina bosluk koyuyor

		}
		cout<<endl;

}
}


void ConnectFourDiagonal::gameEnd(char sign){            
	    int a=draw();                                           //draw fonksiyonun d�nd�rd��� degeri a ya atadim
	    if(a==1){                                                
	   	cout<<"it is draw"<<endl;
	   	gameEndd=true;
	   }
	  
		   int win=control(sign);                               //win d�nd�ren kontrol fonksiyonu yine win e atadim
		   if(win==1){
		
		   gameEndd=true;
	
	       if(prefer==1){                                            //prefer oyun modunu temsil ediyo player to player
		
		   if(sign=='X')
		   cout<<"player1 won"<<endl;                          //OYUN modu 1 ise player to player ise ve signature x ise player1 won
		  
           else 
           cout<<"player2 won"<<endl;                           //OYUN modu 1 ise player to player ise ve signature o ise player2 won
           }
           else{                                                     //player vs com ise
	       if(sign=='X')
	  
	        cout<<"player1 won"<<endl;                         //OYUN modu 0 ise player to computer ise ve signature x ise player1 won
         
           else
       
       	   cout<<"you loseEEEE"<<endl;                          //OYUN modu 0 ise player to computer ise ve signature o ise computer won
    
}
}
}
int ConnectFourDiagonal::draw(){

       int i=0;
	   int prefer;
	   int cont=0;
	   int a;
 	 for(int i=0; i<column; ++i ){

 		if(gameboard[0][i].empty==false)                //ilk s�radaki t�m indexleri kontrol ed�yo eger emptysi false ise i yi artiriyo
			++i;}
          if(i==column){                              //eger column esit olursa beraberlik olmus olur
          	
 		    a=1;}
 	return a;	    
 }
 }


