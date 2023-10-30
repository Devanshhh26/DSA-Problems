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

Node* reverse(Node* head)                           // reversing the LL
{
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=curr->next;
    while(curr!=NULL)
    {   
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool checkPalindrome(Node* head)
{
    if(head==NULL)
    {   
        cout<<"LL is empty";
        return true;
    }
    if(head->next==NULL)
    {
        cout<<"Palindrome";
        return true;
    }

    Node* slow=head;
    Node* fast=head;

    // step1

    while(fast!=NULL&&fast->next!=NULL)                 // find middle node
    {
        fast=fast->next->next;
        slow=slow->next;
    }

    // Step 2
    
    //slow pointer is pointing to the middle node

    Node* reverseLLHead=reverse(slow->next);            // reversing the LL after the middle element
    
    //join the reversed LL into the left part
    slow->next=reverseLLHead;
    Node * temp1=head;
    Node * temp2=reverseLLHead;

    // Step 3

    while(temp2!=NULL)                                  // comparing 1st half and the 2nd half i.e reversed to check if palindrome
    {
        if(temp1->data!=temp2->data)
        {
            return false;
        }
        else{
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true; 

}

int main()
{
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(30);
    Node* fifth=new Node(20);
    Node* sixth=new Node(10);
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=NULL;
    bool isPlaindrome=checkPalindrome(head);
    if(isPlaindrome)
    {
        cout<<"Valid Palindrome";
    }
    else{
        cout<<"Not a Palindrome";
    }    
return 0;

}