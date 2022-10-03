
#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

class Stack
{
private:
    Node *top;
    Node *t;
    int len;
    int capacity;

public:
    Stack(int s)
    {
        top = t = NULL;
        len = 0;
        capacity = s;
    }
    ~Stack()
    {
        delete top;
        delete t;
    }
    void push();
    void pop();
    void peek();
    void size();
    bool isEmp();
    bool isFull();
    void print();
};

void Stack::push()
{
    if (!isFull())
    {
        if (top == NULL)
        {
            top = new Node;
            cout << "Push- ";
            cin >> top->info;
            top->next = NULL;
            len++;
            return;
        }
        t = new Node;
        cout << "Push- ";
        cin >> t->info;
        t->next = top;
        top = t;
        len++;
    }
    return;
}
void Stack::pop()
{
    if (!isEmp())
    {
        t = top;
        cout << "Removing top info: " << t->info << endl;
        top = top->next;
        t = NULL;
        delete t;
        len--;
    }
    return;
}
void Stack::peek()
{
    cout << "TOP: " << top->info << endl;
    return;
}
void Stack::size()
{
    cout << "Len: " << len << endl;
    return;
}
bool Stack::isEmp()
{
    if (top == NULL)
    {
        cout << "Undeflow!" << endl;
        return true;
    }
    else
        return false;
}
bool Stack::isFull()
{
    if (len >= capacity)
    {
        cout << "Stack Capacity Full!" << endl;
        return true;
    }
    else
        return false;
}
void Stack::print()
{
    cout << "Stack:" << endl;
    t = top;
    while (t != NULL)
    {
        cout << t->info << " -> ";
        t = t->next;
    }
    return;
}

int main()
{
    Stack s(5);
    int c;
    do
    {
        cout << "Chose! 1.Push  2.Pop  3.Peek  4.Print  5.Lenght  ";
        cin >> c;
        switch (c)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.print();
            break;
        case 5:
            s.size();
            break;
        }
    } while (c != 6);
}
