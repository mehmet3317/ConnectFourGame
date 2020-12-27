#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
#include"ConnectFourAbstract.h"
#include"Cell.h"
using namespace std;
namespace mehmet
{

void ConnectFourAbstract::displayBoard(){
    
	int a,i,j;
    char harf[]={'A','B','C','D','E','F','G','H','I','j','K','L','M','N','O','P','Q','R','S','T','U','V','W','X'};
     
        	                              
   for(a=0; a<column; a++){
   	cout<<harf[a]<<" ";                         //dizini basina size kadar harfleri sýra ile koyuyor.
   }
   cout<<endl;
	for(i=0; i<row; i++){

		for(j=0; j<column; j++){                      

			if(gameboard[i][j].empty==true){                    //nokta ile doldurmanin kosulu
			gameboard[i][j].signn='.';               //row ve column sayisi kadar . koydurdum
			}                                        
			cout<<gameboard[i][j].signn<<" ";                 //aralara bosluk koydum

		}
		cout<<endl;

}
}
int ConnectFourAbstract::control(char sign){                 //bu fonksiyon bu sinifin d,ger siniflarinda farkli þekilde tanimlanmistir(override.9
}

void ConnectFourAbstract::start_game(){

	    int row=get_row();
		set_row(row);                               //row u aliyorum
		int column=get_column();
        set_column(column);                             //column  u aliyorum
         
        
         gameboard = new Cell*[row];             
	   for (int i = 0; i < row; i++)                     //dinamik memory lulanrak istedigim row v ecolumn saysi kadar yer aciyorum
    	gameboard[i]= new Cell[column];  
    	
    
		displayBoard();                               //row ve column sayisi kadar nokta yazdirdigim fonksiyon

}
	int ConnectFourAbstract::move(){
		int k;
		string komut;
		string file_name;
		string  string_choice;
			do{
			cerr<<"Please Enter the Letter of Column:";
			cin>>string_choice;
				getline(cin,komut);
				string bosluk=" ";
				string my_string(komut);
				komut=my_string.substr(0,my_string.find_first_of(bosluk));
				file_name=my_string.substr(my_string.find_first_of(bosluk)+1);
				
					if(string_choice=="SAVE"){// OYUN kaydi icin kullaniciden string ifade aliyo
					savefile(file_name);          // OYUN kaydi yapiliyo        
					cout<<"file saved\n"; 
					}
					
					else if(string_choice=="LOAD"){
						loadFile(file_name);         //kayitli oyun diziye aktariliyo
						displayBoard();
						cout<<"Loaded game\n";
					}
					else if(string_choice.length()==1){
					char choice=string_choice[0];
					k=choice-'A';
					//k=atoi(string_choice.c_str());
					}
			
			}while(k>column-1|| k<0);//k YI KONTROL ETTÝM K ÝSTEDÝÐÝMÝZ GÝBÝ DEÐÝLSE TEKRAR ÝSTEYECEK
				
		 	if(gameboard[0][k].empty==false){
				cerr<<"This column is full ,enter a new column please:";
				char c;
				cin>>c;//SÜTUN DOLUYSA YENÝ CHOÝCE ALIR
				k=(c-'A');
			}
	 return k;
}
void ConnectFourAbstract::game_play(){   //oyunun oynandigi fomksyon
	
        start_game();                  //row ve column ý set ettigim fonksiyonu cagirdim
       
       	char prefer;                    //oyun modu  p vs p     ||   p vs com
   	  
    cout<<"Enter P for Player TO Player, \nEnter C for Player TO Computer!"<<endl;
	cin>>prefer;
	if(prefer!='P' && prefer!='C') //P veya C girilmediginde tekrar girilmesini isteyecek
			do{
				cerr<<"Enter P for Player TO Player, \nEnter P for Player TO Computer!"<<endl; //
					 cin>>prefer;
				}while(prefer!='P' && prefer!='C'); //P veya C girilene kadar aynýsýný isteyecek
      	if(prefer=='P'){               //eger oyun modu 1 ise player to player oynayacak
	
	    do{                           //do loop ta karsilikli hamleler yapiliyor
	
		   int k=move();
           
		   cout<<"player1 turn"<<endl;        
      	   plays(k,'X');                 //parametre olarak kullaniciden aldigi choice ve player in signature(x) ý kullaigim play fonksiyonu
      	   displayBoard();               //hamleyi aldiktan sonra hamleyi board a yazdirdim
      	   gameEnd('X');                 //oyunun bitip bitmedigini kontrol eden fonksitonu cagirdim
           if(gameEndd==true){             //gameend true olursa  
           upperTOlowerP1('X');              //player1 in hamlesi x leri lowercase yapiyo
		   displayBoard(); 
		   break;                                         //boardi yazdiriyo ve oyun bittyse cikiyo
    }
		
 	
           int k2=move();
	   

        cout<<"player2 turn"<<endl;
		plays(k2,'O');                       //parametre olarak kullaniciden aldigi choice ve player in signature(x) ý kullaigim play fonksiyonu
		displayBoard();                       //hamleyi aldiktan sonra hamleyi board a yazdirdim
        gameEnd('O');                          //oyunun bitip bitmedigini kontrol eden fonksitonu cagirdim
	    if(gameEndd==true){                               //gameend true olursa  
		upperTOlowerP1('O');                                    //player2 in hamlesi x leri lowercase yapiyo
		displayBoard();                                          //boardi yazdiriyo ve oyun bittyse cikiyo
	}
      } while(gameEndd==false);  
}

   	
	  else                                   // eger oyun modu player  vs computer ise
	  {
      do{
        int p=move();
	    cout<<"player1 turn"<<endl;               //ilk olarak kullanici hamle yapiyo
      	plays(p,'X');                             //parametre olarak kullaniciden aldigi choice ve player in signature(x) ý kullaigim play fonksiyonu
      	displayBoard();                          //hamleyi aldiktan sonra hamleyi board a yazdirdim
      	gameEnd('X');                            //oyunun bitip bitmedigini kontrol eden fonksitonu cagirdim
        if(gameEndd==true){                       //gameend true olursa  
        upperTOlowerP1('X');                     //player1 in hamlesi x leri lowercase yapiyo
		displayBoard();                          //boardi yazdiriyo ve oyun bittyse cikiyo
       }
        
      	plays();                                 //parametre almayan computer un hamle yaptigi play fpnksiyonu 
        displayBoard();                          //hamleyi aldiktan sonra hamleyi board a yazdirdim
      	gameEnd('O');                             //oyunun bitip bitmedigini kontrol eden fonksitonu cagirdim
        if(gameEndd==true){                       //gameend true olursa  
        upperTOlowerP1('O');                      //computer in hamlesi x leri lowercase yapiyo
		displayBoard();                           // boardi yazdiriyo ve oyun bittyse cikiyo
       }
		 	
   } while(gameEndd==false);
}
}

