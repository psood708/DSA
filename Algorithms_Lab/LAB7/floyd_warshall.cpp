#include <iostream>
#include <climits>

#define MAX_NODES 100

using namespace std;

int num_nodes; // Number of nodes in the graph
int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix to store the graph

// Function to initialize the adjacency matrix with default values
void initialize() {
    int i, j;

    for (i = 1; i <= MAX_NODES; i++) {
        for (j = 1; j <= MAX_NODES; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INT_MAX;
            }
        }
    }
}

// Function to add an edge to the graph
void add_edge(int source, int destination, int weight) {
    graph[source][destination] = weight;
}

// Function to print the adjacency matrix
void print_graph() {
    int i, j;

    cout << "Adjacency matrix:" << endl;

    for (i = 1; i <= num_nodes; i++) {
        for (j = 1; j <= num_nodes; j++) {
            if (graph[i][j] == INT_MAX) {
                cout << "- ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// Function to perform the Floyd-Warshall algorithm on the graph
void floyd_warshall() {
    int i, j, k;

    // Initialize the distance matrix with the same values as the adjacency matrix
    int distance[MAX_NODES][MAX_NODES];

    for (i = 1; i <= num_nodes; i++) {
        for (j = 1; j <= num_nodes; j++) {
            distance[i][j] = graph[i][j];
        }
    }

    // Perform the Floyd-Warshall algorithm
    for (k = 1; k <= num_nodes; k++) {
        for (i = 1; i <= num_nodes; i++) {
            for (j = 1; j <= num_nodes; j++) {
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX && distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // Print the distance matrix
    cout << "Shortest distances between all pairs of vertices:" << endl;

    for (i = 1; i <= num_nodes; i++) {
        for (j = 1; j <= num_nodes; j++) {
            if (distance[i][j] == INT_MAX) {
                cout << "- ";
            } else {
                cout << distance[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int num_edges, i, source, destination, weight;

    cout << "Enter the number of nodes in the graph: ";
    cin >> num_nodes;

    initialize();

    cout << "Enter the number of edges in the graph: ";
    cin >> num_edges;

    for (i = 0; i < num_edges; i++) {
        cout << "Enter the source, destination and weight of edge " << i + 1 << ": ";
        cin >> source >> destination >> weight;
        add_edge(source, destination, weight);
    }

    print_graph();

    floyd_warshall();

    return 0;
}
