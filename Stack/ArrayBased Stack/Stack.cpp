#include <iostream>
#include "Stack.hpp"

bool Stack::isEmpty()
{
    return (top == -1); //returns true is stack is empty
}

bool Stack::isFull()
{
    return (top == MAX - 1); //returns true if stack is full
}

void Stack::push(int value)
{
    if(isFull()) //check if stack is full
    {
        std::cout << "Stack is Full";
    }
    else 
    {
        top++; //increment top;
        arr[top] = value; //store value;
    }
}

void Stack::pop()
{
    if(isEmpty()) //check if stack is empty
    {
        std::cout << "Stack is Empty";
    }
    else
    {
        top--; //remove the top value
    }
}

int Stack::peek()
{
    if(isEmpty())
    {
        std::cout << "Stack is Empty";
        return -1; // returns an error code
    }
    else 
    {
        return arr[top]; //returns the top-most value
    }
}

void Stack::print()
{
    if(isEmpty()) // check if empty
    {
        std::cout << "Stack is empty!";
        return;
    }

    int index = top;
    do
    {
        std::cout << arr[index] << "\n"; //print all value from top to bottom
        index--;
    } while(index != -1);
}


int main()
{
    Stack s;
    int operation, value;

    std::cout<<"+================================================+\n" << "          Array-Based Stack           \n";
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
            std::cout << "Value: " << s.peek() << " Poped from stack";
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
}