#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int value;
    int a, b;
}Edge;

typedef vector<Edge> Edges;

struct Node {
    int parent;
    int rank;
};

class DisjointSetForest {
public:
    DisjointSetForest(int num_vertices) : nodes_(num_vertices) {
        for (int i = 0; i < num_vertices; i++) {
            nodes_[i].parent = i;
            nodes_[i].rank = 0;
        }
    }

    int find(int x) {
        if (nodes_[x].parent != x) {
            nodes_[x].parent = find(nodes_[x].parent);
        }
        return nodes_[x].parent;
    }

    void union_sets(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y) return;

        if (nodes_[root_x].rank < nodes_[root_y].rank) {
            nodes_[root_x].parent = root_y;
        } else if (nodes_[root_x].rank > nodes_[root_y].rank) {
            nodes_[root_y].parent = root_x;
        } else {
            nodes_[root_y].parent = root_x;
            nodes_[root_x].rank++;
        }
    }

private:
    vector<Node> nodes_;
};

void kruskal(Edges& edges, int num_vertices) {
    // Sort the edges by weight in non-decreasing order
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.value > b.value;
    });


    // Initialize the disjoint-set forest data structure
    DisjointSetForest parents(num_vertices);

    int max_weight = 0;
    for (const auto& edge : edges) {
        // Find the root of the two vertices connected by this edge
        int root_a = parents.find(edge.a);
        int root_b = parents.find(edge.b);

        // If the two vertices are not already in the same tree, add the edge
        // to the maximum weight spanning tree
        if (root_a != root_b) {
            parents.union_sets(root_a, root_b);
            max_weight += edge.value;
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

    kruskal(edges, nodes_num);
    return 0;
}
