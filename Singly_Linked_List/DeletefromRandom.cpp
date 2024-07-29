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

    void delete_from_random(node *head, int pos)
    {
        node *alias = head;
        node *ptr = head;
        for (int i = 1; i < pos; i++)
        {
            ptr = alias;
            alias = alias->link;
        }
        ptr->link = alias->link;
        delete alias;
        cout << "Node at " << pos << "th position deleted!" << endl;
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

    int position;
    cout << "\nEnter the position to delete data : ";
    cin >> position;

    head->delete_from_random(head, position);
    head->display(head);
    return 0;
}