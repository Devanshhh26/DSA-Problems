#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insertIntoBST(Node*root,int data)
{
    if(root==NULL)                  // it means it is first node or the tree is till now empty
    {   
        root=new Node(data);
        return root;
    }
    // not the first node
    if(root->data>data)
    {
        // insert in left
        root->left=insertIntoBST(root->left,data);
    }
    else{
        // insert in right
        root->right=insertIntoBST(root->right,data);
    }
    return root;
}

void takeInput(Node* &root)
{   
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=insertIntoBST(root,data);
        cin>>data;
    }


}


bool findNode(Node*root,int target)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==target)
    {
        return true;
    }
    if(target>root->data)
    {
        findNode(root->right,target);
    }
    else{
        findNode(root->left,target);
    }

}

int main()
{
    Node*root=NULL;
    cout<<"Enter data";
    takeInput(root);
    bool ans =findNode(root,15);
    cout<<ans;
    return 0;
}