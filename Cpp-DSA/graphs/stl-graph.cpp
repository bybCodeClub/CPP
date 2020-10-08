// A directed graph implentation using STL
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int src, dest;
};

class Graph {
    public:
    // construct a vector of vectors to represent our adjacency list
    vector<vector<int>> adjList;
    //  Graph constructor
        Graph(vector<Edge> const &edges, int N) {
         // resize the vector to N elements of type vector<int>
         adjList.resize(N);
        // add edges to the directed graph
        for( const auto &edge: edges){
            // insert at the end
            adjList[edge.src].push_back(edge.dest);
            // uncomment below line for indirected graph
            // adjList[edge.dest].push_back(edge.src);    
        }       
    }    
};

// print adjList representation  of the graph
void printAdj(Graph const& graph, int N){
    for(int i = 0 ; i < N; i++){
        // print the current vertex
        cout << i << " >> ";
        //print all the neighboring verices of vertex i
        for (int v : graph.adjList[i])
            cout << v << " > ";
        cout << endl;
    }
}

// test drive
int main() {
    // vector of graph edges 
    // please noe thar initisalizing the vector in the below format will
    // work fine in cpp 11, 14, 17 but will fail int cpp 98/
    vector<Edge> edges = {
        { 0, 1 }, { 1, 2 }, { 2,0 }, { 2, 1 }, { 3, 2 }, { 4, 5 }, { 5, 4 },
    };
    // num of nodes in the graph
    int N = 6;
    // construct graph
    Graph graph(edges, N);
    // print adjList representation fo the graph
    printAdj(graph, N);
    return 0;
}