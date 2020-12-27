#include <iostream>
using namespace std;
#include"ConnectFourPlus.h"
#include"Cell.h"
using namespace std;

namespace mehmet
{
	int ConnectFourPlus::control(char sign){								
	
		int i,j;
		int win=0;
		
				for(i=row-1; i>=0; i--){					     //sadece yatay ve dikay kontrol yapan kontrol fonksiyonu				
					for(j=column-1; j>=0; j--){

			
				    if(gameboard[i][j].signn==sign && gameboard[i-1][j].signn==sign && gameboard[i-2][j].signn==sign && gameboard[i-3][j].signn==sign){
		            win=1;                 //sutunu sabit tutup satiri 1 er azaltarak dikey kontrol yapar
			        }

			        if(gameboard[i][j].signn==sign && gameboard[i][j-1].signn==sign && gameboard[i][j-2].signn==sign && gameboard[i][j-3].signn==sign){
	      	        win=1;            
	      	}                          //satýrý sabit tutup sutunu 1 er artirarak yatay kontrol yapar
		}	
	
	}
	
	return win;
}
void ConnectFourPlus::displayBoard(){
    
	int a,i,j;
    char harf[]={'A','B','C','D','E','F','G','H','I','j','K','L','M','N','O','P','Q','R','S','T','U','V','W','X'};
     

    
        	
   for(a=0; a<column; a++){
   	cout<<harf[a]<<" ";                         //dizini basina size kadar harfleri sýra ile koyuyor.
   }
   cout<<endl;
	for(i=0; i<row; i++){

		for(j=0; j<column; j++){

			if(gameboard[i][j].empty==true){                                  //nokta ile doldurmanin kosulu
			gameboard[i][j].signn='.';
			}                                        
			cout<<gameboard[i][j].signn<<" ";

		}
		cout<<endl;

}
}
void ConnectFourPlus::gameEnd(char sign){            
	    int i=draw();                                            //draw fonksiyonun döndürdüðü degeri a ya atadim
	   if(i==1){
	   	cout<<"berabereP"<<endl;
	   	gameEndd=true;
	   }
	  
		 int win=control(sign);                                    //win döndüren kontrol fonksiyonu yine win e atadim
		 if(win==1){
		
		 gameEndd=true;
	     int prefer;
	     if(prefer==1){                                            //prefer oyun modunu temsil ediyo player to player
		
		 if(sign=='X'){
		 cout<<"player1 won"<<endl;                                  //OYUN modu 1 ise player to player ise ve signature x ise player1 won
		 }
         else 
         cout<<"player2 won"<<endl;                                //OYUN modu 1 ise player to player ise ve signature o ise player2 won
         }
         else{                                                     //player vs com ise
	     if(sign=='X'){
	  
	     cout<<"player1 won"<<endl;                                //OYUN modu 0 ise player to computer ise ve signature x ise player1 won
         } 
         else
       
       	 cout<<"you loseEE"<<endl;                                  //OYUN modu 0 ise player to computer ise ve signature o ise computer won
    
}
}
}
int ConnectFourPlus::draw(){

       int P=0;
	   int prefer;
	   int cont=0;
	   int a;
 	 for(int i=0; i<column; ++i ){

 		if(gameboard[0][i].empty==false)                //ilk sýradaki tüm indexleri kontrol edþyo eger emptysi false ise D yi artiriyo
			++P;}
          if(P==column){                              //eger column esit olursa beraberlik olmus olur
          	
 		    a=1;}
 	return a;	    
 }
}


