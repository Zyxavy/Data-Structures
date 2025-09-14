#include <iostream>
#include "ArrayQueue.hpp"

bool Queue::isFull()
{
    return(rear + 1) % MAX == front; //return true if queue is  full
}

bool Queue::isEmpty()
{
    return(front == -1); //return true if queue is empty
}

void Queue::enqueue(int value)
{
    if(isFull()) 
    {
        std::cout << "Queue is full! ";
        return;
    }
    else if(isEmpty()) 
    {
        front = rear = 0; 
    }
    else 
    {
        rear = (rear + 1) % MAX; //circular increment
    }
    arr[rear] = value; //add element at the rear
}

int Queue::dequeue()
{
    if(isEmpty()) //check if queue is empty
    {
        std::cout << "Queue is empty! ";
        return -1;
    }

    std::cout << "Dequeued: " <<  arr[front] << std::endl; //print the dequeued element
    int val = arr[front];

    if(front == rear) //queue has only one element
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX; //circular increment
    }
    return val;
}

int Queue::peek()
{
    if(isEmpty())
    {
        std::cout << "Queue is empty! ";
        return -1;
    }
    else
    {
        return arr[front];
    }
}

void Queue::print()
{
    if(isEmpty())
    {
        std::cout << "Queue is empty! ";
        return;
    }

    int i = front;
    while (true)
    {
        std::cout << arr[i];
        if(i == rear) break;
        std::cout << " | ";
        i = (i + 1) % MAX;

    }
    std::cout << " <-rear";
    std::cout << std::endl;
}

int main()
{
    Queue q;
    int operation, value;

    std::cout<<"+================================================+\n" << "          Array-Based Queue           \n";
    std::cout<<"        A Queue has been created\n\n";

    while(true)
    {
        
        std::cout<<"\n\n1. Enqueue\n2. Dequeue\n3. Peek the front value\n4. Print the Queue\n5. Exit\n\n>> ";
        std::cin >> operation;

        switch (operation)
        {
        case 1:
            std::cout << "Enter a value(int): ";
            std::cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            std::cout << "Peeked at: " << q.peek();
            break;
        case 4:
            q.print();
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