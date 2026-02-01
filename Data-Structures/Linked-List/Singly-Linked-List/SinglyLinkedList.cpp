#include "SinglyLinkedList.hpp"

bool LinkedList::isEmpty()
{
    return head == nullptr;
}

void LinkedList::printList()
{
    if(isEmpty())
    {
        std::cout << "No nodes to print!" << std::endl;
        return;
    }
    
    Node *current = head;

  while (current) 
    {
        std::cout << current->data;
        if (current->next) std::cout << " -> "; // Print arrow if not the last node
        current = current->next;
    }
    std::cout << std::endl;
}

void LinkedList::pushFront(int value)
{
    Node *newNode = new Node(value); //create a new node

    if(!head)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head; 
        head = newNode; 
    }

}

void LinkedList::pushRear(int value)
{
    Node* newNode = new Node(value);
    
    if (!head) 
    {
        head = tail = newNode;
    } 
    else 
    {
        tail->next = newNode;
        tail = newNode;
    }
}

Node* LinkedList::find(int value)
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

bool LinkedList::deleteValue(int value)
{
    if (isEmpty()) 
    {
        std::cout << "List is empty" << std::endl;
        return false;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current && current->data != value) // Traverse until we find the value
    {
        prev = current;
        current = current->next;
    }

    if (!current) return false; // value not found

    
    if (!prev) 
    {
        head = current->next; // Deleting the head node
        if (!head) 
        { 
            tail = nullptr;
        }
    } else
    {
        prev->next = current->next; // Bypass the node to be deleted

        if (current == tail) {
            tail = prev;
        }
    }

    delete current;
    return true;
}

// int main()
// {
//     LinkedList list;
//     int operation, value;

//     std::cout << "+================================================+\n"
//               << "            Singly Linked List Menu               \n"
//               << "        A Linked List has been created\n\n";

//     while (true) {
//         std::cout << "\n\n1. Insert at Front"
//                   << "\n2. Insert at Rear"
//                   << "\n3. Delete a Value"
//                   << "\n4. Find a Value"
//                   << "\n5. Print the List"
//                   << "\n6. Exit"
//                   << "\n\n>> ";
//         std::cin >> operation;

//         switch (operation) {
//             case 1:
//                 std::cout << "Enter a value (int): ";
//                 std::cin >> value;
//                 list.pushFront(value);
//                 break;

//             case 2:
//                 std::cout << "Enter a value (int): ";
//                 std::cin >> value;
//                 list.pushRear(value);
//                 break;

//             case 3:
//                 std::cout << "Enter a value to delete: ";
//                 std::cin >> value;
//                 if (list.deleteValue(value))
//                     std::cout << value << " deleted from the list.\n";
//                 else
//                     std::cout << value << " not found in the list.\n";
//                 break;

//             case 4:
//                 std::cout << "Enter a value to find: ";
//                 std::cin >> value;
//                 if (list.find(value))
//                     std::cout << value << " found in the list.\n";
//                 else
//                     std::cout << value << " not found.\n";
//                 break;

//             case 5:
//                 list.printList();
//                 break;

//             case 6:
//                 std::cout << "Exiting...\n";
//                 exit(0);

//             default:
//                 std::cout << "Invalid choice, try again.\n";
//         }
//     }

//     return 0;
// }

//uncomment to test

