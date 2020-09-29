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
    int count = 0;
    bitset<8> flip(A ^ B);
    if(flip.any())
        return flip.count(); 

    return count;
   // return countSetBits(A ^ B);

}
int main() {
    cout << "Flip count " << bitCount(20, 2) << endl;
    /*
    cout << "csb: " << countSetBits(21) << endl;
    cout << "std::bitset ";
     int count = 0;
    bitset<8> flip(21);
    if(flip.any())
         cout << flip.count(); 
    */
    return 0;
}

