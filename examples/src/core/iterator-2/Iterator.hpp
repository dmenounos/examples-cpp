#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template<typename T>
class Iterator {

public:

	virtual ~Iterator() {}

	// Are we still in progress?
	virtual auto operator!=(const Iterator<T>& other) -> bool = 0;

	// Access of current element
	virtual auto operator*() -> T& = 0;
	virtual auto operator->() -> T* = 0;

	// Advance to next element
	virtual auto operator++() -> Iterator<T>& = 0;
	virtual auto operator++(int) -> void = 0;
};

#endif // ITERATOR_HPP
