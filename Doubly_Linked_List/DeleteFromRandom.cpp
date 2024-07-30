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

    node *delete_random(node *head, int pos)
    {
        node *ptr = head;
        for (int i=1 ; i<pos ; i++)
            ptr = ptr->rlink;

        ptr->llink->rlink = ptr->rlink;
        ptr->rlink->llink = ptr->llink;
        delete ptr;
        ptr = NULL;
        cout << "\nNode at " << pos << "th position deleted!" << endl;
        return head;
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

    char user;
    cout <<"Do you want to delete any node at random? [y/n]" << endl;
    cin >> user;

    if(user == 'y' || user == 'Y')
    {
        int pos;
        cout <<"Enter the position of the node to be deleted : ";
        cin >> pos;
        head = head->delete_random(head, pos);
    }
    else
        head->display(head);
    return 0;
}