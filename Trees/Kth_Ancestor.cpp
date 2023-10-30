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

bool KthAncestor(Node*root,int& k,int p)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==p)
    {
        return true;
    }
    
    bool leftAns=KthAncestor(root->left,k,p);
    bool rightAns=KthAncestor(root->right,k,p);

    if(leftAns||rightAns)
    {
        k--;
    }
    if(k==0)
    {
        cout<<"Kth Ancestor is: "<<root->data;
        k=-1;
    }
    return leftAns||rightAns;
}

int main()
{
    Node*root=NULL;
    root=buildTree();
    int k=2;
    bool ans=KthAncestor(root,k,4);

    return 0;
}
