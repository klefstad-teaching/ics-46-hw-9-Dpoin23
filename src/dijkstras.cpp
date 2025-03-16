#include "../src/dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    vector<int> distances(n, INF);
    previous.assign(n, -1);

    using Node = pair<int, int>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    distances[source] = 0;
    pq.push({0. source});

    while (!pq.empty()) {
        int current = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current > distances[u]) continue;

        for (const Edge& e : G[u]) {
            int v = e.dst;
            int weight = e.weight;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push(distances[v], v);
            }
        }
    }

    return distances;
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
    for (int i = 0; i < v.size(); ++i) 
        cout << v[i] << " ";
    cout << endl;
}