#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int destination;
    int weight;
};

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(vector<vector<Edge>>& graph, int numVertices) {
    // Priority queue to store vertices and their corresponding weights
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Vector to store key values (weights) of vertices
    vector<int> key(numVertices, INT_MAX);

    // Vector to store the parent vertex of each vertex
    vector<int> parent(numVertices, -1);

    // Vector to keep track of vertices included in MST
    vector<bool> inMST(numVertices, false);

    // Start with the first vertex
    int startVertex = 0;
    pq.push(make_pair(0, startVertex));
    key[startVertex] = 0;

    while (!pq.empty()) {
        // Extract the vertex with the minimum key value
        int u = pq.top().second;
        pq.pop();

        // Include the extracted vertex in the MST
        inMST[u] = true;

        // Traverse all adjacent vertices of u
        for (const auto& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            // If v is not in MST and the weight is smaller than the current key value
            if (!inMST[v] && weight < key[v]) {
                // Update the key value and parent of v
                key[v] = weight;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print the edges of the MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 1; i < numVertices; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<Edge>> graph(numVertices);

    cout << "Enter the edges in the format: source destination weight\n";
    for (int i = 0; i < numEdges; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph[source].push_back({destination, weight});
        graph[destination].push_back({source, weight});
    }

    // Find and print the minimum spanning tree
    primMST(graph, numVertices);

    return 0;
}
