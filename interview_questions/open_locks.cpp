#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

class Solution {    public:
                
    vector<string> combos(string key){
        vector<string> res;
        for(int i = 0; i < 4; i++){
            string tmp = key;
            tmp[i] = (key[i] - '0' + 1) % 10 + '0';
            res.push_back(tmp);
            tmp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(tmp);
        }
        return res;
    }
                
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dend(deadends.begin(), deadends.end()), visited;
        queue<string> bfs;
        string init = "0000";
        if(dend.find(init) != dend.end()) return -1;
        bfs.push("0000");
        visited.insert("0000");
        int res = 0;
        while(!bfs.empty()){
            int N = bfs.size();
            for(int i = 0; i < N; i++){
            string t = bfs.front();
            bfs.pop();
            if(t == target) return res;
            vector<string> attempts = move(combos(t));
            for(auto s : attempts){
                if(visited.find(s) == visited.end() && dend.find(s) == dend.end()){
                    bfs.push(s);
                    visited.insert(s);
                }
            }
        }
        ++res;
        }
        return -1;
    }
};

// tests
int main () {
vector<string> deadendz = {"0201","0101","0102","1212","2002"};
string target =  "0202";
Solution t;
cout << "number of moves = " << t.openLock(deadendz, target); // output 6
    return 0;
}