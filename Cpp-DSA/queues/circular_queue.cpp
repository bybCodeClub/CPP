#include <iostream>
#include <vector>

class circularQ {

private:
std::vector<int> data;
int head, tail, N;

public:
circularQ(int x){
    data.resize(x);
    head = -1;
    tail = -1;
    N = x;
}

// enQ
bool enQ(int x) {
    if(full())
        return false;
    if(empty())
        head = 0;
    
    tail = (tail +1) % N;
    data[tail] = x;
    return true;
}

// dQ
bool dQ() {
    if(empty())
        return false;
    if(head == tail){
        head = -1;
        tail = -1;
        return true;
    }
    head = (head +1)%N;
    return true;
}

// get front
int front(){
    if(empty())
        return -1;
    return data[head];
}
// get back
int back(){
    if(empty())
        return -1;
    return data[tail];
}
// is full
bool full(){
   return ((tail + 1) % N) == head;
}
// is empty
bool empty() {
    return head == -1;
}
};

// the first 1 simply shows initial function call. After that each 1 on the right side correseponds to the value below it to the left. 
// ie read the output in a zig zag after the first 1.
int main() {
circularQ *queue = new circularQ(5);
std::cout << "back \n";
for(int i = 0; i < 5; i++){
std::cout << queue->enQ(i) << std::endl;
std::cout << queue->back() << " ";
}

std::cout << "\nfront\n";
for(int i = 0; i < 5; i++){
std::cout << queue->dQ() << std::endl;
std::cout << queue->front() << " ";
}
    return 0;
}