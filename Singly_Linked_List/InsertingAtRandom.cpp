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

    void add_at_random(node *head, int userData, int pos)
    {
        node *newnode = new node;
        newnode->data = userData;
        newnode->link = NULL;

        node *alias = head;
        for (int i = 1; i < pos - 1; i++)
        {
            alias = alias->link;
        }
        newnode->link = alias->link;
        alias->link = newnode;
        cout << "\nNew node with data " << newnode->data << " inserted at " << pos << "th position!" << endl;
    }
};

int main()
{
    char choice;

    node *head = new node;
    head->data = 18;
    head->link = NULL;
    cout << "One node already exists with data " << head->data << endl;

    node *temp = head;

    while (1)
    {
        cout << "Do you want to add a new node [y/n]" << endl;
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            node *second = new node;
            cout << "Enter the data : ";
            cin >> second->data;
            second->link = NULL;

            temp->link = second;
            temp = second;
        }
        else
        {
            break;
        }
    }

    int position, userData;
    cout << "Enter the position to add data in the list : ";
    cin >> position;
    cout << "Enter the data to add there : ";
    cin >> userData;

    head->add_at_random(head, userData, position);
    temp->display(head);
    return 0;
}