#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
    // TODO ** add well written explanation 
/*  
------- Longest Arithmetic Subsequence of Given Difference-------
Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
*/
int longestSub(vector<int>& A, int difference) {
    int res = 1; unordered_map<int, int> mapmax;
    for(int i = 0; i < A.size(); i++){
        mapmax[A[i]] = mapmax[A[i] - difference]+1;
    }
    for(auto i:mapmax){
        res = max(res, i.second);
    }
    return res;
}

// alternatively we can compact the code into one loop with some speed sacrifice
int altLongSub(vector<int>& B, int difference) {
    int res = 1; unordered_map<int, int> maxmap;
    for(int j = 0; j < B.size(); j++){
        maxmap[B[j]] = maxmap[B[j] -difference]+1;
        res = max(res, maxmap[B[j]]);
    }
    return res;
}
// test drive
int main () {
vector<int>arr1 = {1,5,7,8,5,3,4,2,1}; // diff of -2 output 4
vector<int>arr2 = {1,3,5,7}; // diff 1 output 1
vector<int>arr3 = {3,5,6, 9,11,12,15}; // with diff of 3 output 5
cout<< "----Approach 1: two passes----\n";
cout << "array1: " << longestSub(arr1, -2) << endl;
cout << "array2: " << longestSub(arr2, 1) << endl;
cout << "array3: " << longestSub(arr3, 3) << endl;
cout<< "-----Approach 2: one passe-----\n";
cout << "array1: " << altLongSub(arr1, -2) << endl;
cout << "array2: " << altLongSub(arr2, 1) << endl;
cout << "array3: " << altLongSub(arr3, 3) << endl;
    return 0;
}