#include <iostream>
#include <bitset>
using namespace std;

// Clear the kth bit

int clearBit(int num, int pos){
    return (num & (~(1 << (pos - 1))));
}
int cb2(int num, int pos){
    bitset<8> bs(num); 
    return bs.set(pos-1, 0).to_ulong();
}

int main(){
    cout << clearBit(12,4) << endl;
    cout << cb2(12, 4);
    return 0;
}
