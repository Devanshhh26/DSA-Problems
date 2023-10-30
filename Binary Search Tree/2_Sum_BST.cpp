//  https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

// inoreder nikal ke store karlo vector me
// uske baad two opinter approach use karke ans find karlo where start=0 and end=vector.size()-1
// sum=vector[start]+vector[end]
// if sum==k    return true;
// if sum>k     end--;
// if sum<k     start++;

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

void storeInorder(Node*root,vector<int>&res)
    {
        if(root==NULL)
        {
            return;
        }
        storeInorder(root->left,res);
        res.push_back(root->data);
        storeInorder(root->right,res);
    }

    bool findTarget(Node* root, int k) {
        vector<int>res;
        storeInorder(root,res);
        int start=0;
        int end=res.size()-1;
        while(start<end)
        {
            if(res[start]+res[end]==k)
            {
                return true;
            }
            else if(res[start]+res[end]>k){
                end--;
            }
            else{
                start++;
            }
        }
        return false;

    }

int main()
{
    Node*root=NULL;
    cout<<"Enter data";
    takeInput(root);
    bool ans=findTarget(root,9);
    cout<<ans;
    return 0;
    
}