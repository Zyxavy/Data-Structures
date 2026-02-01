#ifndef ARRAY_QUEUE_HPP
#define ARRAY_QUEUE_HPP

#define MAX 100

class Queue
{
    private:
        int arr[MAX];
        int front, rear;
    public:
        Queue()
        {
            front = -1;
            rear = -1;
        }
    
    //Methods
    void enqueue(int value);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    void print();
};

#endif // ARRAY_QUEUE_HPP