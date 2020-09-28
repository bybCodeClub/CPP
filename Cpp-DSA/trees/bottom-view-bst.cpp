#include <iostream>
#include <map>
using namespace std;

/* This program will use a pre-order traversal to check the horizontal lengths between nodes and output the bottom view of the tree. */

// As with all tree problems lets first define our node.
struct Node {
    int key;
    Node *left, *right;
    Node(int key) {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

// A recursive preorder traversal to fill our map.
void mapBottom  (Node* node, int len, int level, auto &map) {
    if (node == nullptr) return;
    // if the curr node is greater or equal to the largest level for the same horiz dist
    // or the dist has been seen for the first time. -Update map
    if(level >= map[len].second)  // *note .second simply refers to the second val of a key : val pair. aka the value.
     map[len] = {node->key, level};
    
    mapBottom(node->left, len -1, level+1, map );
    mapBottom(node->right,len + 1, level + 1, map);
}

// Print function to display the bottom view of tree.
void print (Node* root) {
    // create an empty map
    map<int, pair<int, int>> newMap;
    // call mapBottom with our new map to fill it
    mapBottom(root, 0, 0, newMap);
    // loop through our map displaying the bottom view.
    for (const auto &i : newMap) {
        cout << i.second.first << " ";
    }
}

// test 
int main() {
    Node* root = nullptr;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    print(root);
    return 0;
}