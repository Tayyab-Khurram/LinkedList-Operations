#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *link;

    void display(node *head)
    {
        int count = 0;
        node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
            count++;
        }
        cout << "\nTotal Nodes : " << count;
    }

    void add_beg(node **head, int userData)
    {
        node *ptr = new node;
        ptr->data = userData;
        ptr->link = NULL;

        ptr->link = *head;
        *head = ptr;
    }
};

int main()
{
    node *head = new node;
    head->data = 23;
    head->link = NULL;

    node *second = new node;
    second->data = 90;
    second->link = NULL;

    head->link = second;

    head->add_beg(&head, 189);
    head->add_beg(&head, 10);

    head->display(head);
    return 0;
}