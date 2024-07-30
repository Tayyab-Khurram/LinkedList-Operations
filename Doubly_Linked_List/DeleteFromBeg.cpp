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

    node *delete_first(node *head)
    {
        node *ptr = head;
        head = head->rlink;
        head->llink = NULL;
        delete ptr;
        ptr = NULL;
        cout << "\nFirst Node deleted!" << endl;
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
    cout <<"Do you want to delete the first node? [y/n]" << endl;
    cin >> user;

    if(user == 'y' || user == 'Y')
    {
        head = head->delete_first(head);
        head->display(head);
    }
    else
        head->display(head);
    return 0;
}