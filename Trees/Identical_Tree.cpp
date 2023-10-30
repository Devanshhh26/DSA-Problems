//  https://leetcode.com/problems/same-tree/
/*
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)      // agar q ya p me se koi bhi ek null hai to return false else return true
        {
            return true;
        }
       
        if(p && q)          // agar dono exist karte hai
        {
            if(p==q)
            return  (p->val==q->val)  &&  isSameTree(p->left,q->left) &&  isSameTree(p->right,q->right);
        }
        return false
              
    }

    */