#include <iostream>
using namespace std;

class Queue
{
private:
    int *ar;
    int *front;
    int *rear;
    int len;
    int cap;

public:
    Queue(int size)
    {
        cap = size;
        ar = new int[cap];
        front = rear = NULL;
        len = 0;
    }
    ~Queue()
    {
        delete[] ar;
    }
    void Enqueue(int x)
    {
        if (!isFull())
        {
            if (front == NULL)
            {
                rear = front = ar;
                *rear = x;
                ++rear;
                len++;
                return;
            }
            *rear = x;
            ++rear;
            len++;
            return;
        }
        return;
    }
    void Dequeue()
    {
        if (!isEmpty())
        {
            int *p = front + 1;
            for (int i = 0; i < len - 1; i++)
            {
                *(front + i) = *(p + i);
            }
            len--;
            return;
        }
        return;
    }
    bool isEmpty()
    {
        if (len <= 0)
        {
            cout << "Queue is Empty!" << endl;
            return true;
        }
        else
            return false;
    }
    bool isFull()
    {
        if (len >= cap)
        {
            cout << "Queue is Full!" << endl;
            return true;
        }
        else
            return false;
    }
    void print()
    {
        int *print = ar;
        cout << "Front  ";
        for (int i = 0; i < len; i++)
        {
            cout << *print++ << "<-";
        }
        cout << "  Rear" << endl;
        return;
    }
};

int main()
{
    Queue q(5);
    int c;
    do
    {
        cout << "1.Enqueue  2.Dequeue  3.Print  4.Exit!   ";
        cin >> c;
        switch (c)
        {
        case 1:
            int val;
            cout << "Enter Value: ";
            cin >> val;
            q.Enqueue(val);
            break;
        case 2:
            q.Dequeue();
            break;
        case 3:
            q.print();
            break;
        }
    } while (c != 4);
}
