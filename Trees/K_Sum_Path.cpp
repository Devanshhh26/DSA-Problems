//https://leetcode.com/problems/path-sum-iii/description/
/*

hum targetSum me se minus karte jaaenge jitni bhi value hume milegi

int ans=0;
    void pathFromOneRoot(TreeNode* root,long long sum)
    {
        if(!root)
        {
            return;
        }
        if(sum==root->val)                  agar sum ki value node ki value jitni hui to iska matlab hume ek path mil gaya hai
        {
            ++ans;
        }
        pathFromOneRoot(root->left,sum-root->val);
        pathFromOneRoot(root->right,sum-root->val);
    }

    int pathSum(TreeNode* root, long long targetSum) {    
        if(root)
        {
            pathFromOneRoot(root,targetSum);
            pathSum(root->left,targetSum);          hume ans har node ke lie nikalna hai na ki sirf root node ke lie islie hum saari nodes ko traverse karenge
            pathSum(root->right,targetSum);
        }
        return ans;
    }
*/