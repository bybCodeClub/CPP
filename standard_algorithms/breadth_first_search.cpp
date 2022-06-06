#include <iostream>
#include <vector>
#include <queue>
 using namespace std;
 
 // Struct to hold edges
struct Edge {
    int src, dest;
};

 // Graph class
class Graph {
public:
// we'll use a vector of vector for our adjList
vector<vector<int>> adjList;
//Graph constructor
Graph(vector<Edge> const &edges, int N){
    // resize our vector to N elements of type vector<int>
    adjList.resize(N);
    // add edges to undirected graph
    for( auto &edge: edges){
        adjList[edge.src].push_back(edge.dest);
        adjList[edge.dest].push_back(edge.src);
    }
  }
};

 //bfs function iterative - performs a bfs starting from vertex v
void itrBFS(Graph const &graph, int v, vector<bool> &discovered) {
    // create a queue used to do BFS
    queue<int> q;
    // mark source vertex as discovered
    discovered[v] = true;
    // push source vertext into the queue
    q.push(v);
    //loop till the queue is empty
    while(!q.empty()){
        // pop front node from the queue and print it
        v = q.front();
        q.pop(); cout << v << " ";
        // do for every edge (v -> u)
        for(int u : graph.adjList[v])
            if(!discovered[u]){
                //mark it discovered and push it into the queue
                discovered[u] = true;
                q.push(u);
            }
    }
}

 // bfs function recursive
void recBST(Graph const &graph, queue<int> &q, vector<bool> &discovered){
    if(q.empty()) return;
    // pop front node from q and print it
    int v = q.front();
    q.pop();
    cout << v << " ";
    // do for every edge (v -> u)
    for( int u : graph.adjList[v]){
        if(!discovered[u]){
            // mark it discovered and push it nto the q
            discovered[u] = true;
            q.push(u);
        }
    }
    recBST(graph, q , discovered);
}

int main() {
// ***iterative implentation***
cout << "iterative function: \n";
vector<Edge> edges = { // Vector of graph edges as per notes.
{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9}, {5, 10}, {4, 7}, {4,8}, {7, 11}, {7,12}
//vertex 0, 13, 14 are single nodes.
};
// number of nodes in the graph
int N = 15;
// creat a graph from edges
Graph graph(edges, N);
// Stores vertex is discovered or not
vector<bool> discovered(N, false);
// DO BFS traversal from all undiscovered nodes to cover all unconnected
// components of the graph
for(int i = 0; i < N; i++)
    if(discovered[i] == false)
        itrBFS(graph, i, discovered);

cout << endl;
// *** recursive implementtion ***
cout << "recursive function: \n";
vector<bool> discoveredd(N, false);
queue<int> q;
for(int i= 0;i <N; i++ ){
    if(discoveredd[i] == false){
        discoveredd[i] = true;
        q.push(i);
        recBST(graph, q, discoveredd);
    }
}
    return 0;
}