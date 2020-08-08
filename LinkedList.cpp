#include <bits/stdc++.h>
#define pb push_back
using namespace std;
class Linkedlist
{
private:
    struct node
    {
        int data;
        struct node *next;
    };
    node *head;
public:
    Linkedlist()
    {
        head = NULL;
    }
    void AppendLinkedList(int x)
    {
        struct node *cur = head;
        if (head == NULL)
        {
            node *new_node;
            new_node = new node;
            new_node->data = x;
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            while (cur->next != NULL)
            {
                cur = cur->next;
            }

            node *new_node;
            new_node = new node;
            new_node->data = x;
            new_node->next = NULL;
            cur->next = new_node;
        }
    }
    void displayLinkedList()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty" << "\n";
            return;
        }

        node *cur = head;
        while (cur != NULL)
        {
            cout << cur->data << "\n";
            cur = cur->next;
        }
        cout << "\n";
    }
    void deleteLinkedList(int x)
    {
        if (head == NULL)
        {
            cout << "Linked list is empty" << "\n";
            return;
        }

        node *cur = head;
        node *prev;
        while (cur != NULL)
        {
            if (cur->data == x && cur == head)
            {
                head = head->next;
                delete cur;
                return;
            }
            else if (cur->data == x)
            {
                prev->next = cur->next;
                delete cur;
                return;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }

        cout << "The given data is not present in linked list" << "\n";
    }
    void ReverseLinkedList()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty" << "\n";
            return;
        }

        node *cur = head;
        node *prev = NULL;
        node *next_ptr = NULL;
        while (cur != NULL)
        {
            next_ptr = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next_ptr;
        }
        head = prev;
    }
};
int main() {
    Linkedlist lobj;
    lobj.displayLinkedList();
    lobj.AppendLinkedList(1);
    lobj.AppendLinkedList(2);
    lobj.AppendLinkedList(5);
    lobj.AppendLinkedList(4);
    lobj.displayLinkedList();
    lobj.deleteLinkedList(2);
    lobj.displayLinkedList();
    lobj.ReverseLinkedList();
    lobj.displayLinkedList();
    return 0;
}
