#include <iostream>
#include <stack>
#include <map>
using namespace std;
class Solution { public:
bool isValid(std::string s){
stack<char> stck;
map<char, char> m = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
    for(auto x:s){
        if(m.count(x)){
            stck.push(x);
        } else {
            if(stck.empty() || m[stck.top()] != x) return false;
            stck.pop();
        }
    }
    return stck.empty();
}
};

int main() {
cout << " enter a string of parenthesis: \n";
string s;
cin >> s;
Solution t;
cout << "Your answer is : " << t.isValid(s);
    return 0;
}