//https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

/*
 pair<int,int>getMaxSumHelper(Node*root)
    {
        if(!root)
        {
            return{0,0};
        }
        auto left=getMaxSumHelper(root->left);
        auto right=getMaxSumHelper(root->right);
        
        // sum including the node
        int a=root->data+left.second+right.second;
        // sum excluding that node to koi bhi le sakte hai kyoki usse pehl ehumne kuch nahi lia hai
        int b=max(left.first,left.second)+max(right.first,right.second);
        return {a,b};
    }
    
    int getMaxSum(Node *root) 
    {
        auto ans=getMaxSumHelper(root);
        return max(ans.first,ans.second);
    }
*/