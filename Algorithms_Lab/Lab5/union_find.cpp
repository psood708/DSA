#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
    int source, destination, weight;
};

vector<Edge> edges;  
int parent[100];  

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

 
bool compare(Edge edge1, Edge edge2) {
    return edge1.weight < edge2.weight;
}

 
vector<Edge> kruskal(int num_nodes) {
    int i, source, destination;
    vector<Edge> mst; 

    // Initialize the parent of each node to -1
    for (i = 1; i <= num_nodes; i++) {
        parent[i] = -1;
    }

    // here we will perform the first step of Kruskal for sorting the weights
    sort(edges.begin(), edges.end(), compare);

    for (i = 0; i < edges.size(); i++) {
        //here it will search for the parents for both source and destimantion
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
 
    for (i = 0; i < num_edges; i++) {
        cout << "Enter the source, destination and weight of edge " << i + 1 << ": ";
        cin >> source >> destination >> weight;
        edges.push_back({source, destination, weight}); 
    }
    vector<Edge> mst = kruskal(num_nodes);
    int mst_weight = 0; 
    // Print the edges selected in the MSTs
    cout << "Edges in the MST:" << endl;
    for (i = 0; i < mst.size(); i++) {
        cout << mst[i].source << " - " << mst[i].destination << " (" << mst[i].weight << ")" << endl;
        mst_weight+=mst[i].weight;
    }
    cout<<"The total cost is: "<<mst_weight;

    return 0;
}
