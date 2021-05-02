#ifndef ABSTRACT_ALGORITHM_HPP
#define ABSTRACT_ALGORITHM_HPP

#include "node.hpp"

namespace node {

	template<typename N>
	class AbstractAlgorithm : public Object {

	public:

		virtual auto next() -> void;

		virtual auto hasNext() -> bool;

	protected:

		list<shared_ptr<N>> _todo;
		unordered_set<shared_ptr<N>> _done;
	};

	template<typename N>
	auto AbstractAlgorithm<N>::next() -> void {
	}

	template<typename N>
	auto AbstractAlgorithm<N>::hasNext() -> bool {
		return false;
	}

}

#endif // ABSTRACT_ALGORITHM_HPP
