#include "stackClass1.hpp"

// constructor
template<typename T, auto Maxsize>
Stack<T, Maxsize>::Stack()
    : numElems(0)
{
    // nothing to do
}   

template<typename T, auto Maxsize>
void Stack<T, Maxsize>::push(T const& elem){
    assert(numElems < Maxsize);
    elems[numElems] = elem;
    ++numElems;
}

template<typename T, auto Maxsize>
void Stack<T, Maxsize>::pop() {
    assert(!elems.empty());
    --numElems;
}

template<typename T, auto Maxsize> 
T const& Stack<T, Maxsize>::top() const{
    assert(!elems.empty());
    return elems[numElems-1];
}