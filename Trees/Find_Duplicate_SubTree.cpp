// https://leetcode.com/problems/find-duplicate-subtrees/description/

// preorder se ek encoding banaenge aur use map me push kar denge agar vo already present hogi aur to uska root ans vector me push kar denge aur usko map me increament kar denge
// agar vo present nahi hui to use map me push kar denge
// agar vo present hui but uska count >1 hua to skip kar denge

/*
 vector<TreeNode*>ans;
    unordered_map<string,int>subTreeMap;
    string preorder(TreeNode*root)
    {
        if(!root)
        {
            return "N";                                 // null ke lie kyoki sirf akele pre ordere se unique encoding nahi banege but agar hum null ko bhi consider krenge to unique banegi
        }
        string curr=to_string(root->val);               // root ki value ko convert kar dia string me
        string l=preorder(root->left);                  // left me gae
        string r=preorder(root->right);                 // right me gae
        string s=curr+","+l+","+r;                      // string form ki 
        if(subTreeMap.find(s)!=subTreeMap.end())        // check kari string map me
        {
            if(subTreeMap[s]==1)                        // agar vo present hai aur uska count 1 hai to use ans vector me push kar do
            {
                ans.push_back(root);
            }
            subTreeMap[s]++;                            // aur increament bhi
        }
        else{                                           // else use map me push kardo aur count 1 kardo
            subTreeMap[s]=1;
        }
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorder(root);
        return ans;
    }
*/