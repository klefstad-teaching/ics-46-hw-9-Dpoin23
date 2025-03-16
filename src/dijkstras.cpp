#include "../src/dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;

    priority_queue<Node, vector<Node>, greater<Node>> pq;


    while (!pq.empty()) {
        Node current = pq.top();

    }
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> path;
    for (int at = 0; at != -1; at = previous[at]) 
        path.push_back(at);

    reverse(path.begin(), path.end());

    if (path.size() == 1 && path[0] != destination)
        return {};

    return path;
}

void print_path(const vector<int>& v, int total) {
    cout << "Total cost is " << total << endl;
    for (int i : v) 
        cout << i << " ";
    cout << endl;
}