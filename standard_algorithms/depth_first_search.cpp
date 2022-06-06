#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node() : val(0), left(nullptr), right(nullptr){}
    Node(int x) : val(x), left(nullptr), right(nullptr){}
    Node(int x, Node* left, Node* right) : val(x), left(left), right(right){}
class Solution {
public:
    bool dfs(Node* cur,  Node target, set<Node> visited){
        if(cur->val == target.val) return true;
        for(auto &x : cur){

            if( ){
                // something
                dfs(x, target, visited) ? true : false;
            }
        }
        return false;
    }

};

// test
int main() {

    return 0;
}