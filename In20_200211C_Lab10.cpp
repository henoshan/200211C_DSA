#include <iostream>
#include <list>
using namespace std;

struct Node {
    int label;              // Node label or identifier
    list<int> neighbours;   // List of neighbouring nodes
};

struct Graph {
    int n = 8;
    Node* nodes = new Node[n + 1];   // Array of nodes

    void intializenodes() {
        for (int i = 1; i <= n; i++) {
            nodes[i].label = i;     // Assigning labels to each node
        }
    }

    void addedge(int u, int v) {
        nodes[u].neighbours.push_back(v);   // Adding edge between nodes u and v
        nodes[v].neighbours.push_back(u);   // Adding edge between nodes v and u (undirected graph)
    }

    void print() {
        for (int i = 1; i <= n; i++) {
            cout << "Node " << nodes[i].label << " is connected to nodes: [ ";
            for (auto neighbour : nodes[i].neighbours) {
                cout << neighbour << " ";   // Printing the neighbouring nodes of each node
            }
            cout << "]";
            cout << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->intializenodes();

    // Add edges for the graph (based on the given MST)
    g->addedge(1, 2);
    g->addedge(1, 3);
    g->addedge(1, 4);
    g->addedge(1, 5);
    g->addedge(2, 3);
    g->addedge(2, 6);
    g->addedge(4, 6);
    g->addedge(4, 7);
    g->addedge(4, 8);
    g->addedge(5, 6);
    g->addedge(5, 7);
    g->addedge(5, 8);

    // Print the graph adjacency list
    g->print();

    return 0;
}
