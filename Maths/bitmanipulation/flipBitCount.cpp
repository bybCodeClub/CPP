#include <iostream>
#include <bitset>
using namespace std;
/*
    counts the number of bit needed to change to flip a to b
    we can achieve this with a hepler function or use of std::bitset
*/

int countSetBits(int Onum){
    int sbcount = 0; int num = Onum;
    while(num) {
        sbcount += num & 1; // add last bit of num to the sum of sbcount
        num >>= 1; //sihfts num right by one bit to check other bits
    }
    return sbcount;
}
int bitCount(int A, int B){
    bitset<8> flip(A ^ B);
    if(flip.any())
        return flip.count(); 

    return 0;
   // return countSetBits(A ^ B);
}
int main() {
    cout << "Flip count " << bitCount(20, 2) << endl;
    cout << "csb: " << countSetBits(21) << endl;
    cout << "std::bitset ";
    bitset<8> c(21);
    if(c.any())
         cout << c.count(); 
    
    return 0;
}