  void ConnectFourAbstract::plays(int& choice,char sign){            //parametre olarak kullanicinin secimini ve signaturesini alan play fonksiyonu

	 int turn=0;                                                  //while loop un 1 olam kosulu icin 
	
     
	   int i=row;                                                  //row u i ye atadim
	    do{
		         if(gameboard[0][choice].signn!='.'){             //yapilan secimdeki yerde nokta yoksa yani orasi doluysa 
	             cerr<<"please enter a new column"<<endl;         //yeni bi secim yapamsi icin hata veriyo
	 	         cin>>choice;                                      //ve kullanicide tekrar choice aliyo
	 	        }
	  			else break;                                            //eger bos ise cikiyo
		}while(1);

		   do{

          if( gameboard[row-1][choice].empty==true){               //nokta ise
	 		  gameboard[row-1][choice].signn=sign;                 //kullanicinin signature ini isaretiliyo
			  gameboard[row-1][choice].empty=false;               //ve boolean empty sini true yapiyo
			  turn=1;                                            //1 i turn e atiyo
			}
		else
			--row;                                //eger o index dolu ise satiri 1 azaltip bir daha kontrol ediyo
	}while(turn!=1);                                   //turn 1 olana kadaar yani hamle yapilana kadar döngüde akliyo

		  
row=i;                                      //row sayisi azaldiginden  basta i ye atadigim row degerini row a tekrar atiyorum
}

