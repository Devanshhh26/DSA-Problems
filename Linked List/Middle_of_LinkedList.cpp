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

int middleNode(Node* head)
{   
    if(head==NULL)
    {
        return 0;
    }
    if(head->next==NULL)
    {
        cout<<head;
        return 0;
    }
    Node *fast=head;
    Node *slow=head;
    while(fast!=NULL&& fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}

int main()
{
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);
    Node* sixth=new Node(60);
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=NULL;
    cout<<"Middle Node is: "<<middleNode(head)<<endl;
return 0;

}