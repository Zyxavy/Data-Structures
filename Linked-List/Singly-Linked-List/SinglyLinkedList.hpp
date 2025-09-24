#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>



class Node 
{
    public:
        int data;
        Node *next;
    
        Node(int value) : data(value), next(nullptr) {} //constructor
};

class LinkedList
{
    private:
        Node* head;
        Node* tail;
    public:

        LinkedList() 
        {
        head = nullptr;
        tail = nullptr;
        }
        
        ~LinkedList()
        {
            Node* current = head;
            while (current) // Traverse the list and delete each node
            {
                Node* temp = current;
                current = current->next;
                delete temp;
            }

            head = tail = nullptr;
        } //destructor

        //methods
        bool isEmpty();
        void printList();
        void pushFront(int value);   
        void pushRear(int value);
        Node* find(int value);
        bool deleteValue(int value);
};




#endif //SINGLY_LINKED_LIST