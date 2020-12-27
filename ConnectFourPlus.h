#include"ConnectFourAbstract.h"
#ifndef CONNECTFOURPLUS_H
#define CONNECTFOURPLUS_H
using namespace std;

namespace mehmet
{

class ConnectFourPlus:public ConnectFourAbstract{
	
	public:
    	void displayBoard();
        void gameEnd(char sign);
        int upperTOlowerP1(char sign);     
        int draw();
        int control(char sign);
};
}
#endif



