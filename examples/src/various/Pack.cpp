#include <iostream>

using namespace std;

// (2^n)   is the total different values that can be represented with n bits.
// (2^n)-1 is the largest value and has all n bits set to 1.

/**
 * This function packs 2 numbers of supposedly 1 byte (8bit) each to a 32bit int.
 * 
 * Notes, below we use:
 * 1. bit masks, i.e., numbers encoded in the hexadecimal system.
 * 2. bitwise operators to work with the individual bits of int type.
 * 
 * Regarding (1)
 * 
 * How many bits correspond to a hexadecimal digit?
 * A hexadecimal digit allows 16 unique values.
 * 16 = 2^4 = 2^n. Thus 4 bit/hex.
 * 
 * How many hexadecimals correspond to a byte?
 * 8 bit/byte / 4 bit/hex = 2 hex/byte.
 * 
 * Regarding (2)
 * 
 * Bitwise operations can be less cryptic if we break them into discreet steps.
 */
int pack(int a, int b) {

	// In general, a and b are supposed to be 8bit values. 
	// Because however we use a 32bit type we want to make sure 
	// that we keep the rightmost 8 bits of the value of each parameter.
	// For this we use the bitwise AND operation with a mask full of 8 ones.
	
	// Assign the value of the rightmost 8 bits of a.
	int v = a & 0xFF;

	// Move the value to the left by 8 bits.
	// The space to the right is filled with zeros.
	// Combine the value with the rightmost 8 bits of b.
	v = (v << 8) | (b & 0xFF);

	return v;
}

void unpack(int v, int& a, int& b) {
	b = v & 0xFF;
	a = (v >> 8) & 0xFF;
}

void printBinary(int n) {
	for (int i = 31; i >= 0; --i) {
		int bit = ((n >> i) & 0x1);
		cout << bit;
	}

	cout << endl;
}

void test(int a, int b) {
	cout << ">>> test" << endl;

	int p = pack(a, b);

	unpack(p, a, b);

	cout << "a=" << a << " b=" << b << endl;

	cout << "Packed word: ";
	printBinary(p);

	cout << "Un-packed a: ";
	printBinary(a);

	cout << "Un-packed b: ";
	printBinary(b);
}

int main(int argc, char* argv[]) {

	cout << endl;

	test(1, 1);

	cout << endl;

	test(127, 127); // (2^7)-1 or 7 bits set to 1

	cout << endl;

	test(255, 255); // (2^8)-1 or 8 bits set to 1

	cout << endl;

	return 0;
}
