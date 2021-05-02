#include "Algorithm.hpp"
#include "AlgorithmIterator.hpp"
#include <utils/log.hpp>

using namespace std;

void testAlgorithm() {
	LOG_D("testAlgorithm");

	Algorithm a(0, 3);

	while (a.hasNext()) {
		int v = a.next();
		LOG_A("%d", v);
	}
}

void testAlgorithmIterator_Implicit() {
	LOG_D("testAlgorithmIterator_Implicit");

	Algorithm a(0, 3);

	for (auto v : a) {
		LOG_A("%d", v);
	}
}

void testAlgorithmIterator_Explicit_PreIncrement() {
	LOG_D("testAlgorithmIterator_Explicit_PreIncrement");

	Algorithm a(0, 3);

	for (auto i = a.begin(), e = a.end(); i != e; ++i) {
		int v = *i;
		LOG_A("%d", v);
	}
}

void testAlgorithmIterator_Explicit_PostIncrement() {
	LOG_D("testAlgorithmIterator_Explicit_PostIncrement");

	Algorithm a(0, 3);

	for (auto i = a.begin(), e = a.end(); i != e; i++) {
		int v = *i;
		LOG_A("%d", v);
	}
}

void testAlgorithmIterator_Explicit_Ptr() {
	LOG_D("testAlgorithmIterator_Explicit_Ptr");

	Algorithm a(0, 3);

	for (auto i = a.beginPtr(), e = a.endPtr(); *i != *e; ++(*i)) {
		int v = *(*i);
		LOG_A("%d", v);
	}
}

void testAlgorithmIterator_PostIncrement() {
	LOG_D("testAlgorithmIterator_PostIncrement");

	Algorithm a(0, 3);
	AlgorithmIterator i = a.begin();

	i++;

	int i_curr = *i;
	LOG_A("i++; *i: %d", i_curr);
}

int main() {
	log_set_level(LOG_LEVEL_AUDIT);
//	log_set_level(LOG_LEVEL_DEBUG);
//	log_set_level(LOG_LEVEL_TRACE);

	LOG_M(" ");

	testAlgorithm();

	LOG_M(" ");

	testAlgorithmIterator_Implicit();

	LOG_M(" ");

	testAlgorithmIterator_Explicit_PreIncrement();

	LOG_M(" ");

	testAlgorithmIterator_Explicit_PostIncrement();

	LOG_M(" ");

	testAlgorithmIterator_Explicit_Ptr();

	LOG_M(" ");

	testAlgorithmIterator_PostIncrement();

	LOG_M(" ");
}
