#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <string>

using namespace std;

// INDEX BASED LOOPS

// In both regular and reverse we treat the end as the invalid place.
// That is why the comparison does not include the equal case.

// In the reverse case, even though zero is a valid index of the collection, 
// it is however an invalid value for the index data type!

void index_loop(const string& s) {
	fprintf(stdout, "index_loop: \n");

	for (size_t i = 0; i < s.size(); i++) {
		const char& c = s[i];
		cout << c;
	}

	cout << "\n";
}

void index_loop_reverse(const string& s) {
	fprintf(stdout, "index_loop_reverse: \n");

	for (size_t i = s.size(); i > 0; i--) {
		const char& c = s[i - 1];
		cout << c;
	}

	cout << "\n";
}

// ITERATOR BASED LOOPS

void iterator_loop(const string& s) {
	fprintf(stdout, "iterator_loop: \n");

	for (auto i = begin(s); i != end(s); ++i) {
		cout << *i;
	}

	cout << "\n";
}

void iterator_loop_reverse(const string& s) {
	fprintf(stdout, "iterator_loop_reverse: \n");

	for (auto i = rbegin(s); i != rend(s); ++i) {
		cout << *i;
	}

	cout << "\n";
}

// FOR EACH LOOP

void auto_loop(const string& s) {
	fprintf(stdout, "auto_loop: \n");

	for (const auto& c : s) {
		cout << c;
	}

	cout << "\n";
}

int main(int argc, char* argv[]) {
	string s{"lala"};

	cout << "\n";
	index_loop(s);

	cout << "\n";
	index_loop_reverse(s);

	cout << "\n";
	iterator_loop(s);

	cout << "\n";
	iterator_loop_reverse(s);

	cout << "\n";
	auto_loop(s);

	cout << "\n";
	return EXIT_SUCCESS;
}
