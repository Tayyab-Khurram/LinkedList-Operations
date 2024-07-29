#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *link;

    void display(node *kuch)
    {
        if (kuch == NULL)
            cout << "Linked list is empty!";

        int count = 0;
        node *temp = kuch;
        while (temp != NULL)
        {
            count++;
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << "\nTotal Nodes : " << count;
    }

    void add_node_at_the_end(node *head, int userData)
    {
        node *newnode = new node;
        newnode->data = userData;
        newnode->link = NULL;

        node *temp = head;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
};

int main()
{
    node *head = new node;
    head->data = 23;
    head->link = NULL;

    head->add_node_at_the_end(head, 19);
    head->add_node_at_the_end(head, 83);

    head->display(head);
    return 0;
}