#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d) : data(d), next(nullptr) {} 
};

Node* reverselist(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // Previous will be the new head of the reversed list
}

bool func(Node *h1)
{
    Node *head = h1;
    Node *tail = h1;
    while(tail->next && tail->next->next){
        head = head->next;
        tail = tail->next->next;
    }
    Node *rev = reverselist(head->next);
    Node *curr = h1;
    while(rev != nullptr) {
        if(curr->data != rev->data){
            return false;
        }
        curr = curr->next;
        rev = rev->next;
    }
    return true;
}


int main()
{
    Node *head = new Node(12);
    Node *temp = new Node(12121);
    head->next = temp;
    Node *temp1 = new Node(12);
    head->next->next = temp1;

    
 
    bool res = func(head);
    if (res)
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;

    return 0;
}
