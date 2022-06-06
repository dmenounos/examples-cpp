#include <iostream>
#include "PassReturn.hpp"

using namespace std;

// Object

Object::Object() {
	cout << "Object constructor { this: " << this << " }" << endl;
}

Object::Object(const Object& ref) {
	cout << "Object copy constructor { this: " << this << ", ref: " << &ref << " }" << endl;
}

Object& Object::operator=(const Object& ref) {
	cout << "Object assignment operator { this: " << this << ", ref: " << &ref << " }" << endl;
	return *this;
}

Object::~Object() {
	cout << "Object destructor { this: " << this << " }" << endl;
}

// PassByValue

PassByValue::PassByValue(Object val) :
	_object(val) {
	cout << "PassByValue constructor " << endl;
}

void PassByValue::doSomething() {
}

// PassByReference_Inlist

PassByReference_Inlist::PassByReference_Inlist(const Object& ref) :
	_object(ref) {
	cout << "PassByReference_Inlist constructor " << endl;
}

void PassByReference_Inlist::doSomething() {
}

// PassByReference_Assign

PassByReference_Assign::PassByReference_Assign(const Object& ref) {
	_object = ref;
	cout << "PassByReference_Assign constructor " << endl;
}

void PassByReference_Assign::doSomething() {
}

Object returnByValue() {
	return Object();
}

int main(int argc, char* argv[]) {

	cout << endl;

	cout << ">>> Pass By Value" << endl;
	PassByValue(Object()).doSomething();
	cout << endl;

	cout << ">>> Pass By Reference (inlist)" << endl;
	PassByReference_Inlist(Object()).doSomething();
	cout << endl;

	cout << ">>> Pass By Reference (assign)" << endl;
	PassByReference_Assign(Object()).doSomething();
	cout << endl;

	cout << ">>> Return By Value" << endl;
	Object object = returnByValue(); // optimization - no copy constructor
	cout << endl;

	return 0;
}
