#ifndef FILTER_ITERATOR_HPP
#define FILTER_ITERATOR_HPP

#include <functional>

/**
 * An example of a lazy iterator that wraps another (pair) iterator.
 * The steps of this and the wrapped iterator map 1-*.
 */
template<typename I>
class FilterIterator {

public:

	// Standard interface for iterator
	using iterator_category = typename I::iterator_category;
	using difference_type   = typename I::difference_type;
	using value_type        = typename I::value_type;
	using reference         = typename I::reference;
	using pointer           = typename I::pointer;

	/** Begin constructor */
	FilterIterator(I& curIterator, I& endIterator, std::function<bool(value_type)> predicate);
	/** End constructor */
	FilterIterator(I& curIterator, I& endIterator);
	/** Copy constructor */
	FilterIterator(const FilterIterator<I>& other);

	// Are we still in progress?
	auto operator!=(const FilterIterator<I>& other) -> bool;

	// Access of current element
	auto operator*() -> reference;
	auto operator->() -> pointer;

	// Advance to next element
	auto operator++() -> FilterIterator<I>&;
	auto operator++(int) -> FilterIterator<I>;

protected:

	auto advance(I& cur, I& end, bool force) -> void;

private:

	I& _curIterator;
	I& _endIterator;
	std::function<bool(value_type)> _predicate;
	bool _initialized;
	bool _foundValue;
	value_type _value;
};

#include "FilterIterator.cpp.hpp"

#endif // FILTER_ITERATOR_HPP
