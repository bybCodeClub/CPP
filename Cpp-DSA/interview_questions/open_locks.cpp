#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

class Solution { public:
// helper
vector<string> combos(string key){
    vector<string> res;
    for(int i = 0; i < 4; i++){
        string tmp = key;
        tmp[i] = (key[i] +1);
        res.push_back(tmp);
        tmp[i] = (key[i] - 1);
        res.push_back(tmp);
    }
    return res;
}

int openLocks(vector<string > &deadends, string target ){
    unordered_set<string> dends(deadends.begin(), deadends.end()), visited;
    queue<string> bfs;
    string initial = "0000";
    if(dends.find(initial) != dends.end()) return -1;
    visited.insert("0000");
    bfs.push("0000");
    int result = 0;
    while(!bfs.empty()){
        int N = bfs.size();
        for(int i = 0; i < N; i++){
            string t = bfs.front(); bfs.pop();
            vector<string> attempts = move(combos(t));
            for(auto s : attempts){
                if( s == target) return ++result;
                if(visited.find(s) != visited.end()) continue;
                    if(dends.find(s) == dends.end()){
                        bfs.push(s);
                        visited.insert(s);
                    }
            }
        }
        ++result;
    }
    return -1;
}
};

// tests
int main () {
vector<string> deadendz = {"0201","0101","0102","1212","2002"};
string target =  "0202";
Solution t;
cout << "number of moves = " << t.openLocks(deadendz, target); // output 6
    return 0;
}