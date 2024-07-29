#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *llink;
    node *rlink;
    node()
    {
        data = 0;
        llink = rlink = NULL;
    }

    void add_end(node *head, int userData)
    {
        node *t = head;

        node *newnode = new node;
        newnode->data = userData;
        newnode->llink = NULL;
        newnode->rlink = NULL;

        while (t->rlink != NULL)
            t = t->rlink;

        t->rlink = newnode;
        newnode->llink = t;
    }

    void display(node *head)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->rlink;
        }
        cout << endl;
    }
};

int main()
{
    char choice;
    node *head = new node;
    cout << "Enter data for the first node : ";
    cin >> head->data;
    head->llink = NULL;
    head->rlink = NULL;

    node *alias = head; // kyuon kay hum nay head ko move nahi karwaana

    while (1)
    {
        cout << "Do you want to create another node? [y/n]" << endl;
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            node *second = new node;
            cout << "Enter the data : ";
            cin >> second->data;
            second->llink = NULL;
            second->rlink = NULL;

            alias->rlink = second;
            second->llink = alias;
            alias = second;
        }
        else
        {
            break;
        }
    }

    int userData;
    cout << "Enter the data to add at the end : ";
    cin >> userData;

    head->add_end(head, userData);
    head->display(head);
    return 0;
}