#include <iostream>
#include <vector>
#include <limits>

using namespace std;

static int INT_MAX = numeric_limits<int>::max();

void djkstra(vector<vector<int>> graph, int distance[], bool resolved[], size_t size) {

	int resolved_count = 0;

	// run until all nodes have been resolved
	while (resolved_count < size) {

		// find the unresolved node with the minum distance
		int min_distance = INT_MAX;
		size_t i = 0;

		for (size_t j = 0; j < size; j++) {

			if (resolved[j]) {
				continue;
			}

			if (distance[j] < min_distance) {
				min_distance = distance[j];
				i = j;
			}
		}

		resolved[i] = true;
		resolved_count += 1;
		cout << "resolved " << i << " distance " << min_distance << "\n";

		// calculate the distances of the neighbors of the current node [i]
		for (size_t j = 0; j < size; j++) {

			if (graph[i][j] == 0) {
				continue;
			}

			int new_dist = distance[i] + graph[i][j];
			int old_dist = distance[j];

			if (new_dist < old_dist) {
				cout << "updated " << j << " distance " << new_dist << "\n";
				distance[j] = new_dist;
			}
		}
	}
}

int main() {

	size_t size = 9;

	vector<vector<int>> graph = {
		{ 0,  4,  0,  0,  0,  0,  0,  8,  0 },
		{ 4,  0,  8,  0,  0,  0,  0, 11,  0 }, 
		{ 0,  8,  0,  7,  0,  4,  0,  0,  2 }, 
		{ 0,  0,  7,  0,  9, 14,  0,  0,  0 }, 
		{ 0,  0,  0,  9,  0, 10,  0,  0,  0 }, 
		{ 0,  0,  4, 14, 10,  0,  2,  0,  0 }, 
		{ 0,  0,  0,  0,  0,  2,  0,  1,  6 }, 
		{ 8, 11,  0,  0,  0,  0,  1,  0,  7 }, 
		{ 0,  0,  2,  0,  0,  0,  6,  7,  0 }
	};

	int distance[] = {
		0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX
	};

	bool resolved[] = {
		false, false, false, false, false, false, false, false, false
	};

	djkstra(graph, distance, resolved, size);

	cout << "Distances:\n";
	for (size_t i = 0; i < size; i++) {
		cout << i << ": " << distance[i] << "\n";
	}

	return 0;
}
