#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
#include"ConnectFourUndo.h"
#include"Cell.h"


namespace mehmet{

	void ConnectFourUndo::displayBoard(){
    
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
	int ConnectFourUndo::move(){
		int a=-1;
		int game;
		string order;
		string file_name;
		string  string_prefer;
			do{
			cout<<"Please Enter THE Column:";
			cin>>string_prefer;
				getline(cin,order);
				string gap=" ";
				string my_string(order);
				order=my_string.substr(0,my_string.find_first_of(gap));
				file_name=my_string.substr(my_string.find_first_of(gap)+1);
				
					if(string_prefer=="SAVE"){//s GIRILIRSE OYUN KAYDEDILECEK
					savefile(file_name);//OYUN KAYDEDILIYO...
					cout<<"file saved\n"; 
					game=0;                 //BURADA UNDO OLMADIGI ANLAMINA GELIYOR DOLAYISIYLA HAMLE TEKRAR AYNI KULLANICIDAN ISTENECEK
					}
					
					else if(string_prefer=="LOAD"){
						loadFile(file_name);//KAYITLI OYUN DIZIYE ATANACAK
						displayBoard();
						cout<<"Loaded game\n";
						game=0;
					}
					else if(string_prefer=="UNDO"){
						play_undo();//GERI ALMA HAMLESI
						cout<<"HAMLE GERI ALINDI\n";
						displayBoard();
						game=1;
						a=0;
					}
					else if(string_prefer.length()==1){
					char choice=string_prefer[0];
					a=choice-'A';
					game=0;
					if(gameboard[0][a].empty==false){
						cerr<<"This column is full, choose an other column.";
						a=-1;
					}
					else if(a>column){
						cerr<<"There is no column that!";
						a=-1;	
					}
 					}
			
			}while(a>column-1|| a<0);             //k YI KONTROL ETTÝM K ÝSTEDÝÐÝMÝZ GÝBÝ DEÐÝLSE TEKRAR ÝSTEYECEK
			if(game!=-1){	//eger undo -1 degilse ch'yi return et
				array.push_back(a);
				return a;
			}
			else return game;	//undo -1 ise undoyu return et. bunu C.F.abstract'te play fonksiyonunda kullanýyoruz
}
		

void ConnectFourUndo::savefile(string file_name) {
        
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

void ConnectFourUndo::loadFile(string file_name){
	         

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

	void ConnectFourUndo::play_undo(){
		int undo=array[array.size()-1];
		int i=0;	
		bool ctrl=false;
		 	do
			{
				if ( gameboard[i][undo].empty==false)//BU NOKTANIN BOÞ OLUP OLMADIÐI KONTRL EDLÝR
				{
					 gameboard[i][undo].signn ='.';//HMALEYÝ YAPAN PLAYER IN HARFÝ ATANIR BU NOKTAYA
					 gameboard[i][undo].empty=true;
					 ctrl=true;//HAMLE YAPILIRSA CONTROL TRUE OLUR VE BU DÖNGÜYE TEKRAR GÝRMEZ
			}
					i++;       //HAMLE YAPILMADIYSA BÝR ÜST SATIR A GEÇER //BURADA BU NESNEYE AIT ROW AZALDIGI ICIN ASAGIDA YDEKELDIGIMIZ DEGERI GERI ALDIK
		        	}while (ctrl!=true);// BU DÖNGÜ HERHNAGÝ BÝR YERE HAMLE YAPILANA KADAR DEVAM EDER*/
		            array.pop_back();	
		}

   }

