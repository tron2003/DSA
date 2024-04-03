#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Added random pointer
    Node(int d) : data(d), next(nullptr) {} // Constructor initialization list
};

Node *func(Node *h1, Node *h2)
{

    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }
    Node *head = NULL;
    Node *tail = NULL;
    if (h1->data <= h2->data)
    {

        head = tail = h1;
        h1 = h1->next;
    }
    else
    {
        head = tail = h2;
        h2 = h2->next;
    }
    while (h1 != NULL && h2 != NULL)
    {

        if (h1->data <= h2->data)
        {

            tail->next = h1;
            tail = tail->next;
            h1 = h1->next;
        }
        else
        {
            tail->next = h2;
            tail = tail->next;
            h2 = h2->next;
        }
    }
    if (h1 == NULL)
    {
        tail->next = h2;
    }
    else
    {
        tail->next = h1;
    }

    return head;
}


  int main()
{
    Node *head = new Node(12);
    Node *temp = new Node(131);
    head->next = temp;
    Node *temp1 = new Node(230);
    head->next->next = temp1;
   

    Node *head2 = new Node(32);
    Node *temp2 = new Node(230); // Separate node for temp1
    head2->next = temp2;
    Node *head3 = new Node(23);
    head3->next = new Node(834249);

    Node *res = func(head, head3);
    while (res != NULL)
    {
        cout << (res->data) << " ";
        res = res->next;
    }



    return 0;
}
