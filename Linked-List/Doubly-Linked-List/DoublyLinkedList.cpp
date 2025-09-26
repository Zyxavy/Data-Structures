#include "DoublyLinkedList.hpp"

bool DoublyList::isEmpty() const
{
    return head == nullptr;
}

void DoublyList::printForward() const
{
    if(isEmpty())
    {
        std::cout << "List is Empty!" << std::endl;
        return;
    }

    Node* current = head;
    while(current) // Traverse until the end of the list
    {
        std::cout << current->data;
        if(current->next)   std::cout << " <->";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoublyList::printBackward() const 
{
    if(isEmpty())
    {
        std::cout << "List is Empty!" << std::endl;
        return;
    }

    Node* current = tail;
    while(current) // Traverse until the start of the list
    {
        std::cout << current->data;
        if(current->prev)   std::cout << " <->";
        current = current->prev;
    }
    std::cout << std::endl;
}

void DoublyList::pushHead(int value)
{
    Node* newNode = new Node(value);

    if(isEmpty()) //If the list is empty, set both head and tail to the new node
    {
        head = newNode;
        tail = newNode;
    }
    else //If the list is not empty, adjust pointers
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    std::cout << value << " Added to head!\n";
}

void DoublyList::pushTail(int value)
{
    Node* newNode = new Node(value);

    if(isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else //Same with pushHead
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    std::cout << value << " Added to tail!\n";
}

void DoublyList::insertAfter(Node *node, int value)
{
    if(isEmpty())
    {
        std::cout << "List is Empty!";
        return;
    }

    if(node == nullptr) //If the given node is null
    {
        std::cout << "Node does not exist";
    }

    if(node == tail) //if given node is tail, just push to tail
    {
        pushTail(value);
        return;
    }

    Node *newNode = new Node(value);

    //update nodes
    newNode->next = node->next;  
    newNode->prev = node;        

    node->next->prev = newNode;  // fix back link of original next
    node->next = newNode;       
}

void DoublyList::popHead()
{
    if(isEmpty())
    {
        std::cout << "Nothing to delete\n";
        return;
    }

    Node *temp = head;
    if(head == tail)
    {
        head = tail = nullptr; //if there is only one node
    } 
    else
    {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
}

void DoublyList::popTail()
{
    if(isEmpty())
    {
        std::cout << "Nothing to delete\n";
        return;
    }

    Node *temp = tail;
    if(head == tail)
    {
        head = tail = nullptr; //if there is only one node
    } 
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
}

bool DoublyList::deleteValue(int value)
{
    if(isEmpty())
    {
        std::cout << "Nothing to delete\n";
        return false;
    }

    if (head->data == value) //If the value is at the head
    {
        popHead();
        return true;
    }
    else if (tail->data == value) //If the value is at the tail
    {
        popTail();
        return true;
    }

    Node* current = head->next;
    while(current != nullptr)
    {
        if(current->data == value) 
        {
            current->prev->next = current->next;//Bypass the current node

            if (current->next)
            { 
                current->next->prev = current->prev;//Fix back link if not tail
            }
            delete current;

            return true;
        }
        current = current->next;
    }

    return false;
}

Node* DoublyList::find(int value)
{
    if(isEmpty())
    {
        std::cout << "list is Empty" << std::endl;
        return nullptr;
    }

    for(Node* current = head; current; current = current->next) //traverse the list
    {
        if(current->data ==  value) return current;
    }
    return nullptr;
}

int main()
{
     DoublyList list;
    int operation, value, target;

    std::cout << "+================================================+\n"
              << "            Doubly Linked List Menu               \n"
              << "        A Doubly Linked List has been created\n\n";

    while (true) {
        std::cout << "\n\n1. Insert at Front"
                  << "\n2. Insert at Rear"
                  << "\n3. Insert After a Value"
                  << "\n4. Delete a Value"
                  << "\n5. Print Forward"
                  << "\n6. Print Backward"
                  << "\n7. Exit"
                  << "\n\n>> ";
        std::cin >> operation;

        switch (operation) {
            case 1:
                std::cout << "Enter a value (int): ";
                std::cin >> value;
                list.pushHead(value);
                break;

            case 2:
                std::cout << "Enter a value (int): ";
                std::cin >> value;
                list.pushTail(value);
                break;

            case 3:
                std::cout << "Insert after which value? ";
                std::cin >> target;
                if (Node* node = list.find(target)) {
                    std::cout << "Enter new value: ";
                    std::cin >> value;
                    list.insertAfter(node, value);
                } else {
                    std::cout << "Value " << target << " not found in the list.\n";
                }
                break;

            case 4:
                std::cout << "Enter a value to delete: ";
                std::cin >> value;
                if (list.deleteValue(value))
                    std::cout << value << " deleted from the list.\n";
                else
                    std::cout << value << " not found in the list.\n";
                break;

            case 5:
                list.printForward();
                break;

            case 6:
                list.printBackward();
                break;

            case 7:
                std::cout << "Exiting...\n";
                return 0;

            default:
                std::cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}