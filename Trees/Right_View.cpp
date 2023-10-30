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

// method 1 level order traversal use kar lenge aur har level ka sirf 1st element hi dalenge


// method 2 ek map banaenge aur usme har level ko uss level ke  element ke sath map karenge agar koi level already mapped hai to fir use skip kardenge else map kar denge



void printRightView(Node*root,vector<int>&ans,int level)
{
    if(root==NULL)
    {
        return ;
    }
    if(level==ans.size())                     // agar level aur size equal honge to vector me push kar denge matlab jaise level 0 me koi bhi element nahi hoga vector me to root push kar denge fir level 1 me sirf ek element hoga to fir uss level ka first element push kar denge 
    {
        ans.push_back(root->data);
    }
    printRightView(root->right,ans,level+1);
    printRightView(root->left,ans,level+1);
}


int main()
{
    Node*root=NULL;
    root=buildTree();
    vector<int>ans;
    printRightView(root,ans,0);
    
    for(auto i:ans)
    {
        cout<<i<<" "<<endl;
    }

    return 0;
}
