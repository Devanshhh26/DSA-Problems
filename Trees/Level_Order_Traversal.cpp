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
    root=buildTree();
    levelOrder(root);
    return 0;
}
