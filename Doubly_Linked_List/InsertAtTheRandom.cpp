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

    void add_random(node *head, int userData, int pos)
    {
        node *t = head;
        node *newnode = new node;
        newnode->data = userData;
        newnode->llink = NULL;
        newnode->rlink = NULL;

        for (int i = 1; i < pos - 1; i++)
            t = t->rlink;

        newnode->rlink = t->rlink;
        t->rlink->llink = newnode;
        newnode->llink = t;
        t->rlink = newnode;
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

    int pos, userData;
    cout << "Enter the postion to add new data : ";
    cin >> pos;
    cout << "Enter the data to add at " << pos << " position : ";
    cin >> userData;

    head->add_random(head, userData, pos);
    head->display(head);
    return 0;
}