
//  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node* buildTree()
{
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    Node*root=new Node(data);

    cout<<"Enter data for left node "<<data<<"Node "<<endl;
    root->left=buildTree();
    cout<<"Enter data for right node "<<data<<"Node "<<endl;
    root->right=buildTree();
    return root;
}

Node* lowestCommonAncestor(Node* root, Node* p,Node* q) {
        // base case
        if(root==NULL)
        {
            return NULL;
        }
        //check for p and q
        if(root->data==p->data)
        {
            return p;
        }
        if(root->data==q->data)
        {
            return q;
        }
        Node* leftAns=lowestCommonAncestor(root->left,p,q);
        Node* rightAns=lowestCommonAncestor(root->right,p,q);

        if(leftAns==NULL && rightAns==NULL)
        {
            return NULL;
        }
        else if(leftAns!=NULL && rightAns==NULL)
        {
            return leftAns;
        }
        else if(leftAns==NULL && rightAns!=NULL)
        {
            return rightAns;
        }
        else
        {
            return root;
        }

    }
    int main()
{
    Node*root=NULL;
    root=buildTree();
    Node*q;
    Node*p;
    Node*ans=lowestCommonAncestor(root,p,q);
    cout<<ans;
    return 0;
}
