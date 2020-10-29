#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution  {   public:
vector<int> dailyT(vector<int>& T){
    vector<int> ans(T.size());    stack<int>s;
    for(int i = T.size()-1; i >= 0; --i){
        while(!s.empty() && T[i] >= T[s.top()]) s.pop();
        ans[i] = s.empty() ? 0 : s.top() - i;
        s.push(i);
    }
    return ans;
}
};

// test
int main() { 
vector<int> o = {73,74,75,71,69,72,76,73};
Solution t;
auto x =  t.dailyT(o);
for ( int i : x)
cout << i << " ";
    return 0;
}