#include <iostream>
#include <vector>
using namespace std;
// returns the least number of perfect squares which sums to n
class Solution { public:
int numSquares(int n){
        vector<int> mins(n+1, 0);
        for(int i = 1; i <= n; i++){
            int min_val = i, y = 1, sqr = 1;
            while(sqr <= i){
                min_val = min(min_val, 1 + mins[i - sqr]);
                ++y;
                sqr = y*y;
            }
            mins[i] = min_val;
        }
        return mins[n];
}
};

int main() {
Solution t;
cout << t.numSquares(12) << endl;
cout << t.numSquares(9) << endl;
cout << t.numSquares(2) << endl;
cout << t.numSquares(1003) << endl;
    return 0;
}
