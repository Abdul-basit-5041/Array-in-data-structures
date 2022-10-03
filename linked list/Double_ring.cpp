#include <iostream>
using namespace std;
struct node
{
    int info;
    node *next;
    node *prev;
};
class ring
{
private:
    node *head;
    node *temp1;
    node *temp;

public:
    ring()
    {
        head = temp = temp1 = NULL;
    }
    ~ring()
    {
        delete head;
        delete temp1;
        delete temp;
    }
    void insert()
    {
        if (head == NULL)
        {
            head = new node;
            cout << "enter first node" << endl;
            cin >> head->info;
            head->next = head;
            head->prev = head;
            return;
        }
        cout << "after what? ";
        int key;
        cin >> key;
        temp = head;
        do
        {
            if (temp->info == key)
            {
                temp1 = new node;
                cout << "enter the value ";
                cin >> temp1->info;
                temp1->next = temp->next;
                temp->next = temp1;
                temp1->prev = temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
    void remove()
    {
        if (head == NULL)
        {
            cout << "the list is empty!" << endl;
            return;
        }
        cout << "at what position? ";
        int key;
        cin >> key;
        temp = head;
        if (head->info == key)
        {
            head = temp->next;
            head->prev = temp->prev;
            delete temp;
            temp = NULL;
            return;
        }
        while (temp->next != head)
        {
            if (temp->next->info == key)
            {
                temp1 = temp->next;
                temp->next = temp1->next;
                head->prev = temp1->next;
                delete temp1;
                temp1 = NULL;
                return;
            }
            temp = temp->next;
        }
    }
    void print()
    {
        if (head == NULL)
        {
            cout << "the list is empty" << endl;
            return;
        }
        temp = head;
        do
        {
            cout << temp->info << "-->";
            temp = temp->next;
        } while (temp != head);
    }
};
int main()
{
    ring l1;
    l1.insert();
    l1.insert();
    l1.insert();
    l1.print();
    l1.remove();
    l1.print();
    return 0;
}