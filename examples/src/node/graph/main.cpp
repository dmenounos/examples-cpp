#include "graph.hpp"

using namespace node;
using namespace node::graph;

int main() {
	log_set_level(LOG_LEVEL_AUDIT);
	log_set_level(LOG_LEVEL_TRACE);

	vector<shared_ptr<Node>> nodes {
		make_shared<Node>("00"),
		make_shared<Node>("01"),
		make_shared<Node>("02"),
		make_shared<Node>("03"),
		make_shared<Node>("04"),
		make_shared<Node>("05"),
		make_shared<Node>("06"),
		make_shared<Node>("07"),
		make_shared<Node>("08")
	};

	shared_ptr<Edge> e01 = make_shared<Edge>(nodes[0], nodes[1], 4);
	shared_ptr<Edge> e07 = make_shared<Edge>(nodes[0], nodes[7], 8);
	shared_ptr<Edge> e12 = make_shared<Edge>(nodes[1], nodes[2], 8);
	shared_ptr<Edge> e17 = make_shared<Edge>(nodes[1], nodes[7], 11);
	shared_ptr<Edge> e23 = make_shared<Edge>(nodes[2], nodes[3], 7);
	shared_ptr<Edge> e25 = make_shared<Edge>(nodes[2], nodes[5], 4);
	shared_ptr<Edge> e28 = make_shared<Edge>(nodes[2], nodes[8], 2);
	shared_ptr<Edge> e34 = make_shared<Edge>(nodes[3], nodes[4], 9);
	shared_ptr<Edge> e35 = make_shared<Edge>(nodes[3], nodes[5], 14);
	shared_ptr<Edge> e45 = make_shared<Edge>(nodes[4], nodes[5], 10);
	shared_ptr<Edge> e56 = make_shared<Edge>(nodes[5], nodes[6], 2);
	shared_ptr<Edge> e67 = make_shared<Edge>(nodes[6], nodes[7], 1);
	shared_ptr<Edge> e68 = make_shared<Edge>(nodes[6], nodes[8], 6);
	shared_ptr<Edge> e78 = make_shared<Edge>(nodes[7], nodes[8], 7);

	nodes[0]->getNeighbors().push_back(e01); // fw
	nodes[0]->getNeighbors().push_back(e07); // fw

	nodes[1]->getNeighbors().push_back(e01); // bw
	nodes[1]->getNeighbors().push_back(e12); // fw
	nodes[1]->getNeighbors().push_back(e17); // fw

	nodes[2]->getNeighbors().push_back(e12); // bw
	nodes[2]->getNeighbors().push_back(e23); // fw
	nodes[2]->getNeighbors().push_back(e25); // fw
	nodes[2]->getNeighbors().push_back(e28); // fw

	nodes[3]->getNeighbors().push_back(e23); // bw
	nodes[3]->getNeighbors().push_back(e34); // fw
	nodes[3]->getNeighbors().push_back(e35); // fw

	nodes[4]->getNeighbors().push_back(e34); // bw
	nodes[4]->getNeighbors().push_back(e45); // fw

	nodes[5]->getNeighbors().push_back(e25); // bw
	nodes[5]->getNeighbors().push_back(e35); // bw
	nodes[5]->getNeighbors().push_back(e45); // bw
	nodes[5]->getNeighbors().push_back(e56); // fw

	nodes[6]->getNeighbors().push_back(e56); // bw
	nodes[6]->getNeighbors().push_back(e67); // fw
	nodes[6]->getNeighbors().push_back(e68); // fw

	nodes[7]->getNeighbors().push_back(e07); // bw
	nodes[7]->getNeighbors().push_back(e17); // bw
	nodes[7]->getNeighbors().push_back(e67); // bw
	nodes[7]->getNeighbors().push_back(e78); // fw

	nodes[8]->getNeighbors().push_back(e28); // bw
	nodes[8]->getNeighbors().push_back(e68); // bw
	nodes[8]->getNeighbors().push_back(e78); // bw

	Dijkstra algorithm{nodes[0]};
	while (algorithm.hasNext()) {
		algorithm.next();
	}
}
