#include "AlgorithmIterator.hpp"
#include "Algorithm.hpp"
#include "utils/log.hpp"

using namespace std;

AlgorithmIterator::AlgorithmIterator(Algorithm& algorithm) : 
	_algorithm(algorithm), _initialized(false) {
	LOG_D("AlgorithmIterator::AlgorithmIterator(Algorithm& algorithm)");
}

AlgorithmIterator::AlgorithmIterator(const AlgorithmIterator& other) :
	_algorithm(other._algorithm), 
	_initialized(other._initialized), _hasNext(other._hasNext), _next(other._next) {
	LOG_D("AlgorithmIterator::AlgorithmIterator(const AlgorithmIterator& other)");
}

// Are we still in progress?
auto AlgorithmIterator::operator!=(const AlgorithmIterator& other) -> bool {
	LOG_D("AlgorithmIterator::operator!=(const AlgorithmIterator& other)");
	this->advance(false);
	return _hasNext;
}

// Access of current element as a reference
auto AlgorithmIterator::operator*() -> reference {
	LOG_D("AlgorithmIterator::operator*()");
	this->advance(false);
	return _next;
}

// Access of current element as a pointer
auto AlgorithmIterator::operator->() -> pointer {
	LOG_D("AlgorithmIterator::operator->()");
	this->advance(false);
	return &_next;
}

// Advance to next element through pre increment
auto AlgorithmIterator::operator++() -> AlgorithmIterator& {
	LOG_D("AlgorithmIterator::operator++()");
	this->advance(true);
	return *this;
}

// Advance to next element through post increment
auto AlgorithmIterator::operator++(int) -> AlgorithmIterator {
	LOG_D("AlgorithmIterator::operator++(int)");
	this->advance(false);
	AlgorithmIterator tmp(*this);
	this->operator++();
	return tmp;	
}

auto AlgorithmIterator::advance(bool force) -> void {
	LOG_D("AlgorithmIterator::advance(bool force) _initialized:%d force:%d", _initialized, force);

	if (_initialized && !force) {
		return;
	}

	_initialized = true;

	_hasNext = _algorithm.hasNext();
	LOG_T("set _hasNext %d", _hasNext);

	if (_hasNext) {
		_next = _algorithm.next();
		LOG_T("set _next %d", _next);
	}
}
