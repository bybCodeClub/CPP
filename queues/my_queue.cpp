#include <iostream>
#include <vector>
using namespace std;

class myQ {     // implementation #1) Not the best approach
private:
    vector<int> data;   // stores elements
    int p; // pointer tracks front.
public:
    myQ(){ p = 0; }

    // Insert an element into the queue. Return true if the operation is successful. 
    bool enQ(int e){
        data.push_back(e);
        return true;
    }
    //Delete an element from the queue. Return true if the operation is successful. 
bool dQ(){
    if(empty())
        return false;
    p++;
        return true; 
}
    // Get the front item from the queue. 
int front(){
    return data[p];
}
    // Checks whether the queue is empty or not. 
bool empty(){
    return p >= data.size();
}

};

int main() {
 myQ q;
    q.enQ(5);
    q.enQ(3);
    if (!q.empty()) {
        cout << q.front() << endl;
    }
    q.dQ();
    if (!q.empty()) {
        cout << q.front() << endl;
    }
    q.dQ();
    if( !q.empty()) {
        cout << q.front() << endl;
    }else{
        cout << "empty\n";
    }
    return 0;
}