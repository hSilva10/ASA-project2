#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int value;
    int a, b;
}Edge;

typedef vector<Edge> Edges;

void prim(Edges& edges, int num_vertices) {
    // Initialize the list of included vertices
    vector<bool> included(num_vertices, false);

    // edges dimension
    int size = edges.size();

    // DEFAULT vertex 0 = true
    included[0] = true;

    // Add vertex 1 to the maximum weight spanning tree
    included[1] = true;

    int max_weight = 0;
    while (true) {
        // variable to see if all nodes are checked
        bool change = false;

        // Find the heaviest edge from an included vertex to a non-included vertex
        int heaviest_edge_index = -1;
        for (int i = 0; i < size; i++) {
            if ((included[edges[i].a] && !included[edges[i].b]) ||
                (included[edges[i].b] && !included[edges[i].a])){

                if (heaviest_edge_index == -1 || edges[i].value > edges[heaviest_edge_index].value) {
                    heaviest_edge_index = i;
                }
            }
        }
        // If no such edge was found, we have reached the end of the algorithm
        if (heaviest_edge_index == -1){
            for(int i = 0; i < num_vertices; i++)
                if(!included[i]) {
                    included[i] = true;
                    change = true;
                    break;
                }
        }
        if(!change && heaviest_edge_index == -1)
            break;
        if(!change) {
            // Add the heaviest edge to the maximum weight spanning tree
            max_weight += edges[heaviest_edge_index].value;
            if (!included[edges[heaviest_edge_index].a]) {
                included[edges[heaviest_edge_index].a] = true;
            } else {
                included[edges[heaviest_edge_index].b] = true;
            }
        }
    }

    cout << max_weight << endl;
}

int main() {
    int nodes_num, edges_num;
    cin >> nodes_num >> edges_num;

    // Read in the edges
    Edges edges;
    for (int i = 0; i < edges_num; i++) {
        int a, b, value;
        cin >> a >> b >> value;
        edges.push_back({value, a, b});
    }

    prim(edges, nodes_num);
    return 0;
}
