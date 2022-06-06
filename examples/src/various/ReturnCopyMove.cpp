#include <iostream>
#include <string>

using namespace std;

class Object {

	string _s;

public:

	Object(const string& s) : _s(s) {}

	string getImplicitCopy() { return _s; }

	string getExplicitMove() { return move(_s); }

	void print() { cout << "'" << _s << "'" << endl; }
};

int main() {
	Object obj("_0123456789ABCDEF_");

	string s1 = obj.getImplicitCopy();
	obj.print(); // prints '_0123456789ABCDEF_'

	string s2 = obj.getExplicitMove();
	obj.print(); // prints ''
}
