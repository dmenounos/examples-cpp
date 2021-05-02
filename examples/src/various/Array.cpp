#include <iostream>
#include "Array.hpp"

Array::Array(int cols, int rows)
	: _data(new int[cols * rows])
	, _cols(cols)
	, _rows(rows) {
	std::cout << "### Array::Array" << std::endl;
}

Array::~Array() {
	std::cout << "### Array::~Array" << std::endl;

	if (_data != nullptr) {
		delete [] _data;
	}
}

void Array::testSetup() {
	std::cout << ">>> Array::testSetup" << std::endl;

	int v = 0;

	for (int r = 0; r < _rows; r++) {
		for (int c = 0; c < _cols; c++) {
			setItemAt(r, c, v++);
		}
	}
}

void Array::testAccess() {
	std::cout << ">>> Array::testAccess" << std::endl;

	for (int r = 0; r < _rows; ++r) {
		for (int c = 0; c < _cols; ++c) {
			std:: cout << getItemAt(r, c) << " ";
		}

		std::cout << std::endl;
	}
}

// The key point below is how we translate from 2 dimensional coordinates, 
// to the equivalent coordinate for the 1 dimensional continuous array.

// The static number of columns can be thought as a structural grouping factor, 
// whereas row and col as the quotient and remainder for the case at hand.

int Array::getItemAt(int row, int col) {
	int index = row * _cols + col;
	return _data[index];
}

void Array::setItemAt(int row, int col, int val) {
	int index = row * _cols + col;
	_data[index] = val;
}

int main(int argc, char* argv[]) {
	Array array(10, 10);
	array.testSetup();
	array.testAccess();

	return 0;
}
