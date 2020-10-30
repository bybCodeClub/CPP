#include <iostream>
#include <functional>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

class Solution { public:
    int evRpn(vector<string>& tokens){
        // https://en.cppreference.com/w/cpp/header/functional
        unordered_map<string, function<int(int, int)>> operator_map;
        operator_map["+"] = plus<int>();
        operator_map["-"] = minus<int>();
        operator_map["*"] = multiplies<int>();
        operator_map["/"] = divides<int>();

        stack<int> s;
        for(const auto &t : tokens){
            if(const auto func = operator_map[t]){
                const auto b = s.top(); s.pop();    // order matters. B before A
                const auto a = s.top();s.pop();
                s.push(func(a,b));
            } else {
                s.push(atoi(t.c_str()));
            }
        }
        return s.top();
    }
};

int main(){
vector<string> pn{"2", "1", "+", "3", "*"};
Solution t;
cout << " Answer is " << t.evRpn(pn);
    return 0;
}