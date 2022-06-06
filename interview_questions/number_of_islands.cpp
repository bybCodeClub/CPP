#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution { 
private:
void dfs(vector<vector<char>>&grid, int i, int j){
    int m = grid.size(), n = grid[0].size();
    if( i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0'){
        return;
    } 
    grid[i][j] = '0';
    dfs(grid, i-1, j);
    dfs(grid, i+1, j);
    dfs(grid, i, j-1);
    dfs(grid, i, j+1);
}
public:
// dfs solution
int islands_DFS(vector<vector<char>>&grid){
    int m = grid.size(), n = m ? grid[0].size() : 0, c = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '1'){
                c++;
                dfs(grid,i,j);
            }
        }
    }
    return c;
}

// bfs solution
int islands_BFS(vector<vector<char>> &grid){
int x = grid.size(), y = x ? grid[0].size() : 0, count = 0, offsets[] = {0, 1 ,0, -1, 0};
for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
        if(grid[i][j] == '1'){
            count++;
            grid[i][j] = '0';
            queue<pair<int, int>> q;
            q.push({i, j});
            while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int r = cur.first + offsets[k], c = cur.second + offsets[k+1];
                if(r >= 0 && r < x && c >= 0 && c < y && grid[r][c] == '1'){
                    grid[r][c] = '0';
                    q.push({r,c});
                }
            }    
            }
        }
    }
}
 return count;
}
};
//testing
int main() {
vector<vector<char>> grid = {
{'1','1','0','0','0'},
{'1','1','0','0','0'},
{'0','0','1','0','0'},
{'0','0','0','1','1'},
};
vector<vector<char>> grid2 = {
{'1','1','0','0','0'},
{'1','1','0','0','0'},
{'0','0','1','0','0'},
{'0','0','0','1','1'},
};
Solution test; 
cout << "[BFS] oi you have: " << test.islands_BFS(grid) << " Islands" << endl;
cout << "[DFS] oi you have: " << test.islands_DFS(grid2) << " Islands" << endl; 
    return 0;
}