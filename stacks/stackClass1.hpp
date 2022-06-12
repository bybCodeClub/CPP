#ifndef STACK_HPP
#define STACK_HPP

#include <array>
#include <cassert>

template<typename T, auto Maxsize>
class Stack {
    public:
        using size_type = decltype(Maxsize);
    private:
        std::array<T, Maxsize> elems;
        size_type numElems;
    public: 
        Stack(); // constructor
        void push(T const & elem); // push element
        void pop();
        T const& top() const;
        bool empty() const {    // return if statcks empty or not
            return numElems == 0;
        }
        size_type size() const {
            return numElems;
        }
};

#endif