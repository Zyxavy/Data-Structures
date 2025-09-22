#ifndef QUEUE_LINKED_LIST_HPP
#define QUEUE_LINKED_LIST_HPP

#include <iostream>

struct Node //Node structure for the  linked list
{
    int data;
    Node* next;
};

class Queue
{
    private:
        Node* front; // pointer to  the front of  the queue
        Node* rear; // ptr to the rear

    public:
        Queue() //initialize pointers to null
        {   
            front = nullptr;
            rear = nullptr;
        }
    
    //methods
    void enqueue(int value);
    void dequeue();
    int peek();
    bool isEmpty();
    void print();
};



#endif // QUEUE_LINKED_LIST