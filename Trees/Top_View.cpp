#include<iostream>
#include<map>
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

void printTopView(Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    
    // create a map for storing horizontal distance with top Node data
    map<int,int>topNode;
    
    // we will store a pair consisting of node  and horizontal distance
    queue<Node*,int>q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<Node*,int>temp=q.front();
        q.pop();
        
        Node* frontNode=temp.first;
        int hd=temp.second;
        
        // jo bhi horizontal distance aaya hai check if answer for that hd exist or not
        if(topNode.find(hd)==topNode.end())
        {
            // create entry
            topNode[hd]=frontNode->data;
        }
        if(frontNode->left)
        {
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right)
        {
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    // ab answer store hua hoga map me
    cout<<"printing data: "<<endl;
    for(auto i:topNode)
    {
        cout<<i.first<<" -> "<<i.second<<endl;
    }

}

int main()
{
    Node*root=NULL;
    root=buildTree();

    return 0;
}
