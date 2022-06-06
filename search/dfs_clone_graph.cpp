#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    int val;

    vector<Node*> neighbors;  
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> copies;
public: 
Node* clonedGraph (Node* node) {
    if(!node) return nullptr;
    if(copies.find(node) == copies.end()){
        copies[node] = new Node(node->val, {});
        for(Node* neighbor : node->neighbors) {
            copies[node]->neighbors.push_back(clonedGraph(neighbor));
        }
    }
    return copies[node];
}
};

int main() {

Node* n1 = new Node(1);
Node* n2 = new Node(2);
Node* n3 = new Node(3);
Node* n4 = new Node(4);
n1->neighbors.push_back(n2);
n1->neighbors.push_back(n4);
n2->neighbors.push_back(n1);
n2->neighbors.push_back(n3);
n3->neighbors.push_back(n2);
n3->neighbors.push_back(n4);
n4->neighbors.push_back(n1);
n4->neighbors.push_back(n3);

Solution T;
auto adj = T.clonedGraph(n1);
for(Node* e : adj->neighbors)
    cout << e->val;
    return 0;
}