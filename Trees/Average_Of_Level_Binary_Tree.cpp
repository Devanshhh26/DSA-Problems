// https://leetcode.com/problems/average-of-levels-in-binary-tree/
/*

vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        
        if(root == NULL)
        {
            return res;
        }
        q.push(root);
        while(!q.empty())
        {
            double sum = 0;
            int size = q.size();
            
            for(int i = 0;i<size;i++)               // sirft utni baar chalega loop jitni current nodes hai queue me
            {    
                TreeNode* curr = q.front();
                if(curr->left != NULL)
                { 
                    q.push(curr->left);
                }
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                }  
                sum += curr->val;                
                q.pop();
            } 
            res.push_back(sum/size);
        }
        return res;
    }

*/