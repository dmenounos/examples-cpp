#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
struct Reverse {

private:

	T& _iterable;

public:

	explicit Reverse(T& iterable) 
		: _iterable(iterable) {
	}

	auto begin() const {
		return rbegin(_iterable);
	}

	auto end() const {
		return rend(_iterable);
	}
};

template <typename T>
Reverse<T> make_reverse(T& i) {
	fprintf(stdout, "make_reverse: \n");

	return Reverse<T>(i);
}

template <typename T>
void foreach_loop(const T& v) {
	fprintf(stdout, "foreach_loop: \n");

	for (const auto& c : v) {
		cout << c;
	}

	cout << "\n";
}

int main (int argc, char* argv[]) {

	// Test with vector

	vector<char> v{'l', 'a', 'l', 'a'};

	cout << "\n";
	cout << "iteration with vector\n";
	foreach_loop(v);

	cout << "\n";
	cout << "reverse iteration with vector\n";
	foreach_loop(make_reverse(v));

	// Test with string

	string s{"kaka"};

	cout << "\n";
	cout << "iteration with string\n";
	foreach_loop(s);

	cout << "\n";
	cout << "reverse iteration with string\n";
	foreach_loop(make_reverse(s));

	cout << "\n";
	return EXIT_SUCCESS;
}
