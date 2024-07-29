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

    void delete_from_end(node *head)
    {
        node *t = head;
        node *p = head;
        while (t->link!=NULL)
        {
            p = t;
            t = t->link;
        }

        p->link = NULL;
        delete t;
        t= NULL;
        cout <<"\nLast node deleted!"<<endl;
    }
};

int main()
{
    char choice;

    node *head = new node;
    cout << "Enter data for the first node : ";
    cin >> head->data;
    head->link = NULL;

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

    head->delete_from_end(head);
    head->display(head);
    return 0;
}