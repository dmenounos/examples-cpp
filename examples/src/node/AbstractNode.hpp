#ifndef ABSTRACT_NODE_HPP
#define ABSTRACT_NODE_HPP

#include "node.hpp"

namespace node {

	template<typename N>
	class AbstractNode : public Object {

	public:

		auto getNeighbors() -> vector<shared_ptr<N>>&;

	protected:

		vector<shared_ptr<N>> _neighbors;
	};

	template<typename N>
	auto AbstractNode<N>::getNeighbors() -> vector<shared_ptr<N>>& {
		return _neighbors;
	}

}

#endif // ABSTRACT_NODE_HPP
