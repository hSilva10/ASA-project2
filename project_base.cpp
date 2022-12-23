#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

typedef vector<int> vec;

typedef struct {
     vec nodes;
}Node;

typedef struct {
    int value;
    Node *right;
    Node *left;
}Edge;

void parse_input(vec nodes, vec edges);
void get_max_tree();


int main() {
    vec nodes;
    vec edges;
    parse_input(&nodes, &edges);
    return 0;
}

void parse_input(vec nodes, vec edges){
    int nodes_num;
    int edges_num;

    cin >> nodes_num;
    cin >> edges_num;



}
void get_max_tree(){

}
