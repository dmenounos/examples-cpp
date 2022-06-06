#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array {

public:

	Array(int cols, int rows);

	~Array();

	void testSetup();

	void testAccess();

private:

	int getItemAt(int row, int col);

	void setItemAt(int row, int col, int val);

private:

	int* _data;
	int _cols;
	int _rows;
};

#endif
