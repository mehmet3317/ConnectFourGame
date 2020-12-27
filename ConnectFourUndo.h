#ifndef CONNECTFOURUNDO_H
#define CONNECTFOURUNDO_H
#include"ConnectFourAbstract.h"
#include"ConnectFourPlus.h"
#include<vector>
using namespace std;
namespace mehmet{

	class ConnectFourUndo : public ConnectFourPlus{
	protected:
		int move();
		vector<int> array;//YAPILAN HER HAMLE BURAYA KAYDEDILECEK GERI ALIRKEN KULLANILACAK 
		void displayBoard();
		void play_undo();
		void loadFile(string file_name) ;//BU FONSIYON KAYITLI OYUNU DOSYADAN OKUYACAK
		void savefile(string file_name);//BU FONSIYON OYUN U FILE A YAZACAK
	
	
	};
	
}
#endif