	void ConnectFourAbstract::plays(){                              //parametre almayan computer hamlsesi
		 int turn=0;
    int choice=rand()%column;                                //column i random atiyo 
		if(choice=='q'){

		        savefile(file_name);
		        cout<<"file saved"<<endl;}
		int i=row;
		do{
          if( gameboard[row-1][choice-1].empty==true){         //nokta ise
	 		  gameboard[row-1][choice-1].signn='O';           //kullanicinin signature ini isaretiliyo
			  gameboard[row-1][choice-1].empty=false;         //ve boolean empty sini true yapiyo

			turn=1;}                                          //1 i turn e atiyo
			else
			row--;                                             //eger o index dolu ise satiri 1 azaltip bir daha kontrol ediyo
	}

    while(turn!=1);                                              //turn 1 olana kadaar yani hamle yapilana kadar döngüde akliyo
    row=i;                                                      //row u 1 eksilttigi icin basta i ye atadigim row degerini row a geri atadým
   }
  
   int ConnectFourAbstract::currentWidth(){                //
   	
   	
   	return column;}
   	
   	 int ConnectFourAbstract::currentHeight(){
   	
   	
   	return row;}
   	void ConnectFourAbstract::savefile(string file_name) {
        
        int cnt=0;
        int count;
        ofstream myfile;
       
    
       myfile.open(file_name.c_str());                       //dosyayý aciyoruz
       myfile<<row<<endl;
       myfile<<column<<endl;

       
       for(int a=0; a<row; a++){                 
	     for(int b=0; b<column; b++){
	    	
	     myfile<<gameboard[a][b].signn<<" ";                           //dosyaya dizideki verileri aktariyorum
	    
	    if(gameboard[a][b].signn=='X' || gameboard[a][b].signn=='O'){
		
	    
	      count++;	}                                     //siranin kimde  oldugunu saptamak için sayac kaydum
		  cnt=1;                                         
	}
	
	 myfile<<endl;
	}
	   
	   if(count%2==1){
	   	myfile<<"ýt is player2 turn"<<endl;        //eger sayacin modunu aldigimde kalan 1 ise sýra player2 dedir.
	   }  
	     else if(count%2==0){
		 
	     
	     myfile<<"ýt is player1 turn"<<endl;}       //eger sayacin modunu aldigimde kalan 0 ise sýra player1 dedir
	      
	     
     
        myfile.close();   
	 
}

void ConnectFourAbstract::loadFile(string file_name){
	     

    	std::ifstream load(file_name.c_str(), std::ifstream::in);   //daha önce olustugumuz save file dosyasýndan verileri aldým
    	
    	for(int a=0; a<row; a++){
		   for(int b=0; b<column; b++){
		 
    	 
		 char veri;
    	 load>>veri;
    	 gameboard[a][b].signn=veri;
    	if(veri=='X'|| veri=='O')
			gameboard[a][b].empty=true;
    }}
        
        cout<<endl;
        load.close();
    	 
    }


void ConnectFourAbstract::set_row(int new_row)
{
    row= new_row;
}

int ConnectFourAbstract::get_row()                                 
{
	int x;
	cout<<"whatis the row size?"<<endl;
    cin>>x;
    return x;
}


void ConnectFourAbstract::set_column(int new_column)
{
     column= new_column;
}

int ConnectFourAbstract::get_column()
{
	int j;
	cout<<"whatis the column size?"<<endl;
    cin>>j;
    return j;
}




void ConnectFourAbstract::gameEnd(char sign){            
	   
}
		
int ConnectFourAbstract::draw(){

     
       int D=0; 
	   int a;
 	 for(int i=0; i<column; ++i ){

 		if(gameboard[0][i].empty==false)                //ilk sýradaki tüm indexleri kontrol edþyo eger emptysi false ise D yi artiriyo
			++D;}
          if(D==column){                              //eger column esit olursa beraberlik olmus olur
          	
 		    a=1;}                                           //beraberlik olursa a ya 1 atiyo
 	return a;	                                            //ve a yi döndürüyo
 }
 		    
 		    
int ConnectFourAbstract::upperTOlowerP1(char sign){              //iki for kullanarak 4 tane X gördüðünde o X leri x e lowercase etmesi için "tolower" ý kullandým.
	
	int cont=0;
	int i,j;
	for(i=row-1; i>=0; i--){
		
		for(j=column-1; j>=0; j--){
	
		if(gameboard[i][j].signn==sign && gameboard[i-1][j].signn==sign && gameboard[i-2][j].signn==sign && gameboard[i-3][j].signn==sign){    
			  
		  	
		  	  gameboard[i][j].signn=tolower(gameboard[i][j].signn),                       //bu if case de dikeyde search yapýyor bunu satýrý 1 artirip sutunu sabit tutarak saðladým
		  	  gameboard[i-1][j].signn=tolower(gameboard[i-1][j].signn),
		  	  gameboard[i-2][j].signn=tolower(gameboard[i-2][j].signn),
		  	  gameboard[i-3][j].signn=tolower(gameboard[i-3][j].signn);
		  	    cont=1;		  	  
				    
}
				 
        else if(gameboard[i][j].signn==sign  && gameboard[i][j-1].signn==sign && gameboard[i][j-2].signn==sign && gameboard[i][j-3].signn==sign){
			  
		  	
		  	  gameboard[i][j].signn=tolower(gameboard[i][j].signn),
		  	  gameboard[i][j-1].signn=tolower(gameboard[i][j-1].signn),              //bu if case de yatayda search yapýyor bunu sütünu sabit tutup satýrý artýrarak saðladým
		  	  gameboard[i][j-2].signn=tolower(gameboard[i][j-2].signn),
		  	  gameboard[i][j-3].signn=tolower(gameboard[i][j-3].signn);
		  	    cont=1;
		  
}
	    else if(gameboard[i][j].signn==sign  && gameboard[i-1][j+1].signn==sign && gameboard[i-2][j+2].signn==sign && gameboard[i-3][j+3].signn==sign){
			  
		  	
		  	  gameboard[i][j].signn=tolower(gameboard[i][j].signn),
		  	  gameboard[i-1][j+1].signn=tolower(gameboard[i-1][j+1].signn),        //bu if case de sað çaprazda search yapýyor bunu satýrý 1 azaltýp , sütunu 1  artýrarak saðladým
		  	  gameboard[i-2][j+2].signn=tolower(gameboard[i-2][j+2].signn),
		  	  gameboard[i-3][j+3].signn=tolower(gameboard[i-3][j+3].signn);
		  	    cont=1;
		
}
				 
	    else if  
 
   	(gameboard[i][j].signn==sign  && gameboard[i-1][j-1].signn==sign && gameboard[i-2][j-2].signn==sign && gameboard[i-3][j-3].signn==sign){
			  
		  	
		  	  gameboard[i][j].signn=tolower(gameboard[i][j].signn),
		  	  gameboard[i-1][j-1].signn=tolower(gameboard[i-1][j-1].signn),
		  	  gameboard[i-2][j-2].signn=tolower(gameboard[i-2][j-2].signn),           //bu if case de sol çaprazda search yapýyor bunu satýrý 1 azaltýp , sütunu da 1  azaltarak saðladým
		  	  gameboard[i-3][j-3].signn=tolower(gameboard[i-3][j-3].signn);
		  	    cont=1;
		  	    		  	  

				  }
				  }
				  }
				  return cont;
				  		  

			
				  }
}
