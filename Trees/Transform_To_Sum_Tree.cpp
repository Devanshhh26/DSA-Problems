//https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1

/*
     int sum(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->left==NULL && root->right ==NULL)
        {   
            int temp=root->data;        // current node ka data store karlia
            root->data=0;               // current node ko 0 mark kar dia kyoki leaf node hai
            return temp;
        }
        int lSum=sum(root->left);       // left me recursion call
        int rSum=sum(root->right);      // right me recursion call
        int temp=root->data;            // current node ka data store kar lia
        root->data=lSum+rSum;           // current node ke data ko leftsum aur right sum ke data ke addition se replace kar dia
        return root->data+temp;         // current data after addition aur jo previous data stored tha temp me vo aage bhej dia
        
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        sum(node);
    }
*/