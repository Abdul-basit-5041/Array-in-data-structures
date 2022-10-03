// Stack Implementation

#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int *top;
    int len;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        len = 0;
        arr = new int[capacity];
        top = arr - 1;
    }
    ~Stack()
    {
        delete[] arr;
    }
    void push(int x)
    {
        if (!isFull())
        {
            ++top;
            *top = x;
            len++;
        }
        else
        {
            cout << "OverFlow!" << endl;
        }
    }
    void pop()
    {
        if (!isEmpty())
        {
            cout << "Removing--> " << *top << endl;
            --top;
            len--;
        }
        else
        {
            cout << "UnderFlow!" << endl;
        }
    }
    int *peek()
    {
        cout << "TOP: " << *top << endl;
        return top;
    }
    int size()
    {
        cout << "Lenght: " << len << endl;
        return len;
    }
    bool isEmpty()
    {
        if (len == 0)
        {
            cout << "Stack is Empty! ";
            return true;
        }
        else
            return false;
    }
    bool isFull()
    {
        if (len == capacity)
        {
            cout << "Stack is Full! ";
            return true;
        }
        else
            return false;
    }
};

int main()
{
    Stack s(5);
    s.size();
    s.pop();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);
    s.pop();
    s.push(4);
    s.peek();
    s.size();
    s.push(5);
    s.push(6);
}
