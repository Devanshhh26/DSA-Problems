//  https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

// Method 1: inorder nikal ke vector me store kar lenege aur fir vector ka kth element store krwalenge kyoki BST ka inorder sorted hota hai

// Method 2:    
/*
 int kthSmallest(TreeNode* root, int& k) {
       if(root==NULL)
       {
           return -1;
       }
        int leftAns=kthSmallest(root->left,k);
        if(leftAns!=-1)
        {
            return leftAns;
        }
        k--;
        if(k==0)
        {
            return root->val;
        }
        int rightAns=kthSmallest(root->right,k);
        return rightAns;
    }
*/