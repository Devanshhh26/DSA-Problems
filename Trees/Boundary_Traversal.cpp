#include<iostream>
#include<vector>
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


void printLeftBoundary(Node*root)
{
    if(root==NULL)      // if root is null go back
    {
        return ;
    }
    if(root->left==NULL && root->right==NULL)       // if root is leaf node then go back
    {
        return ;
    }
    cout<<root->data<<" ";
    if(root->left)
    {
        printLeftBoundary(root->left);
    }
    else{
        printLeftBoundary(root->right);
    }
    

}

void printLeafBoundary(Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
    }
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node*root)
{
    if(root==NULL)      // if root is null go back
    {
        return ;
    }
    if(root->left==NULL && root->right==NULL)       // if root is leaf node then go back
    {
        return ;
    }
    if(root->right)
    {
        printRightBoundary(root->right);
    }
    else{
        printRightBoundary(root->left); 
    }
    
    cout<<root->data<<" ";
    
}

void boundaryTraversal(Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    // left boundary print karwa lo
    printLeftBoundary(root->left);
    //print leaf nodes
    printLeafBoundary(root);
    //print right boundary
    printRightBoundary(root->right);
}

int main()
{
    Node*root=NULL;
    root=buildTree();
    vector<int>ans;
    boundaryTraversal(root);
    return 0;
}
