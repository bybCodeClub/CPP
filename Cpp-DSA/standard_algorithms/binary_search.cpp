#include <iostream>
#include <vector>
using namespace std;

// A simple binary search
int binary_search(vector <int> arr, int target){
int low = 0;
int high = arr.size() -1;

while(low <= high){
    int mid = low + (high - low)/2; // carfule how you implement this. Some example found online and in books will overflow.

    if(target == arr[mid])
        return mid;

    if(target < arr[mid])
        high = mid -1;
    else
        low = mid +1;
    
}
    return -1;
}

// test
int main() {
    vector<int> A = {2,4,6,8,10,12,14,16,18,20};
    int t = 10;
    cout << binary_search(A, t);
    return 0;
}