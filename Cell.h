#include <iostream>
#ifndef CELL_H
#define CELL_H

namespace mehmet
{
	
	
class Cell{
	private:
		int row;
		int column;
	public:
		char signn;
		bool empty=true;	//Cell boþ olup olmadýðý bilgisini tutacak, default olarak true olacak.
		int get_row();	//kullanýcýdan row size'ý alan fonksiyon
		int get_column();	//kullanýcýdan column size'ý alan fonksiyon
		void set_row(int new_row);	
		void set_column(int new_column);	
};
}
#endif


