#include <iostream>

using namespace std;

// node definition
struct Node {
    int data;
    Node* next = nullptr;
    Node(int x){data = x;};
};
// basic linked list constructor
Node* constructN(int x, int y, int z){
    Node* n1 = new Node(x);
    Node* n2 = new Node(y);
    Node* n3 = new Node(z);
    n1->next = n2; n2->next = n3; n3->next = nullptr;
    return n1;
}
//test
int main(){
   Node* T =  constructN(10, 11 , 12);
   
   while(T){
      cout << T->data << " ";
      T = T->next;
   }
    return 0;
}