#include"ConnectFourAbstract.h"
#ifndef CONNECTFOURDIAGONAL_H
#define CONNECTFOURDIAGONAL_H
using namespace std;

namespace mehmet
{

class ConnectFourDiagonal:public ConnectFourAbstract{
	
	public:
        void displayBoard();
        void gameEnd(char sign);
        int upperTOlowerP1(char sign);     
        int draw();
        int control(char sign);
	    ConnectFourDiagonal();
};
}
#endif



