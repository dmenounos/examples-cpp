#include "graph.hpp"

namespace node::graph {

	Dijkstra::Dijkstra(shared_ptr<Node> root) {
		LOG_D("Dijkstra Dijkstra(...)");
		root->setValue(0);
		_todo.push_back(root);
	}

	auto Dijkstra::next() -> void {
		LOG_D("Dijkstra next()");
		resolveNode();
		prepareNodes();
	}

	auto Dijkstra::hasNext() -> bool {
		LOG_D("Dijkstra hasNext()");
		return !_todo.empty();
	}

	auto Dijkstra::resolveNode() -> void {
		LOG_D("Dijkstra resolveNode()");

		int minDistance = INT_MAX;

		for (shared_ptr<Node>& node : _todo) {
			if (node->getValue() < minDistance) {
				minDistance = node->getValue();
				_resolvedNode = node;
			}
		}

		_todo.remove(_resolvedNode);
		_done.insert(_resolvedNode);
		LOG_T("Dijkstra resolved %s distance %d", _resolvedNode->getKey().c_str(), _resolvedNode->getValue());
	}

	auto Dijkstra::prepareNodes() -> void {
		LOG_D("Dijkstra prepareNodes()");

		for (shared_ptr<Edge>& edge : _resolvedNode->getNeighbors()) {
			shared_ptr<Node> node = edge->getOther(_resolvedNode).lock();

			if (auto it = _done.find(node); it != _done.end()) {
				// node has already been resolved
				continue;
			}

			int newDistance = _resolvedNode->getValue() + edge->getValue();
			int oldDistance = node->getValue();

			if (newDistance < oldDistance) {
				node->setValue(newDistance);
				LOG_T("Dijkstra updated %s distance %d", node->getKey().c_str(), node->getValue());
			}

			_todo.remove(node);
			_todo.push_back(node);
		}
	}

}
