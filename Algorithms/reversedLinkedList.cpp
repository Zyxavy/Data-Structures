#include "../Data-Structures/Linked-List/Singly-Linked-List/SinglyLinkedList.hpp"

void LinkedList::reverseList()
{
    if (!head || !head->next) return;
    tail = head;

    reverseListRecurse(head);
}

void LinkedList::reverseListRecurse(Node* current)
{
    if(current->next == nullptr)
    {
        head = current;
        return;
    }

    reverseListRecurse(current->next);
    current->next->next = current;
    current->next = nullptr;
}

int main(void)
{
    LinkedList list;
    
    // Test the list
    list.pushRear(1);
    list.pushRear(2);
    list.pushRear(3);
    list.pushRear(4);
    
    std::cout << "Original list: ";
    list.printList();
    
    list.reverseList();
    
    std::cout << "Reversed list: ";
    list.printList();
    return 0;
}