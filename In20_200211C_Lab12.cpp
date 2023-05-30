#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;  // Define a shorthand for the pair of integers (vertex, weight)

// Function to add an edge between two vertices in the graph
void addEdge(vector<vector<pii>>& graph, int u, int v, int weight) {
    graph[u].push_back(make_pair(v, weight));  // Add edge from u to v with weight
    graph[v].push_back(make_pair(u, weight));  // Add edge from v to u with weight  
}

// Dijkstra's algorithm implementation
void dijkstra(const vector<vector<pii>>& graph, int source, vector<int>& distances) {
    int n = graph.size();  // Total number of vertices in the graph

    priority_queue<pii, vector<pii>, greater<pii>> pq;  // Priority queue to store vertices with their distances

    distances.assign(n, numeric_limits<int>::max());  // Initialize distances to infinity for all vertices

    distances[source] = 0;  // Distance from source to itself is 0

    pq.push(make_pair(0, source));  // Add source vertex to the priority queue with distance 0

    while (!pq.empty()) {
        int u = pq.top().second;  // Extract the vertex with the minimum distance
        pq.pop();

        // Explore all neighbors of the current vertex
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;  // Neighbor vertex
            int weight = neighbor.second;  // Weight of the edge between u and v

            // Relaxation step: Update the distance if a shorter path is found
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push(make_pair(distances[v], v));  // Add the updated vertex to the priority queue
            }
        }
    }
}

// Function to print the distances from the source vertex to all other vertices
void printDistances(const vector<int>& distances) {
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < distances.size(); ++i) {
        cout << i << "\t" << distances[i] << "\n";
    }
}

int main() {
    int numVertices = 6;  // Total number of vertices in the graph

    vector<vector<pii>> graph(numVertices);  // Adjacency list representation of the graph

    // Adding edges to the graph
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 15);
    addEdge(graph, 0, 5, 5);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 1, 3, 30);
    addEdge(graph, 2, 3, 12);
    addEdge(graph, 2, 4, 5);
    addEdge(graph, 3, 5, 20);

    int source = 5;  // Source vertex for Dijkstra's algorithm

    vector<int> distances(numVertices);  // Vector to store the shortest distances from the source
    dijkstra(graph, source, distances);  // Apply Dijkstra's algorithm

    printDistances(distances);  // Print the distances from the source to all other vertices

    return 0;
}
