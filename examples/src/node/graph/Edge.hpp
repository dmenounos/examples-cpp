#ifndef NODE_GRAPH_EDGE_HPP
#define NODE_GRAPH_EDGE_HPP

#include "graph.hpp"

namespace node::graph {

	class Node;

	class Edge : public Object {

	public:

		Edge(weak_ptr<Node> lhs, weak_ptr<Node> rhs, int value);

		~Edge();

		auto getKey() const -> string;

		auto getLhs() const -> weak_ptr<Node>;

		auto getRhs() const -> weak_ptr<Node>;

		auto getOther(weak_ptr<Node> node) const -> weak_ptr<Node>;

		auto getValue() const -> int;

		auto toString() const -> string override;

	private:

		string _key;
		weak_ptr<Node> _lhs;
		weak_ptr<Node> _rhs;
		int _value;
	};

}

#endif // NODE_GRAPH_EDGE_HPP
