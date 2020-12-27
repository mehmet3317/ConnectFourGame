#include <iostream>
#include <fstream>
#include <string>
#include"ConnectFourAbstract.h"
#include"ConnectFourAbstract.cpp"
#include"ConnectFourPlus.h"
#include"ConnectFourPlus.cpp"
#include"ConnectFourDiagonal.h"
#include"ConnectFourDiagonal.cpp"
#include"ConnectFourUndo.cpp"
#include"ConnectFourUndo.h"
#include"Cell.h"
#include"Cell.cpp"

using namespace std;
using namespace mehmet;

main(){
	
	ConnectFourPlus Plus;                             //ConnectFourPlus Sinifinin plus isimli  bi nesnesi ni olusturdum
	                     //ConnectFourDiagonal Sinifinin diagonal isimli bi nesnesi ni olusturdum
	ConnectFourUndo Undo;                         //ConnectFourUndo Sinifinin gameUndo isimli bi nesnesi ni olusturdum
		
	cout<<"Welcome to the Connect4 Game"<<endl<<endl;
	cout<<"Choose the Game Mod:"<<endl<<"Enter P = Plus \nEnter D = Diagonal \nEnter U = Undo";
	char modChoice;
	cin>>modChoice;
	
	do{
		if(modChoice!='P' && modChoice!='D' && modChoice!='U'){ //Hatali input girildiginde hatayi söyleyecek.
			cout<<"please enter P, D or U";
			cin>>modChoice;
		}
	}while(modChoice!='P' && modChoice!='D' && modChoice!='U');	//P, D veya U girene kadar devam edecek.
	
	if(modChoice=='P'){
		Plus.game_play();
	}
	
	else if(modChoice=='D'){
	 ConnectFourDiagonal Diagonal;
	}
	
	else if(modChoice=='U'){
		Undo.game_play();
	}
	
	
	}


	




