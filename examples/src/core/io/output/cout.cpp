#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	string str = "A string ..";
	int integer = 12345;
	double real = 1.2345;

	cout << "String  : " << str << "\n";
	cout << "Integer : " << integer << "\n";
	cout << "Real    : " << real << "\n";
	cout << "Real with 2 digits : " << fixed << setprecision(2) << real << "\n";

	return 0;
}
