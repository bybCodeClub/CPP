#include <iostream>
using namespace std;

// node definition
 struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 // sorts a singly linked list..
 ListNode *insertSort(ListNode* head){
     ListNode *dummy = new ListNode(0); 
     ListNode *cur = head;
     while(cur){
         ListNode *temp = cur->next;
         ListNode *prev = dummy;
         ListNode *nxt = dummy->next;
         while(nxt){
            if(nxt->val > cur->val) break;
            prev = nxt;
            nxt = nxt->next;
         }
         cur->next = nxt;
         prev->next = cur;
         cur = temp;
     }
    return dummy->next;
 }
//test
 int main() {
// Input: -1->5->3->4->0
ListNode *t = new ListNode(-1);
t->next = new ListNode(5);
t->next->next = new ListNode(3);
t->next->next->next = new ListNode(4);
t->next->next->next->next = new ListNode(0);

//Output: -1->0->3->4->5
ListNode *ans = insertSort(t);
while(ans){
    cout << ans->val << " ";
    ans = ans->next;
}
     return 0;
 }