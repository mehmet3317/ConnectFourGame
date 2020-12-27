#include<string>
#include "string.h"
#include <iostream>
#include"Cell.h"
#include"string.h"
#ifndef CONNECTFOURABSTRACT_H
#define CONNECTFOURABSTRACT_H
using namespace std;
namespace mehmet
{
class ConnectFourAbstract{
	
	
  protected: 
	
	string file_name;//kullanicidan alinan komuta g�rebu degisken kaydedilecek ya da okunacak  dosyanin adini tutacak
    int row;
    int column;
    char modChoice;//plus, diyagonal veya undo modunu se�en P, D veya U olan oyun modu
    int prefer;//playertoPlayer veya playertoComputer modunu se�en, P veya C olan oyun modu
    char signn;//s�ra hangi kullan�c�daysa onun imzas�n� Xv veya O �eklinde b�rakan de�er
    void start_game(); //row ve colum � getter ve setter fonksiyonlar� ile alip bu fonksiyonun icinde kllandim
    char choice;		
    Cell ** gameboard;
    void displayBoard();//oyundaki mevcut board i tutan fonksiyon
    void plays();//parametre almayan comuter in hamle yaptigi fonksiyon
    void plays(int &choice,char sign);//paramtre olarak kullanicinin column choice unu ve signaturesini alan fonksiyon 
    virtual void gameEnd(char sign);//paramete olarak kullanicinin signaturesini alan fonks�yon
    bool gameEndd=false;          //oyunun bitip bitmedigini kontrol etmesi icin tanimladim
    virtual int control(char sign);
    int get_row();                            //row ve coloumn private oldugu icin getter ve setter lari kullandim
    void set_row(int new_row);
    int get_column();
    void set_column(int new_column);
    int upperTOlowerP1(char sign);     
    int draw();
    void savefile(string file_name);   //write to file
    void loadFile(string file_name);   //read from file
    int currentWidth();
    int currentHeight();
    virtual int move();
    void play_undo();

public:
	void game_play();//i�erisinde oyunun oynandigi, play fonksiyonlarini barindiran, kullanicidan row ve columnsize'lar alan fonk.
};
}
#endif


