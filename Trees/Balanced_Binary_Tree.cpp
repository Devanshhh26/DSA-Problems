// https://leetcode.com/problems/balanced-binary-tree/description/


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

    bool isBalanced(Node* root) {
      // base case
      if(root==NULL)
      {
        return true;
      }
      // case 1
      int leftHeight=height(root->left);
      int rightHeight=height(root->right);
      int diff=abs(leftHeight-rightHeight);
      bool ans1=diff<=1;
      // recursion
      bool leftAns=isBalanced(root->left);
      bool rightAns=isBalanced(root->right);

      if(ans1 && leftAns && rightAns)
      {
        return true;
      }
      else 
        return false;
    }
int main()
{
    Node*root=NULL;
    root=buildTree();
    bool ans= isBalanced(root);
    cout<<ans;
    return 0;
}