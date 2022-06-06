#ifndef NODE_GRAPH_NODE_HPP
#define NODE_GRAPH_NODE_HPP

#include "graph.hpp"

namespace node::graph {

	class Edge;

	class Node : public AbstractNode<Edge> {

	public:

		Node(string name);

		~Node();

		auto getKey() const -> string;

		auto getValue() const -> int;
		auto setValue(int value) -> void;

		auto toString() const -> string override;

	private:

		string _key;
		int _value;
	};

}

#endif // NODE_GRAPH_NODE_HPP
