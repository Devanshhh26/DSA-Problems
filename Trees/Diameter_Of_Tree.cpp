
// https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    int ans=max(leftHeight,rightHeight)+1;
    return ans;
}

 int diameterOfBinaryTree(Node* root) {
       if(root==NULL)
       {
           return 0;
       }
       int opt1=diameterOfBinaryTree(root->left);                    // if diameter only lies in the left part of the root
       int opt2=diameterOfBinaryTree(root->right);                   // if diameter only lies in the right part of the root
       int opt3=height(root->left)+height(root->right);             // if diameter includes both the nodes at right and left of root
       int ans=max(opt1,max(opt2,opt3));
       return ans;
    }

int main()
{
    Node*root=NULL;
    root=buildTree();
    int ans= diameterOfBinaryTree(root);
    return 0;
}
