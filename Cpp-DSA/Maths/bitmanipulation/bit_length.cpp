#include <iostream>
using namespace std;
/*
To calculate the number of bits we need to shift 1 one bit left each time and check if the shifted number is larger than the input.
*/
int bLen(int b){
    int bCount = 0;
  while ((1 << bCount) <= b) {
    bCount += 1;
  }
  return bCount;
}

int main(){
    int num;
    cout << "enter a number\n";
    cin >> num;
    cout << "your b length is " << bLen(num) << endl;
}