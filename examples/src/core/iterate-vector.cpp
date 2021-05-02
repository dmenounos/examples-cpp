#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

// INDEX BASED LOOPS

// In both regular and reverse we treat the end as the invalid place.
// That is why the comparison does not include the equal case.

// In the reverse case, even though zero is a valid index of the collection, 
// it is however an invalid value for the index data type!

void index_loop(const vector<char>& v) {
	fprintf(stdout, "index_loop: \n");

	for (size_t i = 0; i < v.size(); i++) {
		const char& c = v[i];
		cout << c;
	}

	cout << "\n";
}

void index_loop_reverse(const vector<char>& v) {
	fprintf(stdout, "index_loop_reverse: \n");

	for (size_t i = v.size(); i > 0; i--) {
		const char& c = v[i - 1];
		cout << c;
	}

	cout << "\n";
}

// ITERATOR BASED LOOPS

void iterator_loop(const vector<char>& v) {
	fprintf(stdout, "iterator_loop: \n");

	for (auto i = begin(v); i != end(v); ++i) {
		cout << *i;
	}

	cout << "\n";
}

void iterator_loop_reverse(const vector<char>& v) {
	fprintf(stdout, "iterator_loop_reverse: \n");

	for (auto i = rbegin(v); i != rend(v); ++i) {
		cout << *i;
	}

	cout << "\n";
}

// FOR EACH LOOP

void auto_loop(const vector<char>& v) {
	fprintf(stdout, "auto_loop: \n");

	for (const auto& c : v) {
		cout << c;
	}

	cout << "\n";
}

int main(int argc, char* argv[]) {
	vector<char> v{'l', 'a', 'l', 'a'};

	cout << "\n";
	index_loop(v);

	cout << "\n";
	index_loop_reverse(v);

	cout << "\n";
	iterator_loop(v);

	cout << "\n";
	iterator_loop_reverse(v);

	cout << "\n";
	auto_loop(v);

	cout << "\n";
	return EXIT_SUCCESS;
}
