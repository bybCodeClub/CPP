#include <iostream>
#include <string>
#include "stackClass1.cpp"

int main() {
    Stack<int, 20> int20Stack;
    Stack<std::string, 40> string40Stack;

    int20Stack.push(12);    
    int20Stack.push(11);
    auto size1 = int20Stack.size();
    std::cout << "The size is " << size1 << " and the top is " << int20Stack.top() << std::endl;

    return 0;
}