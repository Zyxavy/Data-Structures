#include <iostream>
#include "StackLinked.hpp"

bool Stack::isEmpty()
{
    return(top == nullptr); //return if stack is empty
}

void Stack::push(int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value; // Set the data
    newNode->next = top; // Link the new node to the previous top
    top = newNode; // Update top to the new node

}

void Stack::pop()
{
    if(isEmpty())
    {
        std::cout << "Stack is Empty!"; // Handle empty stack case
    }
    else
    {
        std::cout << "Value: " << peek() << " Poped from stack";
        Node* temp = top; // Temporary pointer to the top node
        top = top->next; // Update top to the next node
        delete temp; // Delete the old top node
    }
}

int Stack::peek()
{
    if(isEmpty())
    {
        std::cout << "Nothing to Peek, Stack is Empty! "; // Handle empty stack case
        return -1;
    }
    else
    {
        return top->data; // Return the data of the top node
    }
}

void Stack::print()
{
    if(isEmpty())
    {
        std::cout << "Stack is Empty!";
        return;
    }

    Node* index = top;
    do
    {
        std::cout << index->data << std::endl;
        index = index->next;
    } while (index != nullptr);
    
}

int main()
{
    Stack s;
    int operation, value;

    std::cout<<"+================================================+\n" << "          Linked-list-Based Stack           \n";
    std::cout<<"A stack has been created\n\n";

    while(true)
    {
        
        std::cout<<"\n\n1. Push to stack\n2. Pop the top value\n3. Peek the top value\n4. Print the stack\n5. Exit\n\n>> ";
        std::cin >> operation;

        switch (operation)
        {
        case 1:
            std::cout << "Enter a value(int): ";
            std::cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            std::cout << "Peeked at: " << s.peek();
            break;
        case 4:
            s.print();
            break;
        case 5:
            exit(0);
            break;
        
        default:
            break;
        }
    }
    return 0;
}