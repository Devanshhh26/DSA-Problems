
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
int diameter=0;
int height(Node*root)
{
   if(root==NULL)
   {
    return 0;
   }
   int lh=height(root->left);
   int rh=height(root->right);
   int currDiameter=lh+rh;
   diameter=max(diameter,currDiameter);
   return max(lh,rh)+1; 
}


int main()
{
    Node*root=NULL;
    root=buildTree();
    int ans= height(root);
    cout<<diameter;
    return 0;
}
