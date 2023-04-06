#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
    int source, destination, weight;
};

vector<Edge> edges; // Vector to store all edges in the graph
int parent[100]; // Array to store the parent of each node (used for union-find)

// Function to find the parent of a node in the union-find data structure
int find(int node) {
    if (parent[node] == -1) {
        return node;
    }
    return find(parent[node]);
}

// Function to perform union of two nodes in the union-find data structure
void Union(int node1, int node2) {
    parent[node1] = node2;
}

// Comparator function to sort edges in non-decreasing order of weight
bool compare(Edge edge1, Edge edge2) {
    return edge1.weight < edge2.weight;
}

// Function to perform Kruskal's algorithm and find the MST
vector<Edge> kruskal(int num_nodes) {
    int i, source, destination;
    vector<Edge> mst; // Vector to store the edges selected in the MST

    // Initialize the parent of each node to -1
    for (i = 1; i <= num_nodes; i++) {
        parent[i] = -1;
    }

    // here we will perform the first step of Kruskal for sorting the weights
    sort(edges.begin(), edges.end(), compare);

    for (i = 0; i < edges.size(); i++) {
        source = find(edges[i].source);
        destination = find(edges[i].destination);

        // If the source and destination nodes have different parents, they can be added to the MST
        if (source != destination) {
            mst.push_back(edges[i]);
            Union(source, destination);
        }
    }

    return mst;
}

int main() {
    int num_nodes, num_edges, i, source, destination, weight;
    cout << "Enter the number of nodes in the graph: ";
    cin >> num_nodes;
    cout << "Enter the number of edges in the graph: ";
    cin >> num_edges;
    // Read in the edges from the user
    for (i = 0; i < num_edges; i++) {
        cout << "Enter the source, destination and weight of edge " << i + 1 << ": ";
        cin >> source >> destination >> weight;
        edges.push_back({source, destination, weight}); //using the vectors for the same
    }
    vector<Edge> mst = kruskal(num_nodes);

    // Print the edges selected in the MSTs
    cout << "Edges in the MST:" << endl;
    for (i = 0; i < mst.size(); i++) {
        cout << mst[i].source << " - " << mst[i].destination << " (" << mst[i].weight << ")" << endl;
    }

    return 0;.
}
