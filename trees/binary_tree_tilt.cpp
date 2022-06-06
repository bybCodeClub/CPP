#include <iostream>
using namespace std;

// using Post-Order DFS

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 int help(TreeNode* root, int &ans){
    if(root == nullptr) return 0;
    int left = help(root->left, ans);
    int right = help(root->right, ans);
    ans += abs(left - right);
    return left + right + root->val;  
 }

 int tiltit(TreeNode* root){
int ans=0;
help(root, ans);
return ans;
 }

 int main() {
    // Input: root = [4,2,9,3,5,null,7]
    // Output: 15
    TreeNode *T =  new TreeNode(4);
    T->left = new TreeNode(2); T->right = new TreeNode(9); T->left->left = new TreeNode(3);
    T->left->right= new TreeNode(5); T->right->right= new TreeNode(7);

    cout << tiltit(T) << endl;

     return 0;
 }