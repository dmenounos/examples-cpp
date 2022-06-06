#ifndef NODE_GRAPH_DIJKSTRA_HPP
#define NODE_GRAPH_DIJKSTRA_HPP

#include "graph.hpp"

namespace node::graph {

	class Dijkstra : public AbstractAlgorithm<Node> {

	public:

		Dijkstra(shared_ptr<Node> root);

		auto next() -> void override;

		auto hasNext() -> bool override;

	protected:

		/**
		 * Finds the node with the minum distance - from the unresolved pool.
		 */
		auto resolveNode() -> void;

		/**
		 * Updates the distances of the neighbors of the resolved node.
		 */
		auto prepareNodes() -> void;

	protected:

		shared_ptr<Node> _resolvedNode;
	};

}

#endif // NODE_GRAPH_DIJKSTRA_HPP
