// https://leetcode.com/problems/range-sum-of-bst/

/*
 void solve(TreeNode* root,int low,int high,int &sum)
    {
        if(!root)
        {
            return;
        }
        if(root->val>=low   &&  root->val<=high)
        {
            sum+=root->val;
        }
        solve(root->left,low,high,sum);
        solve(root->right,low,high,sum);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        solve(root,low,high,sum);
        return sum;
    }
*/