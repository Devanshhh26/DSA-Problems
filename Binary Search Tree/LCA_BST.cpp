//  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

// case 1: agar p and q dono root se chote hai tp left me recursion call kardo

// case 2: agar p and q dono root se bade hai to right me recursion call kardo

// case 3: agar p root se bada ho aur q root se chota to root ans hai islie return root

// case 4: agar p root se chota ho aur q root se bada to root ans hai islie return root
/*
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL)
       {
           return NULL;
       }
       if(p->val<root->val && q->val<root->val)
       {
           return lowestCommonAncestor(root->left,p,q);
       }
       if(p->val>root->val && q->val>root->val)
       {
           return lowestCommonAncestor(root->right,p,q);
       }
       return root;
    }
*/