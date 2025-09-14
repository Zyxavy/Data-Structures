#ifndef STACK_LINKED_HPP
#define STACK_LINKED_HPP

struct Node // Node structure for linked list
{
    int data;
    Node* next;
};


class Stack
{
    private:
        Node* top; // Pointer to the top of the stack
        

    public: 
    Stack()
    {
        top = nullptr; // Initialize top to nullptr
    }

    //methods
    void push(int value); // Push an element onto the stack
    void pop(); // Pop an element from the stack
    int peek(); // Peek at the top element of the stack
    bool isEmpty(); // Check if the stack is empty
    void print(); // Print the stack contents

};


#endif // STACK_LINKED_HPP