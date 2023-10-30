//  https://leetcode.com/problems/symmetric-tree/description/

/*
bool check(TreeNode*p,TreeNode*q)
    {
        if(p==NULL  &&  q==NULL)
        {
            return true;
        }
        if(p&&q)
        {
            return (p->val==q->val) && check(p->left,q->right) &&  check(p->right,q->left);
        }
       
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode* p=root->left;
        TreeNode* q=root->right;
        
        bool ans=check(p,q);
        return ans;
    }
*/