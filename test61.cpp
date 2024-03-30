
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

void print(Node *head,int k){
if(head==NULL){
    return ;
}
Node *first =head;
for(int i =0;i<k;i++){
    if(first==NULL){
        return ;
    }
   first=first->next;
}
Node *second = head;
while(first!=NULL){

    first = first->next;
    second = second->next;
}
cout<<second->data;


}

int main()
{
    Node *head = new Node(12);
    Node *temp = new Node(121);
    
    head->next = temp;
   head->next = new Node(230);
   head=head->next;
   head->next = new Node(34);
    // Call the print function to find the 2nd node from the end
    print(head, 2);

    return 0;
}
