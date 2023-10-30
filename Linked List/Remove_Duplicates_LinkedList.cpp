#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};



int main()
{
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(40);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);
    Node* sixth=new Node(60);
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=NULL;
    
    Node* curr=head;
    Node *temp=head->next;
    
    while(temp!=NULL)
    {
        if(curr->data==temp->data)
        {
            temp=temp->next;
        }
        else{
            curr->next=temp;
            temp=temp->next;
            curr=curr->next;
        }
    }
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }


return 0;

}