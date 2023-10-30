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

void levelOrder(Node*root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        //A    first node ko temp me store kardo
        Node*temp=q.front();
         //B      remove kardo fir first node ko queue se
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        
        else{
             //c    print kardo first node ko
            cout<<temp->data<<" ";
            //D     agar first node ke left ya right me koi child hai to use insert kardo
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }

    }
}

int main()
{
    Node*root=NULL;
    cout<<"Enter data";
    takeInput(root);
    levelOrder(root);
}