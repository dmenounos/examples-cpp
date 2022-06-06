#include "../iterator-1/Algorithm.hpp"
#include "../iterator-1/AlgorithmIterator.hpp"
#include "./FilterIterator.hpp"
#include <utils/log.hpp>

using namespace std;

void testFilterIterator_Even() {
	LOG_D("testFilterIterator_Even");

	Algorithm a(0, 3);
	AlgorithmIterator i = a.begin(), e = a.end(); 

	FilterIterator fi(i, e, [](int i) { return i % 2 == 0; });
	FilterIterator fe(i, e);

	while (fi != fe) {
		int v = *fi;
		LOG_A("%d", v);
		++fi;
	}
}

void testFilterIterator_Odd_Bounded() {
	LOG_D("testFilterIterator_Odd_Bounded");

	Algorithm a(0, 10);
	AlgorithmIterator i = a.begin(), e = a.end();

	FilterIterator fi(i, e, [](int i) { return i % 2 != 0; });
	FilterIterator fe(i, e);

	FilterIterator ffi(fi, fe, [](int i) { return i < 5; });
	FilterIterator ffe(fi, fe);

	while (ffi != ffe) {
		int v = *ffi;
		LOG_A("%d", v);
		++ffi;
	}
}

void testFilterIterator_PostIncrement() {
	LOG_D("testFilterIterator_PostIncrement");

	Algorithm a(0, 3);
	AlgorithmIterator i = a.begin(), e = a.end();

	FilterIterator fi(i, e, [](int i) { return i % 2 == 0; });

	int fi_post = *fi++;
	LOG_A("*fi++: %d", fi_post);

	int fi_curr = *fi;
	LOG_A("*fi: %d", fi_curr);
}

int main() {
	log_set_level(LOG_LEVEL_AUDIT);
//	log_set_level(LOG_LEVEL_TRACE);

	LOG_M(" ");

	testFilterIterator_Even();

	LOG_M(" ");

	testFilterIterator_Odd_Bounded();

	LOG_M(" ");

	testFilterIterator_PostIncrement();
	
	LOG_M(" ");
}
