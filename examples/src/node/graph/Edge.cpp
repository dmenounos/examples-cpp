#include "graph.hpp"

namespace node::graph {

	Edge::Edge(weak_ptr<Node> lhs, weak_ptr<Node> rhs, int value) :
		_lhs(lhs), _rhs(rhs), _value(value) {
		LOG_D("Edge Edge(...) %s", toString().c_str());
		_key = _lhs.lock()->getKey() + "-" + _rhs.lock()->getKey();
	}

	Edge::~Edge() {
		LOG_D("Edge ~Edge() %s", _key.c_str());
	}

	auto Edge::getKey() const -> string {
		return _key;
	}

	auto Edge::getLhs() const -> weak_ptr<Node> {
		return _lhs;
	}

	auto Edge::getRhs() const -> weak_ptr<Node> {
		return _rhs;
	}

	auto Edge::getOther(weak_ptr<Node> node) const -> weak_ptr<Node> {
		if (_lhs.lock() == node.lock()) {
			return _rhs;
		}
		if (_rhs.lock() == node.lock()) {
			return _lhs;
		}
		return {};
	}

	auto Edge::getValue() const -> int {
		return _value;
	}

	auto Edge::toString() const -> std::string {
		ostringstream oss;
		oss << "{ ";
		oss << "_lhs:" << (!_lhs.expired() ? _lhs.lock()->getKey().c_str() : "-") << " , ";
		oss << "_rhs:" << (!_rhs.expired() ? _rhs.lock()->getKey().c_str() : "-") << " , ";
		oss << "_value:" << _value;
		oss << " }";
		return oss.str();
	}

}
