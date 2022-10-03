#include <iostream>
using namespace std;
struct node
{
    int info;
    node *next;
};
class ring
{
private:
    node *head;
    node *temp;
    node *temp1;

public:
    ring()
    {
        head = temp = temp1 = NULL;
    }
    ~ring()
    {
        delete head;
        delete temp;
        delete temp1;
    }
    void insert()
    {
        if (head == NULL)
        {
            head = new node;
            cout << "enter first info" << endl;
            cin >> head->info;
            head->next = head;
            return;
        }
        temp = head;
        cout << "insert after: ";
        int key;
        cin >> key;
        do
        {
            if (temp->info == key)
            {
                temp1 = new node;
                cout << "enter value" << endl;
                cin >> temp1->info;
                temp1->next = temp->next;
                temp->next = temp1;
                return;
            }
            temp = temp->next;
        } while (temp != head);
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
        cout << endl;
    }
    void remove()
    {
        if (head == NULL)
        {
            cout << "khan link list chy da kam agha khali da ";
            return;
        }
        temp = head;
        cout << "kam zi na value akhwa kam: ";
        int key;
        cin >> key;
        if (head->info == key)
        {
            head = temp->next;
            temp = NULL;
            delete temp;
            return;
        }
        do
        {
            if (temp->next->info == key)
            {
                temp1 = temp->next;
                temp->next = temp1->next;
                temp1 = NULL;
                delete temp1;
                return;
            }
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
    l1.insert();
    l1.print();
    l1.remove();
    // l1.remove1(1);
    l1.print();

    return 0;
}