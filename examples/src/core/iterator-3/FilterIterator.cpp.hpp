#include "utils/log.hpp"

template<typename I>
FilterIterator<I>::FilterIterator(I& curIterator, I& endIterator, std::function<bool(value_type)> predicate) : 
	_curIterator(curIterator), _endIterator(endIterator), _predicate(predicate), 
	_initialized(false), _foundValue(false) {
	LOG_D("FilterIterator<I>::FilterIterator((I& curIterator, I& endIterator, std::function<bool(value_type)> predicate)");
}

template<typename I>
FilterIterator<I>::FilterIterator(I& curIterator, I& endIterator) : 
	_curIterator(curIterator), _endIterator(endIterator) {
	LOG_D("FilterIterator<I>::FilterIterator((I& curIterator, I& endIterator)");
}

template<typename I>
FilterIterator<I>::FilterIterator(const FilterIterator<I>& other) :
	_curIterator(other._curIterator), _endIterator(other._endIterator), _predicate(other._predicate), 
	_initialized(other._initialized), _foundValue(other._foundValue), _value(other._value) {
	LOG_D("FilterIterator<I>::FilterIterator(const FilterIterator<I>& other)");
}

template<typename I>
auto FilterIterator<I>::operator!=(const FilterIterator<I>& other) -> bool {
	LOG_D("FilterIterator<I>::operator!=(const FilterIterator<I>& other)");
	this->advance(_curIterator, other._endIterator, false);
	return _foundValue;
}

template<typename I>
auto FilterIterator<I>::operator*() -> reference {
	LOG_D("FilterIterator<I>::operator*()");
	this->advance(_curIterator, _endIterator, false);
	return _value;
}

template<typename I>
auto FilterIterator<I>::operator->() -> pointer {
	LOG_D("FilterIterator<I>::operator->()");
	this->advance(_curIterator, _endIterator, false);
	return &_value;
}

template<typename I>
auto FilterIterator<I>::operator++() -> FilterIterator<I>& {
	LOG_D("FilterIterator<I>::operator++()");
	this->advance(_curIterator, _endIterator, true);
	return *this;
}

template<typename I>
auto FilterIterator<I>::operator++(int) -> FilterIterator<I> {
	LOG_D("FilterIterator<I>::operator++(int)");
	this->advance(_curIterator, _endIterator, false);
	FilterIterator tmp(*this);
	this->operator++();
	return tmp;	
}

template<typename I>
auto FilterIterator<I>::advance(I& cur, I& end, bool force) -> void {
	LOG_D("FilterIterator<I>::advance(I& cur, I& end, bool force) _initialized:%d force:%d", _initialized, force);

	if (_initialized && !force) {
		return;
	}

	_initialized = true;
	_foundValue = false;

	while (cur != end) {
		value_type v = *cur++;

		if (_predicate(v)) {
			_foundValue = true;
			LOG_T("set _foundValue %d", _foundValue);
			_value = v;
			LOG_T("set _value %d", _value);
			break;
		}
	}
}
