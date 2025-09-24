#include "QueueLinkedList.hpp"

bool Queue::isEmpty()
{
    return (rear == nullptr);
}

void Queue::enqueue(int value)
{
    Node *newNode = new Node(); //init new node
    newNode->data = value; //assign value
    newNode->next = nullptr; //next is null

    if(isEmpty()) //if queue is empty, front and rear point to new node
    {
        front = newNode;
        rear = newNode;
    }
    else //else, add new node at the end and update rear
    {
        rear->next = newNode;
        rear = newNode;
    }
    
}

void Queue::dequeue()
{
    if(isEmpty())
    {
       std::cout << "Queue is empty!";
        return;
    }

    std::cout << front->data << ", Dequeued.";

    Node *tempNode = front; //create temporary node
    front = tempNode->next; //move the front

    if(front == nullptr) //if front is null, then update rear to null as well. means this queue is empty
    {
        rear = nullptr;
    }

    delete tempNode; //delete the front

}

int Queue::peek()
{
    if(isEmpty())
    {
       std::cout << "Queue is empty!";
        return -1;
    }

    return front->data; //peek at the front of the queue
}

void Queue::print()
{
    if(isEmpty())
    {
        printf("Queue is Empty, nothing to print");
        return;
    }

    Node *i = front; //set i to iterate
    while (i != nullptr) 
    {
        std::cout << i->data; //print the node at the front
        std::cout << " | ";
        i = i->next; //traverse to the next node until you reach the rear
    }
    std::cout << " <-rear";
    std::cout << std::endl;
}

int main()
{
    Queue q;
    int operation, value;

    std::cout<<"+================================================+\n" << "          Linked-List-Based Queue           \n";
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
