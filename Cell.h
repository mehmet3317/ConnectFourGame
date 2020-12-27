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
		bool empty=true;	//Cell bo� olup olmad��� bilgisini tutacak, default olarak true olacak.
		int get_row();	//kullan�c�dan row size'� alan fonksiyon
		int get_column();	//kullan�c�dan column size'� alan fonksiyon
		void set_row(int new_row);	
		void set_column(int new_column);	
};
}
#endif


