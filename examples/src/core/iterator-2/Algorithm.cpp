#include "Algorithm.hpp"
#include "AlgorithmIterator.hpp"

using namespace std;

Algorithm::Algorithm(int init, int size) :
	_curr(init), _size(size) {
}

bool Algorithm::hasNext() {
	return _curr < _size;
}

int Algorithm::next() {
	return _curr++;
}

AlgorithmIterator Algorithm::begin() {
	return AlgorithmIterator(*this);
}

AlgorithmIterator Algorithm::end() {
	return AlgorithmIterator(*this);
}

unique_ptr<AlgorithmIterator> Algorithm::beginPtr() {
	return make_unique<AlgorithmIterator>(*this);
}

unique_ptr<AlgorithmIterator> Algorithm::endPtr() {
	return make_unique<AlgorithmIterator>(*this);
}
