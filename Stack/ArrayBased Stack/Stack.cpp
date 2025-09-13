#include <iostream>
#include "Stack.hpp"

int main()
{
    
}

bool Stack::isEmpty()
{
    return (top == -1);
}

bool Stack::isFull()
{
    return (top == MAX - 1);
}