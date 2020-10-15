#include <iostream>
using namespace std;

  struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    //Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
 };

  Node* insertIntoBST(Node* root, int val) {
       if(!root){
           Node* root = new Node(val);
           return root;
       }
       if(val < root->val){
            root->left = insertIntoBST(root->left, val);
       } else {
            root->right = insertIntoBST(root->right, val);
       }
        return root;
  }

void print (Node* root) {
       if (root != NULL) {
     cout<<root->val<<" ";
      print(root->left);
      print(root->right);
       }
}

  // test 
  int main() {
    Node* root = nullptr;
    root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
   // root->right->left = new Node(5);
   // root->right->right = new Node(6);
   // root->right->left->left = new Node(7);
    //root->right->left->right = new Node(8);

    cout << "Before: ";
    print(root);
    insertIntoBST(root, 5);
    cout << "After: ";
    print(root);
    
      return 0;
  }