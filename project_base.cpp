#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Edge {
public:
    int value, a , b;
    Edge(){
        this->value = 0;
        this->a = 0;
        this->b = 0;
    }
    Edge(int value, int a, int b){
        this->value = value;
        this->a = a-1;
        this->b = b-1;
    }
};

typedef vector<Edge> Edges;


class DisjointSetForest {
    int *rank = nullptr, *parent = nullptr, n = 0;
public:
    DisjointSetForest(int num_vertices) {
        rank = new int[num_vertices];
        parent = new int[num_vertices];
        this->n = num_vertices;
        makeSet();
    }

    /* Time complexity
     * -> O(V)
     * */
    void makeSet(){
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    /* Time complexity:
     *  best case: O(1)
     *  worst case: O(V)
     *  average case: O(alpha(V)) - inverse Ackermann function which means the complexity of find operation is practically constant and close to O(1)
     * */
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    /* Time complexity:
     *  best case: O(1)
     *  worst case: O(V)
     *  average case: O(alpha(V))
     * */
    void union_sets(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y) return;

        link(root_x, root_y);
    }
    /* Time complexity:
     *  -> O(1)
     * */
    void link(int x, int y){
        if(rank[x] > rank[y])
            parent[y] = x;
        else {
            parent[x] = y;
            if (rank[x] == rank[y])
                rank[y]++;
        }
    }
};

/* Time complexity:
 * O(E*logE) + O(E*alpha(V)) => O(E*log(E))
 * */
void kruskal(Edges& edges, int num_vertices) {
    /* Sort the edges by weight in non-decreasing order
    *  Time complexity:
     *  -> O(E*log(E))
     */
     sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.value > b.value;
    });


    // Initialize the disjoint-set forest data structure
    DisjointSetForest parents(num_vertices);

    int num_edges = 0;

    int max_weight = 0;
    /* Time complexity:
     *  average -> O(E*alpha(V)) - E operations of union_sets
     *  note: (|E| >= |V| - 1)
     * */
    for (Edge edge : edges) {
        // Find the root of the two vertices connected by this edge
        int root_a = parents.find(edge.a);
        int root_b = parents.find(edge.b);

        // If the two vertices are not already in the same tree, add the edge
        // to the maximum weight spanning tree
        if (root_a != root_b) {
            parents.union_sets(root_a, root_b);
            num_edges++;
            max_weight += edge.value;
        }
        if(num_edges == num_vertices - 1)
            break;
    }

    printf("%d\n", max_weight);
}

/* Overall time complexity:
 * -> O(E) + O(E*log(E)) => O(E*log(E))
 * */
int main() {
    int nodes_num = 0, edges_num = 0;
    scanf("%d %d", &nodes_num, &edges_num);

    if(nodes_num == 0 || edges_num == 0) {
        printf("%d\n", 0);
        return 0;
    }
    /* Read in the edges
     * Time complexity:
     *  -> O(E)
     */
    Edges edges;
    for (int i = 0; i < edges_num; i++) {
        int a, b, value;
        scanf("%d %d %d", &a, &b, &value);
        edges.push_back(Edge(value,a,b));
    }
    /* Time complexity:
     *  -> O(E*log(E))
     * */
    kruskal(edges, nodes_num);
    return 0;
}
