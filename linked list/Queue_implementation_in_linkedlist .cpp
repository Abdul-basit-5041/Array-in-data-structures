#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
class Queue
{
private:
    node *front;
    node *rear;
    node *t;
    int len;
    int cap;

public:
    Queue(int size)
    {
        front = rear = t = NULL;
        cap = size;
        len = 0;
    }
    ~Queue()
    {
        delete front;
        delete rear;
        delete t;
    }
    void enqueue();
    void dequeue();
    void print();
};

void Queue::enqueue()
{
    if (rear == NULL)
    {
        rear = new node;
        cout << "Enter Value: ";
        cin >> rear->data;
        rear->next = NULL;
        front = rear;
        len++;
        return;
    }
    if (len < cap)
    {
        rear->next = new node;
        rear = rear->next;
        cout << "Enter Value: ";
        cin >> rear->data;
        rear->next = NULL;
        len++;
        return;
    }
    else
    {
        cout << "OverFlow!" << endl;
        return;
    }
}
void Queue::dequeue()
{
    if (front == NULL)
    {
        cout << "UnderFlow!" << endl;
        return;
    }
    t = front;
    front = front->next;
    t = NULL;
    delete t;
    return;
}

void Queue::print()
{
    cout << "Queue: ";
    t = front;
    cout << "Front  ";
    while (t != NULL)
    {
        cout << t->data << "<-";
        t = t->next;
    }
    cout << "  Rear" << endl;
    return;
}

int main()
{
    Queue q(5);
    int c;
    do
    {
        cout << "1.Enqueue  2.Dequeue  3.Print  ";
        cin >> c;
        switch (c)
        {
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.print();
            break;
        }
    } while (c == 1 || c == 2 || c == 3);
}
