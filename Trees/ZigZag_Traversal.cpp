//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

// same level order traversal vala scene hai but ek flag maintain karenge jo bataega kis direction me fill karna hai elements
// agar flag true hua to vector ki starting se aur agar false hua to vector ke end se
// jo q ka size hoga vahi vector ka bhi width hoga to use pehle hi calculate kar lenge jisse elements end me insert karvana easy hoga

/*
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {   
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        bool LeftToRight=true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int width=q.size();             // q ka size nikal lia jisse vector ka size define kra sake
            vector<int>oneLevel(width);     // vector define kar dia
            for(int i=0;i<width;i++)
            {
                TreeNode*front=q.front();       // first node ko store kar lia aur pop kar lia queue se
                q.pop();
                int index=leftToRight?i:width-i-1;       // agar left to right direction hai to index i hoga it means starting se fill hoga else agar direction right to left hui to fill width-i-1 se fill hoga meaning end se
                oneLevel[index]=front->val;
                if(front->left)                     // jo element dala hai vector me uske agar left ya right child exist karte hai to use bhi queue me daal do
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
            }
            leftToRight=!leftToRight;           // direction change kardo
            ans.push_back(oneLevel);            // vector ko vector of vector me daal do
        }
        return ans;
    }
*/