#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoubleList
{
private:
    Node *head;
    Node *tail;

public:
    DoubleList() : head(nullptr), tail(nullptr) {}

    void append(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void prepend(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }

        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    void show()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    DoubleList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    list.show();

    list.prepend(-1);
    list.prepend(-2);

    list.show();

    list.pop_back();
    list.pop_front();

    list.show();

    return 0;
}