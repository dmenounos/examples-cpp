#ifndef PASSRETURN_HPP
#define PASSRETURN_HPP

struct Object {

	Object();
	Object(const Object& ref);
	Object& operator=(const Object& ref);
	~Object();
};

struct PassByValue {

	PassByValue(Object val);
	void doSomething();
	Object _object;
};

struct PassByReference_Inlist {

	PassByReference_Inlist(const Object& ref);
	void doSomething();
	Object _object;
};

struct PassByReference_Assign {

	PassByReference_Assign(const Object& ref);
	void doSomething();
	Object _object;
};

Object returnByValue();

#endif /* PASSRETURN_HPP */
