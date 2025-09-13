#ifndef STACKS_HPP
#define STACKS_HPP

#define MAX 100 //max amount of values

class Stack {
    private:
        int arr[MAX];
        int top;

    public:
        Stack() 
        {
            top = -1; // initialize with no values
        }

        //methods
        void push(int value); // push unto stack
        void pop(); //pop the top of stack
        int peek(); //check top value
        bool isEmpty(); //check if stack is empty
        bool isFull(); //check if full
};

#endif