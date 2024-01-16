#include <iostream>
#include <stack>
using namespace std;

constexpr int STK_MAX = 1000;

class Stack
{
    int _top;
    char buf[STK_MAX];
public:
    stack<char> myStack;
    Stack()
    {
        // code
    }

    void push(char c)
    {
        if (!isFull())
        {
            myStack.push(c);
        }
    }

    bool isEmpty()
    {
        bool isEmpty = myStack.empty();
        if (isEmpty != 0)
        {
            return true;
        }
        return false;
    }

    char pop()
    {
        if (!isEmpty())
        {
            char topChar = myStack.top();
            myStack.pop();
            return topChar;
        }
        return '@';
    }

    char top()
    {
        if (!isEmpty())
        {
            char topChar = myStack.top();
            return topChar;
        }
        return '@';
    }
    
    bool isFull()
    {
        int sizeOfStack = myStack.size();
        if (sizeOfStack >= STK_MAX)
        {
           return true; 
        }
        return false;
    }

};

void push_all(Stack &stk, string line)
{
    for (char c : line)
    {
        stk.push(c);
    }
    
}

void pop_all(Stack &stk)
{
    while (!stk.isEmpty())
    {
        char topChar = stk.top();
        cout << topChar;
        stk.pop();
    } 
} 