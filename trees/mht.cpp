#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// related to scheduling and scheduling II problems. we use a queue to track our leaf nodes process 
// and an adjacency list to track the degrees of our nodes. 
// finally run a bfs until queue is empty and return result.

// function finds the min height tree given
vector<int> findMHT(int n, vector<vector<int>>& edges){
    // base case
    if( n == 1 ) return vector<int> {0};
    // adj list of nodes
    vector<vector<int>> graph(n);
    // degree count of nodes
    vector<int>degree(n,0);

    // populate graph adj list and degree count of nodes
    for(int i = 0; i < edges.size(); i++){
        int a = edges[i][0];
        int b = edges[i][1];

        graph[a].push_back(b);
        graph[b].push_back(a);

        degree[a]++;
        degree[b]++;
    }
    queue<int>q;
    // push degree 1 nodes (leaf nodes) into the queue
    for(int i = 0; i < n; i++)
        if(degree[i] == 1) q.push(i);
    // mht root nodes
    vector<int> res;
    // run bfs until queue is empty
    while(!q.empty()){
        int n = q.size();
        //clear root nodes
        res.clear();
        // prefirm a level order traversal
        while(n--){
            int node =  q.front();
            q.pop();
            // add current into the root node vector
            res.push_back(node);
            // proccess our neighbor nodes.
            for(int i = 0; i < graph[node].size(); i++){
                // decrease nodes in to queue
                degree[graph[node][i]]--;
                // push leaf nodes into queue
                if(degree[graph[node][i]] == 1){
                    q.push(graph[node][i]);
                }
            }
        }
    }
return res;
}

// test
int main() {
vector<vector<int>> e {{3,0},{3,1},{3,2},{3,4},{5,4}};
auto  ans = findMHT(6, e); 
for(auto p : ans)
cout << p << " ";
return 0;
}