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

int height(Node*root)
{
    if(root==NULL)
    return 0;
    int leftHeight=height(root->left);              // traversing the ;eft of the tree
    int rightHeight=height(root->right);            // traversing the right of the tree
    int ans=max(leftHeight,rightHeight)+1;          // finding the max between left and right
    return ans;
}

int main()
{
    Node*root=NULL;
    root=buildTree();
    int res= height(root);
    cout<<res;
    return 0;
}
