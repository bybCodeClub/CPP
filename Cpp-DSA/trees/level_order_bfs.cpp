#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// We will implement a level order traversal or breadth first search on a binary tree both 
// iteratively and recursively
// to demonstrate the functions we'll first define our tree node so we can constuct a tree.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

// iterative level order traversa
vector<vector<int>> itrLOT(TreeNode* root){
    if(root == nullptr) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int level = q.size();
        vector<int> tmp;
        while(level--){
            TreeNode* cur = q.front();
            q.pop();
            tmp.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        ans.push_back(tmp);
    }
    return ans;
}
// RECURSIVE level order traversal
vector<vector<int>> ans{};
void help(TreeNode*node, int level){
if(node == nullptr) return;
if(level == ans.size()){
    vector<int> tmp; 
    ans.push_back(tmp);
}
ans[level].push_back(node->val);
if(node->left) help(node->left, level +1);
if(node->right) help(node->right, level+1);
}
vector<vector<int>> levelOrder(TreeNode*root){
    if(root == nullptr) return {};
    help(root, 0); return ans;
}

// tests
int  main(){
TreeNode  *root = nullptr;
root = new TreeNode(3);
root->left = new TreeNode(9); 
root->left->left  = new TreeNode();
root->left->right = new TreeNode();
root->right = new TreeNode(20);
root->right->left = new TreeNode(15);
root->right->right = new TreeNode(7);
auto t =  levelOrder(root);
for ( const auto &i : t ){
   for ( int x : i ) cout << x << ' ';
   cout << endl;
}
    return 0;
}