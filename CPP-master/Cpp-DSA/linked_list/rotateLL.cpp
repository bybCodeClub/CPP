#include <iostream>
using namespace std;
// todo fix the pushnode or? missing 2 elements in print statement 
// ie: blank -> blank -> val 1 ->val2 -> val 3 -> nullptr 

/*Given a linked list, rotate the list to the right by k places, where k is non-negative.*/
struct Node{
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {};
    Node(int x) : data(x), next(nullptr) {};
    Node(int x, Node *next) : data(x), next(next) {};
};
Node* rotateRight(Node* head, int k) {
     if(!head || !head->next || k == 0) return head;
     Node *cur = head;
     int length = 1;
     while(cur->next && length++)
        cur = cur->next;
    cur->next = head;
    k = length - k % length;
    while(k--)
        cur = cur->next;
    head = cur->next;
    cur->next = nullptr;
        return head;
}
  void push(Node** head_ref, int new_data) { 
    Node* new_node = new Node(); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
// test drive
int main() {
    Node* head = nullptr;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    int k = 2; 
    rotateRight(head, k);
    while(head != nullptr){
       cout<< head->data << " -> ";
       head = head->next;
    }
    return 0;
}
  