#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <iostream>

class Node 
{
    public:
        int data;
        Node *prev;
        Node *next;
    
        Node(int value): data(value), prev(nullptr), next(nullptr) {} //Constructor to initialize a node with a value

};

class DoublyList
{
    private:
        Node *head;
        Node *tail;
    
    public:
        DoublyList() //Constructor to initialize an empty list
        {
            head = nullptr;
            tail = nullptr;
        }

        ~DoublyList() //Destructor to clean up the list
        {
            Node* current = head;
            while (current) //Traverse the list and delete each node
            {
                Node* temp = current;
                current = current->next;
                delete temp;
            }

            head = tail = nullptr;
        }


        //Methods
        bool isEmpty() const;
        void pushHead(int value);
        void pushTail(int value);
        void insertAfter(Node* node, int value);
        void printForward() const;
        void printBackward() const;
        void popHead();
        void popTail();
        bool deleteValue(int value);
        Node* find(int value);


};


#endif //DOUBLY_LINKED_LIST_HPP