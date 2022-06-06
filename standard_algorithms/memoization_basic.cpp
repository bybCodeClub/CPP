#include <iostream>
#include <chrono>
#include <unordered_map>

using namespace std;

unordered_map<int, int> cache = {};

int expensive(int num){
    
    if(cache[num] == (num * num)){
        return cache[num];
    }
    cout << "computing {}..." << num <<endl;
    std::chrono::milliseconds timespan(1000);
    int res = num * num;
    cache[num] = res;
    return res;
};

int main(){
    int rez = expensive(4);
    cout << rez << endl;
    rez = expensive(10);
    cout << rez << endl;
    rez = expensive(4);
    cout << rez << endl;
    rez = expensive(10);
    cout << rez << endl;
    return 0;
}