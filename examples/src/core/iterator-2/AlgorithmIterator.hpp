#ifndef ALGORITHM_ITERATOR_HPP
#define ALGORITHM_ITERATOR_HPP

#include <iterator>
#include "Iterator.hpp"

class Algorithm;

/**
 * An example of a virtual iterator that drives a sequential algorithm.
 * The steps of the iterator and the algorithm map 1-1.
 */
class AlgorithmIterator : public Iterator<int> {

public:

	// Standard interface for iterator
	using iterator_category = std::forward_iterator_tag;
	using difference_type   = ptrdiff_t;
	using value_type        = int;
	using reference         = int&;
	using pointer           = int*;

	/** Begin / End constructor */
	AlgorithmIterator(Algorithm& algorithm);

	/** Copy constructor */
	AlgorithmIterator(const AlgorithmIterator& other);

	// Are we still in progress?
	auto operator!=(const Iterator<value_type>& other) -> bool override;

	// Access of current element as a reference
	auto operator*() -> reference override;

	// Access of current element as a pointer
	auto operator->() -> pointer override;

	// Advance to next element through pre increment
	auto operator++() -> Iterator<value_type>& override;

	// Advance to next element through post increment
	auto operator++(int) -> void override;

protected:

	auto advance(bool force) -> void;

private:

	Algorithm& _algorithm;
	bool _initialized;
	bool _hasNext;
	value_type _next;
};

#endif // ALGORITHM_ITERATOR_HPP
