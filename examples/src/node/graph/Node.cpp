#include "graph.hpp"

namespace node::graph {

	Node::Node(string name) :
		_key(name), _value(INT_MAX) {
		LOG_D("Node Node(...) %s", toString().c_str());
	}

	Node::~Node() {
		LOG_D("Node ~Node() %s", _key.c_str());
	}

	auto Node::getKey() const -> string {
		return _key;
	}

	auto Node::getValue() const -> int {
		return _value;
	}

	auto Node::setValue(int value) -> void {
		_value = value;
	}

	auto Node::toString() const -> std::string {
		ostringstream oss;
		oss << "{ ";
		oss << "_key:" << _key;
		oss << " }";
		return oss.str();
	}

}
